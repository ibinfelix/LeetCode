#include <vector>
#include <stack>
std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> days(n);
    std::stack<int> s;
    for (int i=0; i<n; ++i){
        while(
            !s.empty() && 
            temperatures[s.top()] < temperatures[i]
        ){
            days[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    return days;
}

int main(){
    std::vector<int> t = {4,1,2,3};
    dailyTemperatures(t);
    return 0;
}