#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_H
constexpr int MAXN = 1000;
#else
constexpr int MAXN = 1e6 + 4005;
#endif
int REP_V[MAXN];
int REP_H[MAXN];

int Find_H(int p){
    if (REP_H[p] == p)
        return p;
    return REP_H[p] = Find_H(REP_H[p]);
}

int Find_V(int p){
    if (REP_V[p] == p)
        return p;
    return REP_V[p] = Find_V(REP_V[p]);
}

void Union_H(int a, int b){
    REP_H[Find_H(a)] = Find_H(b);
}

void Union_V(int a, int b){
    REP_V[Find_V(a)] = Find_V(b);
}

struct vert{
    int i, j;
    int parent;
    int bomb_pos;
    bool unsure = true;
    bool dentonated_bomb_somewhere = false;
};
vector<bool> visited;
vector<int> d;
#define INF 1'000'000'001
vector<vert> graph;
vector<string> tab;
vector<vector<int>> pos;

char SKALA = 'X';
char MUR = '#';
char START = 'P';
char KONIEC = 'K';

void bfs(int start){
    stack<int> st;
    st.push(start);
    d[start] = 0;
    while(!st.empty()){
        int v = st.top(); st.pop();
        if(graph[v].i - 1 != 0){
            // dol
            if(tab[graph[v].i - 1][graph[v].j] == SKALA) continue;
            int& new_v = pos[graph[v].i - 1][graph[v].j];
            if(d[v] + 1 < d[new_v]){
                if(tab[graph[v].i - 1][graph[v].j] == MUR)
                    graph[new_v].dentonated_bomb_somewhere = true;
                if(graph[v].unsure){
                    // przyszlismy od kogoś kto nie byl pewny
                    if(graph[v].dentonated_bomb_somewhere && graph[new_v].dentonated_bomb_somewhere)
                        graph[new_v].unsure = false;
                    d[new_v] = d[v] + 1;
                }
            }
            else if(d[v] + 1 <= d[new_v]){

            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    tab.assign(n, "");
    int start_pos = 0;
    int koniec_pos = 0;
    pos.assign(n + 2, vector<int>(n + 2, 0));
    int counter = 0;
    graph.assign((n + 2) * (n + 2) + 1, {});
    d.assign((n + 2) * (n + 2) + 1, INF);
    for(int i = 0; i <= n + 1; ++i){ // y
        for(int j = 0; j <= n + 1; ++j){ // x
            pos[i][j] = counter++;
            graph[pos[i][j]].i = i;
            graph[pos[i][j]].j = j;
            if(i != 0 && j != 0 && i <= n && j <= n){
                REP_V[pos[i][j]] = pos[i][j];
                REP_H[pos[i][j]] = pos[i][j];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cin >> tab[i];
        for(int j = 0; j < tab[i].size(); ++j) {
            if(tab[i][j] == KONIEC){
                koniec_pos = pos[i + 1][j + 1];
            } else if(tab[i][j] == START){
                start_pos = pos[i + 1][j + 1];
            }
        }
    }
    

    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            Union_H(pos[i][j + 1], pos[i][j]);
            Union_V(pos[i + 1][j], pos[i][j]);
        }
    }




}