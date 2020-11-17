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

long long solution(const std::string & barrels, std::vector<long long> & NK){
    long long answer = 0;
    auto n = NK[0];
    auto c0 = NK[1];
    auto c1 = NK[2];
    auto h = NK[3];
    short change_c1 = 0;
    if(c1 + h < c0){
        change_c1 = 1;
    }
    else if (c0 + h < c1){
        change_c1 = -1;
    }
    else{
        change_c1 = 0;
    }
    auto num1 = 0;
    auto num0 = 0;
    for(const auto &c: barrels){
        if(c == '1'){
            num1++;
        }
        else{
            num0++;
        }
    }
    int sum = 0;
    if(change_c1 == 1){
        sum += h*num0;
        num1 += num0;
        num0 = 0;
    }
    else if(change_c1 == -1){
        sum += h*num1;
        num0 += num1;
        num1 = 0;
    }
    sum += num0 * c0 + num1 * c1;
    return sum;
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
    int testcases = stoi(T);
    for(int i = 0; i < testcases; ++i){
        std::getline(std::cin, NK);
        std::istringstream iss1(NK);
        std::vector<long long> NM(std::istream_iterator<long long>(iss1), {});
        std::getline(std::cin, stones);
        auto sol = solution(stones, NM);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}