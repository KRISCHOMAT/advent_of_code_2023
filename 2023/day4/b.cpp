#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(){
    std::ifstream file("input.txt");
    std::string line;
    int result = 0;
    int currentCard = 0;
    std::vector<int> cards = {0};

    while(getline(file,line)){
        cards[currentCard]++;

        size_t cardStart = line.find(":");
        size_t cardSplit = line.find("|");

        std::stringstream winningNumsStream(line.substr(cardStart + 1, cardSplit - cardStart - 1));
        std::stringstream chosenNumsStream(line.substr(cardSplit + 1));

        std::string currentNumWinning;
        std::string currentNumChosen;

        int winningNums = 0;
        while(winningNumsStream >> currentNumWinning){
            chosenNumsStream.clear();
            chosenNumsStream.seekg(0, std::ios::beg);
            while(chosenNumsStream >> currentNumChosen){
                if(currentNumChosen == currentNumWinning){
                    winningNums++;
                }
            }
        }

        if(currentCard + 1 > cards.size()){
            cards.push_back(1);
        }

        for(int x = 0; x < cards[currentCard]; x++ ){
            for(int i = 1; i <= winningNums; i++){
                if(currentCard + i + 1 > cards.size()){
                    cards.push_back(1);
                } else {
                    cards[currentCard + i]++;
                }
            }
        }

        currentCard++;
    }

    for(int i = 0; i < cards.size(); i++){
        result += cards[i];
    }

    std::cout << "Result: " << result << std::endl;
}