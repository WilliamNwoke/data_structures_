//
// Created by Uchenna Nwoke on 3/30/22.
//
#include <cstdio>
#include "Date.h"


/**
 * Default Constructor
 */
Date::Date (){
    this->month = 0;
    this->day = 0;
    this->year = 0;
}

/**
 * Constructor that takes in a month, day and year as param
 * sets the values using the setDate function
 * @param month month of the year
 * @param day day of the year
 * @param year year
 */
Date::Date(int month, int day, int year){
    Date::setDate(month, day, year);
}

/**
 * Takes in the month, day , year as params
 * sets the class private attributes of those values
 * @param month month for the date
 * @param day day for the date
 * @param year year for the date
 */
void Date::setDate(int m, int d, int y) {
    this->day = d;
    this->month = m;
    this->year = y;
}
/**
 * returns the date passed to the date class
 * @return character array of chars in format mm/dd/yyyy
 */
string Date::getDate() const {
     char strB[25];
     sprintf(strB,"%02d/%02d/%04d", month, day, year);
     return strB;
}

/**
 * Gets the season from the date params
 * @return a season message of string type
 */
string Date::getSeason() const {
    // Checks if its Spring
    if (this->month >= 3 && this->day >= 21)
        return "Spring";
    if (this->month <7 && this->day < 21)
        return "Spring";


    // Checks if it's Summer
    if (this->month >= 6 && this->day >= 21)
        return "Summer";
    if (this->month <10 && this->day < 23)
        return "Summer";

    // Checks if it's Fall
    if (this->month >= 9 && this->day >= 23)
        return "Fall";
    if (this->month <=12 && this->month <22)
        return "Fall";

    // Checks if it's Winter using december or january till March
    if (this->month == 12 && this->day >= 22)
        return "Winter";
    if (this-> month >= 1 && this-> month <=3 )
        return "Winter";

    return "";
}

