//
// Created by prenc on 29.06.17.
//

#ifndef TEST_ARRAYLIST_H
#define TEST_ARRAYLIST_H

#include <iostream>


using namespace std;

template<class T>
class LE {
public:
    LE() {}

    LE(T *tab_, int size_) : tab_(tab_), size_(size_), next_(nullptr) {}

    T *tab_;
    int size_;
    LE<T> *next_;

    ~LE() {
//        for (int i = 0; i < size_; i++) {
//            delete (tab_+i);
//        }
        next_ = nullptr;
    }
};

template<class T>
class ArrayList {
public:
    ArrayList() : head(nullptr) {}

    ~ArrayList() {
        LE<T> *tmp = head;
        LE<T> *tmp2;
        while (tmp) {
            tmp2 = tmp->next_;
            //tmp->~LE();
            delete tmp;
            tmp = tmp2;
        }
    }

    LE<T> *head;

    void Change() {
        *(head->tab_ + 1) = 4;
    }

    void Add(T *t, int size) {
        LE<T> *new_one = new LE<T>(t, size);
        LE<T> *tmp;
        if (head == nullptr) {
            head = new_one;
        } else {
            tmp = head;
            while (tmp->next_) {
                tmp = tmp->next_;
            }
            tmp->next_ = new_one;
        }
    }

    void Display() {
        LE<T> *tmp = head;
        while (tmp) {
            for (int i = 0; i < tmp->size_; i++) {
                cout << *(tmp->tab_ + i) << " ";
            }
            cout << endl;
            tmp = tmp->next_;
        }
        cout << endl;
    }

/*
    ArrayList(const ArrayList<T> &l1) {
        if (this == &l1) {
            return;
        }
        LE<T> *tmp = l1.head;
        LE<T> *tmp2 = head;
        while (tmp) {
            tmp2->size_ = tmp->size_;
            LE<T> *new_one = new LE<T>();
            T *tab_ = new T[tmp->size_];
            for (int i = 0; i < tmp->size_; i++) {
                *(new_one->tab_+i) = *(tmp->tab_+i);
            }
            tmp2->tab_=tab_;
            tmp2=new_one;
            tmp = tmp->next_;
            tmp2 = tmp2->next_;

        }
    }*/

    ArrayList(const ArrayList<T> &b) {
        if (this == &b) {
            return;
        }
        if (b.head != NULL) {
            LE<T> *current = b.head;
            LE<T> *tmp;
            T *tab = new T[current->size_];
            for (int i = 0; i < current->size_; i++) {
                *(tab + i) = *(current->tab_ + i);
            }
            tmp = new LE<T>(tab, current->size_);

            this->head = tmp;
            current = current->next_;

            while (current != NULL) {
                tab = new T[current->size_];
                for (int i = 0; i < current->size_; i++) {
                    tab[i] = *(current->tab_ + i);
                }
                tmp->next_ = new LE<T>(current->tab_, current->size_);
                tmp = tmp->next_;
                current = current->next_;
            }
        }
    }

};


#endif //TEST_ARRAYLIST_H
