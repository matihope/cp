#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n, 0);
    vector<int> a(m, 0);
    for(int &i : p)
        cin >> i;
    for(auto &i : a)
        cin >> i;

    sort(p.begin(), p.end());
    sort(a.begin(), a.end());
    int l = 0, r = 0, counter = 0;
    while(l < p.size() && r < a.size()) {
        if(abs(p[l] - a[r]) <= k){
            counter++;
            l++;
            r++;
        } else if (p[l] < a[r]) {
            l++;
        } else {
            r++;
        }
    }
    cout << counter << endl;

}
