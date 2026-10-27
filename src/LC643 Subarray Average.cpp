#include <vector>
double findMaxAverage(std::vector<int>& nums, int k) {
    double  max = -__INT_MAX__, 
            sum = 0;
    int     i = 0,  j = 0;
    while(j<nums.size()){
        if(j -i < k){
            sum += (double) nums[j];
            ++j;
        }else{
            if(sum>max) max = sum;
            sum -= (double) nums[i];
            ++i;
        }
    }
    if(sum>max) max = sum;
    return max/k;
}

int main(){
    std::vector<int> v = {3,3,4,3,0};
    findMaxAverage(v, 3);
    return 0;
}