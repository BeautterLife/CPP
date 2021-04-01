#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int *x = new int[n+1];
    int *y = new int[n+1];
    
    for(int i=0;i<n;i++){
        cin >> *(x+i) >> *(y+i);
    }
    *(x+n) = *x;
    *(y+n) = *y;
    int signedArea = 0;
    for(int i=0;i<n;i++){
        signedArea +=(*(x+i)+(*(x+i+1))) * ((*(y+i+1))-(*(y+i)));
    }
    cout << abs(signedArea) <<" "<< (signedArea<0?-1:1);
    return 0;
}