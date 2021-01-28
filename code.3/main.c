//
// Created by Hannah Laidlaw
//
/**Main.c
 * Function to run the code
 */
#include <stdio.h>
#include "Header.h"

/**
 * Main Function
 */
int main()
{
    FILE *configFiles = loadTheConfigFile();
    if (configFiles != NULL)
    {
        char *potential = NULL;
        config_data_pointer configDataPointer = scanTheConfigData(configFiles, potential);
        thisFunction(configDataPointer);
    }
    return 0;
}
