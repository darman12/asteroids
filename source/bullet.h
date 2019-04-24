#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#define _USE_MATH_DEFINES

#include "flyingObject.h"

// Put your Bullet class here
class Bullet : public FlyingObject
{
private:
   int numFramesAlive;

public:
   Bullet()
   {
      setNumFramesAlive(0);
   }

   int getNumFramesAlive() const { return numFramesAlive; }
   void setNumFramesAlive(int);

   void fire(Point, float, Velocity);

   void draw() const; 
};



#endif /* bullet_h */
