#include <stdio.h>

char *months[] = 
{
    "January", 
    "February",  
    "March", 
    "April", 
    "May", 
    "June", 
    "July", 
    "August",  
    "September",  
    "October", 
    "November",  
    "December"
};

int days_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int imputyear(void){

    int year;

    printf("\nEnter a year: ");
    scanf("%d", &year);
    
    return year;
}

void isLeapYear(int year){

    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        days_month[1] = 29;
    } else {
        days_month[1] = 28;
    }
}

int first_weekday(int year){

    int dayOfWeek;

    dayOfWeek = (year*365 + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400)) % 7;

    return dayOfWeek;
}


void calendar(int year){

    int month, day, daysinMonth, startday, weekday = 0;

    startday =  first_weekday(year);

    for(month = 0; month < 12; month++){
        daysinMonth = days_month[month];
        printf("\n\n---------------- %s ----------------\n", months[month]);
        printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat    \n");

        for(weekday = 0; weekday < startday; weekday++){
            printf("%5s", "  ");
        }

        for(day = 1; day <= daysinMonth; day++){
            printf("%5d",day);
            weekday++;
            if(weekday > 6){
                printf("\n");
                weekday = 0;
            }

            startday = weekday;
        }
    }

}

int main() {
    int year;
    
    printf("\n**************** Calendar ****************");

    year = imputyear();
    isLeapYear(year);
    calendar(year);
    printf("\n\n");

    return 0;
}