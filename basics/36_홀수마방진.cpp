#include <iostream>

using namespace std;

int** genMagicSquare(int n){
    int **sq = new int*[n];
    for(int i=0;i<n;i++) sq[i] = new int[n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sq[i][j] = 0;
        }
    }
    
    int i=0,j=n/2;
    int k=i,l=j;
    for(int m=1;;m++){
        sq[i][j]=m;
        if(m==n*n) break;
      
        if(i==0) k=n-1;
        else k=i-1;
      
        if(j==n-1) l=0;
        else l=j+1;  
        
        if(sq[k][l]) i = (i+1)%n;
        else{
            i=k;
            j=l;
        }               
    }   
    return sq;
}

int main(void) {
    int n;

    cin >> n;
    if (!(n%2)) return 1;

    int **sq = genMagicSquare(n);
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) 
            cout << sq[i][j] << ' ';
        cout << endl;
    }
}
