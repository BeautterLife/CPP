#include <iostream>

using namespace std;

int main(void) {
    unsigned int m,n;
    cin >> m >> n;
    
    int hammingW1=0, hammingW2=0;
    int hammingDist=0;
    for(int i=0;i<32;i++){
        unsigned int hBit1 = m>>i;
        unsigned int hBit2 = n>>i;
        hammingW1 += hBit1&1;
        hammingW2 += hBit2&1;
        hammingDist += (hBit1&1)^(hBit2&1);
    }
    
    cout<< hammingW1<<" "<<hammingW2<<" "<<hammingDist;
    return 0;
}
