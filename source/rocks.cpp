/***********************************************************************
* Implementation File:
*    Rocks: A class representing a Rock base class and three classes
*    derived from it
* Author:
*    Spencer Freebairn
* Summary:
*    Method definitions for the Rock class and its children
* Dependencies (included in header):
*    velocity.h
*    point.h   
*    uiDraw.h
************************************************************************/
#include "rocks.h"
#include <math.h>
#include <cmath>
#include <vector>

/***********************************
* CONSTRUCTORS
* Sets the initial values for rocks
************************************/
// BIG ROCK
BigRock::BigRock()
{
   setRadius(BIG_ROCK_SIZE);
   setChangeInAngle(BIG_ROCK_SPIN);
   velocity.setDx(BIG_ROCK_SPEED * (-cos(M_PI / 180.0 * getInitialAngle())));
   velocity.setDy(BIG_ROCK_SPEED * (sin(M_PI / 180.0 * getInitialAngle())));
}

BigRock::BigRock(Velocity velocity, Point position)
{
   setVelocity(velocity);
   setPosition(position);
}

// MEDIUM ROCK
MediumRock::MediumRock()
{
   setRadius(MEDIUM_ROCK_SIZE);
   setChangeInAngle(MEDIUM_ROCK_SPIN);
   velocity.setDx(DEFAULT_ROCK_SPEED * (-cos(M_PI / 180.0 * getInitialAngle())));
   velocity.setDy(DEFAULT_ROCK_SPEED * (sin(M_PI / 180.0 * getInitialAngle())));
}

MediumRock::MediumRock(Velocity velocity, Point position)
{
   setVelocity(velocity);
   setPosition(position);
   setRadius(MEDIUM_ROCK_SIZE);
   setChangeInAngle(MEDIUM_ROCK_SPIN);
}

// SMALL ROCK
SmallRock::SmallRock()
{
   setRadius(SMALL_ROCK_SIZE);
   setChangeInAngle(SMALL_ROCK_SPIN);
   velocity.setDx(DEFAULT_ROCK_SPEED * (-cos(M_PI / 180.0 * getInitialAngle())));
   velocity.setDy(DEFAULT_ROCK_SPEED * (sin(M_PI / 180.0 * getInitialAngle())));
}

SmallRock::SmallRock(Velocity velocity, Point position)
{
   setVelocity(velocity);
   setPosition(position);
   setRadius(SMALL_ROCK_SIZE);
   setChangeInAngle(SMALL_ROCK_SPIN);
}

/***********************************
* BREAKAPART
************************************/
// BIG ROCK
void BigRock::breakApart(std::vector<Rock*> &asteroids, int parentRockIndex)
{
   // parameters: vector of Rock*, index of parent rock, dx modifier, dy modifier
   newMediumRock(asteroids, parentRockIndex, 0, 1);
   newMediumRock(asteroids, parentRockIndex, 0, -1);
   newSmallRock(asteroids, parentRockIndex, 2, 0);
}

// MEDIUM ROCK
void MediumRock::breakApart(std::vector<Rock*> &asteroids, int parentRockIndex)
{
   newSmallRock(asteroids, parentRockIndex, 3, 0);
   newSmallRock(asteroids, parentRockIndex, -3, 0);
}

// SMALL ROCK
// has to be implemented for compiler to be happy
void SmallRock::breakApart(std::vector<Rock*> &asteroids, int parentRockIndex) {}

/***********************************
* These methods spawn new rocks from other rocks
************************************/
// MEDIUM ROCK
void Rock::newMediumRock(std::vector<Rock*> &asteroids, int parentRockIndex, int dxModifier, int dyModifier)
{
   Rock* newRock = new MediumRock(Velocity(asteroids[parentRockIndex]->getVelocity().getDx() + dxModifier
      , asteroids[parentRockIndex]->getVelocity().getDy() + dyModifier)
      , Point(asteroids[parentRockIndex]->getPosition()));
  
   asteroids.push_back(newRock);
}

// SMALL ROCK
void Rock::newSmallRock(std::vector<Rock*> &asteroids, int parentRockIndex, int dxModifier, int dyModifier)
{
   Rock* newRock = new SmallRock(Velocity(asteroids[parentRockIndex]->getVelocity().getDx() + dxModifier
      , asteroids[parentRockIndex]->getVelocity().getDy() + dyModifier)
      , Point(asteroids[parentRockIndex]->getPosition()));
  
   asteroids.push_back(newRock);
}

/***********************************
* The following methods draw the
* asteroid
************************************/
// BIG ROCK
void BigRock::draw() const
{
   drawLargeAsteroid(position, angle);
}

// MEDIUM ROCK
void MediumRock::draw() const
{
   drawMediumAsteroid(position, angle);
}

// SMALL ROCK
void SmallRock::draw() const
{
   drawSmallAsteroid(position, angle);
}