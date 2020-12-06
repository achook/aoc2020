#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> ids;
    fstream f;

    f.open("input.txt",ios::in);if (f.is_open()) {
        string line;

        while(getline(f, line)){
            int row;
            int min = 0, max = 127;

            for (int i = 0; i < 7; i++) {
                if (line[i] == 'B') {
                    min = max - ((max-min)/2);
                }

                if (line[i] == 'F') {
                    max = min + ((max-min)/2);
                }
            }

            if (max != min) {
                return 1;
            }
            row = min;

            int column;
            min = 0; max = 7;
            for (int i = 0; i < 10; i++) {
                if (line[i] == 'R') {
                    min = max - ((max-min)/2);
                }

                if (line[i] == 'L') {
                    max = min + ((max-min)/2);
                }
            }

            if (max != min) {
                return 1;
            }
            column = min;

            int id = row * 8 + column;

            ids.push_back(id);
        }

        f.close();
    }

    sort(ids.begin(), ids.end());

    int last = ids[0] - 1;

    for(vector<int>::iterator it = ids.begin(); it != ids.end(); it++) {
        if (*it != last + 1) {
            cout << "Your seat: " << last + 1 << endl;
            return 0;
        }
        last = *it;

    }

    return 1;
}