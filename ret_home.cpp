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

struct traverse
{
    long i;
    long j;
    long time;
};


long solution(const std::vector<std::vector<long>> & sides, std::vector<long> & NM, const std::vector<long> & coor){
    std::queue<traverse> xx;
    xx.emplace(traverse{coor[0], coor[1], 0});
    if(coor[0] == coor[2] && coor[1] == coor[3]){
        return 0;
    }
    std::vector<std::vector<long> > matrix(NM[0], std::vector<long>(NM[1], 1));
    for(const auto & c: sides){
        for(int i = 0; i < sides.size(); ++i){
            matrix[i][c[1]] = 0;
        }
        for(int i = 0; i < sides[0].size(); ++i){
            matrix[c[0]][i] = 0;
        }
    }
    long minTime = std::abs(coor[2] - coor[0]) + std::abs(coor[3] - coor[1]);
    while(!xx.empty()){
        auto temp = xx.front();
        xx.pop();
        if(temp.i == coor[2] && temp.j == coor[3]){
            minTime = std::min(minTime, temp.time + matrix[temp.i][temp.j]);
        }
        else{
            for(int i = -1; i <= 1; ++i){
                for(int j = -1; j <= 1; ++j){
                    if(!i && !j){
                        continue;
                    }
                    else{
                        if((temp.i + i) >= 0 && (temp.i + i) < sides.size() && (temp.j + j) >= 0 && (temp.j + j) < sides[0].size()){
                            if(matrix[temp.i + i][temp.j + j] != -1){
                                xx.emplace(traverse{(temp.i + i), (temp.j + j), (temp.time + matrix[temp.i][temp.j])});
                            }
                        }
                    }
                }
            }
        }
        matrix[temp.i][temp.j] = -1;
    }
    return minTime;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string stones;
    std::string coords;
    std::string NM;
    // //assuming that input txt doc is argv[1]
    // std::string inputTxt = argv[1];
    // // output txt doc is argv[2]
    // std::string outputTxt = argv[2];

    // std::ifstream inputFile(inputTxt);
    // std::ofstream outputFile(outputTxt);
    std::getline(std::cin, NM);
    std::istringstream iss1(NM);
    std::vector<long> nm(std::istream_iterator<long>(iss1), {});
    std::getline(std::cin, coords);
    std::istringstream iss3(coords);
    std::vector<long> coor(std::istream_iterator<long>(iss1), {});
    std::vector<std::vector<long>> curr_matrix;
    for(int i = 0; i < nm[1]; ++i){
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<long> e(std::istream_iterator<long>(iss2), {});
        curr_matrix.emplace_back(e);
    }
    auto sol = solution(curr_matrix, nm, coor);
    std::cout << std::to_string(sol) << "\n";
    
    // outputFile.close();
    // inputFile.close();

    return 0;
}