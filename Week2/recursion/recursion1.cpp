//
// Created by Uchenna on 4/13/22.
//
#include <iostream>

int powerNum(int baseNum, int power);
int recFactorial(int num);
int iteFactorial(int num);

int main() {
    // int num = powerH(2, 3);
    std::cout << recFactorial(5);
    std::cout << "\n"<<iteFactorial(3);
}

int iteFactorial (int num){
    while (num > 1){

        num--;
    }
    return num;
}

int recFactorial(int num){
    if (num == 1){
        return num;
    } else {
        return num * recFactorial(num -1);
    }
}
int powerNum(int baseNum, int power){

    if (power == 1){
        return baseNum;
    } else {
        power--;
        return powerNum(baseNum, power) * baseNum;
    }
}