/***********************************************************************
* Implementation File:
*    Ship: A class representing a Ship object
* Author:
*    Spencer Freebairn
* Summary:
*    Method definitions for the Ship class
* Dependencies:
*    FlyingObject.h
************************************************************************/
#include "ship.h"

#include <math.h>
#include <cmath>

void Ship::applyThrust()
{
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * (angle + 90)))));
   velocity.setDy(velocity.getDy() + (THRUST_AMOUNT * (sin(M_PI / 180.0 * (angle + 90)))));
}

void Ship::rotateLeft()
{
   if (rotationInverted)
   {
      setAngle(angle - ROTATE_AMOUNT);
   }
   else
   {
      setAngle(angle + ROTATE_AMOUNT);
   }
}

void Ship::rotateRight()
{
   if (rotationInverted)
   {
      setAngle(angle + ROTATE_AMOUNT);
   }
   else
   {
      setAngle(angle - ROTATE_AMOUNT);
   }
}


/******************************************
* INVERTROTATIONCONTROL
* Inverts the controls that rotate the ship
******************************************/
void Ship::invertRotationControl()
{
   if (rotationInverted)
   {
      rotationInverted = false;
   }
   else
   {
      rotationInverted = true;
   }
}

/***********************************
* DRAW
* Draws a circle to represent a ship
***********************************/
void Ship::draw() const
{
   drawShip(position, angle, canThrust);
}
