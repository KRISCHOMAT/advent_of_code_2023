#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Num{
    int val;
    int length;
    int index;
    int line;
};

struct Symbol{
    int line;
    int index;
    char symbol;
};

bool hasSymbol(Num &num, std::vector<Symbol> &symbols){
    for(Symbol symbol : symbols){
        if( (symbol.line == num.line || 
            symbol.line + 1 == num.line || 
            symbol.line -1 == num.line)
            &&
            (symbol.index >= num.index - 1 &&
            symbol.index <= num.index + num.length)
        ){
            return true;
        } 
    }
    return false;
}

int isEngine(Symbol &symbol, std::vector<Num> &nums){
    int numAmount = 0;
    int result = 0;
    if(symbol.symbol != '*') return -1;
    for(Num num : nums){
        if(numAmount > 2) return -1;
        if( (num.line == symbol.line || 
            num.line + 1 == symbol.line || 
            num.line -1 == symbol.line)
            &&
            (symbol.index >= num.index - 1 &&
            symbol.index <= num.index + num.length)
        ){
            //std::cout << num.val << " ";
            result = result == 0 ? result = num.val : result * num.val;
            numAmount ++;
        }
    }
    //std::cout << std::endl;
    return numAmount == 2 ? result : -1; 
}

int main() {
    int sum = 0;
    int sumB = 0;
    std::ifstream file("input.txt");
    std::string current_line;
    int lineId = 0;

    std::vector<Num> nums;
    std::vector<Symbol> symbols;

    while (getline(file, current_line)) {

        std::string currentNum;

        for(int i = 0; i < current_line.size(); i++){
            if(isdigit(current_line[i])){
                currentNum += current_line[i];
            } else if(current_line[i] != '.' && !isdigit(current_line[i])){
                Symbol symbol;
                symbol.index = i;
                symbol.line = lineId;
                symbol.symbol = current_line[i];
                symbols.push_back(symbol);
                if(!currentNum.empty()){
                    Num num;
                    num.val = stoi(currentNum);
                    num.index = i - currentNum.size();
                    num.length = currentNum.size();
                    num.line = lineId;
                    nums.push_back(num);
                    currentNum.clear();
                }
            } else if(!currentNum.empty()){
                Num num;
                num.val = stoi(currentNum);
                num.index = i - currentNum.size();
                num.length = currentNum.size();
                num.line = lineId;
                nums.push_back(num);
                currentNum.clear();
            }
            if(i == current_line.size() -1 && !currentNum.empty()){
                Num num;
                num.val = stoi(currentNum);
                num.index = i - currentNum.size();
                num.length = currentNum.size();
                num.line = lineId;
                nums.push_back(num);
                currentNum.clear();
            }
        }

        lineId++;
    }


    for(Num num : nums){
        if(hasSymbol(num, symbols)){
            sum += num.val;
        }
    }

    for(Symbol symbol : symbols){
        int engine = isEngine(symbol,nums);
        //std::cout << engine << " ";
        if(engine != -1){
            sumB += engine;
        }
    }

    //std::cout << std::endl;
    std::cout << "Result: " << sum << std::endl;
    std::cout << "ResultB: " << sumB << std::endl;

    return 0;
}
