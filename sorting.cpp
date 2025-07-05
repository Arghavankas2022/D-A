// Includes are algorithms introduced in lecture 5
#include <iostream>
#include <algorithm>

class Solution  {
public:
    
    //SelectionSort with n^2 complexity and n comparisons
    std::vector<int> SelectionSort (std::vector<int> nums){
        int n = nums.size();
        for (int i=0; i<n;++i){
            int p =i;
            
            for (int j=i+1;j<n;++j){
                if (nums[j]<nums[p]){
                    p = j;
                }
            }
            std::swap(nums[i],nums[p]);
        }
        return nums;
    }
    
};

int main(){
    
    Solution Sol;
    std::vector<int> array={3,5,6,2,7,4,3,19,3,22};
    std::vector<int> sorted = Sol.SelectionSort(array);
        std::cout << "Sorted array: ";
        for (int num : sorted) {
            std::cout << num << " ";
        }
        std::cout << std::endl;}





