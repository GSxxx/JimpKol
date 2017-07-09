//
// Created by prenc on 28.06.17.
//

#ifndef TEST_DICTIONARY_H
#define TEST_DICTIONARY_H

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Word {
public:
    Word(const string &text, const string &lang) : text(text), lang(lang) {}

    string text;
    string lang;
};

class Meaning {
public:
    Meaning() {}

    Meaning(Word *first, Word *sec) : fir(first), sec(sec) {}

    Word *fir;
    Word *sec;
};

class Dictionary {
public:
    Word *AddWord(const char *txt, const char *lan) {
        Word *tmp = new Word(txt, lan);
        dict_[tmp];
        return tmp;
    }

    void AddMeaning(const char *t1, const char *lan1, const char *t2, const char *lan2) {
        Word *tmp2 = nullptr;
        Word *tmp = nullptr;
        int flag = 0;
        for (auto i:dict_) {
            if ((i.first->text == t1 && i.first->lang == lan1) || (i.first->text == t2 && i.first->lang == lan2)) {
                flag++;
                if (flag == 1) {
                    tmp = i.first;
                }
                if (flag == 2) {
                    tmp2 = i.first;
                }
            }
        }
        Meaning *mean = new Meaning(tmp, tmp2);
        dict_[tmp].push_back(mean);
        dict_[tmp2].push_back(mean);
    }

    list<string> GetAllWordsInLang(string lang){
        list<string> output_lang;
        for(auto i: dict_){
            if(i.first->lang==lang){
                output_lang.push_back(i.first->text);
            }
        }
        return output_lang;
    }

    list<Word> GetAllMeanings(const char* txt, const char* lan){
        list<Word> output_meanings;
        for(auto i: dict_){
            if(i.first->text==txt && i.first->lang==lan){
                for(auto j: i.second){
                    if(i.first->text==j->fir->text) {
                        output_meanings.push_back(*j->sec);
                    } else{
                        output_meanings.push_back(*j->fir);
                    }
                }
            }
        }
        return output_meanings;
    }

    list<string> GetAllMeaningsInLang(const char* txt, const char* lan, const char* selectedlan){
        list<string> output_allmeanings;
        for(auto i: dict_){
            if(i.first->text==txt && i.first->lang==lan) {
                for (auto j: i.second) {
                    if (i.first->text == j->fir->text) {
                        if (j->sec->lang == selectedlan) {
                            output_allmeanings.push_back(j->sec->text);
                        }
                    } else {
                        if (j->fir->lang == selectedlan) {
                            output_allmeanings.push_back(j->fir->text);
                        }
                    }
                }
            }
        }
        return output_allmeanings;
    }

    void RemoveWord(const char *txt, const char *lan) {
        Word *tmp = nullptr;
        for (map<Word *, vector<Meaning *>>::iterator it = dict_.begin(); it != dict_.end(); it++) {
            if (it->first->text == txt && it->first->lang == lan) {
                tmp = it->first;
                dict_.erase(it);
                break;
            }
        }
        for (auto &i: dict_) {
            for (int j = 0; j < i.second.size(); j++) {
                if (i.second[j]->sec == tmp || i.second[j]->fir == tmp) {
                    i.second.erase(i.second.begin()+j);
                }
            }
        }
    }


    void Display() {
        for (auto i: dict_) {
            cout << i.first->text << ": ";
            for (auto j:i.second) {
                cout << "( " << j->fir->text << " " << j->sec->text << " ) ";
            }
            cout << endl;
        }
    }


private:
    map<Word *, vector<Meaning *>> dict_;
};


#endif //TEST_DICTIONARY_H
