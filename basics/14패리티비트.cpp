#include <iostream>

using namespace std;

int main(void) {
    unsigned int n;
    cin >> n;
    unsigned int tmp = n;
    int cnt=0;
    //n=0인 경우도 있음. 
    while(tmp>0){
        if (tmp%2) cnt++;
        tmp/=2;
    }
    cout << (cnt%2==0? n : (1<<31) | n);
    
    return 0;
}
