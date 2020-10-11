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
typedef long long ll;

long long solution(const std::vector<long long> & arr) { //arr = [x, y, k]
    ll y = arr[1];
    ll k = arr[2];
    ll x = arr[0];
    ll sticks_needed = k*(y+1);
    long long curr = 1;
    long long num = 0;
    num = (sticks_needed-1)/(x-1) + ((sticks_needed-1) % (x-1) != 0);
    num = num + k;
    return num;
}

int main(){
    
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
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<long long> e(std::istream_iterator<long long>(iss2), {});
        auto sol = solution(e);
        std::cout << sol;
        std::cout << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}