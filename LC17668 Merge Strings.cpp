#include <string>
#include<iostream>

std::string merge(std::string a, std::string b){
    int i = 0;
    int size_a = a.size();
    int size_b = b.size();
    std::string r="";
    while(i<size_a && i<size_b){
        char a_i = a[i], b_i = b[i];
        r+=a[i];
        r+=b[i];
        ++i;
    }
    if(i<size_a){
        r += a.substr(i,size_a-i);
    }
    else if (i<size_b)
    {
        r += b.substr(i, size_b-i);
    }
    return r;
}

int main(){
    std::string 
        w1="abc",
        w2="pqr",
        w3="ef",
        w4="123",
        w5="ijk";
    
    std::cout<<merge(w1,w2)<<std::endl;
    std::cout<<merge(w3,w4)<<std::endl;
    std::cout<<merge(w5,"1234567890");
    return 0;
}