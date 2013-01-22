/*
  ID: yaoshen2
  LANG: C++
  TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int np;
    string newline;
    fin >> np;
    getline(fin, newline);
    string *names = new string[np];
    map<string, int> name_map;

    int *balances = new int[np];
    for (int i=0; i < np; ++i) {
        balances[i] = 0;
    }

    for (int i=0; i < np; ++i) {
        getline(fin, names[i]);
        name_map[names[i]] = i;
    }

    string giver;
    while (getline(fin, giver)) {
        int balance, ng;
        fin >> balance >> ng;
        getline(fin, newline);
        if (ng != 0) {
            int gain = balance / ng;
            balances[name_map[giver]] -= gain * ng;
            for (int i=0; i < ng; ++i) {
                string receiver;
                getline(fin, receiver);
                balances[name_map[receiver]] += gain;
            }
        }
    }

    for (int i=0; i < np; ++i) {
        fout << names[i] << ' ' << balances[i] << endl;
    }

    delete[] names;
    delete[] balances;
    return 0;
}
