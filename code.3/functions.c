//
// Created by Hannah Laidlaw
//

/**functions.c
 * Functions for using the data from the collar text files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


/**
 * Function to scan the collar data file
 * @param line - line taken in from file
 * @return - singly linked list with data from line saved in
 */
scanReturn *scanTheFile(char line[100])
{
    char *lines;
    struct scanReturn theData;
    char latitudeCheckedChar[10];
    char longitudeCheckedChar[10];
    double longitudeCheckedDouble;
    double latitudeCheckedDouble;
    char dayTest[3];
    char monthTest[3];
    char yearTest[5];
    char hoursTest[3];
    char minutesTest[3];
    char secondsTest[3];
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    int seconds;

    lines = line;
    sscanf(lines, "%9[^c]", latitudeCheckedChar);
    latitudeCheckedDouble = atof(latitudeCheckedChar);
    lines = strstr(lines, ",") + 2;
    theData.lat = latitudeCheckedDouble;

    sscanf(lines, "%9[^c]", longitudeCheckedChar);
    longitudeCheckedDouble = atof(longitudeCheckedChar);
    lines = strstr(lines, ",") + 2;
    theData.lon = longitudeCheckedDouble;

    sscanf(lines, "%2[^c]", dayTest);
    day = atoi(dayTest);
    lines = strstr(lines, "/") + 1;
    theData.day = day;
    sscanf(lines, "%2[^c]", monthTest);
    if ('/' == monthTest[1])
    {
        monthTest[1] = NULL;
    }
    month = atoi(monthTest);
    lines = strstr(lines, "/") + 1;
    theData.month = month;

    sscanf(lines, "%4[^c]", yearTest);
    year = atoi(yearTest);
    lines = strstr(lines, ",") + 2;
    theData.year = year;

    sscanf(lines, "%2[^c]", hoursTest);
    if (':' == hoursTest[1])
    {
        hoursTest[1] = NULL;
    }
    hours = atoi(hoursTest);
    lines = strstr(lines, ":") + 1;
    theData.hours = hours;

    sscanf(lines, "%2[^c]", minutesTest);
    if (':' == minutesTest[1])
    {
        minutesTest[1] = NULL;
    }
    minutes = atoi(minutesTest);
    lines = strstr(lines, ":") + 1;
    theData.minutes = minutes;

    sscanf(lines, "%2[^c]", secondsTest);
    if (':' == secondsTest[1])
    {
        secondsTest[1] = NULL;
    }
    seconds = atoi(secondsTest);
    theData.seconds = seconds;
    return &theData;
}

/**
 * Function to create a node for the dateStruct
 * @param latitude
 * @param longitude
 * @param day
 * @param month
 * @param year
 * @param hours
 * @param minutes
 * @param seconds
 * @return - node for date struct
 */
date_pointer createDateNode(double latitude, double longitude, int day, int month, int year, int hours, int minutes, int seconds)
{
    date_pointer new_date_pointer;
    new_date_pointer = malloc(sizeof(data));
    if (new_date_pointer == NULL)
    {
        return NULL;
    }
    else
    {
        new_date_pointer->latitude = latitude;
        new_date_pointer->longitude = longitude;
        new_date_pointer->day = day;
        new_date_pointer->month = month;
        new_date_pointer->year = year;
        new_date_pointer->hours = hours;
        new_date_pointer->minutes = minutes;
        new_date_pointer->seconds = seconds;
        new_date_pointer->nextDate = NULL;
        return new_date_pointer;
    }
}

/**
 * function to insert the date node created into the tail of the list
 * @param currentHeadPtr - current list
 * @param newDatePtr - node to be entered
 */
void insertDateAtTailOfList(date_pointer *currentHeadPtr, date_pointer newDatePtr)
{
    //get a temporary pointer to walk down the list
    date_pointer *temp_ptr;
    temp_ptr = currentHeadPtr;

    //walk until pointing at a link containing NULL
    while (*temp_ptr != NULL)
    {
        temp_ptr = &((*temp_ptr)->nextDate);
    }
    //make a new node point where the old link pointed and then  make the old last link point to us
    newDatePtr->nextDate = *temp_ptr;
    *temp_ptr = newDatePtr;
}

/**
 * function to remove the date node at the tail of the list
 * @param currentHeadPtr - current list
 */
void removeDateAtTailOfList(date_pointer *currentHeadPtr)
{
    //get a temporary pointer to walk down the list
    date_pointer *temp_ptr;
    temp_ptr = currentHeadPtr;
    date_pointer *temp_ptr2;
    temp_ptr2 = temp_ptr;
    int i = 0;

    //walk until pointing at a link containing NULL
    while (*temp_ptr != NULL)
    {
        temp_ptr = &((*temp_ptr)->nextDate);
        if (i != 0)
        {
            temp_ptr2 = &((*temp_ptr2)->nextDate);
        }
        i++;
    }
    *temp_ptr2 = NULL;
}

/**
 * function to print the current nodes in the date list
 * @param list_ptr - current date list
 */
void displayContentsOfList(date_pointer list_ptr)
{
    printf("The nodes in the list are as follows. \n");
    while (list_ptr != NULL)
    {
        printf("\n");
        printf("Latitude :  %lf\n", list_ptr->latitude);
        printf("Longitude :%lf\n", list_ptr->longitude);
        printf("day : %d\n", list_ptr->day);
        printf("month : %d\n", list_ptr->month);
        printf("year : %d\n", list_ptr->year);
        printf("hours : %d\n", list_ptr->hours);
        printf("minutes : %d\n", list_ptr->minutes);
        printf("seconds : %d\n", list_ptr->seconds);
        list_ptr = list_ptr->nextDate;
    }
}

/**
 * function to print the nodes in the movement list
 * @param list_ptr - current movement list
 */
void displayContentsOfList2(movement_pointer list_ptr)
{
    printf("The nodes in the list are as follows. \n");
    while (list_ptr != NULL)
    {
        printf("\n");
        printf("Start Latitude :  %lf\n", list_ptr->startLatitude);
        printf("End Latitude :  %lf\n", list_ptr->endLatitude);
        printf("Start Longitude :%lf\n", list_ptr->startLongitude);
        printf("End Longitude :%lf\n", list_ptr->endLongitude);
        printf("Start Time : %s", timeToStringToPrint(list_ptr->startTime));
        printf("End Time : %s", timeToStringToPrint(list_ptr->endTime));
        printf("distance : %f\n", list_ptr->distance);
        printf("time taken : %f\n", list_ptr->timeTaken);
        printf("speed : %f", list_ptr->speed);
        printf("m/s\n");
        list_ptr = list_ptr->nextMovement;
    }
}