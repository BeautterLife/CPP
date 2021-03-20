#include <iostream>

using namespace std;

int main(void) {
    int k;
    cin >> k;
    int m=1;
    for(int i=1;i<=k;i++){
        for(int j=0;j<i;j++){
            cout<<m++<<' ';
        }
        cout<<endl;
    }
    return 0;
}
