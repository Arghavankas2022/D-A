// Includes all algorithms discussed in D&A for selection

#include <iostream>
#include <algorithm>
#include <cstdlib>


class Solution {
    
public:
    
    // Finding min and max simultaneously
    // 3n/2 comparisons
    
    int select_sim(std::vector<int>& nums, int& max) {
        int min = nums[0];
        max = nums[0];
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            if (nums[2*i] < nums[2*i + 1]) {
                if (nums[2*i] < min) min = nums[2*i];
                if (nums[2*i + 1] > max) max = nums[2*i + 1];
            } else {
                if (nums[2*i] > max) max = nums[2*i];
                if (nums[2*i + 1] < min) min = nums[2*i + 1];
            }
        }

        if (n % 2 != 0) {
            if (nums[n-1] < min) min = nums[n-1];
            if (nums[n-1] > max) max = nums[n-1];
        }

        return min;
    }
    
    // Partition algorithm without keeping track of pivot
    
    int partition_simple(std::vector<int>& nums, int p ){
        int l = 1;
        int r = nums.size()-1;
        
        while(true){
            while (nums[l]<p) {
                l = l+1;
            }
            while (nums[r]>p) {
                r = r-1;
            }
            if (l>=r){
                return r;
            }
            std::swap(nums[l],nums[r]);
            l = l+1;
            r = r-1;
            
        }
    }
    //Ensures that pivot is exactly at index m
    int partition(std::vector<int>& nums, int p){
        int l = 1;
        int l_hat = 0;
        int r_hat = 0;
        int r = nums.size()-1;
        while (true){
            while (nums[l]<p) {
                l = l+1;
            }
            while (nums[r]>p) {
                r = r-1;
            }
            if (l>=r){
                if (l_hat!=0){
                    std::swap(nums[l_hat], nums[r]);
                    return r;
                    
                }
                if (r_hat!=0){
                    std::swap(nums[r_hat],nums[l]);
                    return l;
                }
            }
            std::swap(nums[l],nums[r]);
            if (nums[l] == p) l_hat =l;
            if (nums[r] == p) r_hat =r;
            l = l+1;
            r = r+1;
        }
    }
    
    //Find a random pivot
    int RandomPivot( std::vector<int> nums){
        int k =1;
        int n = nums.size();
        
        int randomIndex = rand() % n;  // pick random index
        int p = nums[randomIndex];
        
        while (true) {
            
            for (int j=1; j<n;++j) {
                if (nums[j]<=p) {
                    k=k+1;
                }
                
            }
            if (k >= n / 4 && k <= 3 * n / 4) {
                return p;
            }
        }
        
    }
    
    int QuickSelect(std::vector<int> nums, int k) {
        int n = nums.size()-1;
        if (n == 1) {
            return nums[0];  // base case: return the only element
        }

        int p = RandomPivot(nums);      // select a good pivot
        int m = partition(nums, p);     // partition around p

        if (k < m) {
            std::vector<int> left(nums.begin(), nums.begin() + m);
            return QuickSelect(left, k);
        } else if (k > m) {
            std::vector<int> right(nums.begin() + m + 1, nums.end());
            return QuickSelect(right, k - m - 1);
        } else {
            return p;
        }
    }

    
    
    
    
    

};


int main() {
    std::vector<int> array = {2, 3, 4, 8, 10, 5, 9};
    Solution Sol;
    int maxVal;
    int minVal = Sol.select_sim(array, maxVal);
    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;
    
    int k = Sol.partition_simple(array,5);
    std::cout << "Partition index: " << k << "\n";
    
    int m = Sol.partition(array,5);
    std::cout << "Partition index of algo 2: " << m << "\n";
    std::cout << "Partitioned array: ";
        for (int x : array) std::cout << x << " ";
        std::cout << std::endl;
    
    int random_pivot = Sol.RandomPivot(array);
    std::cout << "Random Pivot"<< random_pivot<<"\n";
    
    int rank = 3;
    int value = Sol.QuickSelect(array,rank);
    std::cout <<"largest 3rd element is "<<value<<"\n";
    
    
}
