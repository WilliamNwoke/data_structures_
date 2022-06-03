//
// Created by Uchenna on 3/30/22.
//

#ifndef ICE1_DATE_H
#define ICE1_DATE_H

#endif //ICE1_DATE_H
#include <string>

using namespace std;
/**
 * Date specification header file
 */
class Date {
    /**
     *
     */
public:
    Date();
    Date(int, int, int);
    void setDate(int, int, int);
    string getDate() const;
    string getSeason() const;

// Private values specifications
private:
    int year{};
    int month{};
    int day{};
};