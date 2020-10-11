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

template <typename T>
void printdebug(const T & dbg){
    std::cout << dbg << std::endl;
}

std::vector<long> solution(int N, std::vector<long> & e, const std::vector<long> & l) {
    std::priority_queue<long, std::vector<long>, std::greater<long> > pq;
    std::priority_queue<long> pq2;

    long total = 0;
    long running_total = 0;
    for(int i = 0; i < e.size(); ++i){
        running_total += e[i];
        if(l[i] == 0){
            total += e[i];
            pq.emplace(e[i]);
            pq2.emplace(e[i]);
        }
    }
    // printdebug<long>(total);
    // printdebug<long>(pq2.top());
    // printdebug<long>(pq.top());
    long running_prefix = 0;
    for(int i = 0; i < e.size(); ++i){
        if(l[i] == 0){
            if(running_prefix + pq2.top() >= abs(pq.top())){
                // printdebug<std::string>("yo");
                e[i] = pq2.top();
                running_prefix += pq2.top();
                pq2.pop();
            }
            else {
                if(total < 0){
                    e[i] = pq.top();
                    running_total += pq.top();
                    pq.pop();
                }
                else {
                    e[i] = pq2.top();
                    running_prefix += pq2.top();
                    pq2.pop();
                }
            }
        }
    }
    
    return e;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::string stones;
    std::string locks;
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
        N = stoi(T);
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<long> e(std::istream_iterator<long>(iss2), {});
        std::getline(std::cin, locks);
        std::istringstream iss3(locks);
        std::vector<long> l(std::istream_iterator<long>(iss3), {});
        auto sol = solution(N, e, l);
        for(const auto &c: sol){
            std::cout << std::to_string(c) << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    // outputFile.close();
    // inputFile.close();

    return 0;
}