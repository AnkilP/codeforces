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

long solution(const std::vector<long> & sides){
    return *std::max_element(sides.begin(), sides.end());
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
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
        std::istringstream iss2(stones);
        std::vector<long> e(std::istream_iterator<long>(iss2), {});
        auto sol = solution(e);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}