//
// Created by מוחמד עבידאת on 26/08/2021.
//

#ifndef DATA_STRUCTURE_CIRCULAR_LINKED__LIST_H
#define DATA_STRUCTURE_CIRCULAR_LINKED__LIST_H
/**
 * this class is about circular linked list
 * the first is using std::vector
 * the second is heir from "list.h"
 */

#include "header.h"

template <typename T> class CIRLIST;
template <typename T> std::ostream& operator<<( std::ostream&, CIRLIST<T>& );

template<typename T>
class CIRLIST {
    list<T> l;
    int interv(int x){
        if (x < 0)
            while (x < 0)
                x += l.size();
        else if (x >= l.size())
            while (x >= l.size())
                x -= l.size();
        return x;
    }

public:
     T const &operator[](int x) {

        vector<T> myVector(l.begin(), l.end());
        auto i = l.begin();
        std::advance(i,interv(x));
        return *i;
    }

    T &operator[](int x) const {
        auto i = l.begin();
        std::advance(i,interv(x));
        return *i;
    }
    int size(){
        return l.size();
    }

    void push_back(T t){
        l.push_back(t);
    }

    void remove(T t){
        l.remove(t);
    }
    friend std::ostream &operator<<<T>(std::ostream &,  CIRLIST<T> &);
};

std::ostream& operator<<( std::ostream& os,  CIRLIST<string>& s ) {
    int x = 0;
    string a;
    while(x !=s.size()){
        a= "";
        string t = s[x];
        //if(typeof(t) != 'string')
        int pr = int((t.length()));
        a+= u8"╔" + string(u8"═") * pr + u8"╗\n";
        a+= u8"║" + t + u8"║\n";
        a+= u8"╚" +string(u8"═") * pr +u8"╝\n";
        x++;
        os<< a;
    }
    os<<"\n" <<string(UNDERLINE)*4<<endl;
    return os;
}





template <typename T>
std::ostream& operator<<( std::ostream& os,  CIRLIST<T>& s ) {
    //vector<int> myVector(s.l.begin(), s.l.end());
    int x = 0;
    string a;
    while(x !=s.l.size()){
        a= "";
        T t = s[x];
        //if(typeof(t) != 'string')
        int pr = int((to_string(static_cast<int>(t)).length()));
        a+= u8"╔" + string(u8"═") * pr + u8"╗\n";
        a+= u8"║" + (to_string(static_cast<int> (t))) + u8"║\n";
        a+= u8"╚" +string(u8"═") * pr +u8"╝\n";
        x++;
        os<< a;
    }
    return os;
}







#endif //DATA_STRUCTURE_CIRCULAR_LINKED__LIST_H
