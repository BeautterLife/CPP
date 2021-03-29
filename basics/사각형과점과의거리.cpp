/*
대소 비교 잘 하면 abs안써도 될 듯
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int ax,ay,bx,by,x,y;
    cin >> ax >> ay>>bx>>by>>x>>y;

    if ((ax<=x && x<=bx) && (ay<=y && y<=by)) cout<<0<<" "<<0;

    else{
        if(ax<=x && x<=bx) cout<< pow(min(abs(y-ay),abs(y-by)),2)<<" "<<min(abs(y-ay),abs(y-by));
        else if(ay<=y && y<=by) cout<< pow(min(abs(x-ax),abs(x-bx)),2)<<" "<<min(abs(x-ax),abs(x-bx));
        else {
            cout<<pow(min(abs(x-ax),abs(x-bx)),2)+pow(min(abs(y-ay),abs(y-by)),2);
            cout<<" " <<(min(abs(x-ax),abs(x-bx))+min(abs(y-ay),abs(y-by)));
        }
    }

    return 0;
}