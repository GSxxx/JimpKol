//
// Created by prenc on 25.06.17.
//

#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {
public:
    void Add(const char *new_one) {
        core[new_one];
    }

    void Remove(const char *toerase) {
        map<string, vector<string>>::iterator it;
        it = core.find(toerase);
        if (it != core.end()) {
            core.erase(it);
        }
    }

    void AddEdge(const char *one, const char *two) {
        bool flag = 0;
        vector<string> v = core.find(one)->second;
        for (auto i: v) {
            if (i == two) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            core[one].push_back(two);
        }
    }

    void Merge(const char *one, const char *two) {
        vector<string> *v = &core.find(two)->second;
        for (int i = 0; i < v->size(); i++) {
            bool flag = 0;
            for (auto j: core.find(one)->second) {
                if ((*v)[i] == j) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                core.find(one)->second.push_back((*v)[i]);
            }
        }
        vector<string> w = core.find(one)->second;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] == two) {
                w.erase(w.begin() + i - 1);
            }
        }
        core.erase(core.find(two));

    }

    void wypisz() {
        for (auto a: core) {
            cout << a.first << ": ";
            for (string d : a.second) {
                cout << d << " ";
            }
            cout << endl;
        }
    }


private:
    map<string, vector<string>> core;


};


#endif //TEST_GRAPH_H
