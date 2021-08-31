//
// Created by מוחמד עבידאת on 31/08/2021.
//

#ifndef DATA_STRUCTURE_PRINT_VECTOR_H
#define DATA_STRUCTURE_PRINT_VECTOR_H

#include "header.h"
int get_max(const vector<string> &v){
    string a = v[0];
    for(const auto& i : v){
        i.length() > a.length() ? a = i : a;
    }
    return a.length();
}

template<typename T>
T get_max(const vector<T> &v){
    T a = v[0];
    for(auto i : v){
        i > a ? a = i : a;
    }
    return a;
}

std::ostream& operator<<( std::ostream& os,  vector<string>& s ) {
    if(s.size() == 0){
        important("Empty vector !");
        return os;
    }
    for(auto i :s){
        int pr = i.length();
        os<< u8"╔" + string(u8"═") * pr + u8"╗  ";
    }
    os<<endl;
    for(int i = 0 ; i < s.size()-1;i++){
        os<< u8"║" <<s[i]<< u8"║" <<LIFT<<RIGHT;
    }
    os<< u8"║" <<s[s.size()-1]<< u8"║";
    os<<endl;
    for(auto i :s){
        int pr = i.length();
        os<< u8"╚" +string(u8"═") * pr +u8"╝  ";
    }
    return os;
}

template <typename T>
std::ostream& operator<<( std::ostream& os,  vector<T>& s ) {
    if(s.size() == 0){
        important("Empty vector !");
        return os;
    }
    int max = get_max(s);
    for(auto i :s){
        int pr = int((to_string(static_cast<int>(i)).length()));
        os<< u8"╔" + string(u8"═") * pr + u8"╗  ";
    }
    os<<endl;
    for(int i = 0 ; i < s.size()-1;i++){
        os<< u8"║" <<s[i]<< u8"║" <<LIFT<<RIGHT;
    }
    os<< u8"║" <<s[s.size()-1]<< u8"║";
    os<<endl;
    for(auto i :s){
        int pr = int((to_string(static_cast<int>(i)).length()));
       os<< u8"╚" +string(u8"═") * pr +u8"╝  ";
    }
    return os;
}


#endif //DATA_STRUCTURE_PRINT_VECTOR_H
