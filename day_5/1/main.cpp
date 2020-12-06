#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream f;
    int highest = -1;

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

            if (id > highest) {
                highest = id;
            }
        }

        f.close();
    }

    cout << "Highest ID: " << highest << endl;
}