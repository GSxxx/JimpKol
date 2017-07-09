//
// Created by prenc on 27.06.17.
//

#ifndef TEST_SOCIALGRAPH_H
#define TEST_SOCIALGRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Person {
public:
    Person() {};

    Person(string name, string surname, string email) : name_(name), surname_(surname), email_(email) {};

    ~Person() {};
private:
    string name_;
    string surname_;
    string email_;

    friend class SocialGraph;
};

class SocialGraph {
public:
    bool AddPerson(string name, string surname, string email) {
        for (auto i:core_) {
            if (i.first->email_ == email)return 0;
        }
        Person *new_one = new Person(name, surname, email);
        core_[new_one];
        return 1;
    }

    bool RemovePerson(const char *email) {
        for (map<Person *, vector<Person *>>::iterator it = core_.begin(); it != core_.end(); it++) {
            if (it->first->email_ == email) {
                core_.erase(it);
                return 1;
            }
        }
        return 0;

    }

    bool AddFollower(const char *emailFrom, const char *emailTo) {
        Person *tmp = nullptr, *tmp2 = nullptr;
        for (auto &i: core_) {
            if (i.first->email_ == emailFrom) {
                tmp = i.first;
            }
            if (i.first->email_ == emailTo) {
                tmp2 = i.first;
            }
        }
        if (!tmp || !tmp2) {
            return 0;
        }
        core_[tmp].push_back(tmp2);
        return 1;
    }


    bool UnFollower(const char *emailFrom, const char *emailTo) {
        Person *tmp = nullptr, *tmp2 = nullptr;
        for (auto &i: core_) {
            if (i.first->email_ == emailFrom) {
                tmp = i.first;
                break;
            }
        }
        if (!tmp) {
            return 0;
        }
        for (vector<Person *>::iterator it = core_[tmp].begin(); it != core_[tmp].end(); it++) {
            if ((*it)->email_ == emailTo) {
                core_[tmp].erase(it);
                break;
            }
        }
        return 1;
    }

    set<string> GetDirectF(const char *email) {
        set<string> output_direct;
        for (auto i: core_) {
            for (auto j: i.second) {
                if (j->email_ == email) {
                    output_direct.insert(i.first->email_);
                }
            }
        }
        return output_direct;
    }

    set<string> GetAllF(const char *email) {
        set<string> output_all;
        for (auto i: core_) {
            for (auto j: i.second) {
                if (j->email_ == email) {
                    output_all.insert(i.first->email_);
                }
            }
        }
        int flag = 1;
        while (flag) {
            flag = 0;
            for (auto d : output_all) {
                for (auto i: core_) {
                    for (auto j: i.second) {
                        if (j->email_ == d) {
                            auto it = output_all.find(i.first->email_);
                            if (it == output_all.end()) {
                                output_all.insert(i.first->email_);
                                flag++;
                            }

                        }
                    }
                }
            }
        }
        return output_all;
    }

    void Display() {
        for (auto i: core_) {
            cout << i.first->email_ << " " << i.first->name_ << " " << i.first->surname_ << ": ";
            for (auto j:i.second) {
                cout << j->email_ << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
//private:
    map<Person *, vector<Person *>> core_;
};


#endif //TEST_SOCIALGRAPH_H