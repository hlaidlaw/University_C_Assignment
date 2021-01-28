# University_C_Assignment
Assignment that was submitted for a second year university module named "C and C ++". The project was coded in C and achieved a first.

The brief was to collect GPS data from sheep collars, remove repeated data/data that was unreasonable. The data was then written to a csv file.
This process was designed using a config file where the user could enter the parameters they wanted to control the processing of the data such as where to store that data, maximum speed to conside and duration of movement etc. .

CS23820 Assessed Assignment 2020-2021: 
“Analysing Sheep Behaviour from Tracker Tag Data”

-------------------What the project contains----------------------------------------------

This project is split into 6 files, 1 header file and the rest as source files.
Their should be:

	ExtensionFeature.c - source file containing code for task4.4 for the extended feature 

	functions.c - source file containing functions for using the data from the collar text files

	generateMovements.c - source file containing functions for generating the movements

	Header.h - header file containing all the structs and function definitions

	main.c - source file containing the function to run the code.

	mainFunction.c - source file containing the function that runs everything once config file and data is sorted


Also included are 3 .txt files :


	config.txt - the configuration file

	default.txt - the default values for the configuration file

	Example.txt - the default file to save the changes to the config file too.
	
	Collar_12.txt - text file containing the raw data movements from Collar 12 to be processed.


All the .txt files should be placed in the cmake-build-debug folder. The rest should just be in the main code folder.
 

-------------------What you need to run the project---------------------------------------

Extra .txt files can be created if wished, however nothing more is needed than the ones provided.

-------------------Expected Output--------------------------------------------------------

The user is prompted to enter the name of a config file.

If a config file is given:

	- a summary should be printed to the terminal with the total number of:
		+ total lines
		+ Duplicated Lines
		+ Valid lines
		+ Invalid Speeds

	-the user should then be prompted to enter the file to write to

	-a total time summary of the time spent in each section will then be printed:
		+Stationary Speed
		+Foraging Speed
		+Moving Speed
		+Implausible Speed
		+Total (in seconds)
		+Total (in days)

	-If the file did not exist, a file has now been created and has been written to,if it did then it will be written to

	-The program is exited

If a config file is not given:

	- a menu will be printed:

		Please choose an option
 		1 - Load the configuration File
 		2 - Load the data and generate the csv output file and graph plots
 		3 - Change the current configuration information
 		4 - Update the configuration file
 		Q - Quit the program
	
	- If 1 is entered, the user will be prompted for a config file and the same process as above is completed

	- If 2 is entered:

		+ The user is prompted to enter the name of the file that has the data in
		+ The total time summary, like before, is printed
		+ The user is prompted to enter the name of a file to write to, like before
		+ A total time summary should be printed to the terminal ,like before.

		THIS WILL BE ALL 0'S AND THE FILE TO WRITE TO WILL BE EMPTY AS IT WILL BE USING DEFAULT.TXT AS THE CONFIG FILE. 
				PLEASE CHANGE DEFAULT.TXT IF WANTING TO CHANGE THE DEFAULT CONFIG DATA

	-If 3 is entered:

		+ The user will be prompted for a config file
		+ The current data in the config file given will be printed along with a menu:
			Please choose an option
 			1 - Change the data file name
			2 - Change the movement duration start
 			3 - Change the movement duration end
 			4 - Change the maximum speed 
 			5 - Change the num of bars 
 			6 - Change the longitude start
 			7 - Change the longitude end
 			8 - Change the latitude start
 			9 - Change the latitude end
 			Q - Quit the program
		
		+Whichever option is chose between 1 and 9, the user will be prompted to enter the new data, which will then be printed.
					(THIS IS NOT CHANGING THE CONFIG FILE YET)

		+If Q is entered, the config data is printed showing any changes made and the menu is exited
	
	-If 4 is entered:

		+If 3 has not been previously entered an error message will be printed:"Need to change the data before running this", meaning option 3 will need to be run. 
		 The menu is printed again.

		+ If 3 has been previously enter a message will be printed:
			The current file to save the configurations too is Example.txt ,would you like to change that?
			 Y - Yes 
			 N - No 
 			 E - exit this menu

		(THE DEFAULT FILE FOR THE NEW CONFIG DATA IS EXAMPLE.TXT)

			* If y is entered, the user will be prompted to enter the name of the file to use instead and then will be saved to said file
			* If n is entered, the config data will be saved to example.txt
			* If e is entered, the menu is exited and the menu printed again

	-If Q is entered, the program will be exited.

IF A USER ENTERS AN INVALID CHARACTER FOR ANY OF THE MENUS THEY WILL BE PROMPTED TO TRY AGAIN
IF A USER ENTERS A FILE NAME THAT DOESNT EXIST WHEN ASKED FOR A FILE TO WRITE TO, A FILE WITH THAT NAME WILL BE CREATED AND THE DATA WRITTEN TO IT


-------------------Config File Description------------------------------------------------

The two config files provided are config.txt and default.txt. As mentioned above, the current values in default.txt will 
cause no valid movements. The current config.txt will cause valid movements.

An example of a valid config file format is shown below. This is config.txt

data_file_name "Collar_12.TXT"
movement_duration <0 : 45.0>
maximum_speed 30.0
num_bars 60
range_lon < -3.611 : -3.61 >
range_lat < 52.0 : 52.254 >



-------------------Where to find the comments in the code---------------------------------

The majority of the comments in this code are found before the function definition in the source files.
There are also in code comments in the header.h file dividing the function descriptions into sections. 
There is also a comment at the top of each class describing the class.


-------------------Standard Libraries-----------------------------------------------------

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <math.h>

#include <time.h>

#include "stdbool.h"

#include "Header.h"

