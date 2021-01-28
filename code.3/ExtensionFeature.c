//
// Created by Hannah Laidlaw
//
/**ExtensionFeature.c
 * Source file containing code for task4.4 for the extended feature
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <ctype.h>


/**
 * Function to load the config file at the beginning.
 * If the user does not enter a valid file, the menu is run.
 * @return file the user would like to run
 */
FILE *loadTheConfigFile()
{
    char configFileName[50];
    printf("Please enter the name of the config file");
    scanf("%s", configFileName);
    FILE *cf = fopen(configFileName, "r");
    if (cf == NULL)
    {
        runTextualMenu();
        return NULL;
    }
    else
    {
        return cf;
    }
}

/**
 * Function to scan the data in the config file
 * @param configFile - the valid config file
 * @param potential - the file name if not given
 * @return  - singly linked list with data from config file in
 */
config_data_pointer scanTheConfigData(FILE *configFile, char *potential)
{
    char *lines;
    char num_bars[15];
    char thefileName[15];
    char blank[15];
    char blank2[15];
    char blank3[15];
    char blank4[15];
    char blank5[15];
    char blank6[15];
    char maximum_speed[15];
    char first_movement_duration[15];
    char second_movement_duration[15];
    char firstLong[15];
    char secondLong[15];
    char firstLat[15];
    char secondLat[15];
    double movementStartSave;
    double movementEndSave;
    double maximumSpeedSave;
    int numBarsSave;
    double startLatitudeSave;
    double endLatitudeSave;
    double startLongitudeSave;
    double endLongitudeSave;
    char line[100];

    config_data_pointer newConfigPointer;
    newConfigPointer = malloc(sizeof(configs));

    if (potential != NULL)
    {
        strcpy((newConfigPointer->fileName), potential);
    }
    else
    {
        fgets(line, 45, configFile);
        if (line[0] == 'd')
        {
            lines = line;
            sscanf(lines, "%14[^c]", blank);
            lines = strstr(lines, " ") + 2;
            sscanf(lines, "%13[^c]", thefileName);
            strcpy((newConfigPointer->fileName), thefileName);
        }
    }

    fgets(line, 45, configFile);
    if (line[0] == 'm' && line[1] == 'o')
    {
        lines = line;
        sscanf(lines, "%18[^c]", blank2);
        lines = strstr(lines, " ") + 2;
        sscanf(lines, "%2[^c]", first_movement_duration);
        movementStartSave = atof(first_movement_duration);
        newConfigPointer->movementStart = movementStartSave;
        lines = strstr(lines, " :") + 3;
        sscanf(lines, "%7[^c >]", second_movement_duration);
        movementEndSave = atof(second_movement_duration);
        newConfigPointer->movementEnd = movementEndSave;
    }

    fgets(line, 45, configFile);
    if (line[0] == 'm' && line[1] == 'a')
    {
        lines = line;
        sscanf(lines, "%14[^c]", blank3);
        lines = strstr(lines, " ") + 1;
        sscanf(lines, "%4[^c]", maximum_speed);
        maximumSpeedSave = (int) atof(maximum_speed);
        newConfigPointer->maximumSpeed = maximumSpeedSave;
    }

    fgets(line, 45, configFile);
    if (line[0] == 'n' &&  line[1] == 'u')
    {
        lines = line;
        sscanf(lines, "%9[^c]", blank4);
        lines = strstr(lines, " ") + 1;
        sscanf(lines, "%2[^c]", num_bars);
        numBarsSave = atoi(num_bars);
        newConfigPointer->numBars = numBarsSave;
    }

    fgets(line, 45, configFile);
    if (line[0] == 'r' &&  line[7] == 'o')
    {
        lines = line;
        sscanf(lines, "%11[^c]", blank5);
        lines = strstr(lines, " ") + 3;
        sscanf(lines, "%6[^c:]", firstLong);
        startLongitudeSave = atof(firstLong);
        newConfigPointer->startLongitude = startLongitudeSave;
        lines = strstr(lines, " :") + 3;
        sscanf(lines, "%6[^c >]", secondLong);
        endLongitudeSave = atof(secondLong);
        newConfigPointer->endLongitude = endLongitudeSave;
    }

    fgets(line, 45, configFile);
    if ( line[0] == 'r' &&  line[7] == 'a')
    {
        lines = line;
        sscanf(lines, "%11[^c]", blank6);
        lines = strstr(lines, " <") + 3;
        sscanf(lines, "%5[^c:]", firstLat);
        startLatitudeSave = atof(firstLat);
        newConfigPointer->startLatitude = startLatitudeSave;
        lines = strstr(lines, " :") + 3;
        sscanf(lines, "%6[^c >]", secondLat);
        endLatitudeSave = atof(secondLat);
        newConfigPointer->endLatitude = endLatitudeSave;
    }
    return newConfigPointer;
}

/**
 * Function to run the menus if the user does not enter a valid config file
 */
void runTextualMenu()
{
    bool prevAnswerWasThree = false;
    char charUpperCase;
    config_data_pointer configDataPointerToChange;
    configDataPointerToChange = malloc(sizeof(configs));

    do
    {
        char chars;
        printf("\nPlease choose an option\n");
        printf(" 1 - Load the configuration File\n");
        printf(" 2 - Load the data and generate the csv output file and graph plots\n");
        printf(" 3 - Change the current configuration information\n");
        printf(" 4 - Update the configuration file\n");
        printf(" Q - Quit the program\n");

        scanf(" %c", &chars);
        int charint = (toupper(chars));
        charUpperCase = (char) charint;
        switch (charUpperCase)
        {
            case '1':
                printf("Load the configuration File\n");
                FILE *configFile = loadTheConfigFile();
                char *potential = NULL;
                config_data_pointer configDataPointer = scanTheConfigData(configFile, potential);
                thisFunction(configDataPointer);
                break;

            case '2':
                printf("Load the data and generate the csv output file and graph plots\n");
                FILE *defaultFile = fopen("default.txt", "r");
                if (defaultFile == NULL)
                {
                    printf("Error, please try again\n");
                    break;
                }

                printf("Please enter the name of the file that has the data in\n");
                char theName[100];
                scanf("%s", theName);
                FILE *theNameFile = fopen(theName, "r");
                if (theNameFile == NULL)
                {
                    printf("Error, please try again\n");
                    break;
                }
                config_data_pointer configDataPointer2 = scanTheConfigData(defaultFile, theName);
                thisFunction(configDataPointer2);
                break;

            case '3':
                prevAnswerWasThree = true;
                printf("Change the current configuration information\n");
                printf("Please enter the name of the file that has the config data in");
                char configToChange[100];

                scanf("%s", configToChange);
                FILE *configToChangeFile = fopen(configToChange, "r");
                if (configToChangeFile == NULL)
                {
                    printf("Error, please try again\n");
                    break;
                }
                else
                {
                    char *potential = NULL;
                    configDataPointerToChange = scanTheConfigData(configToChangeFile, potential);
                    printf("The current config file data is :\n");
                    printf(" data_file_name ' %s '\n", configDataPointerToChange->fileName);
                    printf(" movement_duration < %lf : %lf >\n", configDataPointerToChange->movementStart,
                           configDataPointerToChange->movementEnd);
                    printf(" maximum_speed  %lf \n", configDataPointerToChange->maximumSpeed);
                    printf(" num_bars ' %d '\n", configDataPointerToChange->numBars);
                    printf(" range_lon < %lf : %lf >\n", configDataPointerToChange->startLongitude,
                           configDataPointerToChange->endLongitude);
                    printf(" rang_lat < %lf : %lf >\n", configDataPointerToChange->startLatitude,
                           configDataPointerToChange->endLatitude);

                    char subMenu;
                    char subMenuUpperCase;

                    do
                    {
                        printf("\nPlease choose an option\n");
                        printf(" 1 - Change the data file name\n");
                        printf(" 2 - Change the movement duration start\n");
                        printf(" 3 - Change the movement duration end\n");
                        printf(" 4 - Change the maximum speed \n");
                        printf(" 5 - Change the num of bars \n");
                        printf(" 6 - Change the longitude start\n");
                        printf(" 7 - Change the longitude end\n");
                        printf(" 8 - Change the latitude start\n");
                        printf(" 9 - Change the latitude end\n");
                        printf(" Q - Quit the program\n");

                        scanf(" %c", &subMenu);
                        int subMenuint = (toupper(subMenu));
                        subMenuUpperCase = (char) subMenuint;
                        switch (subMenuUpperCase)
                        {
                            case '1':
                                printf(" 1 - Change the data file name\n");
                                printf("Please enter the name of the file you'd like to change to");
                                char theNewFile[100];
                                scanf("%s", theNewFile);
                                FILE *theNewFileFile = fopen(theNewFile, "r");
                                if (theNewFileFile == NULL)
                                {
                                    printf("Error, please try again\n");
                                    break;
                                }
                                else
                                {
                                    strcpy((configDataPointerToChange->fileName), theNewFile);
                                    printf("The data file name has now been changed, it now is ' %s '",
                                           configDataPointerToChange->fileName);
                                }
                                break;

                            case '2':
                                printf(" 2 - Change the movement duration start\n");
                                printf("Please enter the new movement duration start");
                                double newMovementDurationStart;
                                char theMovementStart[100];
                                scanf("%s", theMovementStart);
                                newMovementDurationStart = atof(theMovementStart);
                                configDataPointerToChange->movementStart = newMovementDurationStart;
                                printf("The movement duration start has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->movementStart);
                                break;

                            case '3':
                                printf(" 3 - Change the movement duration end\n");
                                printf("Please enter the new movement duration end");
                                double newMovementDurationEnd;
                                char theMovementEnd[100];
                                scanf("%s", theMovementEnd);
                                newMovementDurationEnd = atof(theMovementEnd);
                                configDataPointerToChange->movementEnd = newMovementDurationEnd;
                                printf("The movement duration end has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->movementEnd);
                                break;

                            case '4':
                                printf(" 4 - Change the maximum speed \n");
                                printf("Please enter the new maximum speed");
                                double newMaximumSpeed;
                                char theMaximumSpeed[100];
                                scanf("%s", theMaximumSpeed);
                                newMaximumSpeed = atof(theMaximumSpeed);
                                configDataPointerToChange->maximumSpeed = newMaximumSpeed;
                                printf("The maximum speed has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->maximumSpeed);
                                break;

                            case '5':
                                printf(" 5 - Change the num of bars \n");
                                printf("Please enter the new number of bars");
                                int newNumBars;
                                char theNumBars[100];
                                scanf("%s", theNumBars);
                                newNumBars = atoi(theNumBars);
                                configDataPointerToChange->numBars = newNumBars;
                                printf("The number of bars has now been changed, it now is ' %d '",
                                       configDataPointerToChange->numBars);
                                break;

                            case '6':
                                printf(" 6 - Change the longitude start\n");
                                printf("Please enter the new start longitude");
                                double newLongStart;
                                char theLongStart[100];
                                scanf("%s", theLongStart);
                                newLongStart = atof(theLongStart);
                                configDataPointerToChange->startLongitude = newLongStart;
                                printf("The start longitude has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->startLongitude);
                                break;

                            case '7':
                                printf(" 7 - Change the longitude end\n");
                                printf("Please enter the new end longitude");
                                double newLongEnd;

                                char theLongEnd[100];
                                scanf("%s", theLongEnd);
                                newLongEnd = atof(theLongEnd);
                                configDataPointerToChange->endLongitude = newLongEnd;
                                printf("The end longitude has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->endLongitude);
                                break;

                            case '8':
                                printf(" 8 - Change the latitude start\n");
                                printf("Please enter the new start latitude");
                                double newLatStart;
                                char theLatStart[100];
                                scanf("%s", theLatStart);
                                newLatStart = atof(theLatStart);
                                configDataPointerToChange->startLatitude = newLatStart;
                                printf("The start latitude has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->startLatitude);
                                break;

                            case '9':
                                printf(" 9 - Change the latitude end\n");
                                printf("Please enter the new end latitude");
                                double newLatEnd;
                                char theLatEnd[100];
                                scanf("%s", theLatEnd);
                                newLatEnd = atof(theLatEnd);
                                configDataPointerToChange->endLatitude = newLatEnd;
                                printf("The end latitude has now been changed, it now is ' %lf '",
                                       configDataPointerToChange->endLatitude);
                                break;

                            case 'Q':
                                printf("Quitting the Program\n");
                                printf("The current config file data is :\n");
                                printf(" data_file_name ' %s '\n", configDataPointerToChange->fileName);
                                printf(" movement_duration < %lf : %lf >\n", configDataPointerToChange->movementStart,
                                       configDataPointerToChange->movementEnd);
                                printf(" maximum_speed  %lf \n", configDataPointerToChange->maximumSpeed);
                                printf(" num_bars ' %d '\n", configDataPointerToChange->numBars);
                                printf(" range_lon < %lf : %lf >\n", configDataPointerToChange->startLongitude,
                                       configDataPointerToChange->endLongitude);
                                printf(" rang_lat < %lf : %lf >\n", configDataPointerToChange->startLatitude,
                                       configDataPointerToChange->endLatitude);
                                break;

                            default:
                                printf("Try Again");
                                break;
                        }
                    } while ((subMenuUpperCase != ('Q')));
                }
                break;

            case '4':

                printf("Update the configuration file\n");
                char answer;
                char answerUpperCase;

                if (prevAnswerWasThree == false)
                {
                    printf("Need to change the data before running this \n");
                    break;
                }
                prevAnswerWasThree = false;
                do
                {
                    printf("\nThe current file to save the configurations to is Example.txt , would you like to change that?\n");

                    printf(" Y - Yes \n");
                    printf(" N - No \n");
                    printf(" E - exit this menu\n");
                    scanf(" %c", &answer);
                    int answerint = (toupper(answer));
                    answerUpperCase = (char) answerint;
                    char *buffer;

                    switch (answerUpperCase)
                    {
                        case 'Y':
                            printf("Please enter the name of the file you'd like to change to");

                            char theNewFile[100];
                            scanf(" %s", theNewFile);

                            FILE *theNewFileName = fopen(theNewFile, "w");
                            if (theNewFileName == NULL)
                            {
                                printf("error\n");
                                break;
                            }
                            fprintf(theNewFileName, "data_file_name \"%s\" \n", configDataPointerToChange->fileName);
                            fprintf(theNewFileName, "movement_duration < %lf : %lf >\n",
                                    configDataPointerToChange->movementStart,
                                    configDataPointerToChange->movementEnd);
                            fprintf(theNewFileName, "maximum_speed %lf\n", configDataPointerToChange->maximumSpeed);
                            fprintf(theNewFileName, "num_bars %d\n", configDataPointerToChange->numBars);
                            fprintf(theNewFileName, "range_lon < %lf : %lf >\n",
                                    configDataPointerToChange->startLongitude,
                                    configDataPointerToChange->endLongitude);
                            fprintf(theNewFileName, "range_lat < %lf : %lf >\n",
                                    configDataPointerToChange->startLatitude,
                                    configDataPointerToChange->endLatitude);
                            fclose(theNewFileName);
                            break;

                        case 'N':
                            buffer = (char *) malloc(10000 * sizeof(configs));
                            memset(buffer, 0, 1000 * sizeof(configs));

                            FILE *theFile = fopen("example.txt", "r");
                            if (theFile == NULL)
                            {
                                printf("error\n");
                                break;
                            }

                            while (!(feof(theFile)))
                            {
                                char line[100];
                                fgets(line, 45, theFile);
                            }

                            theFile = fopen("example.txt", "w");
                            fprintf(theFile, "%s", buffer);
                            fprintf(theFile, "data_file_name \"%s\" \n", configDataPointerToChange->fileName);
                            fprintf(theFile, "movement_duration < %lf : %lf >\n",
                                    configDataPointerToChange->movementStart,
                                    configDataPointerToChange->movementEnd);
                            fprintf(theFile, "maximum_speed %lf\n", configDataPointerToChange->maximumSpeed);
                            fprintf(theFile, "num_bars %d\n", configDataPointerToChange->numBars);
                            fprintf(theFile, "range_lon < %lf : %lf >\n", configDataPointerToChange->startLongitude,
                                    configDataPointerToChange->endLongitude);
                            fprintf(theFile, "range_lat < %lf : %lf >\n", configDataPointerToChange->startLatitude,
                                    configDataPointerToChange->endLatitude);
                            fclose(theFile);
                            break;

                        case 'E':
                            printf("Quitting this menu");
                            break;

                        default:
                            printf("Try Again");
                            break;
                    }
                } while ((answerUpperCase != ('E')));
                break;

            case 'Q':
                printf("Quitting the Program\n");
                exit(0);

            default:
                printf("Try Again");
                if (chars >1)
                {
                    chars = 0;
                }
                break;
        }
    } while ((charUpperCase != ('Q')));
}