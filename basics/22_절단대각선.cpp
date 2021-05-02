#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int calcDiagonal(vector<vector<int>>& v, int n, int m, int dir);

int main(void) {
    int n;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(n)); 
    int maxDiagonal= INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    
    for(int i=0;i<v.size()-1;i++){
        maxDiagonal = max(maxDiagonal, calcDiagonal(v,0,i,1));
        maxDiagonal = max(maxDiagonal, calcDiagonal(v,i,0,1));
        maxDiagonal = max(maxDiagonal, calcDiagonal(v,i,v.size()-1,-1));
        maxDiagonal = max(maxDiagonal, calcDiagonal(v,0,v.size()-1-i,-1));
    }
    cout<< maxDiagonal;
    
    return 0;
}

int calcDiagonal(vector<vector<int>>& v, int x, int y, int dir){
    int sumDiagonal = 0;

    for(int i=0;i<v.size();i++){
        sumDiagonal+=v[x++][y];
        y+=dir;
        if(x==v.size()) x=0;
        else if(y==v.size()||y==-1){
            if(dir==1) y=0;
            else y=v.size()-1;
        }
    }
    return sumDiagonal;
}

