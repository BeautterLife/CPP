#include <iostream>

using namespace std;

int main(void) {
    int r,s,t;
    cin >> r >> s >>t;
    
    int **arr_a = new int*[r];
    int **arr_b = new int*[s];
    int **arr_c = new int*[r];
    
    for(int i=0;i<r;i++){
        arr_a[i] = new int[s];
        for(int j=0;j<s;j++){
            cin >> arr_a[i][j];
        }
    }
    for(int i=0;i<s;i++){
        arr_b[i] = new int[t];
        for(int j=0;j<t;j++){
            cin >> arr_b[i][j];
        }
    }
    
    for(int i=0;i<r;i++) arr_c[i] = new int[t];
    
    for(int i=0;i<r;i++){
        for(int j=0;j<t;j++){
            for(int k=0;k<s;k++){
                arr_c[i][j] += arr_a[i][k]*arr_b[k][j];
            }
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<t;j++){
            cout<<arr_c[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0;i<r;i++){
        delete[] arr_a[i];
        delete[] arr_c[i];
    }
    for(int i=0;i<s;i++) delete[] arr_b[i];
    
    delete[] arr_a;
    delete[] arr_b;
    delete[] arr_c;
    
    return 0;
}
