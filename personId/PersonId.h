//
// Created by prenc on 25.06.17.
//

#ifndef TEST_PERSONID_H
#define TEST_PERSONID_H


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    Person() {}

    Person(string a,
           string b, string c) : firstname_(a), secondname_(b),
                                 pesel_(c) {}

    ~Person() {
    }

    friend class LO;

private:
    string secondname_;
    string firstname_;
    string pesel_;
};

class Node {
public:
    Node() : next_(nullptr) {}

    Node(const Person &os) : value_(os), next_(nullptr) {}

    friend class LO;

private:
    Person value_;
    Node *next_;

};

class LO {
    Node *head_;
public:
    LO() : head_(nullptr) {};

    ~LO() {
        Node *tmp = head_;
        Node *tmp2;
        while (tmp) {
            tmp2 = tmp;
            tmp = tmp->next_;
            delete tmp2;
        }
        head_ = nullptr;
    }

    bool operator==(const LO &l) {
        Node *tmp = head_;
        Node *tmp2 = l.head_;

        while (tmp && tmp2) {
            if (tmp->value_.firstname_ != tmp2->value_.firstname_ ||
                tmp->value_.secondname_ != tmp2->value_.secondname_ ||
                tmp->value_.pesel_ != tmp2->value_.pesel_) {
                return 0;
            }
            tmp = tmp->next_;
            tmp2 = tmp2->next_;
            if (tmp == nullptr && tmp2 == nullptr) return 1;
            if (tmp == nullptr || tmp2 == nullptr) return 0;
        }
        return 1;
    }

    LO &operator*(const LO &a) {
        LO *result = new LO();
        Node *tmp = head_;
        while (tmp) {
            Node *tmp2 = a.head_;
            while (tmp2) {
                if (tmp->value_.firstname_ == tmp2->value_.firstname_ &&
                    tmp->value_.secondname_ == tmp2->value_.secondname_ &&
                    tmp->value_.pesel_ == tmp2->value_.pesel_) {

                    Person *new_osoba = new Person(tmp->value_.firstname_,
                                                   tmp->value_.secondname_,
                                                   tmp->value_.pesel_);
                    Node *new_node = new Node();
                    new_node->value_ = *new_osoba;
                    if (result->head_ == nullptr) {
                        result->head_ = new_node;
                    } else {
                        Node *tmp3 = result->head_;
                        while (tmp3->next_ != nullptr)
                            tmp3 = tmp3->next_;
                        tmp3->next_ = new_node;
                    }

                }
                tmp2 = tmp2->next_;
            }
            tmp = tmp->next_;
        }
        return *result;
    }

    LO &operator=(const LO &os) {
        if (this == &os) {
            return *this;
        }
        this->~LO();
        Node *tmp = os.head_;
        while (tmp) {

            Person *new_osoba = new Person(tmp->value_.firstname_,
                                           tmp->value_.secondname_,
                                           tmp->value_.pesel_);
            Node *tmp3;
            Node *new_node = new Node();
            new_node->value_ = *new_osoba;
            if (head_ == nullptr) {
                head_ = new_node;
            } else {
                tmp3 = head_;
                while (tmp3->next_ != nullptr) tmp3 = tmp3->next_;
                tmp3->next_ = new_node;
            }

            tmp = tmp->next_;
        }
        return *this;
    }

    void Add(const Person &os) {
        Node *tmp;
        tmp = head_;
        while (tmp) {
            if (tmp->value_.pesel_ == os.pesel_) {
                tmp->value_.firstname_ = os.firstname_;
                tmp->value_.secondname_ = os.secondname_;
                return;
            }
            tmp = tmp->next_;
        }
        if (head_ == nullptr) {
            head_ = new Node(os);
        } else {
            tmp = head_;
            while (tmp->next_ != nullptr)
                tmp = tmp->next_;
            tmp->next_ = new Node(os);
        }
    }

    void Find(LO &wynik, const char *txt) {
        wynik.~LO();
        Node *tmp = head_;
        while (tmp) {
            if (txt == tmp->value_.pesel_ ||
                txt == tmp->value_.firstname_ ||
                txt == tmp->value_.secondname_) {
                Person *new_osoba = new Person(tmp->value_.firstname_,
                                               tmp->value_.secondname_,
                                               tmp->value_.pesel_);
                Node *new_node = new Node();
                new_node->value_ = *new_osoba;
                if (wynik.head_ == nullptr) {
                    wynik.head_ = new_node;
                } else {
                    Node *tmp2 = wynik.head_;
                    while (tmp2->next_ != nullptr)
                        tmp2 = tmp2->next_;
                    tmp2->next_ = new_node;
                }
            }
            tmp = tmp->next_;
        }

    }

    void wypisz() {
        Node *tmp = head_;
        while (tmp) {
            cout << tmp->value_.firstname_ << " " <<
                 tmp->value_.secondname_ << " " << tmp->value_.pesel_ << endl;
            tmp = tmp->next_;
        }
        cout << endl;
    }

};


#endif //TEST_PERSONID_H
