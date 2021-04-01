#include <iostream>

using namespace std;

int main(void) {
    int h,w,n;
    cin >> h >> w >> n;
    int horizon = n%h;
    cout << (horizon==0?h:horizon);
    if(n<10*h) cout<<0;
    cout<< (horizon==0?n/h:n/h+1);
    return 0;
}