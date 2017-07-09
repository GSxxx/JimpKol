//
// Created by prenc on 29.06.17.
//

#include "Farm.h"

int main(){
    Farm a;
    Hen h2("Stasia");
    Dog d2("Sonia");
    Cat c1("Mruczek");
    Dog d1("Reks");
    Hen h1("Koko");
    Cat c2("Staś");


    cout<<endl;

    a.AddAnimal(h2);
    a.AddAnimal(h1);
    a.AddAnimal(c2);
    a.AddAnimal(c1);
    a.AddAnimal(d1);

    cout<<a;
}