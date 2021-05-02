#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int j = i <= n/2 ? i : n-i-1;
        for(int k=0;k<j;k++) cout << '-';
        for(int k=0;k<n-2*j;k++){
            if (k%2==0) cout<<'*';
            else cout <<'+';
        }
        for(int k=0;k<j;k++) cout << '-';
        cout<<endl;
    }
    return 0;
}
