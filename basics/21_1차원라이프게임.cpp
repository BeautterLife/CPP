#include <iostream>
#include <vector>
using namespace std;

void bacteria(vector<int>& v);

int main(void) {
    int n;
    int k;
    cin >> n >> k;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++) cin >> v[i];
    
    for(int i=0;i<k;i++){
        bacteria(v);
    }
    for(int i=1;i<=n;i++) cout<< v[i]<<" ";
    return 0;
}

void bacteria(vector<int>& v){
    //v 벡터 순회를 마치면 tmp의 결과를 v에 복사하여 다음 time의 박테리아 life 계산
    vector<int> tmp(v.size());
    int adjBact=0;
    for(int i=1;i<=v.size()-2;i++){
        adjBact = v[i-1]+v[i+1];
        if(adjBact < 3 || adjBact > 7) tmp[i] = v[i]>0 ? v[i]-1 : 0;
        else if(4 <= adjBact && adjBact <=7) tmp[i] = v[i] <9 ? v[i]+1 : 9;
        else tmp[i]=v[i];
    }
    //default copy structor
    v = tmp;
}
