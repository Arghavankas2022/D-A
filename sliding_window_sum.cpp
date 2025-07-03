#include <iostream>
class Solution{
public:
    std::pair<int, int> sliding_window(std::vector<int>& nums,int k){
        int left = 0;
        int sum = 0;
        if(nums.size()==0){
            return {0,0};
        }
        for(int right=0; right<nums.size();++right){
            sum = sum + nums[right];
            
            while (sum > k && left <= right) {sum -= nums[left];
                ++left;
            }
            if (sum == k){
                return {left,right};
            }
            
            
        }
        return{-1,-1};
        
    }
    
    
};

int main(){
    std::vector<int> array = {2,3,1,2,2,3,4,6,7,6};
    int m = 7;
    Solution Sol;
    std::pair<int,int> value = Sol.sliding_window(array,m);
    std::cout << "Subarray with sum " << m << " is from index "
    << value.first << " to " << value.second << "\n";
    
    
}
 
