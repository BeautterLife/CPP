#include <iostream>
#include <cstdlib> // int abs(int num) 은 cmath가 아닌 여기에 있음
//#include <cmath>
using namespace std;

int main(void) {
    int x1,y1,x2,y2, x3,y3,x4,y4;
    cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
   
    //수평, 수직 선분 순서로 생각하려고(같은 알고리즘 적용을 위해)
    //수직,수평 선분이 나온 경우는 반대로 뒤집어줌
    if(x1==x2){
        int tmp1 = x1;
        int tmp2 = x2;
        x1 = x3;
        x2 = x4;
        x3 = tmp1;
        x4 = tmp2;

        tmp1 = y1;
        tmp2 = y2;
        y1 = y3;
        y2 = y4;
        y3 = tmp1;
        y4 = tmp2;
    }
    
 
    if((abs(x1-x3)+abs(x2-x3))==abs(x1-x2) && (abs(y3-y1)+abs(y4-y1) == abs(y3-y4))){
        if(y1==y3 || y1==y4 || x1==x3 || x2 == x4)  cout<<2; 
        else cout<<1;
    
    }
    else cout<<0;
    
    return 0;
}
