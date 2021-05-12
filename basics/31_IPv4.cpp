#include <iostream>
#include <string>
using namespace std;
unsigned int Ipv4ToString(string s);
string uIntToIpv4(unsigned int n);
int main(void) {
    int k;
    cin >>k;
    if (k==1) {
        string s;
        cin >>s;
        cout<< Ipv4ToString(s);
        return 0;
    }
    unsigned int n;
    cin >> n;
    cout<< uIntToIpv4(n);
    return 0;
}

unsigned int Ipv4ToString(string s){
    int a1 = s.find('.');
    int a2 = s.find('.',a1+1);
    int a3 = s.find('.',a2+1);
    int a4 = s.length();
    unsigned int ipv4 = 0;
    ipv4 = (stoul(s.substr(0,a1))<<24) + (stoul(s.substr(a1+1,a2-a1-1))<<16) + (stoul(s.substr(a2+1,a3-a2-1))<<8) + (stoul(s.substr(a3+1,a4-a3-1)));

    return ipv4; 
    
}

string uIntToIpv4(unsigned int n){
    string a;
    for(int i=3;i>-1;i--){
        // 상위 바이트부터 추출하고 나눠주면 하위 바이트만 남음
        a+= to_string(n/(1<<(8*i)));  // 나눈 몫이 추출한 주소
        if (i>0) a+='.';
        n%=(1<<(8*i));  // 나눈 나머지가 다음에 추출할 대상
    }
    return a;

}
