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

    public: 
        std::string path;
        Directions current;
        void addNode(std::string pos, Directions& dirs){
            nodes[pos] = dirs;
        }

        Directions& getDirs(std::string pos){
            return nodes[pos];
        }

        void traverse(){
            bool found = false;
            current = nodes["AAA"];
            int attempts = 0;
            while(!found){
                for(char dir : path){
                    attempts++;
                    if(dir == 'L'){
                        if(current.left == "ZZZ"){
                            found = true;
                            break;
                        }
                        current = nodes[current.left];
                    } else {
                        if(current.right == "ZZZ"){
                            found = true;
                            break;
                        } 
                        current = nodes[current.right];
                    }   
                }
            }
            std::cout << "Attempts: " << attempts << std::endl;
        }



        void printAll(){
            for(const auto& pair : nodes){
                std::cout << "Position: " << pair.first 
                        << " Left: " << pair.second.left
                        << " Right: " << pair.second.right 
                        << std::endl;
            }        
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

    Directions& dirs = nodes.getDirs("AAA");

    nodes.traverse();

}