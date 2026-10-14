#include <vector>
#include <unordered_map>
std::vector<int> n2(std::vector<int> input, int target){
    int n = input.size();
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(i==j) continue;
            if(input[i] + input[j] == target) return {i,j};
        }
    }
    return {};
}

std::vector<int> n(std::vector<int> input, int target){
    std::unordered_map<int,int> um;
    int n = input.size();
    for(int i = 0; i<n; ++i){
        int x = target-input[i];
        auto find = um.find(x);
        if(find != um.end()){
            return {i, find->second};
        }
        um.insert({input[i], i});
    }
}

std::vector<int> twoSum(std::vector<int> input, int target){
    return n(input, target);
}

int main(){
    std::vector<int> r = twoSum({2,11,7,15}, 9);
    return 0;
}