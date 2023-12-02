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
        int red, green, blue;
        Round(std::string content):red(0), green(0), blue(0){
            size_t colors[3] = {content.find("red"),content.find("green"),content.find("blue")};
            for(int i = 0; i < 3; i++){
                if(colors[i] != std::string::npos){
                    std::string num;
                    if(isdigit(content[colors[i]-3])){
                        num += content[colors[i]-3];
                    }
                    num += content[colors[i]-2];
                    switch (i)
                    {
                    case 0:
                        red = std::stoi(num);
                        break;
                    case 1:
                        green = std::stoi(num);
                        break;
                    case 2:
                        blue = std::stoi(num);
                        break;
                    
                    default:
                        break;
                    }
                }
            }
        }
        bool isValid(){
            return (red <= TOTAL_RED && 
                    green <= TOTAL_GREEN && 
                    blue <= TOTAL_BLUE);
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