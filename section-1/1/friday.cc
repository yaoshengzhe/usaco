/*
  ID: yaoshen2
  LANG: C++
  TASK: friday
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N;
    fin >> N;
    int week[7] = {0};
    // Dec to Dec
    int days_of_month[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int prev_13th = 2; // Dec 13, 1899 is Wednesday
    for (int year=1900; year < 1900 + N; ++year) {
        bool is_leap = ( (year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0);
        for (int month=1; month < 13; ++month) {
            int carry = ((month == 3) && is_leap) ? 1 : 0;
            prev_13th = (days_of_month[month-1] + prev_13th + carry) % 7;
            week[prev_13th]++;
        }
    }

    for (int i=0; i < 6; ++i) {
        fout << week[(5+i) % 7] << ' ';
    }
    fout << week[4] << endl;
    return 0;
}
