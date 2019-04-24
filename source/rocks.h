/*************************************************************
* File: rocks.h
* Author: Spencer Freebairn
*
* Description: Defines a Rock base class and three classes
* derived from it
*
* Dependencies:
*    velocity.h
*    point.h
*************************************************************/
#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"
#include <vector>

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPEED 1
#define DEFAULT_ROCK_SPEED 1
#define _USE_MATH_DEFINES

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

class Rock : public FlyingObject
{
private:
   int initialAngle;

public:
   Rock()
   {
      setPosition(Point(random(-200, 201), random(-200, 201)));
      setAngle(random(0, 361));
      initialAngle = angle;
   }

   Rock(float angle)
   {
      setAngle(angle);
      initialAngle = angle;
   }
   int getInitialAngle() { return initialAngle; }

   /************************
   * HIT
   * Handles what happens when rock is hit.
   ************************/
   int hit() { kill(); }

   virtual void breakApart(std::vector<Rock*> &asteroids, int) = 0;
   void newMediumRock(std::vector<Rock*> &asteroids, int, int, int);
   void newSmallRock(std::vector<Rock*> &asteroids, int, int, int);

   /************************
   * DRAW
   * Displays the rock
   *
   * Pure virtual funciton that must be defined in child class
   ************************/
   virtual void draw() const = 0;
};


//   BigRock   
class BigRock : public Rock
{
public:
   /*********************************************
   * constructors
   *********************************************/
   BigRock();
   BigRock(Velocity, Point);

   void breakApart(std::vector<Rock*> &asteroids, int);

   /*************************
   * DRAW
   * displays the big rock
   *************************/
   void draw() const;
};


//   MediumRock
class MediumRock : public Rock
{
public:
   /*********************************************
   * constructors
   *********************************************/
   MediumRock();
   MediumRock(Velocity, Point);

   void breakApart(std::vector<Rock*> &asteroids, int);
   
   /*************************
   * DRAW
   * displays the medium rock
   *************************/
   void draw() const;
};


//   SmallRock
class SmallRock : public Rock
{
public:
   /************************
   * constructors
   ************************/
   SmallRock();
   SmallRock(Velocity, Point);

   void breakApart(std::vector<Rock*> &asteroids, int);

   /*************************
   * DRAW
   * displays the small rock
   *************************/
   void draw() const;
};

#endif /* rocks_h */
