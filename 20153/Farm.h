//
// Created by prenc on 29.06.17.
//

#ifndef TEST_FARM_H
#define TEST_FARM_H

#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(const string &name_) : name_(name_) {}

    string name_;

    friend class Farm;
};

class Dog : public Animal {
public:
    Dog(const string &name_) : Animal(name_) { cout << "jestem nowym pieskiem!" << endl; }
};

class Cat : public Animal {
public:
    Cat(const string &name_) : Animal(name_) { cout << "jestem nowym kotkiem!" << endl; }
};

class Hen : public Animal {
public:
    Hen(const string &name_) : Animal(name_) { cout << "jestem nową kurką!" << endl; }
};

class Farm {
public:
    void AddAnimal(Animal &animal) {
        farmSet_.push_back(move(&animal));
    }

private:
    vector<Animal *> farmSet_;

    friend ostream &operator<<(ostream &s, const Farm &farm);
};

ostream &operator<<(ostream &s, const Farm &farm);

#endif //TEST_FARM_H
