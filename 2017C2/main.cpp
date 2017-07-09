#include "GPSTracer.h"

//
// Created by prenc on 29.06.17.
//
int main(){
    GPSTracer a;
    a.AddPoint(1,2,20);
    a.AddPoint(2,2,40);
    a.AddPoint(3,2,60);
    GPSTracer b(a);
    a.Display();

    b.AddPoint(4,2,80);
    b.AddPoint(4,2,76);
    b.Display();
    b=a;
    b.Display();

}
