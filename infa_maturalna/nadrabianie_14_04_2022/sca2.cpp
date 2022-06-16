#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> nums1, nums2;
    for(int i = 0; i < 1000; ++i){
        VI n(10);
        for(int j = 0; j < 10; ++j)
            cin >> n[j];
        nums1.push_back(n);
    }
    for(int i = 0; i < 1000; ++i){
        VI n(10);
        for(int j = 0; j < 10; ++j)
            cin >> n[j];
        nums2.push_back(n);
    }
    int counter = 0;
    for(int i = 0; i < 1000; ++i){
        int p1 = 0, p2 = 0;
        for(int j = 0; j < 10; ++j)
            if(nums1[i][j] % 2 == 0)
                p1++;
        
        for(int j = 0; j < 10; ++j)
            if(nums2[i][j] % 2 == 0)
                p2++;
        
        if(p1 == 5 && p2 == 5)
            counter++;        
    }
    cout << counter << endl;
}