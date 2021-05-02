#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    cout << a + b<< ' '<< a-b << ' '<< abs(a-b) << ' '<< a*b << ' '<< a/b << ' '<< a%b << ' '<< (a>b?a:b);
    cout <<' '<<int(a==b);
    return 0;
}
