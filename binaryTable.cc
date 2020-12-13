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


void printMatrix(const std::vector<std::vector<short>> & matrix){
    for(const auto & c: matrix){
        for(const auto & d: c){
            std::cout << d << " ";
        }
        std::cout << "\n";
    }
}

void addCoords(int i, int j, std::vector<int> & coords){
    coords.emplace_back(i);
    coords.emplace_back(j);
}

std::vector<std::vector<int>> solution(std::vector<std::vector<short>> & grid){
    std::vector<std::vector<int>> answer;
    for(int i = 0; i < grid.size() - 1; ++i){
        for(int j = 0; j < grid[0].size() - 1; ++j){
            short count = 3;
            std::vector<int> coords;
            if(grid[i][j] == 1 && count){
                grid[i][j] = 0;
                addCoords(i+1,j+1,coords);
                count--;
            }
            if(grid[i+1][j] == 1 && count){
                grid[i+1][j] = 0;
                addCoords(i+2, j+1, coords);
                count--;
            }
            if(grid[i+1][j+1] == 1 && count){
                grid[i+1][j+1] = 0;
                addCoords(i+2, j+2, coords);
                count--;
            }
            if(grid[i][j+1] == 1 && count){
                grid[i][j+1] = 0;
                addCoords(i+1, j+2, coords);
                count--;
            }
            if(count < 3 && count > 0){
                
            }
            answer.emplace_back(coords);
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
    int testcases = stoi(T);
    for(int i = 0; i < testcases; ++i){
        std::getline(std::cin, NK);
        std::istringstream iss1(NK);
        std::vector<int> NM(std::istream_iterator<int>(iss1), {});
        std::vector<std::vector<short>> grid(NM[0]);
        for(int i = 0; i < NM[0]; ++i){
            std::getline(std::cin, NK);
            std::vector<short> x(NM[1], 0);
            for(int j = 0; j < x.size(); ++j){
                NK[j] == '1' ? x[j] = 1 : x[j] = 0;
            }
            grid[i] = x;
        }
        auto sol = solution(grid);
        std::cout << std::to_string(sol.size()) << "\n";
        for(const auto & c: sol){
            for(const auto &d: c){
                std::cout << d << " ";
            }
            std::cout << "\n";
        }
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}