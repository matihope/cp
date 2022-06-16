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
    vector<int> lines;
    int counter = 0;
    for(int i = 0; i < 1000; ++i){
        set<int> a, b;
        for(int j = 0; j < 10; ++j)
            a.insert(nums1[i][j]);
        
        for(int j = 0; j < 10; ++j)
            b.insert(nums2[i][j]);
        
        bool good = true;
        for(auto it1 = a.begin(), it2 = b.begin(); it1 != a.end() && it2 != b.end(); ++it1, ++it2){
            if(*it1 != *it2){
                good = false;
                break;
            }
        }
        if(good && a.size() == b.size()){
            counter++;
            lines.push_back(i + 1);
        }
    }
    cout << counter << endl;
    for(auto& i: lines)
        cout << i << endl;
}