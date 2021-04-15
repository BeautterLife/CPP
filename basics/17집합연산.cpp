#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a;
    vector<int> arr1;
    int num;
    for(int i=0;i<a;i++) {
        cin>> num; 
        arr1.push_back(num);
    }
  
    cin >> b;
    vector<int> arr2;
    for(int i=0;i<b;i++) {
        cin>>num;
        arr2.push_back(num);
    }

    // <algorithm>의 집합연산 함수는 inputIterator를 순자적으로 비교하므로 정렬해야함
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
  
    // 집합연산 함수 return 받을 iterator 객체
    vector<int>::iterator iter;
    //결과를 담을 buf 벡터
    vector<int> buf(arr1.size());

    // return : outputIterator의 end
    iter = set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), buf.begin());
    //buf.resize(iter-buf.begin());
    //for_each(buf.begin(),iter, [](int i){cout<<i<<" ";});
    // vector 멤버 함수인 resize와 erase의 사용법이 다름
    
    // erase([start,end]) 를 지우고 vector size 변경
    // resize(sz) s만큼의 size로 변경. 모자르거나 넘치는 경우를 care 해 줌. (size와 capacity도 고려함)
  
    cout<<iter-buf.begin()<<" ";
    buf.erase(iter,buf.end());
    sort(buf.begin(),buf.end());
    for_each(buf.begin(), buf.end(), [](int i){cout<<i<<" ";});
    cout<<endl;
    buf.clear();

    buf.resize(arr1.size()+arr2.size());
    iter = set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), buf.begin()); 
    buf.resize(iter-buf.begin());

    cout<<buf.size()<<" ";
    sort(buf.begin(),buf.end());
    for_each(buf.begin(), buf.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    buf.clear();
    buf.resize(arr1.size());
    iter = set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), buf.begin()); 
    buf.resize(iter-buf.begin());
    sort(buf.begin(),buf.end());
    cout<<buf.size()<<" ";
    for_each(buf.begin(), buf.end(), [](int i){cout<<i<<" ";});


    cout<<endl;


    return 0;
}
