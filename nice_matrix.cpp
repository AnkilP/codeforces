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

long long solution(const std::vector<std::vector<long long>> & sides, std::vector<long long> & NM){
    long long answer = 0;
    if(NM[0] % 2 != 0){
        NM[0]++;
    }
    if(NM[1] % 2 != 0){
        NM[1]++;
    }

    for(int j = 0; j < NM[1]/2; ++j){
        for(int i = 0; i < NM[0]/2; ++i){
            long long temp_mean = std::floor(static_cast<double>(sides[sides.size() - i - 1][j] + sides[i][sides[0].size() - j - 1] + sides[i][j] + sides[sides.size() - i - 1][sides[0].size() - j - 1])/4.0);
            if(i != sides.size() - i - 1){
                answer += std::abs(temp_mean - sides[sides.size() - i - 1][j]);
                answer += std::abs(temp_mean - sides[i][sides[0].size() - j - 1]);
            }
            answer += std::abs(temp_mean - sides[i][j]);
            answer += std::abs(temp_mean - sides[sides.size() - i - 1][sides[0].size() - j - 1]);
        }
    }
    return answer;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
    std::string NM;
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
        std::getline(std::cin, NM);
        std::istringstream iss1(NM);
        std::vector<long long> NM(std::istream_iterator<long long>(iss1), {});
        std::vector<std::vector<long long>> curr_matrix;
        for(int i = 0; i < NM[0]; ++i){
            std::getline(std::cin, stones);
            std::istringstream iss2(stones);
            std::vector<long long> e(std::istream_iterator<long long>(iss2), {});
            curr_matrix.emplace_back(e);
        }
        long long sol = solution(curr_matrix, NM);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}