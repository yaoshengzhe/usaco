/*
ID: yaoshen2
LANG: C++
TASK: ride
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int get_scheme(const string &name) {
    int result = 1;
    for (int i=0; i < name.size(); ++i) {
        result = (result * (name[i] - 'A' + 1)) % 47;
    }
    return result;
}

int main(int argc, char *argv[]) {
    string comet, group;
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    getline(fin, comet);
    getline(fin, group);
    if (get_scheme(comet) == get_scheme(group)) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
