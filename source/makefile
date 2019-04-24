###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Walker, CS165
# Author:
#     Spencer Freebairn
# Summary:
#     This program allows the user to play a game of Asteroids.
#     The user controls a ship using the arrow keys and fires
#     bullets using the space key to destroy asteroids.
# Above and Beyond
#     - added stars to the background
#     - added start screen with instructions at beginning
#       of game
#     - added game over screen
#     - added automatic restart after game over
#	  - changed ship/rock colors
#     - added ability to invert contols by pressing F1
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o stars.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o stars.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

stars.o: stars.o
	g++ -c stars.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
