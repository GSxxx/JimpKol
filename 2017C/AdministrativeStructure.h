//
// Created by prenc on 27.06.17.
//

#ifndef TEST_ADMINISTRATIVESTRUCTURE_H
#define TEST_ADMINISTRATIVESTRUCTURE_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class City {
public:
    City(string name, int pop) : name_(name), population_(pop) {};
public:
    string name_;
    int population_;

    friend class AdministrativeStructure;

};

class County {
public:
    County(string name) : name_(name) {};
private:
    vector<City> cities_;
    string name_;

    friend class AdministrativeStructure;
};

class Region {
public:
    Region(string name) : name_(name) {};
private:
    vector<County> counties_;
    string name_;

    friend class AdministrativeStructure;
};


class AdministrativeStructure {
public:
    void AddCity(const char *name, int pop, const char *county, const char *region) {
        for (vector<Region>::iterator it = regions_.begin();; it++) {
            if (it == regions_.end()) {
                regions_.push_back(move(*new Region(region)));
                it = regions_.end() - 1;
            }
            if (it->name_ == region) {
                for (vector<County>::iterator it2 = it->counties_.begin();; it2++) {
                    if (it2 == it->counties_.end()) {
                        it->counties_.push_back(move(*new County(county)));
                        it2 = it->counties_.end() - 1;
                    }
                    if (it2->name_ == county) {
                        for (vector<City>::iterator it3 = it2->cities_.begin();; it3++) {
                            if (it3 == it2->cities_.end()) {
                                it2->cities_.push_back(move(*new City(name, pop)));
                                it3 = it2->cities_.end() - 1;
                            }
                            if (it3->name_ == name) {
                                it3->population_ = pop;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    City *FindCity(const char *name) {
        for (auto &i: regions_) {
            for (auto &j: i.counties_) {
                for (vector<City>::iterator it = j.cities_.begin(); it != j.cities_.end(); it++) {
                    if (it->name_ == name) {
                        return &*it;
                    }
                }
            }
        }
        return 0;
    }


    void RemoveCity(const char *name) {
        for (vector<Region>::iterator i = regions_.begin(); i != regions_.end(); i++) {
            for (vector<County>::iterator j = i->counties_.begin(); j != i->counties_.end(); j++) {
                for (vector<City>::iterator it = j->cities_.begin(); it != j->cities_.end(); it++) {
                    if (it->name_ == name) {
                        j->cities_.erase(it);
                        break;
                    }
                }
                if (j->cities_.size() == 0) {
                    i->counties_.erase(j);
                    break;
                }

            }
            if (i->counties_.size() == 0) {
                regions_.erase(i);
                break;
            }
        }
    }

    set<string> GetCitiesInCounty(const char *cntname) {
        set<string> output_county;
        for (auto i: regions_) {
            for (auto j: i.counties_) {
                if (j.name_ == cntname) {
                    for (auto k: j.cities_) {
                        output_county.insert(k.name_);
                    }

                }
            }
        }
        return output_county;
    }

    set<string> GetCitiesInRegion(const char *regname) {
        set<string> output_region;
        for (auto i: regions_) {
            if (i.name_ == regname) {
                for (auto j: i.counties_) {
                    for (auto k: j.cities_) {
                        output_region.insert(k.name_);
                    }
                }
            }
        }
        return output_region;
    }

    set<string> GetCountiesInRegion(const char *regname) {
        set<string> output_region;
        for (auto i: regions_) {
            if (i.name_ == regname) {
                for (auto j: i.counties_) {
                        output_region.insert(j.name_);
                }
            }
        }
        return output_region;
    }

        void Display() {
            for (auto i: regions_) {
                cout << i.name_ << ": " << endl;
                for (auto j: i.counties_) {
                    cout << "\t" << j.name_ << ": " << endl;
                    for (auto k: j.cities_) {
                        cout << "\t\t" << k.name_ << endl;
                    }
                }
            }
            cout << "-------------------------------------" << endl;
        }

        private:
        vector<Region> regions_;
    };


#endif //TEST_ADMINISTRATIVESTRUCTURE_H
