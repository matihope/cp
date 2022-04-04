#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct el{
    int left, right, index, ans = 0;
};

struct el2{
    int val, ile = 0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, a, b;
    cin >> n >> t;
    vector<long long> tab(n);
    for(int i = 0; i < n; ++i) cin >> tab[i];

    vector<el> qs;
    for(int i = 0; i < t; ++i){
        cin >> a >> b;
        priority_queue<int> s;
        for(int i = a - 1; i < b; ++i) s.push(tab[i]);
        long long ans = 0;
        int top = s.top(); s.pop();
        int count = 1;
        while(!s.empty()){
            if(s.top() == top){
                count++;
                s.pop();
            } else {
                ans += count * count * top;
                top = s.top(); s.pop();
                count = 1;
            }
        }
        ans += count * count * top;
        cout << ans << endl;
    }
    
}