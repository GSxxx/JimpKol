#include "ArrayList.h"

//
// Created by prenc on 29.06.17.
//
int main(){
    ArrayList<int> a;
    int tab[]={1,2,3,4,5};
    int tab2[5]={0};
    int tab3[]={0,1,2,3,4,5};
    a.Add(tab, 5);
    a.Add(tab2,5);
    a.Add(tab3,6);

    ArrayList<int> b(a);

    a.Display();
    b.Display();

    b.Change();
}
