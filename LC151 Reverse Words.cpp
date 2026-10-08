#include <string>
#include <stack>
std::string joinStack(std::stack<std::string> stack, std::string u){
    std::string r="";
    while(!stack.empty()){
        r.append(stack.top());
        r+=u;
        stack.pop();
    }
    r.erase(r.size()-1);
    return r;
}
std::string reverseWords(std::string s) {
    std::stack<std::string> stack;
    int n = s.size(),
        begin = 0,
        end = 0;
    while (end<n && begin<n){
        if(s[begin] == ' ') {
            ++begin;
            continue;
        }
        if(end<=begin) {
            ++end;
            continue;
        };
        if(s[end] == ' '){
            std::string sub = s.substr(begin, end-begin);
            stack.push(sub);
            begin = end+1;
        }
        ++end;
    }
    // Append remaining word
    std::string sub = s.substr(begin, end-begin);
    if(sub != " " && sub != "") stack.push(sub);
    return joinStack(stack, " ");
}

int main(){
    std::string 
        a = reverseWords("the sky is blue"),
        b = reverseWords("  hello world  "),
        c = reverseWords("  Bob    Loves  Alice   ");
    return 0;
}