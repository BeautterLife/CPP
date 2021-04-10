#include <iostream>

using namespace std;

int main(void) {
    int a,b,n,w;
    cin >> a >> b >> n >> w;
   
    int cnt = 0;
    int num_sheep = 0;
    
    if(a==b){
        cout<<"-1";
        return 0;
    }
    
    for(int i=1;i*a<=w;i++){
        if (w%(a*i+b*(n-i))==0) {
            num_sheep=i;
            if((++cnt)==2){
                cout<<"-1";
                return 0;
            }
        }
    }
    if(n==(2*num_sheep) || num_sheep ==0 || num_sheep == n) cout<<"-1";
    else cout<<num_sheep<<" "<<n-num_sheep;
    
    return 0;
}
