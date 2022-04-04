#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 10000000000000001

vector<tuple<int, int, int>> graph;
vector<long long> dists;
int n, m;

void bf(int v){
    dists[v] = 0;
    for(int i = 0; i <= n; ++i){
        bool any = false;
        for(auto& [a, b, cost]: graph){
            if(dists[b] > dists[a] + cost){
                dists[b] = dists[a] + cost;
                any = true;
            }
        }
        if(!any)
            break;
        else if (any && i == n)
            cout << "NEGATIVE CYCLE!" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> n >> m;
    dists.assign(n + 1, INF);
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        graph.emplace_back(a, b, c);
        graph.emplace_back(b, a, c);
    }
    bf(1);
}