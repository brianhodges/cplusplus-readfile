#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "team.h"
using namespace std;

string convertIntToString(int n) {
   ostringstream ss;
   ss << n;
   return ss.str();
}

int main(int argc, const char * argv[]) {
    vector<Team> teams;
    string filename = "top3list.csv";
    ifstream file(filename);
    string str;
    string delimiter = ",";
    while (getline(file, str)) {
        Team t;
        string name = str.substr(0, str.find(delimiter));
        str.erase(0, str.find(delimiter) + delimiter.length());
        int wins;
        string sbw = str.substr(0, str.find(delimiter));
        stringstream convert(sbw);
        if ( !(convert >> wins) )
            wins = 0;
        t.set_values(name, wins);
        teams.push_back(t);
    }
    
    cout << endl;
    cout << "Filename: " + filename;
    cout << endl << endl;
    for (vector<int>::size_type i = 0; i != teams.size(); i++) {
        string team_line = "| Team: " + teams[i].name + " |";
        string wins_line = "| Super Bowl Wins: " + convertIntToString(teams[i].super_bowl_wins);
        int ws = team_line.size() - wins_line.size() - 2;
        string border = "+" + string((team_line.size() - 2), '-') + "+";
        cout << border << endl;
        cout << team_line << endl;
        cout << wins_line << string(ws, ' ') << " |" << endl;
        cout << border << endl;
        cout << endl;
    }
    return 0;
}