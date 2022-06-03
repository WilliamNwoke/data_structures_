// Specification file for the FeetInches class
// The FeetInches class holds distances or measurements 
// expressed in feet and inches.
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <string>
using namespace std;

class FeetInches {
public:
    // Constructor
    FeetInches(int f = 0, int i = 0);

    // Mutator functions
    void setFeet(int f);
    void setInches(int i);

    // Accessor functions
    int getFeet() const;
    int getInches() const;

    // Overloaded operator functions
    FeetInches operator + (const FeetInches &); // Overloaded +
    FeetInches operator - (const FeetInches &); // Overloaded -
    FeetInches operator ++ ();				    // Prefix ++
    FeetInches operator ++ (int);			    // Postfix ++
    bool operator > (const FeetInches &);		// Overloaded >
    bool operator < (const FeetInches &);		// Overloaded <
    bool operator == (const FeetInches &);		// Overloaded ==

    // String rep of FeetInches object
    string to_string() const;
private:
    int feet;
    int inches;
    void simplify();
};

#endif
