#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  
#include <stdbool.h>

int main()
{
    double temperature;
    double celsius;
    double convertedTemperature;
    char originalScale;
    char targetScale;

    while (true) {
        printf("Enter the temperature value: ");
        if (scanf("%lf", &temperature) != 1) {
            printf("Error: Invalid temperature format entered. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        break;
    }

    while (true) {
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &originalScale);
        originalScale = toupper(originalScale);

        if (originalScale == 'C' || originalScale == 'F' || originalScale == 'K') {
            break;
        }
        printf("Error: Invalid scale. Please use C, F, or K.\n");
    }

    while (true) {
        int validTemp = 1;
        
        if (originalScale == 'F') {
            if (temperature < -459.67) {
                printf("Error: Temperature is below absolute zero (-459.67°F).\n");
                validTemp = 0;
            } else {
                celsius = (temperature - 32.0) * 5.0 / 9.0;
            }
        }
        else if (originalScale == 'C') {
            if (temperature < -273.15) {
                printf("Error: Temperature is below absolute zero (-273.15°C).\n");
                validTemp = 0;
            } else {
                celsius = temperature;
            }
        }
        else if (originalScale == 'K') {
            if (temperature < 0.0) {
                printf("Error: Temperature is below absolute zero (0 K).\n");
                validTemp = 0;
            } else {
                celsius = temperature - 273.15;
            }
        }

        if (validTemp) {
            break;
        }

        printf("Please re-enter a valid temperature value: ");
        while (scanf("%lf", &temperature) != 1) {
            printf("Error: Invalid format. Enter a number: ");
            while (getchar() != '\n');
        }
    }

    while (true) {
        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &targetScale);
        targetScale = toupper(targetScale);

        if (targetScale == 'C' || targetScale == 'F' || targetScale == 'K') {
            break;
        }
        printf("Error: Invalid target scale. Please use C, F, or K.\n");
    }

    if (targetScale == 'F') {
        convertedTemperature = (celsius * 9.0 / 5.0) + 32.0;
    }
    else if (targetScale == 'C') {
        convertedTemperature = celsius;
    }
    else if (targetScale == 'K') {
        convertedTemperature = celsius + 273.15;
    }

 
    printf("Converted temperature: %.2f %c\n", convertedTemperature, targetScale);

    printf("Temperature category: ");
    if (celsius < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Bundle up and stay warm!\n");
    }
    else if (celsius < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (celsius < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the pleasant weather!\n");
    }
    else if (celsius < 35) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep cool!\n");
    }

    return 0;
}