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


int solution(std::vector<int> & list){
    std::sort(list.begin(), list.end());
    int left = 0;
    int right = 0;
    while(left < right){
        auto sum = list[left] + list[right];
        if(sum == 2020){
            return list[left] * list[right];
        }
        else if(sum < 2020){
            left++;
        }
        else{
            right--;
        }
    }
    return -1;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string in;
    std::vector<int> list;
    while(std::getline(std::cin, in)){
        list.emplace_back(stoi(in));
    }
    auto result = solution(list);
    std::cout << result << std::endl;
    // outputFile.close();
    // inputFile.close();

    return 0;
}