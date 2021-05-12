#include <iostream>

using namespace std;

int main(void) {
    unsigned int a;

    cin >> a ;
    
    int b[3];
    //최하위 1바이트
    int originChecksum = (a%(1<<8));
    //상위 3바이트로부터 checksum 계산
    int calcChecksum = 0;
    for(int i=0;i<3;i++){
        //상위 바이트부터 추출
        // 나눈 나머지로 해도 되고, right shift로 해도 됨
        calcChecksum+=(a>>((8*(3-i))));
        a%=(1<<(8*(3-i)));
    }
    calcChecksum%=256;
    calcChecksum = 255- calcChecksum;
    cout << (calcChecksum==originChecksum) ? 1 : 0;
    
    return 0;
}
