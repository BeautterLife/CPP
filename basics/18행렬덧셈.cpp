#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int m;
    int n;
    int num;
    cin >> m >> n;
    
    vector<vector<int>> arr1(m);//,vector<int>(n));

    //vector<vector<int>> arr2;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            arr1[i].push_back(num);
            //arr1[i][j]=(num);
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            arr1[i][j]+=num;
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
