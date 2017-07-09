//
// Created by prenc on 25.06.17.
//

#include "Graph.h"

int main() {

    Graph a;

    a.Add("aa");
    a.Add("bb");
    a.Add("cc");
    a.Add("dd");
    a.Add("ee");

    cout << endl;
    a.AddEdge("aa", "bb");
    a.AddEdge("aa", "ee");
    a.AddEdge("bb", "cc");
    a.AddEdge("bb", "dd");
    a.AddEdge("cc", "ee");
    a.AddEdge("ee", "aa");
    a.AddEdge("dd", "ee");

    a.wypisz();

    a.Merge("bb","dd");
    cout<<endl;
    a.wypisz();

}