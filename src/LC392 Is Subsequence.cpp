#include <string>
bool isSubsequence(std::string s, std::string t) {
    long long unsigned int i=0, j=0;
    while(i<s.size() && j<t.size()){
        if(s[i] == t[j]) ++i;
        ++j;
    }
    return i>=s.size() ? true : false;
}

bool isSubsequence2(std::string s, std::string t){
    if(s.size() == 0) return true;
    if(t.size() == 0) return false;
    long long unsigned int i=0;
    for(auto c : t){
        if(c == s[i]) ++i;
        if(i >= s.size()) return true;
    }
    return false;
}

int main(){
    std::string s = "ahbgdc";
    isSubsequence("abc", s);
    return 0;
}