/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#define START_SCREEN 0
#define GAME_RUNNING 1
#define GAME_OVER    2

#define RESTART_DELAY_TIME 180 // time is in frames/sec

#include "uiInteract.h"
#include <vector>
#include "ship.h"
#include "bullet.h"
#include "point.h"
#include "rocks.h"
#include "stars.h"

/*****************************************
* GAME
* The main game class containing all the state
*****************************************/
class Game
{
public:
   /*********************************************
   * Constructor
   * Initializes the game
   *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
   * Function: handleInput
   * Description: Takes actions according to whatever
   *  keys the user has pressed.
   *********************************************/
   void handleInput(const Interface & ui);

   void drawScore();
   
   /*********************************************
   * Function: advance
   * Description: Move everything forward one
   *  step in time.
   *********************************************/
   void advance();
   void endGame();
   void displayInstructions();
   void restartGame();

   /*********************************************
   * Function: draw
   * Description: draws everything for the game.
   *********************************************/
   void draw(const Interface & ui);

   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;

private:
   int gameState = START_SCREEN;
   int restartDelay = RESTART_DELAY_TIME;
   int score;
   int highestScore;

   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   Ship ship;
   Stars stars;
   std::vector<Bullet> bullets;
   std::vector<Rock *> asteroids;

   /*************************************************
   * Private methods to help with the game logic.
   *************************************************/
   void advanceBullets();
   void advanceAsteroids();
   void advanceShip();

   void handleCollisions();
   void cleanUpZombies();
};


#endif /* GAME_H */
