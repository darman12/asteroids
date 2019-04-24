/***********************************************************************
* Implementation File:
*    STARS: A class representing the starry sky
* Author:
*    Spencer Freebairn
*
* Created: June/July 2018
*
* Summary:
*    Details about the starry sky
* Dependencies:
*    uiDraw.h
*    point.h
************************************************************************/

#include "stars.h"
#include "point.h"
#include "uiDraw.h"

/******************************************
* SET NUM STARS
* Randomly chooses the number of stars to
* be drawn.
*   DEPENDENCIES
*      uiDraw.h  For random()
*   INPUT  minNumStars  The minimum number
*                       of stars to draw
*          maxNumStars  The maximum number
*                       of stars to draw
******************************************/
void Stars::setNumStars(int numStars)
{
   this->numStars = numStars;
}

/******************************************
* GENERATE STARS
* Fills an array of point objects with
* random coordinates within the game window
*   DEPENDENCIES
*	   uiDraw.h  For random()
******************************************/
void Stars::generateStars()
{
   for (int i = 0; i < (numStars - 1); i++)
   {
      starLocations[i].setX(random(-200, 200));
      starLocations[i].setY(random(-200, 200));
   }
}

/******************************************
* DRAW
* Renders stars at the locations given in
* the array of point objects
*   DEPENDENCIES
*	   uiDraw.h  For drawDot()
******************************************/
void Stars::draw() const
{
   for (int i = 0; i < (numStars - 1); i++)
   {
      drawDot(starLocations[i]);
   }
}
