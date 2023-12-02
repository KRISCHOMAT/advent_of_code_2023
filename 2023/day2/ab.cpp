#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define TOTAL_RED 12
#define TOTAL_GREEN 13
#define TOTAL_BLUE 14

class Round{
    public:
        int red;
        int green;
        int blue;
        Round(std::string content):red(0), green(0), blue(0){
            size_t r = content.find("red");
            size_t g = content.find("green");
            size_t b = content.find("blue");
            if(r != std::string::npos){
                std::string num;
                if(isdigit(content[r-3])){
                    num += content[r-3];
                }
                num += content[r-2];
                red = std::stoi(num);
            }
            if(g != std::string::npos){
                std::string num;
                if(isdigit(content[g-3])){
                    num += content[g-3];
                }
                num += content[g-2];
                green = std::stoi(num);
            }
            if(b != std::string::npos){
                std::string num;
                if(isdigit(content[b-3])){
                    num += content[b-3];
                }
                num += content[b-2];
                blue = std::stoi(num);
            }
        }
        bool isValid(){
            return (red <= TOTAL_RED && 
                    green <= TOTAL_GREEN && 
                    blue <= TOTAL_BLUE
                    );
        }
        void print(){
            std::cout << "red: " << red << " green: " << green << " blue: " << blue << " | ";
        }
};

int main(){

    std::ifstream file("input.txt");
    std::string line;
    int result = 0;
    int roundNum = 1;
    int powers = 0;

    while(getline(file,line)){

        size_t start = line.find(":") + 1;
        size_t end = line.find(";" , start);

        std::vector<std::string> roundContents;

        while(end != std::string::npos){
            roundContents.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find(";", start);
        }
            roundContents.push_back(line.substr(start, end - start));

        bool isValid = true;
        int minRed = 0, minGreen = 0, minBlue = 0;

        for(std::string content : roundContents){
            Round round(content);
            if(!round.isValid()){
                isValid = false;
            }

            if(round.red > minRed){
                minRed = round.red;
            }
            if(round.green > minGreen){
                minGreen = round.green;
            }
             if(round.blue > minBlue){
                minBlue = round.blue;
            }           
        }

        powers += minRed * minGreen * minBlue;

        if(isValid){
            result += roundNum;
        }
        roundNum ++;
    }

    std::cout << "ResultA: " << result << std::endl;
    std::cout << "ResultB: " << powers << std::endl;

}