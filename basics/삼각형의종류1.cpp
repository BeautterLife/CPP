#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;

    cin >> a >> b >> c;
    
    if (a+b <=c)cout<<0;
    else if(a*a+b*b==c*c) cout<<2;
    else if(a==b){
        if(b==c) cout<<1;
        else cout<<3;
    }
    else cout<< 4;
    
    return 0;
}