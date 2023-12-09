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
        std::vector<Node> ghosts;
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
                    }
                }
            } else if(direction == 'L'){
                for(int i = 0 ; i < nodes.size(); i++){
                    if(nodes[i].position == current.left){
                        current = nodes[i];
                        return true;
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
                for(char dir : path){
                    findNextNode(dir);
                    pathLength++;
                    if(current.position == "ZZZ") break;
                }
            }
        }

        void findGhostStarts(){
            for(Node node : nodes){
                if(node.position[2] == 'A'){
                    ghosts.push_back(node);
                }
            }
        }

        void printGhosts(){
            for(Node ghost : ghosts){
                std::cout << ghost.position << " ";
            }
            std::cout << std::endl;
        }

        void findNextGhosts(){
            bool isEnd = false;
            long long times = 0;
            while(!isEnd){
                for(char dir : path){
                    times++;
                    for(Node& ghost : ghosts){
                        for(const Node& node : nodes){
                            if(dir == 'L' && ghost.left == node.position){
                                ghost = node;
                                break;
                            } else if(dir == 'R' && ghost.right == node.position){
                                ghost = node;
                                break;
                            }
                        }
                    }

                    for(Node ghost : ghosts){
                        if(ghost.position[2] == 'Z'){
                            isEnd = true;
                        } else {
                            isEnd = false;
                            break;
                        }
                    }
                    if(isEnd) break;
                }
            }

            std::cout << "times: " << times << std::endl;
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
    // nodes.findGhostStarts();
    // nodes.findNextGhosts();
    // nodes.printGhosts();

}