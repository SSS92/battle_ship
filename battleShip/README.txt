INTRODUCTION
------------------------------------------------

This is the README file for the “Battle Ship” program version 1.0.0
This package can be found in https://github.com/SSS92/battle_ship

The “Battle Ship” program presents some cases of the famous homonyms game. The program creates an area where should be placed user’s ships and will allow the user to insert coordinates for shooting. The ships layout will be generated randomly. The program is designed to implement the ability of playing the game by two users. 


CODE COMPILATION
------------------------------------------------

For compilation use the following command in the project root directory: 

make

To generate doxygen documentations use the following command: 

make docs

To delete secondary files which should be generated after compilation and doxygen files use the following command:

make clean

SORCE CODE ORGANIZATION
------------------------------------------------

- battleShip – the top directory
	- src – should contain the source code of the project
	- headers – should contain header files
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
