//
// Created by מוחמד עבידאת on 31/08/2021.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H



#include "matrix.h"
#include "Print_vector.h"
/**
 * this class is about Aiming graph
 */
typedef matrix<int> mat;
class Proximity_matrix{
   mat graph;
   int V;
   int E;
public:
    Proximity_matrix(int i): graph(mat(i+1)),V(i+1),E(0){
        for(int x = 1 ; x < i+1;x++){
            graph[0][x]=x;
            graph[x][0] = x;
        }
    }
    void insert() {}
    template <typename ...Args>
    void insert(const pair<int,int>& p, Args...more) {
        if(graph[p.first][p.second] != 1) {
            graph[p.first][p.second] = 1;
            graph[p.second][p.first] = 1;
            E++;
        }
        insert(more...);
    }

    void remove() {}
    template <typename ...Args>
    void remove(const pair<int,int>& p, Args...more) {
        if(graph[p.first][p.second] == 1) {
            graph[p.first][p.second] = 0;
            graph[p.second][p.first] = 0;
            E--;
        }
        insert(more...);
    }
    friend ostream& operator<<(ostream&,Proximity_matrix&);


      vector<int> neighbors(int x){
          vector<int> temp;
          int y=0;
          for(auto i : graph[x]){
              if(i >0)
                  temp.push_back(y);
              y++;
          }
          temp.erase(temp.begin());

            return temp;
      }
};
ostream& operator<<(ostream& os ,Proximity_matrix& p){
    return os << p.graph<<endl;
}

class Proximity_List{
    vector<vector<int>> gra;
    int E;
    int V;
public:
    Proximity_List(int x):E(0),V(0),gra(vector<vector<int>> (x)){}
    void insert() {}
    template <typename ...Args>
    void insert(const pair<int,int>& p, Args...more) {
        bool temp = true;
        for(auto  i : gra[p.first-1]){
            if(i == p.second)
                temp = false;
        }
        if(temp) {
            gra[p.first-1].push_back(p.second);
            gra[p.second-1].push_back(p.first);
            E++;
        }
        insert(more...);
    }
    friend ostream& operator<<(ostream&,Proximity_List&);


    vector<int>& neighbors(int x){
//        vector<int> temp;
//        int y=0;
//        for(auto i : gra[x]){
//            if(i >0)
//                temp.push_back(y);
//            y++;
//        }
//        temp.erase(temp.begin());

        return gra[x-1];
    }
};
ostream& operator<<(ostream& os,Proximity_List& p){
    int j =0;
    for(auto & i : p.gra){
        os<<++j<<":"<<endl;

        if(i.size() != 0)
           os<< i<<endl;
    }
    return os;
}

#endif //DATA_STRUCTURE_GRAPH_H
