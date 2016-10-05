#include <stdio.h>

int main(void)
{
    int days, start_day, i, j;
    days=31;
    start_day=6;
    printf("\n");
    char daysname[]={ 'S','M','Tu','W','Th','F','S'};
    
    char month[]="January 2016";
    printf("        %s  ",month);
    printf("\n");
    printf("   S   M  Tu   W  Th   F   S");
    printf("\n");
    
    /* prints the blank days of the first week */
    for (i = 1; i < start_day; i++) {
        printf("    ");
    }
    
    /* prints the calendar numbers */
    for (j = 1; j <= days; i++, j++) {
        printf("%4d", j);
        if (i % 7 == 0)
            printf("\n");
    }
    
    printf("\n\n");
    
    return 0;
}
