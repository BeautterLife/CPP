#include <iostream>
#include <set>

using namespace std;
string isHappy(int num,set<int>& s);
int main(void) {
    int n;
    cin >> n;
    set<int> s;
    s.insert(n);
    
    cout<< isHappy(n,s);
    
    return 0;
}

string isHappy(int num, set<int>& s){
    if (num==1) return "HAPPY";
    int sqaure_sum = 0;
    while(num!=0){
        square_sum+=(num%10)*(num%10);
        num/=10;
    }
  
    if (s.find(square_sum)!=s.end()) return "UNHAPPY";
    s.insert(square_sum);
    return isHappy(square_sum,s);
}
