#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string numStrings[10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    ifstream file("input.txt");
    string line;
    int finalResult = 0;

    while (getline(file, line)) {

        int results[2][2] = { { -1,-1 },{ -1,-1 } };

        // find first
        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) {
                results[0][0] = line[i] - '0';
                results[0][1] = i;
                break;
            };
        }

        // find last
        for (int i = line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                results[1][0] = line[i] - '0';
                results[1][1] = i;
                break;
            }
        }

        // handle string nums
        for (int i = 0; i < 10; i++) {
            size_t index = line.find(numStrings[i]);
            while (index != string::npos) {
                if (index < results[0][1] || results[0][1] == -1) {
                    results[0][0] = i;
                    results[0][1] = index;
                }
                if (index > results[1][1] || results[1][1] == -1) {
                    results[1][0] = i;
                    results[1][1] = index;
                }
                index = line.find(numStrings[i], index + 1);
            }
        }

        string resultString;
        resultString += to_string(results[0][0]);
        resultString += to_string(results[1][0]);

        finalResult += stoi(resultString);
    }

    cout << finalResult << endl;

    return 0;
}
