//
// Created by מוחמד עבידאת on 21/08/2021.
//
#ifndef DATA_STRUCTURE_ARRAYO1_HPP
#define DATA_STRUCTURE_ARRAYO1_HPP

#include "header.h"
/**
 * this project creat a array with O(1) run time.
 * use 3 arrays.
 * i don't use an exceptions.
 */

template<typename T>
class ArrayO1{
private:
    int top;
    int max;
    T *A;
    int *B;
    int *C;

public:
    ArrayO1(int i = 10):top(0), max(i),A(new T[i]),B(new int[i]),C(new int[i]) {}
    ~ArrayO1(){
        delete[] A;
        delete[] B;
        delete [] C;
    }

  ArrayO1(const ArrayO1& other):top(other.top), max(other.max),A(new T[other.max]),B(new int[other.max]),C(new int[other.max]){
        for(int i =0 ; i < top; i++){
            A[C[i]] = other.A[other.C[i]];
            B[C[i]] = i;
            assert(B[C[i]] == other.B[other.C[i]]);
        }
    }


    ArrayO1& operator=(const ArrayO1& other){
        if(other == this){
            return *this;
        }
        delete [] this->A;
        delete [] this->B;
        delete [] this->C;
        /*
        max = oth.max;
        top = oth.top;
        this->A = new T[max_size];
        current = oth.current;
        */
        this = ArrayO1(other.max);
        this->top = other.top;
        for(int i =0 ; i < top; i++){
            A[C[i]] = other.A[other.C[i]];
            B[C[i]] = i;
            //assert(B[C[i]] == other.B[other.C[i]]);
        }
        return *this;
    }

    bool is_initialized(int i){
        return (B[i] < top && B[i]>=0 && C[B[i]] == i);
    }


    T& operator[](int i) {
        if(i >= max){
            throw error_throw("out of array ");
        }
        if( top <= max)
            if (!(is_initialized(i))) {
                correct("initialized to zero");
                C[top] = i;
                B[i] = top;
                top++;
                A[i] = 0;
            }
        return A[i];
    }


    friend ostream& operator<<(ostream& os, ArrayO1& c);
};

ostream& operator<<(ostream& os, ArrayO1<int>& c) {
    for(int i = 0 ; i<c.top;i++){
        os<< "(" + to_string(i) + ",["+ to_string(c.A[c.C[i]])+","+ to_string(c.C[i])+"])";
    }
    return os << endl;
}





#endif //DATA_STRUCTURE_ARRAYO1_HPP
