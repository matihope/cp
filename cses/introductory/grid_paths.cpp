#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct Path {
    string p;
    int v = 0, h = 0;
    vector<vector<bool>> vis;
    Path() {
        vis.assign(7, vector<bool>(7, 0));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Path> paths;
    queue<Path> q;
    q.push({});
    while(!q.empty()){
        Path p = q.front(); q.pop();
        if(p.p.size() == 48){
            if(p.h == 0 && p.v == 6)
                paths.push_back(p);
            cout << q.size() << '\n';
            continue;
        }
        if(p.h - 1 >= 0 && !p.vis[p.v][p.h - 1]){
            Path p2 = p;
            p2.h--;
            p2.p += "L";
            p2.vis[p2.v][p2.h] = true;
            q.push(p2);
        }

        if(p.h + 1 <= 6 && !p.vis[p.v][p.h + 1]){
            Path p2 = p;
            p2.h++;
            p2.p += "R";
            p2.vis[p2.v][p2.h] = true;
            q.push(p2);
        }

         if(p.v - 1 >= 0 && !p.vis[p.v - 1][p.h]){
            Path p2 = p;
            p2.v--;
            p2.p += "U";
            p2.vis[p2.v][p2.h] = true;
            q.push(p2);
        }

        if(p.v + 1 <= 6 && !p.vis[p.v + 1][p.h]){
            Path p2 = p;
            p2.v++;
            p2.p += "D";
            p2.vis[p2.v][p2.h] = true;
            q.push(p2);
        }
    }
}
