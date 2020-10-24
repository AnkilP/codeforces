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


long long __findKthLargest(std::vector<long long>& nums, long long k, long long start, long long end) {
    if (start == end)
        return nums[start];
    auto pivot = nums[(start + end) / 2];
    auto i = start, j = end;
    // perform the partitioning
    while (i <= j) {
        while (nums[i] > pivot)
            i++;
        while (nums[j] < pivot)
            j--;
        if (i <= j) {
            std::swap(nums[i], nums[j]);
            i++, j--;
        }
    }
    // after partition, the elements left to j are the largest(unordered), and
    // the elements right to i are the smallest(unordered). However, we still 
    // need to check if i or j has gone beyond the border.
    auto left = j - start + 1, right = end - i + 1;
    if (left > 0) { // the j index is valid
        if (left >= k) // there are enough elements left to j, find the kth largest there!
            return __findKthLargest(nums, k, start, j);
        else // the kth largest must lie on the right of index j, discard the ones left to j!
            return __findKthLargest(nums, k - left, j + 1, end);
    } else {
        if ((end - start + 1) - right >= k)
            return __findKthLargest(nums, k, start, i - 1);
        else
            return __findKthLargest(nums, k - (end - start + 1 - right), i, end);
    }
}

long long solution(std::vector<long long> & barrels, std::vector<long long> & NK){
    long long answer = 0;
    auto k = NK[1];
    __findKthLargest(barrels, k + 1, 0, barrels.size() - 1);
    for(int i = 0; i < k + 1; ++i){
        answer += barrels[i];
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
        std::vector<long long> NM(std::istream_iterator<long long>(iss1), {});
        std::getline(std::cin, stones);
        std::istringstream iss2(stones);
        std::vector<long long> e(std::istream_iterator<long long>(iss2), {});
        auto sol = solution(e, NM);
        std::cout << std::to_string(sol) << "\n";
    }
    // outputFile.close();
    // inputFile.close();

    return 0;
}