#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include "templates.h"


int main() {
    char str[12];
    std::cin >> str;
    if(strcmp("five_angles",str)==0) {
        five_angles<double> real_five_angles(std::cin);
        print(real_five_angles);
        std::tuple<point<double>, point<double>, point<double>, point<double>, point<double>>
                fake_five_angles{real_five_angles.one,
                                 real_five_angles.two,
                                 real_five_angles.three,
                                 real_five_angles.four,
                                 real_five_angles.five};
        print(fake_five_angles);
        std::cout << std::endl;
        std::cout << center(real_five_angles) << "\n";
        std::cout << center(fake_five_angles) << "\n";
        std::cout << square(real_five_angles) << "\n";
        std::cout << square(fake_five_angles);
        std::cout << std::endl;
    }else {
        if(strcmp("six_angles",str)==0) {
            six_angles<double> real_six_angles(std::cin);
            print(real_six_angles);
            std::tuple<point<double>, point<double>, point<double>, point<double>, point<double>, point<double>>
                    fake_six_angles{real_six_angles.one,
                                    real_six_angles.two,
                                    real_six_angles.three,
                                    real_six_angles.four,
                                    real_six_angles.five,
                                    real_six_angles.six};
            print(fake_six_angles);
            std::cout << std::endl;
            std::cout << center(real_six_angles) << "\n";
            std::cout << center(fake_six_angles) << "\n";
            std::cout << square(real_six_angles) << "\n";
            std::cout << square(fake_six_angles);
            std::cout << std::endl;
        }else{
            if(strcmp("eight_angles",str)==0) {
                eight_angles<double> real_eight_angles(std::cin);
                print(real_eight_angles);
                std::tuple<point<double>, point<double>, point<double>, point<double>, point<double>, point<double>, point<double>,
                        point<double>> fake_eight_angles{real_eight_angles.one,
                                                         real_eight_angles.two,
                                                         real_eight_angles.three,
                                                         real_eight_angles.four,
                                                         real_eight_angles.five,
                                                         real_eight_angles.six,
                                                         real_eight_angles.seven,
                                                         real_eight_angles.eight};
                print(fake_eight_angles);
                std::cout << std::endl;
                std::cout << center(real_eight_angles) << "\n";
                std::cout << center(fake_eight_angles) << "\n";
                std::cout << square(real_eight_angles) << "\n";
                std::cout << square(fake_eight_angles);
                std::cout << std::endl;
            }
        }
    }
    return 0;
}