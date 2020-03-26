#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_double.h"

char* get_char(char min, char max) {
    char *op;
    while(1) {
        op = get_string();
        if (strlen(op) > 1 || (*op < min || *op > max)) {
            printf("String should contain digits from %c to %c, try again\n", min, max);
            continue;
        }
        break;
    }
    return op;
}

void change(double list_of_coeff[4], double *milimiters) {
    puts("Enter option");
    double coeff = list_of_coeff[*get_char('1', '4') - '0' - 1];
    puts("Enter value in chosen measure");
    *milimiters = get_udouble() * coeff;
    puts("New length have been saved.");
}

int main() {
    double milimiters = 0;
    while(1) {
        puts("Enter 1 to input length in ISU (kilometers, meters, centimeters, millimeters).  ");
        puts("Enter 2 to input length in Russian traditional units (versts, arshins, fathoms, tops). ");
        puts("Enter 3 to input length in English traditional units (miles, yards, feet, inches). ");
        puts("Enter 4 to see the report in defferent ways (kilometers, meters, centimeters, millimeters). ");
        puts("Enter 5 to see information about version of program and author of the program.");
        puts("Enter 6 to quite the program.");
        double list_of_coeff[4];
        switch(*get_char('1', '6')) {
            case '1' :
                puts("");
                puts("Enter 1 to input value in kilometers");
                puts("Enter 2 to input value in meters");
                puts("Enter 3 to input value in centimeters");
                puts("Enter 4 to input value in millimeters");
                list_of_coeff[0] = 1000 * 100 * 10;
                list_of_coeff[1] = 100 * 10;
                list_of_coeff[2] = 10;
                list_of_coeff[3] = 1;
                change(list_of_coeff, &milimiters);
                break;
            case '2' :
                puts("");
                puts("Enter 1 to input value in versts");
                puts("Enter 2 to input value in arshins");
                puts("Enter 3 to input value in fathoms");
                puts("Enter 4 to input value in tops");
                list_of_coeff[0] = 500 * 3 * 16 * 44.45;
                list_of_coeff[2] = 3 * 16 * 44.45;
                list_of_coeff[1] = 16 * 44.45;
                list_of_coeff[3] = 44.45;   
                change(list_of_coeff, &milimiters);  
                break;
            case '3' :
                puts("");
                puts("Enter 1 to input value in miles");
                puts("Enter 2 to input value in yards");
                puts("Enter 3 to input value in feet");
                puts("Enter 4 to input value in inches");
                list_of_coeff[0] = 1760 * 3 * 12 * 2.54 * 10;
                list_of_coeff[1] = 3 * 12 * 2.54 * 10;
                list_of_coeff[2] = 12 * 2.54 * 10;
                list_of_coeff[3] = 2.54 * 10;   
                change(list_of_coeff, &milimiters); 
                break;
            case '4' :
                puts("");
                puts("Current length");
                printf("in kilometers - %lf\n", milimiters / 10 / 100 / 1000);
                printf("in meters - %lf\n", milimiters / 10 / 100);
                printf("in centimeters - %lf\n", milimiters / 10);
                printf("in millimeters - %lf\n", milimiters);
                break;
            case '5' :
                puts("");
                puts("This program is used to conveniently transform different measures");
                puts("Was made in Visual Studio Code (C89 compiler)");
                puts("version 0.5");
                break;
            case '6' :
                puts("");
                puts("Goodbye!");
                return 0;
                break;
        }
        puts("");
        getchar();
    }
    return 0;
}