//
// Created by prenc on 29.06.17.
//

#include "Farm.h"

ostream &operator<<(ostream &s, const Farm &farm) {
    for (auto i: farm.farmSet_) {
        s << i->name_ << " ";
    }
    return s;
}
