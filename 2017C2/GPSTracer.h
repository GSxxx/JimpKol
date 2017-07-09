//
// Created by prenc on 29.06.17.
//

#ifndef TEST_GPSTRACER_H
#define TEST_GPSTRACER_H


#include <iostream>

using namespace std;


class PointGPS {
public:
    double x_;
    double y_;
    double time_;

    PointGPS() {};

    PointGPS(double x, double y, double time) : x_(x), y_(y), time_(time) {}
};

class GPSTracer {
public:
    PointGPS *tab_;
    int tab_size_;

    GPSTracer() : tab_(nullptr), tab_size_(0) {}
    ~GPSTracer() {
        delete[]tab_;
        tab_= nullptr;
        tab_size_=0;
    }

    GPSTracer(const GPSTracer &g) {
        if (this == &g) {
            return;
        }
        tab_size_ = g.tab_size_;
        PointGPS *new_tab = new PointGPS[tab_size_];
        for (int i = 0; i < tab_size_; i++) {
            new_tab[i] = g.tab_[i];

        }
        tab_ = new_tab;
    }
    GPSTracer& operator=(const GPSTracer &g) {
        if (this == &g) {
            return *this;
        }
        this->~GPSTracer();
        tab_size_ = g.tab_size_;
        PointGPS *new_tab = new PointGPS[tab_size_];
        for (int i = 0; i < tab_size_; i++) {
            new_tab[i] = g.tab_[i];

        }
        tab_ = new_tab;
        return *this;
    }

    bool AddPoint(double x, double y, double time) {
        if (tab_size_ != 0) {
            if (tab_[tab_size_ - 1].time_ > time) {
                return 0;
            }
        }

        PointGPS *new_one = new PointGPS(x, y, time);
        tab_size_++;
        PointGPS *new_tab = new PointGPS[tab_size_];
        for (int i = 0; i < tab_size_ - 1; i++) {
            new_tab[i] = tab_[i];
        }
        new_tab[tab_size_ - 1] = *new_one;
        delete[] tab_;
        tab_ = new_tab;
        return 1;
    }

    void Display() {
        for (int i = 0; i < tab_size_; i++) {
            cout << " (" << tab_[i].x_ << ", " << tab_[i].y_ << ") time: " << tab_[i].time_ << endl;
        }
        cout << endl;
    }

};


#endif //TEST_GPSTRACER_H
