#include <vector>
bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int empty_count = 1, count = 0, size = flowerbed.size();
    for(int i=0; i<size; ++i){
        if(flowerbed[i]==0) 
            ++empty_count;
        else
            empty_count = 0;
        if(empty_count>=3){
            empty_count = 1;
            ++count;
        }
    }
    if(empty_count>=2){
        ++count;
    }
    return count>=n;
}