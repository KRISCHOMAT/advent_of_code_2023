#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ifstream file("input.txt");
    string line;
    int result = 0;

    while(getline(file, line)){
        vector<int> nums{};

        for (char c : line) {
            if (isdigit(c)) {
                nums.push_back(c - '0');
            }
        }

        string resultString;
        resultString += nums[0];
        resultString += nums[nums.size() - 1];
        result += stoi(resultString);
    }

    cout << result << endl;
}
