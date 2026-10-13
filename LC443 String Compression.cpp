#include <vector>
#include <string>
#include <iostream>
int compress(std::vector<char>& chars){
    int count = 0;
    char prev = ' ';
    std::string s = "";
    for(char c : chars){
        if(c != prev){
            if(count > 1){
                s+=prev;
                s.append(std::to_string(count));
            }
            else if(count == 1) s+=prev;
            prev = c;
            count = 1;
        }
        else ++count;
    }
    if(count > 1){
        s+=prev;
        s.append(std::to_string(count));
    }
    else if(count == 1) s+=prev;
    for (int i = 0; i<s.size(); ++i){
        chars[i] = s[i];
    }
    chars.resize(s.size());
    return chars.size();
}

int main(){
    std::vector<char> 
        x = {'a','a','b','b','c','c','c','d'},
        y = {'a','a','a','a','a','a','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c'};
    int comp = compress(y);
    return 0;
}