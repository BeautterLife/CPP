#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) {
    int ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx>> by>> cx>>cy;
    
    int area = ((bx-ax)*(cy-ay) - (cx-ax)*(by-ay));
    cout<< abs(area)<<" "<<(area==0?0:(area>0?1:-1));
    
    
    return 0;
}