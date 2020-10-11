#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

template <typename T>
void printdebug(const T & dbg){
    std::cout << dbg << std::endl;
}

double distance(std::vector<long> & coord1, std::vector<long> & coord2){
    auto dx = coord1[0] - coord2[0];
    auto dy = coord1[1] - coord2[1];
    return sqrt(dx*dx + dy*dy);
}

typedef struct container {
    double distance_con;
    int i;
    int j;
} distance_container;

std::vector<long> solution(const std::vector<long> & sp, const std::vector<std::vector<long>> & coords) {
    std::priority_queue<distance_container, std::vector<distance_container>, std::greater<distance_container>> edges;
    for(int i = 0; i < coords.size(); ++i){
        for(int j = i+ 1; j < coords.size(); ++j){
            auto dist = distance(coords[i], coords[j]);
            edges.push(distance_container{dist, i, j});
        }
    }
}

int main(int argc, char* argv[]){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
    std::string locks;
    //assuming that input txt doc is argv[1]
    std::string inputTxt = argv[1];
    // output txt doc is argv[2]
    std::string outputTxt = argv[2];

    std::ifstream inputFile(inputTxt);
    std::ofstream outputFile(outputTxt);

    std::string T;
    std::getline(inputFile,T);
    int testcases = stoi(T);
    for(int i = 0; i < testcases; ++i){
        T.clear();
        std::getline(inputFile, stones);
        std::istringstream iss2(stones);
        std::vector<long> sp(std::istream_iterator<long>(iss2), {});
        std::vector<std::vector<long>> coords;
        for(auto i = 0; i < sp[1]; ++i){
            std::getline(inputFile, locks);
            std::istringstream iss3(locks);
            std::vector<long> l(std::istream_iterator<long>(iss3), {});
            coords.emplace_back(l);
        }
        auto sol = solution(sp, coords);
        for(const auto &c: sol){
            std::cout << std::to_string(c) << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    // outputFile.close();
    // inputFile.close();

    return 0;
}