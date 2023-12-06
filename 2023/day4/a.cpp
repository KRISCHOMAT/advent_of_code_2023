#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(){

    std::ifstream file("input.txt");
    std::string line;
    int result = 0;

    while(getline(file,line)){

        size_t cardStart = line.find(":");
        size_t cardSplit = line.find("|");

        std::stringstream winningNumsStream(line.substr(cardStart + 1, cardSplit - cardStart - 1));
        std::stringstream chosenNumsStream(line.substr(cardSplit + 1));

        std::string currentNumWinning;
        std::string currentNumChosen;
        std::vector<int> numsWinning;
        std::vector<int> numsChosen;

        while(winningNumsStream >> currentNumWinning){
            numsWinning.push_back(stoi(currentNumWinning));
        }
        
        while(chosenNumsStream >> currentNumChosen){
            numsChosen.push_back(stoi(currentNumChosen));
        }

        int cardNum = 0;

        for(int i = 0; i < numsWinning.size(); i++){
            for(int y = 0; y < numsChosen.size(); y++){
                if(numsWinning[i] == numsChosen[y]){
                    cardNum = cardNum == 0 ? 1 : cardNum * 2;
                }
            }
        }

        result += cardNum;
    }

    std::cout << "Result: " << result << std::endl;

}