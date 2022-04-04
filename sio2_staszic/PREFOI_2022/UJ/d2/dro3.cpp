#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct vert: vector<int> {
    int parent;
    long long depth = 0;
    int children = 0;
    int pre_order_pos = 0;
};
vector<vert> graph;
int preord;

void dfs(int v, int p){
    graph[v].parent = p;
    graph[v].depth = graph[p].depth + 1;
    graph[v].pre_order_pos = preord++;
    for(auto& c: graph[v]){
        if(c != p){
            dfs(c, v);
            graph[v].children += 1 + graph[c].children;
        }
    }
}

struct segtree{
    int size;
    vector<long long> op;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(size * 2, 0);
    }

    void add(int l, int r, long long val, int x, int tl, int tr){
        if(l > r) return;
        if(tl == l && tr == r){
            op[x] += val;
        } else {
            int m = (tl + tr) / 2;
            add(l, min(r, m), val, x * 2, tl, m);
            add(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
        }
    }

    void add(int l, int r, long long val){
        add(l, r, val, 1, 0, size - 1);
    }

    long long query(int pos, int x, int tl, int tr){
        if(tl == tr){
            return op[x];
        }
        int m = (tl + tr) / 2;
        if(pos <= m)
            return op[x] + query(pos, x * 2, tl, m);
        return op[x] + query(pos, x * 2 + 1, m + 1, tr);
    }

    long long query(int pos){
        return query(pos, 1, 0, size - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        int n, q, a, b;
        cin >> n >> q;
        graph.clear();
        graph.assign(n + 1, {});
        for(int i = 1; i < n; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        preord = 0;
        dfs(1, 1);
        int op, x, d;
        segtree st1, st2;
        st1.init(n);
        st2.init(n);
        while(q--){
            cin >> op >> x;
            int l = graph[x].pre_order_pos, r = graph[x].pre_order_pos + graph[x].children;
            if(op == 1){
                cin >> d;
                st1.add(l, r, d - graph[x].depth * d);
                st2.add(l, r, d);
            } else {
                cout << st1.query(l) + st2.query(l) * graph[x].depth << endl;
            }
        }
    }
}