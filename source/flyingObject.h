/*************************************************************
* File: FlyingObject.h
* Author: Spencer Freebairn
*
* Description: Defines a flying object. Provides methods and
* data to keep track and change a flying object's location in
* two-dimensional space as well as remove it from the game
*
* Dependencies:
*    velocity.h
*    point.h
*    uiDraw.h
*************************************************************/
#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

#define ANGLE_START 90
#define DEFAULT_RADIUS 10

class FlyingObject
{
protected:
   Point position;
   Velocity velocity;
   bool alive;
   float angle;
   float changeInAngle;
   int radius;
   float RGBColor[3]; // can be used to pass new colors to glColor3f()

public:
   /*********************************************
   * constructors
   *********************************************/
   FlyingObject()
   {
      alive = true;
      setPosition(Point(-200, 200));
      setAngle(ANGLE_START);
      radius = DEFAULT_RADIUS;
      setChangeInAngle(0);
      for (int i = 0; i < 3; i++)
      {
         RGBColor[i] = 1.0;
      }
   }

   FlyingObject(Point startingPosition, float startingAngle, int radius, 
      float changeInAngle)
   {
      alive = true;
      setPosition(startingPosition);
      setAngle(startingAngle);
      setRadius(radius);
      setChangeInAngle(changeInAngle);
      for (int i = 0; i < 3; i++)
      {
         RGBColor[i] = 1.0;
      }
   }

   /********************
   * getters
   ********************/
   Point getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   bool isAlive() const   { return alive; }
   int getRadius() const  { return radius; }
   int getAngle() const { return angle; }

   /********************
   * setters
   ********************/
   void setPosition(Point);
   void setVelocity(Velocity);
   void setAngle(float);
   void setRadius(int);
   void setChangeInAngle(float);
   
   void revive();
   void kill();

   /*****************************************************
   * Updates the object's position by adding its Y 
   * velocity to its current Y value and its X velocity 
   * to its current X value
   *****************************************************/
   void advance();

   /*************************
   * displays the flying object
   *************************/
   virtual void draw() const = 0;

   //~FlyingObject();
};
#endif // FLYING_OBJECT_H
