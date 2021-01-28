//
// Created by Hannah Laidlaw
//
/**generateMovements.c
 * Functions for generating the movements
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <__wctype.h>

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
int invalidSpeed = 0;

/**
* The great circle distance or the orthodromic distance is the shortest distance
* between two points on a sphere
* @param first - a structure containing (at least) the fields Double lng and Double lat
* @param second - a structure containing (at least) the fields Double lng and Double lat
* @return distance in m
*/

double generateTHEDistance(double first, double second, double third, double fourth)
{
    double lon1 = degToRad(second);
    double lon2 = degToRad(fourth);
    double lat1 = degToRad(first);
    double lat2 = degToRad(third);
// Haversine formula (alt. vincenties formula)
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2), 2)
               + cos(lat1) * cos(lat2)
                 * pow(sin(dlon / 2), 2);
    double c = 2 * asin(sqrt(a));
// Radius of earth in kilometers. Use 3956
// for miles
    double r = 6371;
// calculate the result (in m)
    return ((c * r) * 1000);
}

/**
 * Function to make the time into time_t format
 * @param day
 * @param month
 * @param year
 * @param hours
 * @param minutes
 * @param seconds
 * @return - time_t format of the date
 */
time_t generateTHETime(int day, int month, int year, int hours, int minutes, int seconds)
{
    int ret;
    struct tm info;
    char buffer[80] = {0};
    info.tm_year = year - 1900;
    info.tm_mon = month - 1;
    info.tm_mday = day;
    info.tm_hour = hours;
    info.tm_min = minutes;
    info.tm_sec = seconds;

    ret = (int) mktime(&info);

    if (ret == -1 && hours != 0)
    {
        printf("Error: unable to make time using mktime\n");
    }
    else
    {
        strftime(buffer, sizeof(buffer), "%c", &info);
        time_t theTime;
        theTime = ret;
        strftime(buffer, sizeof(buffer), "%c", &info);
        return theTime;
    }
}

/**
 * Function to create a node for the movementStruct
 * @param configDataPointer - configuration list with config file data in
 * @param startLatitude
 * @param endLatitude
 * @param startLongitude
 * @param endLongitude
 * @param distance_travelled
 * @param day - end day
 * @param month -end month
 * @param year -end year
 * @param hours  -end hours
 * @param minutes  -end minutes
 * @param seconds  -end seconds
 * @param dayPrev  - start day
 * @param monthPrev - start month
 * @param yearPrev - start year
 * @param hoursPrev - start hours
 * @param minutesPrev - start minutes
 * @param secondsPrev  - start seconds
 * @return node for movement list
 */
movement_pointer createMovementNode(config_data_pointer configDataPointer, double startLatitude, double endLatitude,
                                    double startLongitude, double endLongitude,
                                    double distance_travelled, int day, int month, int year, int hours, int minutes,
                                    int seconds, int dayPrev, int monthPrev, int yearPrev, int hoursPrev,
                                    int minutesPrev, int secondsPrev)
{
    movement_pointer new_moving_pointer;
    new_moving_pointer = malloc(sizeof(moving));
    if (new_moving_pointer == NULL || dayPrev == NULL)
    {
        return NULL;
    }
    else
    {
        time_t firstTime = generateTHETime(dayPrev, monthPrev, yearPrev, hoursPrev, minutesPrev, secondsPrev);
        time_t secondTime = generateTHETime(day, month, year, hours, minutes, seconds);
        double time_taken = difftime(secondTime, firstTime);
        double old_time = 0;
        if (time_taken < 0)
        {
            old_time = time_taken;
            time_taken = fabs(time_taken);
        }

        double speed = distance_travelled / time_taken;
        if (time_taken == 0)
        {
            invalidSpeed++;
            return NULL;
        }

        if (speed > 50 || speed > configDataPointer->maximumSpeed || configDataPointer->movementStart > time_taken ||
            configDataPointer->movementEnd < time_taken)
        {
            invalidSpeed++;
            return NULL;
        }
        else
        {
            new_moving_pointer->startLatitude = startLatitude;
            new_moving_pointer->endLatitude = endLatitude;
            new_moving_pointer->startLongitude = startLongitude;
            new_moving_pointer->endLongitude = endLongitude;
            new_moving_pointer->startTime = firstTime;
            new_moving_pointer->endTime = secondTime;
            new_moving_pointer->distance = distance_travelled;
            new_moving_pointer->timeTaken = time_taken;
            new_moving_pointer->speed = speed;
            new_moving_pointer->nextMovement = NULL;
            return new_moving_pointer;
        }
    }
}


/**
 * function to insert the movement node created into the tail of the movement list
 * @param currentHeadPtr - current list
 * @param newMovementPtr - node to be entered
 */
void insertMovementAtTailOfList(movement_pointer *currentHeadPtr, movement_pointer newMovementPtr)
{
    //get a temporary pointer to walk down the list
    movement_pointer *temp_ptr;
    temp_ptr = currentHeadPtr;

    //walk until pointing at a link containing NULL
    while (*temp_ptr != NULL)
    {
        temp_ptr = &((*temp_ptr)->nextMovement);
    }

    //make a new node point where the old link pointed and then  make the old last link point to us
    newMovementPtr->nextMovement = *temp_ptr;
    *temp_ptr = newMovementPtr;
}

/**
 * Function to convert time to a string so it can be printed
 * @param originalTime - time in a string
 * @return
 */
char *timeToStringToPrint(time_t originalTime)
{
    return ctime(&originalTime);
}

/**
 * Function to return number of lines with an invalid speed number
 * @return number of lines with an invalid speed number
 */
int returnInvalidSpeedNumber()
{
    return invalidSpeed;
}

/**
 * Function to convert year to a string so it can be printed
 * @param theTimeToFormat - year in time_t format
 * @return year as a string
 */
int formatTheTimeYear(time_t theTimeToFormat)
{
    char result[100];

    /* Output the current year into the result string */
    strftime(result, sizeof(result), "%Y", localtime(&theTimeToFormat));

    int year;
    sscanf(result, "%d", &year);
    return year;
}

/**
 * Function to convert month to a string so it can be printed
 * @param theTimeToFormat - month in time_t format
 * @return month as a string
 */
int formatTheTimeMonth(time_t theTimeToFormat)
{
    char result[100];
    strftime(result, sizeof(result), "%m", localtime(&theTimeToFormat));

    int month;
    sscanf(result, "%d", &month);
    return month;

}

/**
 * Function to convert day to a string so it can be printed
 * @param theTimeToFormat - day in time_t format
 * @return day as a string
 */
int formatTheTimeDay(time_t theTimeToFormat)
{
    char result[100];
    strftime(result, sizeof(result), "%d", localtime(&theTimeToFormat));
    int day;
    sscanf(result, "%d", &day);
    return day;
}

/**
 * Function to convert hours to a string so it can be printed
 * @param theTimeToFormat - hour in time_t format
 * @return hour as a string
 */
int formatTheTimeHours(time_t theTimeToFormat)
{
    char result[100];
    strftime(result, sizeof(result), "%H", localtime(&theTimeToFormat));
    int hours;
    sscanf(result, "%d", &hours);
    return hours;
}

/**
 * Function to convert minutes to a string so it can be printed
 * @param theTimeToFormat - minutes in time_t format
 * @return minutes as a string
 */
int formatTheTimeMinutes(time_t theTimeToFormat)
{
    char result[100];
    strftime(result, sizeof(result), "%M", localtime(&theTimeToFormat));
    int min;
    sscanf(result, "%d", &min);
    return min;
}

/**
 * Function to convert seconds to a string so it can be printed
 * @param theTimeToFormat - seconds in time_t format
 * @return seconds as a string
 */
int formatTheTimeSeconds(time_t theTimeToFormat)
{
    char result[100];
    strftime(result, sizeof(result), "%S", localtime(&theTimeToFormat));
    int sec;
    sscanf(result, "%d", &sec);
    return sec;
}

/**
 * Function to write the data to a csv file
 * @param newMovementPtr  - movement list to be written file
 */
void writingToCSVFile(movement_pointer newMovementPtr)
{
    char textFileName[100];
    printf("\nPlease enter the name of the file you would like to write to ");
    scanf("%s", textFileName);
    FILE *f = fopen(textFileName, "w");

    if (f == NULL)
        exit(EXIT_FAILURE);

    int i = 0;
    double stationarySpeed = 0;
    double movingSpeed = 0;
    double foragingSpeed = 0;
    double impossibleSpeed = 0;
    double totalSpeed = 0;
    double totalSpeedTest = 0;

    while (newMovementPtr != NULL)
    {
        fprintf(f, "Movement: %d , ", i);

        fprintf(f, "%d / %d / %d , ",
                formatTheTimeDay(newMovementPtr->startTime),
                formatTheTimeMonth(newMovementPtr->startTime),
                formatTheTimeYear(newMovementPtr->startTime));

        fprintf(f, "%d : %d :%d , ",
                formatTheTimeHours(newMovementPtr->startTime),
                formatTheTimeMinutes(newMovementPtr->startTime),
                formatTheTimeSeconds(newMovementPtr->startTime));

        fprintf(f, " %lf , ", newMovementPtr->startLatitude);
        fprintf(f, "%lf  , ", newMovementPtr->startLongitude);
        fprintf(f, "%lf , ", newMovementPtr->endLatitude);
        fprintf(f, "%lf  ,", newMovementPtr->endLongitude);
        fprintf(f, "distance : %lfm  , ", newMovementPtr->distance);
        fprintf(f, "time taken : %lfs, ", newMovementPtr->timeTaken);
        fprintf(f, "speed : ");
        fprintf(f, "%lfm/s ,  ", newMovementPtr->speed);

        totalSpeedTest = ((newMovementPtr->timeTaken) + totalSpeedTest);


        if (newMovementPtr->speed < 0.02)
        {
            fprintf(f, "STATIONARY\n");
            stationarySpeed += newMovementPtr->timeTaken;
            totalSpeed = totalSpeed + newMovementPtr->timeTaken;
        }
        else if (newMovementPtr->speed < 0.33)
        {
            fprintf(f, "FORAGING\n");
            foragingSpeed = (foragingSpeed + (newMovementPtr->timeTaken));
            totalSpeed = totalSpeed + newMovementPtr->timeTaken;
        }
        else if (newMovementPtr->speed < 12.00)
        {
            fprintf(f, "MOVING\n");
            movingSpeed += newMovementPtr->timeTaken;
            totalSpeed = totalSpeed + (newMovementPtr->timeTaken);
        }
        else if (newMovementPtr->speed >= 12.00)
        {
            fprintf(f, "IMPOSSIBLE\n");
            impossibleSpeed += newMovementPtr->timeTaken;
            totalSpeed = totalSpeed + (newMovementPtr->timeTaken);
        }
        newMovementPtr = newMovementPtr->nextMovement;
        i++;
    }
    printf("Stationary Speed : %lf s \n", stationarySpeed);
    printf("Foraging Speed : %lf s \n", foragingSpeed);
    printf("Moving Speed : %lf s \n", movingSpeed);
    printf("Implausible Speed : %lfs \n", impossibleSpeed);
    printf("Total : %lf s \n", totalSpeed);
    printf("Total Amount in days: %lf  days \n", totalSpeed / 86400);
}