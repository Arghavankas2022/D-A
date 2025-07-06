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
    
    // Merge
        std::vector<int> Merge(std::vector<int> X, std::vector<int> Y) {
            int n = X.size();
            int l = Y.size();
            int x = 0, y = 0, z = 0;
            
            std::vector<int> Z(n + l);
            
            while ((x < n) && (y < l)) {
                if (X[x] <= Y[y]) {
                    Z[z] = X[x];
                    x++;
                } else {
                    Z[z] = Y[y];
                    y++;
                }
                z++;
            }

            while (x < n) {
                Z[z] = X[x];
                x++;
                z++;
            }

            while (y < l) {
                Z[z] = Y[y];
                y++;
                z++;
            }

            return Z;
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
        std::cout << std::endl;
        
        std::vector<int> X = {3,4,2,5,6,7,23,1};
        std::vector<int> Y = {4,5,6,31,2,3,8};
        std::vector<int> merged = Sol.Merge(X,Y);
        std::cout << "merged array: ";
        for (int num : merged) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        
    }




