//
// Created by Uchenna on 4/13/22.
//

#include  <iostream>

int main(){
    float amount = 100.00;
    float expense = 0;
    float horse, pig, rabbit;
    horse = 10.00;
    pig = 3.00;
    rabbit = 0.5;
    int count1 =0;
    int count2 = 0;
    int count3 = 0;

    while (expense <=amount){
        if (expense <=100) {
            expense +=horse;
            count1++;
            }
        if (expense <=100) {
            expense+=pig;
        }
        if (expense <=100) {
            expense+=rabbit;
        }
    }

    std::cout << "Horse: " + count1 << "";

}

