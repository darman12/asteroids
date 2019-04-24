# Asteroids
School assignment to implement a "clone" of the classic video game, Asteroids using C++. This was a sort of capstone project for the semester where we used the object oriented programming paradigm we had been studying. This readme is focused on the project and what I learned, you will find instructions on building the game from source at the bottom of this page.

## Scope of project
James N Helfrich, faculty member of the College of Computer Science and Electrical Engineering at Brigham Young University - Idaho, provided some of the core components of the game, such as the game loop and uiDraw, an abstraction over OpenGL. The game loop and graphics drawing were outside of the scope of the course; thus, the instructor provided this code. My responsibility was to design and implement additional classes and game logic that would complete the game. This started with designing the classes with class diagrams.

## What I learned
This project was the largest project I had worked on before. The project included several files and many classes. I practiced designing and implementing classes, then using them in my program. That was a lot of fun.

After meeting the core specifications of the assignment, I did some exploration of uiDraw and learned a bit about how to make calls to OpenGL. I did additional research about OpenGL itself, learning about graphics APIs, specs/implementations, graphics hardware, etc.

I learned a bit about tooling. I used Visual Studio, GCC, and makefiles. While this was not my first time using Visual Studio, I dove into some of its features more than I had in the past. One of my favorites shows you all of the places where a function/method was called in the current project.

## What I need to improve
Planning was my weakest area for this project. In particular, I found myself adding many methods and properties in my classes that I had not planned for. Even worse, I didn't even plan out the game as a whole. To be fair, we were provided with a document outlining most of the specs for the project, excluding the actual implementation of the classes.

I need to learn how to use debugging tools. I used Visual Studio throughout the project, but I did not leverage any of its debugging tools. I used simple methods such as print statements.



## Classes implemented by instructor
* driver.cpp *main function that starts the game. Contains the game loop.*
* uiDraw *some functions that draw and translate basic shapes with OpenGL*
* uiInteract *sets up an OpenGL window and sets it up to receive user input. Input logic is included in the Game class, implemented by myself*
* Point

## Classes I implemented
* Game
* FlyingObject
  * Ship
  * Bullet
  * Rocks
* Stars
* Velocity

## Building the game from source
