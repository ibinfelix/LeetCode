#include <vector>
#include <math.h>
std::vector<int> productExceptSelf(std::vector<int>& nums){
    int n = nums.size(), 
        acc = 1;
    std::vector<int> p(n);
    for(int i=0, left = 1; i<n; ++i){
        p[i] = left;
        left *= nums[i];
    }
    acc = 1;
    for(int i=n-1, right = 1; i>=0; --i){
        p[i] *= right;
        right *= nums[i];
    }
    return p;
}

int main(){
    std::vector<int> 
        input = {1,2,3,4},
        output = productExceptSelf(input);
    return 0;
}