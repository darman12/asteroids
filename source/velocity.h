#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dx;
   float dy;

public:
   /**************************
   * Constructors
   **************************/
   Velocity();
   Velocity(float, float);

   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;
};

#endif
