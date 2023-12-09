#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Node{
        std::string position;
        std::string left;
        std::string right;
};

class Nodes{
    private:
        std::vector<Node> nodes;
        Node current;
        
        void setCurrent() {
            for(int i = 0; i < nodes.size(); i++){
                if(nodes[i].position == "AAA"){
                    current = nodes[i];
                }
            }
        };

        bool findNextNode(char direction) {
            if(direction == 'R'){
                for(int i = 0 ; i < nodes.size(); i++){
                    if(nodes[i].position == current.right){
                        current = nodes[i];
                        return true;
                        break;
                    }
                }
            } else if(direction == 'L'){
                for(int i = 0 ; i < nodes.size(); i++){
                    if(nodes[i].position == current.left){
                        current = nodes[i];
                        return true;
                        break;
                    }
                }
            }
            return false;
        }

    public: 
        std::string path;
        int pathLength = 0;
        void addNode(Node &node){
            nodes.push_back(node);
        }
        void printNodes(){
            for(int i = 0; i < nodes.size(); i++){
                std::cout   << nodes[i].position << " " 
                            << nodes[i].left << " " 
                            << nodes[i].right << std::endl;
            }
        }

        void traverse(){
            setCurrent();
            while(current.position != "ZZZ"){
                for(int i = 0; i < path.size(); i++){
                    findNextNode(path[i]);
                    pathLength++;
                    if(current.position == "ZZZ") break;
                }
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
            Node node = {line.substr(0,3), line.substr(7,3), line.substr(12,3)};
            nodes.addNode(node);
        }
    }

    nodes.traverse();

    std::cout << "Result: " << nodes.pathLength << std::endl;
}