#include <vector>
int maxArea(std::vector<int>& heights){
    int i=0, 
        j=heights.size()-1, 
        maxArea=0;
    while(i!=j){
        maxArea = std::max(
            maxArea, 
            (std::min(heights[i],heights[j]) * (j-i))
        );
        if      (heights[i]<heights[j]) ++i;
        else    --j;
    }
    return maxArea;
}

int main(){
    maxArea(*(new std::vector({1,2,3})));
    return 0;
}