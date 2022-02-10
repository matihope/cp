#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;
    cin >> n;
    map<int, int> nums;
    for(int i = 0; i < n; ++i){
        cin >> a;
        nums[a]++;
    }
    int count = 0;
    for(auto it = nums.rbegin(); it != nums.rend(); ++it){
        if(it->second == 0) continue;
        // cout << it->first << ": " << it->second << endl;
        int l = 0, r = 31, m;
        while(l < r){
            m = (l + r) / 2;
            if((1<<m) > it->first)
                r = m;
            else
                l = m + 1;
        }
        if((1<<l) == 2 * it->first){
            count += it->second / 2;
        } else if(nums[(1<<l) - it->first] > 0){
            count += min(nums[(1LL<<l) - it->first], it->second);
            nums[(1<<l) - it->first] -= min(nums[(1<<l) - it->first], it->second);
        }
    }
    cout << count << endl;
}