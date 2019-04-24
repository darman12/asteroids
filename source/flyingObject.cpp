/***********************************************************************
* Implementation File:
*    FlyingObject: A class representing a flying object
* Author:
*    Spencer Freebairn
* Summary:
*    Method definitions for the FlyingObject class
* Dependencies (included in header):
*    velocity.h
*    point.h
************************************************************************/

#include "flyingObject.h"


/************************
* setters
************************/
void FlyingObject::setPosition(Point point)
{
   position.setX(point.getX());
   position.setY(point.getY());
}

void FlyingObject::setVelocity(Velocity velocity)
{
   this->velocity.setDx(velocity.getDx());
   this->velocity.setDy(velocity.getDy());
}

void FlyingObject::setAngle(float angle)
{
   // if the angle is being increased and goes out 
   //    of range, sets it back to 1, if the angle
   //    is being decreased and goes below
   //    0, set it back to 360.
   if (angle > 360)
   {
      this->angle = 1;
   }
   else if (angle < 0)
   {
      this->angle = 360;
   }
   else
   {
      this->angle = angle;
   }  
}

void FlyingObject::setRadius(int radius)
{
   if (radius < 0)
   {
      this->radius = DEFAULT_RADIUS;
   }
   else
   {
      this->radius = radius;
   }
}

void FlyingObject::setChangeInAngle(float changeInAngle)
{
   this->changeInAngle = changeInAngle;
}

/**********************************************
* REVIVE
* sets the FlyingObject to alive
**********************************************/
void FlyingObject::revive()
{
   alive = true;
}

/**********************************************
* KILL
* sets the FlyingObject to not alive
**********************************************/
void FlyingObject::kill()
{
   alive = false;
}

/**********************************************
* ADVANCE
* uses the FlyingObject's velocity to calculate 
* its new position
**********************************************/
void FlyingObject::advance()
{
   if (alive)
   {
      position.addX(velocity.getDx());
      position.addY(velocity.getDy());

      if (position.getX() > 200 || position.getX() < -200)
      {
         position.setX(-position.getX());
      }
      
      if (position.getY() > 200 || position.getY() < -200)
      {
         position.setY(-position.getY());
      }

      setAngle(angle + changeInAngle);
   }
}