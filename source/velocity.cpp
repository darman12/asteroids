#include "velocity.h"

#include <iostream>
using namespace std;

/**************************
* Constructors
**************************/
Velocity::Velocity()
{
   setDx(0);
   setDy(0);
}

Velocity::Velocity(float dx, float dy)
{
   setDx(dx);
   setDy(dy);
}

void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}
