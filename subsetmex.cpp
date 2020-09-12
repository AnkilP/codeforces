#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <utility>

int solution(const int & N, const std::vector<int> & nums) {
    
}

int main(int argc, char * argv[]){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
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
        T.clear();
        std::getline(std::cin, T);
        std::istringstream iss(T);
        iss >> N;
        stones.clear();
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<int> e(std::istream_iterator<int>(iss2), std::istream_iterator<int>());
        auto sol = solution(N, stones);
        std::cout << sol;
        std::cout << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}