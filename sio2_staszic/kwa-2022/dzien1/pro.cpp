#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, y;
struct col{
    vector<int> vals;
    int pos = 0;
    void srt(){ sort(vals.begin(), vals.end()); }
    int closest(int level){
        if(vals.size() == 0 || level > vals[pos])
            return m + 1;
        if(vals[pos] == level)
            return vals[pos++];
        return vals[pos];
    }
};

vector<col> area;

struct el{
    int val, ile;
};
deque<el> mini_q;

void push(int val){
    int ile = 0;
    while(!mini_q.empty() && mini_q.back().val >= val){
        ile += 1 + mini_q.back().ile;
        mini_q.pop_back();
    }
    mini_q.push_back({val, ile});
}

void pop(){
    if(mini_q.front().ile-- == 0)
        mini_q.pop_front();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    area.assign(n + 1, {});
    for(int i = 0; i < k; ++i){
        cin >> x >> y;
        area[x].vals.push_back(y);
    }
    for(int i = 1; i <= n; ++i)
        area[x].srt();
    long long rects = 0;
    for(int i = 1; i <= m; ++i){
        vector<int> heights(n + 1);
        int mini = 10000;
        mini_q.clear();
        for(int j = 1; j <= n; ++j)
            push(area[j].closest(i) - i);
        cout << mini_q.front().val << " " << mini_q.front().ile << endl;
        for(int i = 1; i <= n; ++i){
            rects += 1;
        }
    }
    cout << rects << endl;
}