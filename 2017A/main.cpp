#include "Dictionary.h"

//
// Created by prenc on 28.06.17.
//
int main(){
    Dictionary a;
    a.AddWord("pies","pl");
    a.AddWord("dog","en");
    a.AddWord("hund","de");
    a.AddWord("abcd","de");
    a.AddWord("cat","en");
    a.AddWord("kot","pl");

    a.AddMeaning("pies","pl","dog","en");
    a.AddMeaning("kot","pl","cat","en");
    a.AddMeaning("pies","pl","hund","de");
    a.AddMeaning("dog","en","abcd","de");

    //a.RemoveWord("pies","pl");
    a.Display();

    cout<<"--------"<<endl;
    for(auto i: a.GetAllWordsInLang("en")){
        cout<<i<<" ";
    }

    cout<<endl;

    for(auto i: a.GetAllMeanings("pies","pl")){
        cout << i.text <<" ";
    }

    cout<<endl;

    for(auto i: a.GetAllMeaningsInLang("pies","pl","de")){
        cout << i<<" ";
    }



}
