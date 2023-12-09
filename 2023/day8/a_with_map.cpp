#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>



struct Directions{
    std::string left;
    std::string right;
};

class Nodes{
    private:
        std::map<std::string, Directions> nodes;
        Directions current;
        void updateCurrentPos(char dir, bool& found){
            if(dir == 'L'){
                if(current.left == "ZZZ"){
                    found = true;
                }
                current = nodes[current.left];
            } else {
                if(current.right == "ZZZ"){
                    found = true;
                } 
                current = nodes[current.right];
            }   
        }

    public: 
        std::string path;
        
        void addNode(std::string pos, Directions& dirs){
            nodes[pos] = dirs;
        }

        void traverse(){
            bool found = false;
            current = nodes["AAA"];
            int attempts = 0;
            while(!found){
                for(char dir : path){
                    attempts++;
                    updateCurrentPos(dir, found);
                }
                if(found) break;
            }
            std::cout << "Attempts: " << attempts << std::endl;
        }
};

int main(){

    std::ifstream file("input.txt");
    std::string line;
    std::string path;
    Nodes nodes;

    getline(file, path);

    nodes.path = path;

    while(getline(file,line)){
        if(line.size()){
            Directions dirs = {line.substr(7,3), line.substr(12,3)};
            nodes.addNode(line.substr(0,3), dirs);
        }
    }

    nodes.traverse();

}