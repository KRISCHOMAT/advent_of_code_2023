#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {

    int result = 1;

    std::ifstream file("input.txt");
    std::string timeString;
    std::string distanceString;

    std::vector<int> distances;
    std::vector<int> times;

    std::string timeB, distanceB;

    getline(file, timeString);
    getline(file, distanceString);

    size_t cardStart;

    cardStart = timeString.find(":");
    timeString = timeString.substr(cardStart + 1);

    cardStart = distanceString.find(":");
    distanceString = distanceString.substr(cardStart + 1); 

    std::stringstream timeStringStream(timeString);
    std::stringstream distanceStringStream(distanceString);
    std::string currentTime;
    std::string currentDistance;

    while(timeStringStream >> currentTime){
        timeB += currentTime;
        times.push_back(stoi(currentTime));
    }

    while(distanceStringStream >> currentDistance){
        distanceB += currentDistance;
        distances.push_back(stoi(currentDistance));
    }

    for(int i = 0; i < distances.size(); i++){
        int time = times[i];
        int bestDistance = distances[i];
        int options = 0;
        for(int y = 1; y < time; y++){
            int remainingTime = time - y;
            int distance = remainingTime * y;
            if(distance > bestDistance){
                options++;
            }

        }
        result *= options;
    }
    std::cout << result << std::endl;

    // Part B
    int options = 0;
    long time = stol(timeB);
    long bestDistance = stol(distanceB);
    for(int i = 1; i < time; i++){
        long remainingTime = time - i;
        long distance = remainingTime * i;
        if(distance > bestDistance){
            options++;
        }
    }
    std::cout << options << std::endl;

}
