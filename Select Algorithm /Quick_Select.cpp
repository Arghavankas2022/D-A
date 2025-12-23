#include <iostream>
#include <vector>
int partition(std::vector<int>nums, int p, int left, int right ){

    int l = left;
    int r = right;
    int l_hat=-1;
    int r_hat=-1;

    while(true){
        while (nums[l]<p) l++;
        while (nums[r]>p) r--; 

        if (l>=r){
            if (l_hat>0) {std::swap(nums[l_hat], nums[r]); return r;}
            if (r_hat>0) {std::swap(nums[r_hat],nums[l]); return l;}
        }
        std::swap(nums[r],nums[l]);
        if (nums[l] == p) l_hat = l;
        if (nums[r] == p) r_hat = r;
        l++;
        r--;
    }
}

int select(std::vector<int> nums,int k, int left, int right){
    if (left==right) return nums[left];
    int pivot_index = right / 2;
    int pivot = nums[pivot_index];
    int m = partition(nums,pivot,left,right);
    if (k<m) select(nums,left,m-1,k);
    if (k>m) select(nums, right,m+1,k)

    else return nums[m];
}

int main(){
    std::vector<int> A={1,3,4,58,12};
    int k =3;
    int result = select(A, 0, A.size()-1,k);
    std::cout<<result;

}