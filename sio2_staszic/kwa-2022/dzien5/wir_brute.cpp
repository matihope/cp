#include <bits/stdc++.h>

using namespace std;

struct segtree{
    int size;
    vector<int> t;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
        build(1, 0, size - 1);
    }

    void build(int x, int tl, int tr){
        if(tl == tr){
            t[x] = 1;
        } else {
            int m = (tl + tr) / 2;
            build(x * 2, tl, m);
            build(x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int pos, int x, int tl, int tr){
        if(tl == tr){
            t[x] = 0;
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                set(pos, x * 2, tl, m);
            else
                set(pos, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int pos){
        set(pos, 1, 0, size - 1);
    }

    int query(int kth, int x, int tl, int tr){
        if(tl == tr){
            return tl;
        } else {
            int m = (tl + tr) / 2;
            if(kth <= t[x * 2])
                return query(kth, x * 2, tl, m);
            return query(kth - t[x * 2], x * 2 + 1, m + 1, tr);
        }
    }

    int query(int kth){
        return query(kth, 1, 0, size - 1);
    }

};

struct vert: vector<int>{
    int parent = -1;
    int scc_parent = 0;
    int children = 0;
};
vector<vert> graph;
int n, x1, a, b;

void dfs_init(int v, int p, int scc_parent){
    graph[v].parent = p;
    graph[v].scc_parent = scc_parent;
    graph[v].children = 1;
    for(auto& c: graph[v]){
        if(c != p){
            dfs_init(c, v, scc_parent);
            graph[v].children += graph[c].children; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x1;
    vector<int> g(n - 2);
    graph.assign(n + 1, {});
    for(int i = 0; i < n - 2; ++i){
        cin >> g[i];
    }
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    segtree st;
    st.init(n + 1);
    st.set(0);
    st.set(1);
    dfs_init(1, 1, 1);
    for(int i = 1; i < n; ++i){
        st.set(x1);
        vert& parent = graph[graph[x1].parent];
        for(size_t i = 0; i < parent.size(); ++i){
            if(parent[i] == x1){
                parent.erase(parent.begin() + i);
                break;
            }
        }
        for(size_t i = 0; i < graph[x1].size(); ++i){
            if(graph[x1][i] == graph[x1].parent){
                graph[x1].erase(graph[x1].begin() + i);
                break;
            }
        }
        int old_scc = graph[x1].scc_parent;
        int x = graph[x1].parent;
        dfs_init(x, x, x);
        dfs_init(old_scc, old_scc, old_scc);
        // cout << "X1: " << x1 << endl;
        cout << graph[x1].children << endl;
        if(i + 1 < n){
            x1 = st.query((graph[x1].children + g[i - 1]) % (n - i - 1) + 1);
        }
    }
}