/***********************************************************************
* Header File:
*    STARS : A class representing the starry sky
* Author:
*    Spencer Freebairn
*
* Created: June/July 2018
*
* Summary:
*    Details about the starry sky
************************************************************************/

#ifndef STARS_H
#define STARS_H

#include "point.h"
#include "uiDraw.h"

class Stars
{
   private:
      Point starLocations[99];
      int numStars;

   public:
      /***********************************************
      * sets some default values and generates star
      * locations
      ***********************************************/
      Stars()
      {
         setNumStars(random(50, 100));
         generateStars();
      }
      
      Stars(int numStars)
      {
         setNumStars(numStars);
         generateStars();
      }

      Stars(int minNumStars, int maxNumStars)
      {
         setNumStars(random(minNumStars, maxNumStars));
         generateStars();
      }

      /***********************************************
      * calls uiDraw::random to set a random number of
      * stars to be generated
      ***********************************************/
      void setNumStars(int);

      /***********************************************
      * just in case somebody wants to know :)
      ***********************************************/ 
      int getNumStars() { return numStars; };
     
      /***********************************************
      * randomly determines the locations of the stars
      ***********************************************/
      void generateStars();

      /*******************
      * displays the stars
      *******************/
      void draw() const;
};

#endif // STARS_H


