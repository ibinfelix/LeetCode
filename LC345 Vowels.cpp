#include <string>
#include <cstring>
bool notVowel(char c){
    if(std::strchr("aeiouAEIOU", c)) return false;
    return true;
}
std::string reverseVowels(std::string s) {
    int i=0, j = s.size()-1;
    while(i<j){
        if(notVowel(s[i])) {++i; continue;}
        if(notVowel(s[j])) {--j; continue;}
        std::swap(s[i], s[j]);
        ++i; --j;
    }
    return s;
}