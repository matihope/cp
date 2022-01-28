#include <bits/stdc++.h>

using namespace std;

struct vert{
    size_t pos = -1;
    size_t len = 0;
    int dist = 0;
    vector<int> conns;
};

vector<vert> graph;
vector<int> pre;
vector<bool> vis;

void dfs(int v){
    graph[v].pos = pre.size();
    pre.push_back(v);
    vis[v] = true;
    for(auto c: graph[v].conns){
        if(!vis[c]){
            graph[c].dist = graph[v].dist + 1;
            dfs(c);
            graph[v].len += graph[c].len + 1;
        }
    }
}

struct segtree{
    vector<int> t;
    vector<bool> marked;
    vector<int> op;
    int size;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
        marked.assign(size * 2, 0);
        op.assign(size * 2, 0);
        build(1, 0, size - 1);
    }
    void build(int x, int tl, int tr){
        if(tl == tr){
            if(t.size() > tl){
                t[x] = graph[pre[tl]].dist;
            }
        } else {
            int m = (tl + tr) / 2;
            build(x * 2, tl, m);
            build(x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void push(int x, int tl, int tr){
        if(tl == tr) return;
        if(marked[x]){
            marked[x * 2] = marked[x * 2 + 1] = true;
            marked[x] = false;
            op[x * 2] += op[x];
            op[x * 2 + 1] += op[x];
            t[x * 2] += op[x];
            t[x * 2 + 1] += op[x];
            op[x] = 0;

        }
    }

    void sub(int l, int r, int x, int tl, int tr){
        if(l > r) return;
        push(x, tl, tr);
        if(tl == l && tr == r){
            marked[x] = true;
            op[x]--;
            t[x]--;
        } else {
            int m = (tl + tr) / 2;
            sub(l, min(r, m), x * 2, tl, m);
            sub(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void sub(int l, int r){
        sub(l, r, 1, 0, size - 1);
    }

    int query(int pos, int x, int tl, int tr){
        if(tl == tr)
            return t[x];
        push(x, tl, tr);
        int m = (tl + tr) / 2;
        if(pos <= m)
            return query(pos, x * 2, tl, m);
        return query(pos, x * 2 + 1, m + 1, tr);
    }

    int query(int pos){
        return query(pos, 1, 0, size - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, a, b, m;
    char op;
    cin >> n;
    graph.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].conns.push_back(a);
    }
    cin >> m;
    dfs(1);
    segtree st;
    st.init(n);
    for(int i = 0; i < m + n - 1; ++i){
        cin >> op >> a;
        if(op == 'A'){
            cin >> b;
            st.sub(graph[b].pos, graph[b].pos + graph[b].len);
        } else {
            cout << st.query(graph[a].pos) << endl;
        }
    }

}