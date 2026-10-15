#include <vector>
void moveZeroes(std::vector<int>& nums){
    int zero = 0, n = nums.size();
    for(int i=0; i<n; ++i){
        if(nums[i]!=0){
            if(i>zero){
                std::swap(nums[i], nums[zero]);
            }
            ++zero;
            continue;
        }
    }
}