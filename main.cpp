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
                fake_five_angles{{1,  2},
                                 {2,  -1},
                                 {-3, -3},
                                 {-4, 0},
                                 {-3, 2}};
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
                    fake_six_angles{{1,  2},
                                    {2,  -1},
                                    {1,  -3},
                                    {-3, -3},
                                    {-4, 0},
                                    {-3, 2}};
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
                        point<double>> fake_eight_angles{{1,  2},
                                                         {2,  -1},
                                                         {1,  -3},
                                                         {0,  -5},
                                                         {-2, -5},
                                                         {-3, -3},
                                                         {-4, 0},
                                                         {-3, 2}};
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