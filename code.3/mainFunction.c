//
// Created by Hannah Laidlaw
//

/**mainFunction.c
 * One function to run majority of functions
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <ctype.h>

/**
 * Function that runs everything once config file and data is sorted
 * @param configDataPointer
 */
void thisFunction(config_data_pointer configDataPointer)
{
    double latitude = 0;
    double longitude = 0;
    double longitudeCheckedDouble;
    double latitudeCheckedDouble;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    int seconds;
    int dayPrev = 0;
    int monthPrev = 0;
    int yearPrev = 0;
    int hoursPrev = 0;
    int minutesPrev = 0;
    int secondsPrev = 0;
    int duplicatedLines = 0;
    int totalLines = 0;
    int inValidLines = 0;
    int validLines = 0;
    int amountOfNodes = 0;
    int testingThis = 0;
    time_t firstTime = 0;
    time_t thisTime;
    int dayOrig = 0;
    int monthOrig = 0;
    int yearOrig = 0;
    int hoursOrig = 0;
    int minutesOrig = 0;
    int secondsOrig = 0;

    date_pointer newDatePointer;
    date_pointer date_Head = NULL;
    movement_pointer movement_Head = NULL;

    movement_pointer new_moving_pointer;

    const char nameToUse[100];
    strcpy(nameToUse, configDataPointer->fileName);
    FILE *theFile = fopen(nameToUse, "r");
    if (theFile == NULL)
        exit(EXIT_FAILURE);
    while (!(feof(theFile)))
    {
        totalLines++;
        char line[100];

        fgets(line, 45, theFile);
        if (isdigit(line[0]) && isdigit(line[1]))
        {
            scanReturn *theData = scanTheFile(line);
            latitudeCheckedDouble = theData->lat;
            longitudeCheckedDouble = theData->lon;
            day = theData->day;
            month = theData->month;
            year = theData->year;
            hours = theData->hours;
            minutes = theData->minutes;
            seconds = theData->seconds;

            validLines++;

            if ((latitudeCheckedDouble == latitude) && (longitudeCheckedDouble == longitude))
            {
                if (testingThis == 0)
                {
                    firstTime = generateTHETime(day, month, year, hours, minutes, seconds);
                    dayOrig = day;
                    monthOrig = month;
                    yearOrig = year;
                    hoursOrig = hours;
                    minutesOrig = minutes;
                    secondsOrig = seconds;
                }

                testingThis++;
                latitude = latitudeCheckedDouble;
                longitude = longitudeCheckedDouble;
                removeDateAtTailOfList(&date_Head);
                newDatePointer = createDateNode(latitude, longitude, day, month, year, hours, minutes, seconds);
                insertDateAtTailOfList(&date_Head, newDatePointer);
                duplicatedLines++;

                dayPrev = day;
                monthPrev = month;
                yearPrev = year;
                hoursPrev = hours;
                minutesPrev = minutes;
                secondsPrev = seconds;
            }
            else
            {
                if (date_Head == NULL)
                {
                    firstTime = generateTHETime(day, month, year, hours, minutes, seconds);
                    dayOrig = day;
                    monthOrig = month;
                    yearOrig = year;
                    hoursOrig = hours;
                    minutesOrig = minutes;
                    secondsOrig = seconds;
                    testingThis = 1;
                }
                else
                {
                    testingThis = 0;
                }

                double distanceTravelled;
                amountOfNodes++;

                if (validLines != 1)
                {
                    thisTime = generateTHETime(dayPrev, monthPrev, yearPrev, hoursPrev, minutesPrev, secondsPrev);
                    if (firstTime != thisTime)
                    {
                        dayPrev = dayOrig;
                        monthPrev = monthOrig;
                        yearPrev = yearOrig;
                        hoursPrev = hoursOrig;
                        minutesPrev = minutesOrig;
                        secondsPrev = secondsOrig;
                    }

                    if (
                            (latitude == 0 && longitude == 0)

                            ||
                            (
                                    configDataPointer->startLatitude < latitude &&
                                    configDataPointer->endLatitude > latitude &&

                                    configDataPointer->startLatitude < latitudeCheckedDouble &&
                                    configDataPointer->endLatitude > latitudeCheckedDouble &&

                                    configDataPointer->startLongitude < longitude &&
                                    configDataPointer->endLongitude > longitude &&

                                    configDataPointer->startLongitude < longitudeCheckedDouble &&
                                    configDataPointer->endLongitude > longitudeCheckedDouble
                            )
                         )
                    {

                        distanceTravelled = generateTHEDistance(latitudeCheckedDouble, longitudeCheckedDouble,
                                                                latitude,
                                                                longitude);

                        new_moving_pointer = createMovementNode(configDataPointer, latitude, latitudeCheckedDouble,
                                                                longitude,
                                                                longitudeCheckedDouble, distanceTravelled, day,
                                                                month,
                                                                year, hours, minutes,
                                                                seconds, dayPrev, monthPrev, yearPrev, hoursPrev,
                                                                minutesPrev, secondsPrev);
                        if (new_moving_pointer != NULL)
                        {
                            insertMovementAtTailOfList(&movement_Head, new_moving_pointer);
                        }
                    }
                    dayPrev = day;
                    monthPrev = month;
                    yearPrev = year;
                    hoursPrev = hours;
                    minutesPrev = minutes;
                    secondsPrev = seconds;
                    latitude = latitudeCheckedDouble;
                    longitude = longitudeCheckedDouble;

                    dayOrig = dayPrev;
                    monthOrig = monthPrev;
                    yearOrig = yearPrev;
                    hoursOrig = hoursPrev;
                    minutesOrig = minutesPrev;
                    secondsOrig = secondsPrev;
                    testingThis = 1;

                    firstTime = generateTHETime(dayOrig, monthOrig, yearOrig, hoursOrig, minutesOrig,
                                                secondsOrig);
                    newDatePointer = createDateNode(latitudeCheckedDouble, longitudeCheckedDouble, day, month,
                                                    year,
                                                    hours, minutes, seconds);
                    if (newDatePointer == NULL)
                    {
                        printf("This is null");
                    }
                    insertDateAtTailOfList(&date_Head, newDatePointer);
                }
            }
        }
    }
    printf("\nTotal Lines: ");
    printf("%d", totalLines);
    printf("\nDuplicated Lines: ");
    printf("%d", duplicatedLines);
    printf("\nValid Lines: ");
    printf("%d", validLines);
    printf("\nInvalid Speeds : ");
    printf("%d", returnInvalidSpeedNumber());

    writingToCSVFile(movement_Head);
}