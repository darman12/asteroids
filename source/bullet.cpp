#include "bullet.h"

void Bullet::setNumFramesAlive(int num)
{
   if (num < 0)
   {
      numFramesAlive++;
   }
   else
   {
      numFramesAlive = num;
   }
}

void Bullet::fire(Point startPoint, float shipAngle, Velocity shipVelocity)
{
   position.setX(startPoint.getX());
   position.setY(startPoint.getY());

   this->angle = angle;

   velocity.setDx(shipVelocity.getDx() - (BULLET_SPEED * (-cos(M_PI / 180.0 * 
      shipAngle))));
   velocity.setDy(shipVelocity.getDy() + (BULLET_SPEED * (sin(M_PI / 180.0 * 
      shipAngle))));
}

void Bullet::draw() const
{
   drawDot(position);
}