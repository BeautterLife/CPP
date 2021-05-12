#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    vector<int> incv;
    int val;
    int profit = 0;
    for(int i=0;i<n-1;i++){
        val=v[i];
        for(int j=i+1;j<n;j++){
            if(val < v[j]) val = v[j];
        }
        profit += (val-v[i]);
    }
    
   
    /*
    너무 어렵게 생각함(two pointer)
    시간복잡도 생각하면 값을 저장하긴 해야될 듯
    vector<pair<int,int> > incV;
    int e=0 , s=0, eValue=0;
    for(int i=1;i<n;i++){
        if (eValue>v[i]) {
            
            incV.push_back(make_pair(s,e));
            s = e= i;
        }
        else e = i;
        eValue = v[i];
    }
    if(s!=e) incV.push_back(make_pair(s,e));
    for(int i=0;i<incV.size();i++) cout << incV[i].first <<incV[i].second << " ";
    */
    
   cout << profit;
    return 0;
}
