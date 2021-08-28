//
// Created by מוחמד עבידאת on 21/08/2021.
//

#ifndef DATA_STRUCTURE_COMPLEX_H
#define DATA_STRUCTURE_COMPLEX_H

#include <iostream>
using namespace std;

//int operator^(int z,int y);


class Complex{
private:
    int real;
    int imag;
public:
    Complex(int r=0, int i=0):real(r),imag(i){}

    friend Complex operator+(const Complex &other1,const Complex &other2);

    const int getReal(){
        return real;
    }

    string print()const{
        return  to_string(real) +"+" + to_string(imag) + "i";
    }

};
ostream& operator<<(ostream& os, const Complex& c){
    return os<<c.print();
}
Complex operator+(const Complex &other1,const Complex &other){
    return Complex(other1.real+other.real, other1.imag+other.imag);
}





#endif //DATA_STRUCTURE_COMPLEX_H
