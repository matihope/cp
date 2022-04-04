#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pole;
vector<vector<int>> saved;

struct el{
    int ile, val;
};
deque<el> q;

void add(int val){
    int ile = 0;
    while(!q.empty() && q.back().val >= val){
        ile += 1 + q.back().ile;
        q.pop_back();
    }
    q.push_back({ile, val});
}

void pop(){
    if(q.front().ile-- == 0)
        q.pop_front();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, l;
    cin >> n >> m >> k >> l;
    pole.assign(n, vector<int>(m, {}));
    saved.assign(n, vector<int>(m - l + 1, 1'000'001));
    int x = 0;
    for(int i = 0; i < n; ++i){
        q.clear();
        x = 0;
        for(int j = 0; j < m; ++j){
            cin >> pole[i][j];
            add(pole[i][j]);
            if(j + 1 >= l){
                saved[i][x++] = q.front().val;
                pop();
            }
        }
    }
    for(int j = 0; j < m - l + 1; ++j){
        q.clear();
        for(int i = n - 1; i >= 0; --i){
            add(saved[i][j]);
            if(i < n - k + 1){
                saved[i][j] = q.front().val;
                pop();
            }
        }
    }
    for(int i = 0; i < n - k + 1; ++i){
        for(int j = 0; j < m - l + 1; ++j){
            cout << saved[i][j] << " ";
        }
        cout << '\n';
    }
}