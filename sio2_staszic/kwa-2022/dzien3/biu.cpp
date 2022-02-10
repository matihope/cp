#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

struct vert{
    int parent;
    long long packs = 0;
    long long packs_from_children = 0;
    long long per_day = 1;
    long long days_to_take_own = 0;
    long long days_to_take_rest = 0;
    long long ile_dni_do_mnie_schodzi = 0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vert> graph;
        graph.assign(n + 1, {});
        long long all_packs = 0;
        for(int i = 2; i <= n; ++i) {cin >> graph[i].packs; all_packs += graph[i].packs; }
        for(int i = 2; i <= n; ++i) cin >> graph[i].parent;
        for(int i = 2; i <= n; ++i) cin >> graph[i].per_day;
        int days = 1;
        while(graph[1].packs < all_packs){
            for(int i = 2; i <= n; ++i){
                graph[graph[i].parent].packs += min(graph[i].packs, graph[i].per_day);
                graph[i].packs = max(graph[i].packs - graph[i].per_day, 0LL);
            }
            if(graph[1].packs != all_packs)
                days++;
        }
        cout << days << endl;
    }
}