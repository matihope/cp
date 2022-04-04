#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
struct vert{
    // 0 = skala, 1 = mur, 2 = puste, 3 = K, 4 = S
    int type = 0;
    PII parent = {-1, -1};
};
#define INF 1'000'000'001

struct G{
    vector<vector<int>> vis;
    vector<vector<vert>> graph;
    vector<vector<int>> d_bez_bomby;
    vector<vector<int>> d_bomba_h;
    vector<vector<int>> d_bomba_v;

    void bfs(int start_y, int start_x){
        queue<PII> q;
        q.push({start_y, start_x});
        d_bez_bomby[start_y][start_x] = 0;
        vis[start_y][start_x] = 1;
        while(!q.empty()){
            auto [cy, cx] = q.front(); q.pop();
            vis[cy][cx] -= 1;
            if(vis[cy][cx]) continue; // jest gdzies dalej w kolejce

            // murki
            if(graph[cy][cx + 1].type == 1){
                // right
                bool found = false;
                if(d_bomba_h[cy][cx + 1] > (min(d_bez_bomby[cy][cx], d_bomba_h[cy][cx]) + 1)){
                    found = true;
                    d_bomba_h[cy][cx + 1] = min(d_bez_bomby[cy][cx], d_bomba_h[cy][cx]) + 1;
                }
                if(d_bomba_v[cy][cx + 1] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bomba_v[cy][cx + 1] = d_bez_bomby[cy][cx] + 1;
                }
                if(found){
                    vis[cy][cx + 1] += 1;
                    q.emplace(cy, cx + 1);
                }
            }

            if(graph[cy][cx - 1].type == 1){
                // left
                bool found = false;
                if(d_bomba_h[cy][cx - 1] > (min(d_bez_bomby[cy][cx], d_bomba_h[cy][cx]) + 1)){
                    found = true;
                    d_bomba_h[cy][cx - 1] = min(d_bez_bomby[cy][cx], d_bomba_h[cy][cx]) + 1;
                }
                if(d_bomba_v[cy][cx - 1] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bomba_v[cy][cx - 1] = d_bez_bomby[cy][cx] + 1;
                }
                if(found){
                    vis[cy][cx - 1] += 1;
                    q.emplace(cy, cx - 1);
                }
            }
            if(graph[cy + 1][cx].type == 1){
                // up
                bool found = false;
                if(d_bomba_v[cy + 1][cx] > (min(d_bez_bomby[cy][cx], d_bomba_v[cy][cx]) + 1)){
                    found = true;
                    d_bomba_v[cy + 1][cx] = min(d_bez_bomby[cy][cx], d_bomba_v[cy][cx]) + 1;
                }
                if(d_bomba_h[cy + 1][cx] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bomba_h[cy + 1][cx] = d_bez_bomby[cy][cx] + 1;
                }
                if(found){
                    vis[cy + 1][cx] += 1;
                    q.emplace(cy + 1, cx);
                }
            }

            if(graph[cy - 1][cx].type == 1){
                // down
                bool found = false;
                if(d_bomba_v[cy - 1][cx] > (min(d_bez_bomby[cy][cx], d_bomba_v[cy][cx]) + 1)){
                    found = true;
                    d_bomba_v[cy - 1][cx] = min(d_bez_bomby[cy][cx], d_bomba_v[cy][cx]) + 1;
                }
                if(d_bomba_h[cy - 1][cx] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bomba_h[cy - 1][cx] = d_bez_bomby[cy][cx] + 1;
                }
                if(found){
                    vis[cy - 1][cx] += 1;
                    q.emplace(cy - 1, cx);
                }
            }


            // default block
            if(graph[cy][cx + 1].type == 2){
                // right
                bool found = false;
                if(d_bez_bomby[cy][cx + 1] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bez_bomby[cy][cx + 1] = d_bez_bomby[cy][cx] + 1;
                }
                if(d_bomba_h[cy][cx + 1] > d_bomba_h[cy][cx] + 1){
                    found = true;
                    d_bomba_h[cy][cx + 1] = d_bomba_h[cy][cx] + 1;
                }
                if(found){
                    vis[cy][cx + 1] += 1;
                    q.emplace(cy, cx + 1);
                }
            }

            if(graph[cy][cx - 1].type == 2){
                // left
                bool found = false;
                if(d_bez_bomby[cy][cx - 1] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bez_bomby[cy][cx - 1] = d_bez_bomby[cy][cx] + 1;
                }
                if(d_bomba_h[cy][cx - 1] > d_bomba_h[cy][cx] + 1){
                    found = true;
                    d_bomba_h[cy][cx - 1] = d_bomba_h[cy][cx] + 1;
                }
                if(found){
                    vis[cy][cx - 1] += 1;
                    q.emplace(cy, cx - 1);
                }
            }
            if(graph[cy + 1][cx].type == 2){
                // up
                bool found = false;
                if(d_bez_bomby[cy + 1][cx] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bez_bomby[cy + 1][cx] = d_bez_bomby[cy][cx] + 1;
                }
                if(d_bomba_v[cy + 1][cx] > d_bomba_v[cy][cx] + 1){
                    found = true;
                    d_bomba_v[cy + 1][cx] = d_bomba_v[cy][cx] + 1;
                }
                if(found){
                    vis[cy + 1][cx] += 1;
                    q.emplace(cy + 1, cx);
                }
            }

            if(graph[cy - 1][cx].type == 2){
                // down
                bool found = false;
                if(d_bez_bomby[cy - 1][cx] > d_bez_bomby[cy][cx] + 1){
                    found = true;
                    d_bez_bomby[cy - 1][cx] = d_bez_bomby[cy][cx] + 1;
                }
                if(d_bomba_v[cy - 1][cx] > d_bomba_v[cy][cx] + 1){
                    found = true;
                    d_bomba_v[cy - 1][cx] = d_bomba_v[cy][cx] + 1;
                }
                if(found){
                    vis[cy - 1][cx] += 1;
                    q.emplace(cy - 1, cx);
                }
            }

        }
    }

    void bfs2(int start_y, int start_x){
        d_bez_bomby[start_y][start_x] = 0;
        queue<PII> q;
        q.push({start_y, start_x});
        while(!q.empty()){
            auto [cy, cx] = q.front(); q.pop();
            if(vis[cy][cx]) continue;
            vis[cy][cx] = 1;
            if(d_bez_bomby[cy - 1][cx] > d_bez_bomby[cy][cx] + 1){
                graph[cy - 1][cx].parent = {cy, cx};
                d_bez_bomby[cy - 1][cx] = d_bez_bomby[cy][cx] + 1;
                q.emplace(cy - 1, cx);
            }
            if(d_bez_bomby[cy + 1][cx] > d_bez_bomby[cy][cx] + 1){
                graph[cy + 1][cx].parent = {cy, cx};
                d_bez_bomby[cy + 1][cx] = d_bez_bomby[cy][cx] + 1;
                q.emplace(cy + 1, cx);
            }
            if(d_bez_bomby[cy][cx + 1] > d_bez_bomby[cy][cx] + 1){
                graph[cy][cx + 1].parent = {cy, cx};
                d_bez_bomby[cy][cx + 1] = d_bez_bomby[cy][cx] + 1;
                q.emplace(cy, cx + 1);
            }
            if(d_bez_bomby[cy][cx - 1] > d_bez_bomby[cy][cx] + 1){
                graph[cy][cx - 1].parent = {cy, cx};
                d_bez_bomby[cy][cx - 1] = d_bez_bomby[cy][cx] + 1;
                q.emplace(cy, cx - 1);
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, mini = INF;
    cin >> n;
    G start_p, start_e;
    start_p.graph.assign(n + 2, vector<vert>(n + 2, {0, -1}));
    start_p.d_bez_bomby.assign(n + 2, vector<int>(n + 2, INF));
    start_p.d_bomba_h.assign(n + 2, vector<int>(n + 2, INF));
    start_p.d_bomba_v.assign(n + 2, vector<int>(n + 2, INF));
    start_p.vis.assign(n + 2, vector<int>(n + 2, 0));
    start_e.graph.assign(n + 2, vector<vert>(n + 2, {0, -1}));
    start_e.d_bez_bomby.assign(n + 2, vector<int>(n + 2, INF));
    start_e.d_bomba_h.assign(n + 2, vector<int>(n + 2, INF));
    start_e.d_bomba_v.assign(n + 2, vector<int>(n + 2, INF));
    start_e.vis.assign(n + 2, vector<int>(n + 2, 0));


    pair<int, int> start, end;
    for(int i = 1; i <= n; ++i){
        string line;
        cin >> line;
        for(int j = 1; j <= n; ++j){
            switch (line[j - 1]){
                case 'K':
                    end = {i, j};
                    start_p.graph[i][j].type = 2;
                    start_e.graph[i][j].type = 2;
                    break;
                case 'P':
                    start = {i, j};
                    start_p.graph[i][j].type = 2;
                    start_e.graph[i][j].type = 2;
                    break;
                case '.':
                    start_p.graph[i][j].type = 2;
                    start_e.graph[i][j].type = 2;
                    break;
                case 'X':
                    start_p.graph[i][j].type = 0;
                    start_e.graph[i][j].type = 0;
                    break;
                case '#':
                    start_p.graph[i][j].type = 1;
                    start_e.graph[i][j].type = 1;
                    break;
            }
        }
    }

    start_p.bfs(start.first, start.second);
    start_e.bfs(end.first, end.second);
    PII bomb_pos;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int dist_from_start = min(min(start_p.d_bez_bomby[i][j], start_p.d_bomba_v[i][j]), start_p.d_bomba_h[i][j]);
            int dist_from_end = min(min(start_e.d_bez_bomby[i][j], start_e.d_bomba_v[i][j]), start_e.d_bomba_h[i][j]);
            if(dist_from_start + dist_from_end < mini) {
                mini = dist_from_start + dist_from_end;
                bomb_pos = {i, j};
            }
        }
    }

    int b_y = bomb_pos.first;
    int b_x = bomb_pos.second;
    start_p.graph.assign(n + 2, vector<vert>(n + 2, {0, -1}));
    start_p.d_bez_bomby.assign(n + 2, vector<int>(n + 2, INF));
    start_p.d_bomba_h.assign(n + 2, vector<int>(n + 2, INF));
    start_p.d_bomba_v.assign(n + 2, vector<int>(n + 2, INF));
    start_p.vis.assign(n + 2, vector<int>(n + 2, 0));
    start_p.graph[b_y - 1][b_x].type = 1;
    while(start_p.graph[b_y - 1][b_x].type != 0){
        b_y--;
        start_p.graph[b_y][b_x].type = 1;
    }
    b_y = bomb_pos.first;
    while(start_p.graph[b_y + 1][b_x].type != 0){
        b_y++;
        start_p.graph[b_y][b_x].type = 1;
    }
    b_y = bomb_pos.first;
    while(start_p.graph[b_y][b_x + 1].type != 0){
        b_x++;
        start_p.graph[b_y][b_x].type = 1;
    }
    b_x = bomb_pos.second;
    while(start_p.graph[b_y][b_x - 1].type != 0){
        b_x--;
        start_p.graph[b_y][b_x - 1].type = 1;
    }
    b_x = bomb_pos.second;


    if(mini == INF){
        cout << "NIE" << endl;
        return 0;
    }
    cout << mini << endl;
    cout << bomb_pos.first << " " << bomb_pos.second << endl;
}