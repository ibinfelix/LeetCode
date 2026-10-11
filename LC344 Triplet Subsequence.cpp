#include <vector>
bool increasingTriplet(std::vector<int>& nums) {
    if(nums.size()<3) return false;
    int first=__INT_MAX__,
        second=__INT_MAX__;
    for(int i:nums){
        if(i<=first) first = i;
        else if(i<=second) second = i;
        else return true;
    }
    return false;
}

int main(){
    std::vector<int> 
        v1({2,4,-2,-3}),
        v2({1,1,-2,6});
    bool
        r1 = increasingTriplet(v1),
        r2 = increasingTriplet(v2);
    return 0;
}