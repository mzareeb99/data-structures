//
// Created by מוחמד עבידאת on 21/08/2021.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#include <iostream>
using namespace std;

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void error(std::string b = "Empty Stack !!!"){
        cout<<RED<<b<<RESET<<endl;
}

template<class T>
class Stack{
private:
    int max_size;
    T *array;
    int current;
public:
    explicit Stack(int size=15):max_size(size),array(new T[size]),current(0){}
    Stack(const Stack& other):max_size(other.max_size),array(new T[max_size]),
    current(other.current){
        for( int i = 0 ; i < current;i++){
            array[i] = other.array[i];
        }
    }
    ~Stack(){
        //for(int i =0 ; i < current; i ++)
          //  delete array[i];
        delete [] array;
    }

    Stack& operator=(const Stack& oth){
        if(oth == this){
            return *this;
        }
        delete [] this->array;
        max_size = oth.max_size;
        this->array = new T[max_size];
        current = oth.current;

        for(int i = 0 ; i < current; i++){
            array[i] = oth.array[i];
        }
        return *this;
    }

    void push(const T& a){
        if(current >= max_size){
            return error("FULL Stack !!!");
        }
        array[current++] = a;
    }

    void pop(){
        if(current==0){
                return error();
        }
        --current;
    }

    T& top(){
        if(current==0){
            error();
        }
        return array[current-1];
    }

    int getSize(){
        return current;
    }
    int getEmptySpots() {
        return max_size - current;
    }
    string printStackString(){

        if(current == 0){return "Empty stack !\n";}
        std::string s1 = "#########\n";
        for (int i =0 ; i < current ; i++){
            s1 +="#   "+array[i]+"    #\n";
        }
        return s1 += "#########\n";
    }
    void setCurr(int s){current = s; }
    friend ostream& operator<<(ostream& os, Stack& c);
};


ostream& operator<<(ostream& os, Stack<int>& c) {
    Stack<string> c2(c.max_size);
    for(int i = 0 ; i<c.current;i++){
        c2.push(to_string(c.array[i]));
    }
    c2.setCurr(c.current);
    return os << c2.printStackString();
}


ostream& operator<<(ostream& os, Stack<string>& c){
    return os<<c.printStackString();
    /*
    if(c.current == 0){return os <<"Empty stack !"<<std::endl;}
    std::string s1 = "#########\n";
    for (int i =0 ; i < c.current ; i++){
        s1 +="#   "+ c.array[i] +"    #\n";
    }
    s1 += "#########\n";
    os<<s1;
    return os;
     */
}




#endif //DATA_STRUCTURE_STACK_H
