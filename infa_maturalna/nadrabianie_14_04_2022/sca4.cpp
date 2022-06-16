#include <iostream>
#include <vector>
#include <set>

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
    for(int i = 0; i < 1000; ++i){
        multiset<int> a;
        for(int j = 0; j < 10; ++j)
            a.insert(nums1[i][j]);
        
        for(int j = 0; j < 10; ++j)
            a.insert(nums2[i][j]);
        
        for(auto it = a.begin(); it != a.end(); ++it)
            cout << *it << ' ';
        cout << endl;
    }
}