#include <bits/stdc++.h>

using namespace std;

struct el{
    int ile;
    long long val;
};
deque<el> q;

void push(long long val){
    int ile = 0;
    while(!q.empty() && q.back().val < val){
        ile = ile + 1 + q.back().ile;
        q.pop_back();
    }
    q.push_back({ile, val});
}

void pop(){
    if(q.front().ile-- == 0) q.pop_front();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, p, d;
    cin >> n >> p >> d;
    vector<int> tab(n, 0);
    vector<long long> pref(n, 0);
    cin >> tab[0];
    pref[0] = tab[0];
    for(int i = 1; i < n; ++i) {
        cin >> tab[i];
        pref[i] = pref[i - 1] + tab[i];
    }
    int t = 0, h = d - 1;
    long long takes_up = pref[h];
    int max_len = d;
    push(takes_up);
    while(t <= h - d + 1){
        while(h + 1 < n && takes_up - q.front().val <= p){
            takes_up += tab[++h];
            push(pref[h] - pref[h - d]);

            if(takes_up - q.front().val <= p)
                max_len = max(max_len, h - t + 1);
        }
        takes_up -= tab[t++];
        pop();
    }
    cout << max_len << endl;
    
}