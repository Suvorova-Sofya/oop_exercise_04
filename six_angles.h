#ifndef D_SIX_ANGLES_H_
#define D_SIX_ANGLES_H_

#include <iostream>
#include "point.h"


template<class T>
struct six_angles {

    six_angles(std::istream &is);

    point<T> center() const ;
    void print() const ;
    double square() const ;
private:
    point<T> one,two,three,four,five,six;
};

#include <iostream>

#include "six_angles.h"

template<class T>
six_angles<T>::six_angles(std::istream &is){
    is >> one >> two >> three >> four >> five >>six;
}

template<class T>
point<T> six_angles<T>::center() const {
    point<T> p;
    p=one+two+three+four+five+six;
    p/=6;
    return p;
}

template<class T>
void six_angles<T>::print() const {
    std::cout << one << " " << two << " " << three << " " << four << " " << five << " " << six <<"\n";
}

template<class T>
double six_angles<T>::square() const {
    double s=0;
    s=(one.x*two.y+two.x*three.y+three.x*four.y+four.x*five.y+five.x*six.y+six.x*one.y-two.x*one.y-
       three.x*two.y-four.x*three.y-five.x*four.y-six.x*five.y-one.x*six.y)/2;
    if(s<0){
        return -s;
    }else {
        return s;
    }
}

#endif