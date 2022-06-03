// Implementation file for the FeetInches class
#include <cstdlib>  // Needed for abs()
#include <sstream>
#include "FeetInches.h"

//*********************
// PUBLIC FUNCTIONS   *
//*********************

FeetInches::FeetInches(int f, int i) {
    feet = f;
    inches = i;
    simplify();
}

void FeetInches::setFeet(int f) {
    feet = f;
}

void FeetInches::setInches(int i) {
    inches = i;
    simplify();
}

int FeetInches::getFeet() const {
    return feet;
}

int FeetInches::getInches() const {
    return inches;
}

string FeetInches::to_string() const {
    stringstream ss;
    ss << feet << "' " << inches << "\"\n";
    return ss.str();
}

FeetInches FeetInches::operator + (const FeetInches &right) {
    // TODO: Overloaded binary + operator
    // Add the right object from the current object.
    // Returns the sum. Note that neither object is changed.
    int sum_feet = this->feet + right.feet;
    int sum_inches = this->inches + right.inches;
    return {sum_feet, sum_inches};
}

FeetInches FeetInches::operator - (const FeetInches &right) {
    // TODO: Overloaded binary - operator
    // Subtracts the right object from the current object.
    // Returns the difference. Note that neither object is changed.
    int sum_feet;
    int sum_inches;
    if (this->inches < right.inches){
        sum_feet = (this->feet - 1) - right.feet;
        sum_inches = (this->inches + 12) - right.inches;
    } else {
        sum_feet = this->feet - right.feet;
        sum_inches = this->inches - right.inches;
    }

    return {sum_feet, sum_inches};
}

FeetInches FeetInches::operator ++ () {
    // TODO: Overloaded prefix ++ operator
    // Causes the inches member to be incremented.
    // Returns the incremented object.
    int incr_feet = this->feet;
    int incr_inches = this->inches++;
    simplify();
    return {incr_feet,incr_inches};
}

FeetInches FeetInches::operator ++ (int) {
    // TODO: Overloaded postfix ++ operator
    // Causes the inches member to be incremented.
    // Returns the value of the object before the increment.
    FeetInches temp(feet, inches);
    inches++;
    simplify();

    return temp;
}

bool FeetInches::operator > (const FeetInches &right) {
    // TODO: Overloaded > operator
    // Returns true if the current object is set to a value
    // greater than that of right.
    if (this->feet > right.feet)
        return true;
    else if( this->feet == right.feet && this->inches > right.inches)
        return true;

    return false;

}

bool FeetInches::operator < (const FeetInches &right) {
    // TODO: Overloaded < operator
    // Returns true if the current object is set to a value
    // less than that of right.
    if (this->feet < right.feet)
        return true;
    else if( this->feet == right.feet && this->inches < right.inches)
        return true;

    return false;
}

bool FeetInches::operator == (const FeetInches &right) {
    // TODO: Overloaded == operator
    // Returns true if the current object is set to a value
    // equal to that of right
    return this->feet == right.feet && this->inches == right.inches;

}


//*********************
// PRIVATE FUNCTIONS  *
//*********************

void FeetInches::simplify() {
    if (inches >= 12) {
        feet += (inches / 12);
        inches = inches % 12;
    } else if (inches < 0) {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}