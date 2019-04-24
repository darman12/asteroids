/*************************************************************
* File: ship.h
* Author: Spencer Freebairn
*
* Description: Defines a Ship class
* Extends FlyingObject
*
* Dependencies:
*    FlyingObject.h
*    uiDraw.h
*************************************************************/
#include "flyingObject.h"
#include "uiDraw.h"

#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10


#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define _USE_MATH_DEFINES


// Put your Ship class here
class Ship : public FlyingObject
{
private:
   bool rotationInverted = false;

public:
   Ship()
   {
      setAngle(0);
   }

   bool canThrust = false;
   void applyThrust();
   void rotateLeft();
   void rotateRight();

   /***************************
   * Inverts the controls that rotate
   * the ship
   ***************************/
   void invertRotationControl();

   void draw() const;
};

#endif /* ship_h */
