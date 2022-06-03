//
// Created by Uchenna on 4/13/22.
//

#include <iostream>
#include <random>
#include <sstream>

bool isNumber(std::string str) {
    for (int i =0; i < str.length(); i++){
        if (isdigit(str[i]) == false){
            return false;
        }
        return true;
    }
}

int main() {
    // Using C++ 11 randomness
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type>
            dist6(1,100); // Distribution between 1 and 100

    uint number = dist6(rng);

    std::string strGuess;
    int guess;
    do {
        std::cout << "guess a number: ";
        std::cin >> strGuess;
        if (isNumber(strGuess)) {
            std::stringstream strConv(strGuess);
            strConv >> guess;


            if (guess < 0 || guess > 100) {
                std::cout << "Out of range 1-100\n";
            }
            else if (guess > number){
                std::cout << "guess too high\n";
            }
            else{
                std::cout << "guess too low\n";
            }

        } else {
            std::cout << "not a number" << std::endl;
            guess = -1;
        }
    } while (guess != number);

    std::cout << "You guessed correct\n" << "Exiting the program";


    return 0;
}

/**
* //    srand((unsigned) time(nullptr));
//    int randomNumber;
//    for (int index = 0; index < 5; index++) {
//        randomNumber = (rand() % 100) + 1;
//        cout << randomNumber << endl;
//    }
*/