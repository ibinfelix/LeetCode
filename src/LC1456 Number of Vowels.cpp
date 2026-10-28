#include <string>
#include <vector>
bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
int maxVowels(std::string s, int k){
    unsigned int    i = 0,  
                    j = 0,
                    acc = 0,
                    max = 0;
    while(j<s.size()){
        if(j-i<k){
            if(isVowel(s[j])) ++acc;
            ++j;
        }
        else{
            if(acc>max) max = acc;
            if(isVowel(s[i])) --acc;
            ++i;
        }
    }
    if(acc>max) return acc;
    return max;
}

int maxVowels_(std::string s, int k){
    int n = s.size();
    bool* v = new bool[n];
    for(int a = 0; a<n; ++a){
        v[a] = isVowel(s[a]);
    }
    unsigned int    i = 0,
                    j = 0,
                    acc = 0,
                    max = 0;
    while(j<n){
        if(j-i<k){
            acc += v[j];
            ++j;
        }
        else{
            if(acc > max) max = acc;
            acc -= v[i];
            ++i;
        }
    }
    delete[] v;
    if(acc>max) return acc;
    return max;
}

int main(){
    maxVowels_("leetcode", 3);
    return 0;
}