# Asteroids
School assignment to implement a "clone" of the classic video game, Asteroids using C++. This was a sort of capstone project for the semester where we used the object oriented programming paradigm we had been studying.

## What I learned

## Scope
The instructor provided some key libraries and some of the core components of the game, such as the game loop and uiDraw, an abstraction over OpenGL. The game loop and graphics drawing were outside of the scope of the course; thus, the instructor provided this code. A detailed list of the provided source will follow.

### Classes implemented by instructor
* driver.cpp *main function that starts the game. Contains the game loop.
* uiDraw *some functions that draw and translate basic shapes with OpenGL*
* uiInteract *sets up an OpenGL window and sets it up to receive user input. Input logic is included in the Game class, implemented by myself*
* Point

### Classes I implemented
* Game
* FlyingObject
  * Ship
  * Bullet
  * Rocks
* Stars
* Velocity

## Building the game from source
