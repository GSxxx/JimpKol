//
// Created by prenc on 27.06.17.
//

#include "AdministrativeStructure.h"

int main(){
    AdministrativeStructure a;
    a.AddCity("Krakow",765000, "krakowski", "malopolskie");
    a.AddCity("Krzeszowice",10000, "krakowski", "malopolskie");
    a.AddCity("Skała",3000, "krakowski", "malopolskie");
    a.AddCity("Skawina",25000, "krakowski", "malopolskie");
    a.AddCity("Słomniki",5000, "krakowski", "malopolskie");
    a.AddCity("Wieliczka",10000, "wielicki", "malopolskie");
    a.AddCity("Oświęcim",23000,"oświęcimski", "malopolskie");
    a.AddCity("Brzeszcze",50000,"oświęcimski", "malopolskie");
    a.AddCity("Chełmek",100000,"oświęcimski", "malopolskie");
    a.AddCity("Kęty",12000,"oświęcimski", "malopolskie");
    a.AddCity("Bielsko-Biała",170000,"bielski", "śląskie");
    a.AddCity("Szczyrk",20000,"bielski", "śląskie");
    a.AddCity("Czechowice-Dziedzice",20000,"bielski", "śląskie");
    a.AddCity("Wilamowice",20000,"bielski", "śląskie");
    a.AddCity("Gliwice",115000,"gliwicki", "śląskie");

    cout<< a.FindCity("Szczyrk")->name_<<endl;
    cout<< a.FindCity("Warszawa")<<endl;

    a.Display();
    cout<<endl;
    a.RemoveCity("Krakow");
    a.RemoveCity("Gliwice");
    a.Display();

    for(auto i:a.GetCitiesInCounty("krakowski")){
        cout<<i<<" ";
    }
    cout<<endl;


    for(auto i:a.GetCitiesInRegion("malopolskie")){
        cout<<i<<" ";
    }
    cout<<endl;


    for(auto i:a.GetCountiesInRegion("malopolskie")){
        cout<<i<<" ";
    }
    cout<<endl;

}
