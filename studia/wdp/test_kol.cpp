#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#define INF 100000

using namespace std;

void floyd_warshall(const vector<vector<int>> &graph,
                    vector<vector<int>> &result) {
    int n = (int)graph.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (graph[i][j])
                result[i][j] = 1;
            else
                result[i][j] = INF;
        }

    for (int k = 0; k < n; ++k) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (!graph[x][k] || !graph[y][k]) continue;
                result[x][y] = min(result[x][k] + result[y][k], result[x][y]);
            }
        }
    }
}

int main() {
    srand(1);
    int n = rand() % 15;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<vector<int>> dists(n, vector<int>(n, INF));
    vector<vector<int>> dists2(n, vector<int>(n, INF));

    for (int i = 0; i < n * n / 3; ++i) {
        int a = rand() % n;
        int b = rand() % n;
        if (a == b) continue;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    floyd_warshall(graph, dists);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << graph[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << dists[i][j] << " ";
        cout << endl;
    }
}
