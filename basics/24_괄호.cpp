#include <iostream>
#include <string>
#include <stack>
using namespace std;

const char start = '(';

int main(void) {
    string s;
    stack<char> st;
    
    cin >> s;
    
    for(int i=0;i<s.length();i++){
        if (char(s[i])==start) st.push(start);
        else{
            if(st.empty()) {cout<< 0; return 0;}
            st.pop();
        }
    }
    if(!st.empty()) {cout<<0; return 0;}
    cout <<1;
    
    return 0;
}
