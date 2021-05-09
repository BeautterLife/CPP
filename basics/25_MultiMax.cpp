#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int main(void) {
    int num_card;
    cin >> num_card;
    int *card = new int[num_card];
    for(int i=0;i<num_card;i++) cin >> card[i];
    
    int max_1=INT_MIN;
    int max_2=INT_MIN;
    int max_3=INT_MIN;

    int min_1=INT_MAX;
    int min_2=INT_MAX;
    int min_3=INT_MAX;
    sort(card,card+num_card);
    max_1 = card[num_card-1];
    max_2 = card[num_card-2];
    max_3 = card[num_card-3];
    
    min_1 = card[0];
    min_2 = card[1];
    min_3 = card[2];
    
    int max_mult =INT_MIN;
    max_mult = max(max_1*max_2,max_mult);
    max_mult = max(min_1*min_2, max_mult);
    max_mult = max(max_1*max_2*max_3,max_mult);
    max_mult = max(max_1*max_2*min_1,max_mult);
    max_mult = max(max_1*min_1*min_2,max_mult);

    
    /*
    int *two_mult_max = new int[num_card];
    int *two_mult_min = new int[num_card];
    memset(two_mult_max, 0, sizeof(int));
    memset(two_mult_min, 0, sizeof(int));

    
    for(int i=1;i<num_card;i++){
        for(int j=0;j<i;j++){
            two_mult_max[i] = max(two_mult_max[i],card[j]*card[i]);
            two_mult_min[i] = min(two_mult_min[i],card[j]*card[i]);
        }
        
    }
    
    int *three_mult = new int[num_card];
    memset(three_mult, 0, sizeof(int));
    
    for(int i=2;i<num_card;i++){
        for(int j=1;j<i;j++){
            three_mult[i] = max(three_mult[i], two_mult_max[j]*card[i]);
            three_mult[i] = max(three_mult[i], two_mult_min[j]*card[i]);
        }
    }

    int max_mult = 0;
    for(int i=0;i<num_card;i++){
        max_mult = max(max_mult,max(three_mult[i],two_mult_max[i]));
    }
    */
    cout<<max_mult;
    
    return 0;
}
