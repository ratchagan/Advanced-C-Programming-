#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date {
    int month;
    int day;
};

int main(){
    int dif1=0,dif2=0,i;
    
    int daysMonth[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    char *months[12]={"Jan","Feb","March","April","May","June","July","Aug","Sept","Oct","Nov","Dec"};
    struct date date1,date2;
    
    printf("Input :");
    scanf("%d %d %d %d",&date1.month,&date1.day,&date2.month,&date2.day);
    if((date2.month > date1.month) && (date1.month <= 12 && date2.month <= 12)){
        dif1 = dif1 + date1.day;
        dif2 = dif2 + date2.day;
    
        for(i=0;i<date1.month-1;i++)
            dif1 +=daysMonth[i];
    
        for(i=0;i<date2.month-1;i++)
            dif2 +=daysMonth[i];
    
        printf("%s. %d is %d days after %s. %d.",months[date2.month-1],date2.day,dif2-dif1,months[date1.month-1],date1.day);
    }
    }
