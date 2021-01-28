//
// Created by Hannah Laidlaw
//
/**Header.h
 * Header file containing all the structs and function definitions
 */

#include <time.h>
#include "stdbool.h"
#include <string.h>

#ifndef CODE_3_HEADER_H
#define CODE_3_HEADER_H

#endif //CODE_3_HEADER_H

//Config File Functions and Struct

FILE * loadTheConfigFile();
void runTextualMenu();


typedef struct configData *config_data_pointer;

struct configData
{
    char fileName[100];
    double movementStart;
    double movementEnd;
    double maximumSpeed;
    int numBars;
    double startLatitude;
    double endLatitude;
    double startLongitude;
    double endLongitude;
}configs;


config_data_pointer scanTheConfigData(FILE *configFile, char* potential);


//Reading the File struct and functions

typedef struct scanReturn
{
    double lat, lon;
    int day, month, year, hours, minutes, seconds;
} scanReturn;

scanReturn* scanTheFile(char line[100]);


//Date Functions and Struct
typedef struct  dateStruct *date_pointer;
struct dateStruct
{
    double latitude;
    double longitude;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    int seconds;
    date_pointer nextDate;
}data;

date_pointer createDateNode(double latitude, double longitude, int day, int month, int year, int hours, int minutes ,int seconds);
void insertDateAtTailOfList(date_pointer * currentHeadPtr, date_pointer newDatePtr);
void displayContentsOfList(date_pointer list_ptr);
void removeDateAtTailOfList(date_pointer * currentHeadPtr);


//Generating Movements Functions and Struct

typedef struct  movementStruct *movement_pointer;
struct movementStruct
{
    double startLatitude;
    double endLatitude;
    double startLongitude;
    double endLongitude;
    time_t startTime;
    time_t endTime;
    double distance;
    double timeTaken;
    double speed;
    movement_pointer nextMovement;
}moving;

double generateTHEDistance(double first,double  second, double third, double fourth);
void insertMovementAtTailOfList(movement_pointer * currentHeadPtr, movement_pointer newMovementPtr);
void displayContentsOfList2(movement_pointer list_ptr);
movement_pointer createMovementNode(config_data_pointer configDataPointer, double startLatitude,double endLatitude, double startLongitude, double endLongitude,
                                    double distance_travelled, int day, int month, int year, int hours, int minutes,
                                    int seconds, int dayPrev, int monthPrev, int yearPrev, int hoursPrev, int minutesPrev, int secondsPrev);
time_t generateTHETime(int day, int month, int year, int hours, int minutes, int seconds);
char* timeToStringToPrint(time_t originalTime);
int returnInvalidSpeedNumber();
void writingToCSVFile(movement_pointer newMovementPtr);
int  formatTheTimeSeconds(time_t theTimeToFormat);
int formatTheTimeMinutes(time_t theTimeToFormat);
int formatTheTimeDay(time_t theTimeToFormat);
int  formatTheTimeHours(time_t theTimeToFormat);
int  formatTheTimeMonth(time_t theTimeToFormat);
int formatTheTimeYear(time_t theTimeToFormat);


//Main Function
void thisFunction(config_data_pointer configDataPointer);