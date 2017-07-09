//
// Created by prenc on 27.06.17.
//

#include "Map.h"
int City::counter=0;
int main(){


    Map a;
    a.AddCity("Krakow", 57, 64);
    a.AddCity("Warszawa", 37, 44);
    a.AddCity("Bielsko", 27, 74);
    a.AddCity("Wroclaw", 17, 60);
    a.AddConnection(1,2,20);
    a.AddConnection(1,3,30);
    a.AddConnection(1,4,40);
    a.AddConnection(3,4,90);

    a.Display();

    list<int> list1;
    a.ListOfNeighbours(1,list1);
    cout<<"Dla id 1: ";
    for(auto i: list1){
        cout<< i <<" ";
    }
    cout<<endl;

    cout<<a.GetDistance(1,2)<<endl;
    cout<<a.GetDistance(1,1)<<endl;
}