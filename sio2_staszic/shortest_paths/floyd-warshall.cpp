#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 10000000000000001


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<long long>> graph;
    graph.assign(n + 1, vector<long long>(n + 1, INF));
    for(int i = 1; i <= n; ++i)
        graph[i][i] = 0;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    cout << "Gut" << endl;
}