#ifndef D_EIGHT_ANGLES_H_
#define D_EIGHT_ANGLES_H_

#include <iostream>
#include "point.h"

template<class T>
struct eight_angles {

    eight_angles(std::istream &is);

    point<T> center() const ;
    void print() const ;
    double square() const ;

    point<T> one,two,three,four,five,six,seven,eight;
};

template<class T>
eight_angles<T>::eight_angles(std::istream &is){
    is >> one >> two >> three >> four >> five >>six >>seven >>eight;
}

template<class T>
point<T> eight_angles<T>::center() const {
    point<T> p;
    p=one+two+three+four+five+six+seven+eight;
    p/=8;
    return p;
}

template<class T>
void eight_angles<T>::print() const {
    std::cout << one << " " << two << " " << three << " " << four << " " << five << " " << six << " " << seven
              << " " << eight<<"\n";
}

template<class T>
double eight_angles<T>::square() const {
    double s=0;
    s=(one.x*two.y+two.x*three.y+three.x*four.y+four.x*five.y+five.x*six.y+six.x*seven.y+seven.x*eight.y+
       eight.x*one.y-two.x*one.y-three.x*two.y-four.x*three.y-five.x*four.y-six.x*five.y-seven.x*six.y
       -eight.x*seven.y-one.x*eight.y)/2;
    if(s<0){
        return -s;
    }else {
        return s;
    }
}

#endif