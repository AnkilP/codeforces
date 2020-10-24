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

long long solution(std::vector<long> & t){
    auto x1 = t[0];
    auto y1 = t[1];
    auto x2 = t[2];
    auto y2 = t[3];
    auto dx = std::abs(x2 - x1);
    auto dy = std::abs(y2 - y1);
    auto sum = dx + dy;
    if(dx && dy){
        sum += 2;
    }
    return static_cast<long long>(sum);
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