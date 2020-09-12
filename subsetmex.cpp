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

template <typename T>
void printdebug(const T & dbg){
    std::cout << dbg << std::endl;
}

int solution(const int & N, std::vector<int> & nums) {
    std::sort(nums.begin(), nums.end());
    auto min1 = 0;
    auto min2 = 0; 
    auto pointer = 0;
    bool mex1 = false;
    bool mex2 = false;

    if(nums.size() == 1) {
        return 1;
    }
    else if(nums.size() == 0) {
        return 0;
    }
    else {
        while(mex1 == false || mex2 == false) {
            //printdebug<std::string>("Beginning of loop");
            if(pointer >= nums.size()){
                //printdebug<std::string>("mex1 stop");
                mex1 = true;
            }
            else if(nums[pointer] <= min1 && mex1 == false){
                //printdebug<std::string>("lol what");
                if(nums[pointer++] == min1){
                    min1++;
                }
            }
            else {
                //pointer1 can stop moving
                //printdebug<std::string>("mex1 check triggered");
                mex1 = true;
            }
            //printdebug<int>(min1);
            if(pointer >= nums.size()){
                //printdebug<std::string>("mex2 stop");
                mex2 = true;
            }
            else if(nums[pointer] <= min2 && mex2 == false) {
                //printdebug<std::string>("lol what 2");
                if(nums[pointer++] == min2){
                    min2++;
                }
            }
            else {
                //printdebug<std::string>("check triggered");
                mex2 = true;
            }
            //printdebug<int>(min2);
        }
    }
    //printdebug<std::string>("End of loop");
    //printdebug<int>(min1);
    //printdebug<int>(min2);
    return min1 + min2;
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
        std::vector<int> e(std::istream_iterator<int>(iss2), {});
        auto sol = solution(N, e);
        std::cout << sol;
        std::cout << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}