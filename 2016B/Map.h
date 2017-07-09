//
// Created by prenc on 27.06.17.
//

#ifndef TEST_MAP_H
#define TEST_MAP_H

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <cmath>


using namespace std;

class City {
public:
    static int counter;

    City(string name, double x, double y) : name_(name), x_(x), y_(y), id_(++counter) {}

private:
    map<City *, double> neighbours_;
    string name_;
    double x_;
    double y_;
    int id_;

    friend class Map;

};

class Map {
public:
    int AddCity(const char* name, double x, double y){
        City *new_city = new City(name, x, y);
        core_.push_back(*new_city);
        delete new_city;
        return core_[core_.size()-1].id_;
    }
    bool AddConnection(int m1, int m2, double d1){
        if(m1==m2){
            return 0;
        }
        int flag=0;
        City *city1,*city2;
        for (auto &i: core_){
            if(i.id_==m1 || i.id_==m2){
                flag++;
                if(flag==1){
                    city1=&i;
                }
                if(flag==2){
                    city2=&i;
                }
            }

        }
        if(flag==2){
            city1->neighbours_[city2]=d1;
            city2->neighbours_[city1]=d1;
            return 1;
        }
        return 0;
    }

    void ListOfNeighbours(int m1, list<int>&sa){
        for(auto i: core_){
            if(i.id_==m1){
                for(auto k: i.neighbours_){
                    sa.push_back(k.first->id_);
                }
            }
        }
    }

    double GetDistance(int m1,int m2){
        if(m1==m2)return 0;
        for(auto i: core_){
            if(i.id_==m1){
                for(auto d: i.neighbours_){
                    if(d.first->id_ == m2){
                        return sqrt(pow(i.x_-d.first->x_, 2)+pow(i.y_-d.first->y_,2));
                    }
                }
            }
        }
    }

    void Display(){
        for(auto i:core_){
            cout<< i.name_<<" x_: "<< i.x_<<" y_: "<< i.y_<<" id: "<< i.id_<<endl;
            for(auto j: i.neighbours_){
                cout<<"\t"<<j.first->name_<<" odleglosc: "<< j.second<<endl;
            }
        }
    }
private:
    vector<City> core_;
};


#endif //TEST_MAP_H
