#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
using namespace std;

class Team {
    public:
        string name;
        int super_bowl_wins;
        void set_values(string, int);
};

void Team::set_values(string n, int s) {
    name = n;
    super_bowl_wins = s;
}

#endif