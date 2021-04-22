#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(void) {
    int k;
    cin >> k;

    set<int> hamming;
    hamming.insert(1);
    int next_ham=1; 
    set<int>::iterator iter;
    for(int i=1;i<k;i++){
        next_ham = (1<<31)-1;

        //set<int>::reverse_iterator riter;

        for(iter=hamming.begin();iter!=hamming.end();iter++){
            if(hamming.find((*iter)*2)==hamming.end()) {
                next_ham = next_ham > (*iter)*2 ? (*iter)*2 : next_ham; 
            }
            if(hamming.find((*iter)*3)==hamming.end()) {
                next_ham = next_ham > (*iter)*3 ? (*iter)*3 : next_ham;
            }
            if(hamming.find((*iter)*5)==hamming.end()) {
                next_ham = next_ham > (*iter)*5 ? (*iter)*5 : next_ham;
            }
        }
        hamming.insert(next_ham);

    }
    cout<<next_ham;
    return 0;
}