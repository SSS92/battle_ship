
This is the README file of “Battle Ship” program developed by
Galust Betkhemyan and Sevak Sahakyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. BUILD
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION
        

1. AUTHOR
Galust Betkhemyan, Sevak Sahakyan.
E-mail: sevak.sahakyan29@gmail.com
		galustbetkhemyan@gmail.com

Project Maintainer
	Galust Betkhemyan, Sevak Sahakyan.
	sevak.sahakyan29@gmail.com
	galustbetkhemyan@gmail.com
	
2. INTRODUCTION
The “Battle Ship” program presents some cases of the famous homonyms game. 
The program creates an area where should be placed user’s ships and will allow the user to insert coordinates for shooting. 
The ships layout will be generated randomly. The program is designed to implement the ability of playing the game by two users. 

3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen

4. BUILD
See the following commands in the project root directory.
Build the project
	make
	
Delete secondary files
	make clean

5. DIRECTORY STRUCTURE
- battleShip – the top directory
	- src – should contain the source code of the project
	- makefile – the top makefile for building the project
	- docs -  for containing documentations
		Product requirements document
		Functional specification document
		Development specification document
		/doxygen_config should contain file for doxygen configuration file

After building, the following directories should be created:
	- deps – should contain dependency files
	- obj – should contain oject files
	- bin – should contain executable file
	
	
6. USAGE
The “Battle Ship” program can be run with "bin/program" command.
The program presents some cases of the famous homonyms game. The program creates an area where should be placed
 user’s ships and will allow the user to insert coordinates for shooting. The ships layout will be generated randomly. 
 The program is designed to implement the ability of playing the game by two users. Each user run the program on his personal computer. 
 The program generates an area and  fill it with ships in the random layout. After it each user have ability to insert coordinates, 
 where his(him) opponent shots. There is no control on the user’s step sequence, all of this are controlled by users.
 After each step program prints corresponding result for the shooting such as “out of sea”, “killed”, “your opponent won”, 
 etc.. The game is finished, when one of the users has no undamaged unit of a ship.

7. DOCUMENTATION
"make docs" command generates doxygen documentation.

Doxygen also generates documentation from C/C++ code comments.

To see the generated documentation use ./docs/doxygen/html/index.html.
