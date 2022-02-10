#include <bits/stdc++.h>

using namespace std;

struct segtree_children{
    int size;
    vector<int> t;
    vector<int> op;
    vector<bool> marked;

    void init(int n, int start){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, start);
        op.assign(size * 2, 0);
        marked.assign(size * 2, 0);
    }

    void push(int x, int tl, int tr){
        if(tl == tr) return;
        if(marked[x]){
            marked[x * 2] = marked[x * 2 + 1] = true;
            marked[x] = false;
            t[x * 2] = op[x];
            t[x * 2 + 1] = op[x];
            op[x * 2] = op[x];
            op[x * 2 + 1] = op[x];
        }
    }
    
    void set(int l, int r, int val, int x, int tl, int tr){
        if(l > r) return;
        push(x, tl, tr);
        if(l == tl && r == tr){
            marked[x] = true;
            op[x] = val;
            t[x] = val;
        } else {
            int m = (tl + tr) / 2;
            set(l, min(r, m), val, x * 2, tl, m);
            set(max(l, m + 1), r, val, x * 2 + 1, m + 1, tr);
        }
    }

    int query(int pos, int x, int tl, int tr){
        if(tl == tr){
            return t[x];
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                return query(pos, x * 2, tl, m);
            else 
                return query(pos, x * 2 + 1, m + 1, tr);
        }
    }
};

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
        if (tl == tr){
            t[x] = 1;
        } else {
            int m = (tl + tr) / 2;
            build(x * 2, tl, m);
            build(x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int v, int x, int tl, int tr){
        if (tl == tr){
            t[x] = !t[x];
        } else {
            int m = (tl + tr) / 2;
            if(v <= m)
                set(v, x * 2, tl, m);
            else
                set(v, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int v){
        set(v, 1, 0, size - 1);
    }

    int query(int kth, int x, int tl, int tr){
        if(tl == tr)
            return tl;        
        int left = t[x * 2];
        int m = (tl + tr) / 2;
        if(kth <= left)
            return query(kth, x * 2, tl, m);
        return query(kth - left, x * 2 + 1, m + 1, tr);
    }

    int query(int kth){
        return query(kth, 1, 0, size - 1) + 1;
    }

};

segtree_children st_ch;
segtree_children st_father;
segtree st_kth;

struct vert: vector<int>{
    int parent = -1;
    int children = 0;
    int pos = 0; 
};
vector<vert> graph;
vector<int> cool_pre;
int n, x1, a, b;

void dfs(int v, int p){
    graph[v].parent = p;
    graph[v].pos = cool_pre.size();
    cool_pre.push_back(v);
    for(auto c: graph[v]){
        if(c != p){
            dfs(c, v);
            graph[v].children += 1 + graph[c].children; 
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x1;
    st_kth.init(n);
    st_ch.init(n, n - 1);
    st_father.init(n, 1);
    vector<int> g(n);
    graph.assign(n + 1, {});
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
    for(int i = 0; i < n - 2; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    st_kth.set(0);
    dfs(1, 1);
    cout << st_kth.query(5) << endl;
    for(int i = 1; i < n; ++i){
        st_kth.set(x1);
        st_father.set(graph[x1].pos + graph[x1].children);
    }
}