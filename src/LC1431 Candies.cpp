#include <vector>
std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies){
    int max = 0;
    std::vector<bool> greatest(candies.size());
    for(int i=0; i<candies.size(); ++i){
        if(candies[i]>max) max = candies[i];
    }
    max -= extraCandies;
    for(int i=0; i<candies.size(); ++i){
        if(candies[i]>max) greatest[i] = true;
        else greatest[i] = false;
    }
}