#include <bits/stdc++.h>
#include "slo.h"

using namespace std;

#define LL long long

struct vert{
    vector<pair<int, int>> conns;
    int parent;
    bool visited;
    LL dist;
    int pos;
    int size_of_subtree = 0;
    int edge_to_me = 0;
};
int n = 0;
vector<vert> graph;
vector<int> tin, tout;
int L;
vector<vector<int>> up;
int timer = 0;
vector<int> numbers;

struct segtree{
    int size;
    vector<long long> delta;
    vector<bool> marked;
    vector<LL> op;

    void init(int s){
        size = 1;
        while(size < n) size *= 2;
        delta.assign(size * 2, 0);
        marked.assign(size * 2, 0);
        op.assign(size * 2, 0);
    }

    void push_down(int x, int tl, int tr){
        if(tl == tr) return;
        if(marked[x]){
            marked[x * 2] = marked[x * 2 + 1] = true;
            op[x * 2] += op[x];
            op[x * 2 + 1] += op[x];
            delta[x * 2] += op[x];
            delta[x * 2 + 1] += op[x];
            op[x] = 0;
            marked[x] = false;
        }
    }

    LL query(int pos, int x, int tl, int tr){
        push_down(x, tl, tr);
        if(tl == tr){
            return delta[x];
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                return query(pos, x * 2, tl, m);
            else
                return query(pos, x * 2 + 1, m + 1, tr);
        }
    }

    LL query(int pos){
        return query(pos, 1, 0, size - 1);
    }

    void set(int l, int r, int val, int x, int tl, int tr){
        if(l > r) return;
        push_down(x, tl, tr);
        if(l == tl && r == tr){
            delta[x] += val;
            op[x] = val;
            marked[x] = true;
        } else {
            int m = (tl + tr) / 2;
            set(l, min(m, r), val, x * 2, tl, m);
            set(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
            delta[x] = delta[x * 2] + delta[x * 2 + 1];
        }
    }

    void set(int l, int r, int val){
        set(l, r, val, 1, 0, size - 1);
    }
};

segtree st;


void dfs(int v, int p){
    graph[v].pos = numbers.size();
    numbers.push_back(v);
    graph[v].visited = true;
    tin[v] = timer++;
    up[v][0] = p;
    for(int i = 1; i <= L; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(auto& c: graph[v].conns){
        if(!graph[c.first].visited){
            graph[c.first].visited = true;
            graph[c.first].parent = v;
            graph[c.first].dist = graph[v].dist + c.second;
            graph[c.first].edge_to_me = c.second;
            dfs(c.first, v);
            graph[v].size_of_subtree += graph[c.first].size_of_subtree + 1;
        }
    }
    tout[v] = timer++;
}

void preprocess(int v){
    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    dfs(1, 1);
    st.init(n);
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;
    for(int i = L; i >= 0; --i)
        if(!is_ancestor(up[b][i], a)) b = up[b][i];
    return up[b][0];
}

void init(vector<tuple<int, int, int>> edges){
    n = int(edges.size()) + 1;
    graph.assign(n + 1, {});
    for(auto& t: edges){
        graph[get<0>(t)].conns.emplace_back(get<1>(t), get<2>(t));
        graph[get<1>(t)].conns.emplace_back(get<0>(t), get<2>(t));
    }
    preprocess(1);
}

int distance(int a, int b){
    int l = lca(a, b);
    LL dist1 = graph[a].dist + st.query(graph[a].pos);
    LL dist2 = graph[b].dist + st.query(graph[b].pos);
    LL distLCA = graph[l].dist + st.query(graph[l].pos);
    if(a == l)
        return dist2 - dist1;
    if(b == l)
        return dist1 - dist2;
    return dist1 + dist2 - distLCA * 2;
}

void change(int a, int b, int c){
    if(is_ancestor(a, b)){
        st.set(graph[b].pos, graph[b].pos + graph[b].size_of_subtree, c - graph[b].edge_to_me);
        graph[b].edge_to_me = c;
    } else {
        st.set(graph[a].pos, graph[a].pos + graph[a].size_of_subtree, c - graph[a].edge_to_me);
        graph[a].edge_to_me = c;
    }
}

#ifdef LOCAL_H 
 int main(){
     int x, a, b, c;
     char op;
     cin >> x;
     vector<tuple<int, int, int>> edges;
     while(--x){
         cin >> a >> b >> c;
         edges.emplace_back(a, b, c);
     }
     init(edges);
     cin >> op;
     while(op != 'x'){
         cin >> a >> b;
         if(op == '*'){
             cin >> c;
             change(a, b, c);
         } else {
             cout << distance(a, b) << endl;
         }
         cin >> op;
     }

 }
 #endif
