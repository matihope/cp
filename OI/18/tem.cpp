#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> q;

void add(int val){
    int ile = 0;
    while(!q.empty() && q.back().first <= val){
        ile += q.back().second + 1;
        q.pop_back();
    }
    q.push_back({val, ile});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, a, b, max_len = 1, curr = 1;
    cin >> n >> a >> b;
    add(a);
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        while(!q.empty() && q.front().first > b){
            if(q.front().second-- == 0)
                q.pop_front();
            curr--;
        }
        max_len = max(max_len, ++curr);
        add(a);
    }
    cout << max_len << endl;
}