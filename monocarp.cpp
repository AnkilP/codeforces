#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

// std::vector<int> getTriple(const std::vector<int> weights, const int W, const int three, const int five, const int seven){
//     std::vector<int> result;
//     result.emplace_back(three);
//     result.emplace_back(five);
//     result.emplace_back(seven);
//     result.emplace_back(W - seven * weights[2] - five * weights[1] - three * weights[0]);
//     return result;
// }

std::vector<int> solution(int W){
    std::vector<int> result(3, 0);
    std::map<int, std::vector<int>, std::greater<int>> a;
    a[0] = std::vector<int>{0};
    a[3] = std::vector<int>{3};
    a[5] = std::vector<int>{5};
    a[6] = std::vector<int>{3,3};
    a[7] = std::vector<int>{7};
    a[8] = std::vector<int>{3,5};
    a[9] = std::vector<int>{3,3,3};
    a[10] = std::vector<int>{5,5};
    a[11] = std::vector<int>{3,5,3};
    a[12] = std::vector<int>{5,7};
    while(W){
        for(const auto & c: a){
            if(c.first == 0){
                continue;
            }
            auto addend = static_cast<int>(floor(W/c.first));
            auto rem = W % c.first;
            if(a.find(rem) != a.end()){
                for(const auto & d: c.second){
                    if(d == 3){
                        result[0] += addend;
                    }
                    else if(d == 5){
                        result[1] += addend;
                    }
                    else{
                        result[2] += addend;
                    }
                }
                W -= c.first * addend;
                if(rem == 0){
                    break;
                }
                else{
                    for(const auto & d: a[rem]){
                        if(d == 3){
                            result[0] += 1;
                        }
                        else if(d == 5){
                            result[1] += 1;
                        }
                        else{
                            result[2] += 1;
                        }
                    }
                }
                W -= rem;
                break;
            }
        }
        break;
    }
    if(W > 0){
        return std::vector<int>{-1};
    }
    else{
        return result;
    }
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
        auto sol = solution(stoi(NM));
        for(const auto & c: sol){
            std::cout << std::to_string(c) << " ";    
        }
        std::cout << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}