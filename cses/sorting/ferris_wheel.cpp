#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto& i: v){
        cin >> i;
    }

    sort(v.begin(), v.end());

    int l = 0;
    int r = n - 1;
    int needed = 0;
    while(l < r){
        if(v[l] + v[r] <= x){
            l++;
            r--;
        } else {
            r--;
        }
        needed++;
    }
    if(l == r)
        needed++;
    cout << needed << endl;
}
