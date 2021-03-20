#include <iostream>

using namespace std;

int main(void) {
    int k;
    const char dot = '.';
    const char Y = 'I';
    const char X ='+';
    const char line ='*';
    const char origin = 'O';
    cin >> k ;
    char charcter;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if (k/2==i) {
                //if (k/2==j) cout<< origin;
                //else cout<< X;
                cout<< ((k/2==j) ? origin : X);
            }
            else if (k/2==j) cout<< Y;
            else if (i+j==k-1) cout<<line;
            else cout<< dot;
        }
        cout<<endl;
    }

    return 0;
}
