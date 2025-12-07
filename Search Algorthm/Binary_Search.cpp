#include <iostream>
#include <vector>
// binary seatch of ascending sorted array 
int binarySearchRec(const std::vector<int>& nums, int left, int right, int k) {
    if (left > right) return -1;

    int m = left + (right - left) / 2;

    if (nums[m] == k)
        return m;
    else if (k < nums[m])
        return binarySearchRec(nums, left, m - 1, k);
    else
        return binarySearchRec(nums, m + 1, right, k);
}

int main(){
    std::vector<int> nums = {1, 3, 5, 7, 9};
    std::cout << binarySearchRec(nums, 0, nums.size()-1, 5) ;

}