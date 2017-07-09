#include "SocialGraph.h"

//
// Created by prenc on 27.06.17.
//
int main(){
    SocialGraph a;
    a.AddPerson("Pawel","Renc","prenc");
    a.AddPerson("Tomek","Renc","wrenc");
    a.AddPerson("Zuza","Dziedzic","zdzie");
    a.AddPerson("Maciek","Renc","mrenc");
    a.AddPerson("Grażyna","Renc","asdf");
    a.AddPerson("Bożena","Renc","bolek");
    a.AddPerson("Janusz","Renc","trutut");

    a.Display();
    //a.RemovePerson("prenc");
    a.AddFollower("zdzie","prenc");
    a.AddFollower("zdzie","trutut");
    a.AddFollower("wrenc","bolek");
    a.AddFollower("prenc","zdzie");
    a.AddFollower("bolek","asdf");
    a.AddFollower("asdf","wrenc");
    a.AddFollower("trutut","wrenc");
    a.Display();
    a.UnFollower("zdzie","mrenc");
    a.Display();

    for(auto i: a.GetDirectF("prenc")){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto i: a.GetAllF("prenc")){
        cout<<i<<" ";
    }
    cout<<endl;

}
