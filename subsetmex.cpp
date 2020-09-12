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

int solution(const int & N, std::vector<int> & nums) {
    std::sort(nums.begin(), nums.end());
    auto min1 = 0;
    auto min2 = 0; 
    auto pointer1 = 0;
    auto pointer2 = 1;
    bool mex1 = false;
    bool mex2 = false;

    if(nums.size() == 1) {
        return 1;
    }
    else if(nums.size() == 0) {
        return 0;
    }
    else {
        while((pointer1 <= nums.size() && pointer2 <= nums.size()) || (mex1 == true && mex2 == true)) {
            if(nums[pointer1] == min1 && mex1 == false){
                int step = 1;
                if(mex2 == true) {
                    pointer1 = pointer1 + step;
                }
                pointer1 = pointer1 + step + 1;
                min1++;
            }
            else {
                //pointer1 can stop moving
                mex1 = true;
            }

            if(nums[pointer2] == min2 && mex2 == false) {
                int step = 1;
                if(mex1 == true) {
                    pointer2 = pointer2 + step;
                }
                pointer2 = pointer2 + step + 1;
                min2++;
            }
            else {
                mex2 = true;
            }
        }
    }
    return min1 + mn2;
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