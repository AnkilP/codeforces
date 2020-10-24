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

long long average(const long long x, const long long y){
    return static_cast<long long>(ceil((x + y)/2));
}

long long solution(int N, std::vector<std::pair<long long, long long >> & t){
    if(N == 0){
        return 0;
    }
    long long average;
    std::deque<long long> test;
    for(int i = 1; i <= N; ++i){
        test.emplace_back(i);
    }
    long long hold = -1;
    while(N){
        auto x = test.front();
        test.pop_back();
        if(x % 2 == 0){

        }        
    }
    return average;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string NK;
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
        std::vector<std::pair<long long, long long >> x;
        std::getline(std::cin, NK);
        auto sol = solution(stoi(NK), x);
        std::cout << std::to_string(sol) << "\n";
        for(const auto & c: x){
            std::cout << std::to_string(c.first) << " " << std::to_string(c.second) << "\n";
        }
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}