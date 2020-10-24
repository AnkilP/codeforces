#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>

bool isCycle(const std::string &){

}

long long solution(const int & t, const std::string & f){
    std::map<int, std::vector<int>> adj_list;
    for(int i = 0; i < f.length(); ++i){
        if(f[i] == '-'){
            adj_list[i].emplace_back((i + 1) % t);
            adj_list[(i + 1) % t].emplace_back(i);
        }
        else if(f[i] == '>'){
            adj_list[i].emplace_back((i + 1) % t);
        }
        else{
            adj_list[(i + 1) % t].emplace_back(i);
        }
    }
    long long sum = 0;
    for(int i = 0; i < t; ++i){ 
        std::vector<int> visited(t, 0);
        std::queue<int> bfs_queue;
        while(!bfs_queue.empty()){
            auto x = bfs_queue.front();
            bfs_queue.pop();
            visited[x]++;
        }
        if(visited[i] > 0){
            sum++;
        }
    }
    return sum;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
    std::string conveyor;
    // //assuming that input txt doc is argv[1]
    // std::string inputTxt = argv[1];
    // // output txt doc is argv[2]
    // std::string outputTxt = argv[2];

    // std::ifstream inputFile(inputTxt);
    // std::ofstream outputFile(outputTxt);

    std::string T;
    std::getline(std::cin,T);
    int testcases = stoi(T);
    for(int i = 0; i < testcases; ++i){
        std::getline(std::cin, stones);
        std::getline(std::cin, conveyor);
        auto sol = solution(stoi(stones), conveyor);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}