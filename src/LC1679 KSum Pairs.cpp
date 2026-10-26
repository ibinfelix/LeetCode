#include <vector>
#include <unordered_map>
#include <algorithm>
int maxOperations_(std::vector<int>& nums, int k){
    std::unordered_multimap<int, int> map;
    long long unsigned int i = 0;
    int count = 0;
    for(int n : nums){
        int r = k-n;
        auto it = map.find(r);
        if(it!=map.end()){
            map.erase(it);
            ++count;
        }
        else{
            map.insert({n, i});
        }
        ++i;
    }
    return count;
}

int maxOperations(std::vector<int>& nums, int k){
    std::unordered_map<int,int> map;
    unsigned int count = 0;
    for(int n:nums){
        int r = k-n;
        if(map.find(r)!=map.end() && map[r] > 0){
            --map[r];
            ++count;
        }
        else ++map[n];
    }
    return count;
}

int sortMaxOperations(std::vector<int>& nums, int k){
    if(nums.size() <= 1) return 0;
    std::sort(nums.begin(), nums.end());
    unsigned int    
        count = 0,
        i=0,
        j = nums.size()-1;
    while(i<j){
        int sum = nums[i]+nums[j];
        if(sum == k){
            ++i;
            --j;
            ++count;
        }
        else if(sum < k) ++i;
        else --j;
    }
    return count;
}

int main(){
    std::vector v = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    // v = {1,2,3,4};
    sortMaxOperations(v, 5);
    return 0;
}