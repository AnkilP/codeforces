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

long long solution(const std::vector<long long> & barrels, const std::vector<long long> & NK){
    if(NK[0] == 1){
        long long sum = 0;
        for(const auto & c: barrels){
            sum += c;
        }
        return sum;
    }
    long long answer = 0;
    long long n = NK.at(0)/2 + 1;
    n = std::max(n, static_cast<long long>(2));
    long long k = NK.at(1);
    long long iter = 1;
    long long count = 0;
    for(long long i = barrels.size() - 1; i >= 0; --i){
        if(iter < n){
            iter++;
            continue;
        }
        else{
            answer += barrels[i];
            iter = 1;
            count++;
            if(count == k){
                return answer;
            }
        }
    }
    return answer;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
    std::string NK;
    // //assuming that input txt doc is argv[1]
    // std::string inputTxt = argv[1];
    // // output txt doc is argv[2]
    // std::string outputTxt = argv[2];

    // std::ifstream inputFile(inputTxt);
    // std::ofstream outputFile(outputTxt);

    std::string T;
    std::getline(std::cin,T);
    long long testcases = stoi(T);
    for(long long i = 0; i < testcases; ++i){
        std::getline(std::cin, NK);
        std::istringstream iss1(NK);
        std::vector<long long> NM(std::istream_iterator<long long>(iss1), {});
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<long long> s(std::istream_iterator<long long>(iss2), {});
        auto sol = solution(s, NM);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}