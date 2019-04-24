/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "stars.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

using namespace std;

/***************************************
* GAME CONSTRUCTOR
***************************************/
Game::Game(Point tl, Point br)
   : topLeft(tl), bottomRight(br)
{
   ship.setPosition(Point(0, 0));
   
   stars.setNumStars(25);

   for (int i = 0; asteroids.size() < 5; i++)
   {      
      // dynamically allocate a new rock, then add its pointer
      //    the vector of rock pointers
      Rock * pNewRock = new BigRock;
      asteroids.push_back(pNewRock);
   }
}

/****************************************
* GAME DESTRUCTOR
****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently an asteroid allocated
   //       and if so, delete it.
}

/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
   if (gameState == GAME_RUNNING)
   {
      advanceBullets();
      advanceShip();
      advanceAsteroids();
      handleCollisions();
      if (asteroids.size() == 0)
      {
         gameState = GAME_OVER;
      }
   }
   
   if (gameState == GAME_OVER && restartDelay / 30 > 0)
   {
      endGame();
   }
   else if (gameState == GAME_OVER)
   {
      restartGame();
   }

   cleanUpZombies();
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
***************************************/
void Game::advanceBullets()
{
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].getNumFramesAlive() > 40)
      {
         bullets[i].kill();
      }
      else
      {
         bullets[i].setNumFramesAlive(bullets[i].getNumFramesAlive() + 1);
      }
   }

   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
      }
   }
}

/**************************************************************************
* GAME :: ADVANCE SHIP
***************************************************************************/
void Game::advanceShip()
{
   if (ship.isAlive())
   {
      ship.advance();
   }
}

/**************************************************************************
* GAME :: ADVANCE ASTEROIDS
**************************************************************************/
void Game::advanceAsteroids()
{
   for (int i = 0; i < asteroids.size(); i++)
   {
      asteroids[i]->advance();
   }
}

/**************************************************************************
* GAME :: DISPLAY INSTRUCTIONS
**************************************************************************/
void Game::displayInstructions()
{
   // render the stars
   stars.draw();

   // display game instructions
   drawText(Point(-100, 85), "MISSION: Destroy all of the asteroids");
   drawText(Point(-22, 35), "Controls:");
   drawText(Point(80, -12), "start / fire");

   // draw symbols
   drawPolygon(Point(-80, -8), 10, 3, 180);  // left arrow
   drawPolygon(Point(-50, 8), 10, 3, 90);    // up arrow
   drawPolygon(Point(-20, -8), 10, 3, 0);    // right arrow
   drawRect(Point(50, -8), 50, 15, 0);       // space bar
}

/**************************************************************************
* GAME :: END GAME
**************************************************************************/
void Game::endGame()
{

   if (score > highestScore)
   {
      highestScore = score;
   }
  
   // display game over message
   drawText(Point(-35, 5), "GAME OVER");
   
   restartDelay--;
   
   // display restart timer
   if (restartDelay / 30 > 0)
   {
      drawText(Point(-40, -24), "Restarting in");
      drawNumber(Point(36, -15), restartDelay / 30);
   }

   // kills all of the asteroids so cleanUpZombies will delete them
   for (int i = 0; i < asteroids.size(); i++)
   {
      asteroids[i]->kill();
   }

   // kills all of the bullets so cleanUpZombies will delete them
   for (int i = 0; i < bullets.size(); i++)
   {
      bullets[i].kill();
   }

   // make sure that all bullets and rocks are deleted
   //    before restarting the game.
   cleanUpZombies();
}

/**************************************************************************
* GAME :: RESTART GAME
**************************************************************************/
void Game::restartGame()
{
   // reset the ship to its beginning state
   ship.setPosition(Point(0, 0));
   ship.setVelocity(Velocity(0, 0));
   ship.setAngle(0);
   ship.setChangeInAngle(0);
   ship.revive();
   ship.canThrust = false;

   score = 0;

   restartDelay = RESTART_DELAY_TIME;
   gameState = GAME_RUNNING;

   for (int i = 0; asteroids.size() < 5; i++)
   {
      Rock* pNewRock = new BigRock;
      asteroids.push_back(pNewRock);
   }
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a rock, ship and a bullet.
**************************************************************************/
void Game::handleCollisions()
{
   for (int i = 0; i < asteroids.size(); i++)
   {
      // check for bullets impacting with asteroids
      for (int bulletsCounter = 0; bulletsCounter < bullets.size(); bulletsCounter++)
      {
         if (bullets[bulletsCounter].isAlive()
            && getClosestDistance(*asteroids[i], bullets[bulletsCounter]) 
            < asteroids[i]->getRadius())
         {
            // delete the bullet that collided so that it doesn't
            //    cause unexpected collisions before cleanUpZombies
            //    gets to it
            bullets[bulletsCounter].kill();

            score++;

            // spawn new asteroids if applicable
            asteroids[i]->breakApart(asteroids, i);

            asteroids[i]->kill();
         }
      }

      // check for ship impacting with asteroids
      if (getClosestDistance(*asteroids[i], ship) <= (asteroids[i]->getRadius() 
         + ship.getRadius()))
      {
         asteroids[i]->kill();
         ship.kill();
         gameState = GAME_OVER;
      }
   }
}

/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects
**************************************************************************/
void Game::cleanUpZombies()
{
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }

   // iterate through the vector of rock pointers, deleting the 
   //    memory and pointer of all dead asteroids
   for (int i = 0; i < asteroids.size(); )
   {
      if (!asteroids[i]->isAlive())
      {
         // deallocate memory allocated for asteroid
         delete asteroids[i];

         // set pointer to null
         asteroids[i] = NULL;

         // delete pointer
         asteroids.erase(asteroids.begin() + i);
      }
      else
      {
         i++;
      }
   }
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
   // invert the rotation control when F1 is pressed
   if (ui.isF1())
   {
      ship.invertRotationControl();
   }

   if (gameState == GAME_RUNNING)
   {
      if (ui.isUp())
      {
         ship.applyThrust();
         ship.canThrust = true;
      }
      else
      {
         ship.canThrust = false;
      }

      if (ui.isLeft())
      {
         ship.rotateLeft();
      }

      if (ui.isRight())
      {
         ship.rotateRight();
      }

   }

   // starts/restarts the game, or fires a bullet when space bar is pressed
   if (ui.isSpace()) 
   {
      if (gameState == START_SCREEN)
      {
         gameState = GAME_RUNNING;
      }
      else
      {
         Bullet newBullet;
         newBullet.fire(ship.getPosition(), (ship.getAngle() + 90)
            , ship.getVelocity());

         bullets.push_back(newBullet);
      }
   }
}

void Game::drawScore()
{
   drawText(Point(-175, 175), "Highscore: ");
   drawNumber(Point(-110, 185), highestScore);

   drawText(Point(-175, 150), "Current Score: ");
   drawNumber(Point(-90, 160), score);
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
   stars.draw();

   if (gameState == GAME_RUNNING)
   {
      if (ship.isAlive())
      {
         drawScore();
         ship.draw();

         for (int i = 0; i < asteroids.size(); i++)
         {
            if (asteroids[i]->isAlive())
            {
               asteroids[i]->draw();
            }
         }

         // draw the bullets, if they are alive
         for (int i = 0; i < bullets.size(); i++)
         {
            if (bullets[i].isAlive())
            {
               bullets[i].draw();
            }
         }
      }
      else
      {
         endGame();
      }
   }
   else if (gameState == START_SCREEN)
   {
      displayInstructions();
   }
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPosition().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPosition().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPosition().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPosition().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


