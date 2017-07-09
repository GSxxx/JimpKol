#include "PersonId.h"

int main() {
    LO a, l, p;
    Person d("Jan", "Kowlaski", "123");
    Person b("Adam", "Nowicki", "677");
    Person c("Michał", "Nowak", "677");
    Person e("zuza", "nuuuuua", "789");
    Person r("zuza", "ASAsaS", "999");


    a.Add(d);
    a.Add(b);
    a.Add(e);


    p.Add(d);
    p.Add(b);
    p.Add(e);
    p.Add(r);

    a.wypisz();
    p.wypisz();

    l=a*p;
    //a.Add(c);

    //a.Display();
    //a.Find(l, "zuza");
    l.wypisz();

    if (a == a) {
        cout << "it works" << endl;
    }

}