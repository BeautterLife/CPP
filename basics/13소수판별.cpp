#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for(int i=2; i<=sqrt(n);i++){
        if (!(n%i)) {
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}
