#include <string>
#include <iostream>

// Original Solution
std::string gcdOfString(std::string str1, std::string str2){
    int size1 = str1.size(), 
        size2 = str2.size();
    std::string* greater;
    std::string* shorter;
    if(size1 < size2){
        greater = &str2;
        shorter = &str1;
    }else{
        greater = &str1;
        shorter = &str2;
    }

    for(int i=shorter->size(); i>0; --i){
        std::string gcd = shorter->substr(0,i);
        // std::cout<<gcd<<std::endl; // DEBUG PTR
        int counter = 0;
        for(std::string* x : {greater, shorter}){
            for(int j=x->size(); j>0; --j){
                if(size1 % gcd.size() == 0 && size2 % gcd.size() == 0){
                    std::string temp = "";
                    while(temp.size()<x->size()){
                        temp.append(gcd);
                    }
                    if(*x==temp){
                        counter+=1;
                        break;
                    }
                }
            }
        }
        if(counter >= 2) return gcd;
        
    }
    return "";
}

// Time Optimal Solution
int gcd(int a, int b){
    for(int i=std::max(a,b); i>0; --i){
        if(a%i == 0 && b%i == 0){
            return i;
        }
    }
    return 0;
}
std::string gcdOfStrings(std::string str1, std::string str2){
    if(str1+str2 != str2+str1){
        return "";
    }
    int gcdLength = gcd(str1.size(), str2.size());
    if (gcdLength < 1) return "";
    return str1.substr(0,gcdLength);
}

int main(){
    std::string case1 = gcdOfStrings("ABCABC", "ABC"),
                case2 = gcdOfStrings("ABABAB", "ABAB"),
                case3 = gcdOfStrings("LEET", "CODE");
    return 0;
}