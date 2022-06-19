#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct SegTree {
    int size;
    vector<LL> vals;
    vector<LL> ops;
    vector<bool> marked;

    void push(int x, int tl, int tr){
        if(tl == tr) return;
        if(!marked[x]) return;

        ops[x * 2] += ops[x];
        ops[x * 2 + 1] += ops[x];
        vals[x * 2] += ops[x] * (tr - tl + 1) / 2;
        vals[x * 2 + 1] += ops[x] * (tr - tl + 1) / 2;
        ops[x] = 0;
        marked[x * 2] = marked[x * 2 + 1] = true;
        marked[x] = false;
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        vals.assign(size * 2, 0);
        ops.assign(size * 2, 0);
        marked.assign(size * 2, 0);
    }

    void _add(int l, int r, LL val, int x, int tl, int tr){
        if(l > r) return;
        push(x, tl, tr);
        if(l == tl && r == tr){
            vals[x] += val * (tr - tl + 1);
            ops[x] += val;
            marked[x] = true;
        } else {
            int m = (tl + tr) / 2;
            _add(l, min(m, r), val, x * 2, tl, m);
            _add(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
            vals[x] = vals[x * 2] + vals[x * 2 + 1];
        }
    }

    void add(int l, int r, int val){
        _add(l, r, val, 1, 0, size - 1);
    }

    LL _query(int l, int r, int x, int tl, int tr){
        push(x, tl, tr);
        if(l > r) return 0;
        if(l == tl && r == tr){
            return vals[x];
        } else {
            int m = (tl + tr) / 2;
            auto q1 = _query(l, min(m, r), x * 2, tl, m);
            auto q2 = _query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
            return q1 + q2;
        }
    }

    LL query(int l, int r){
        return _query(l, r, 1, 0, size - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;
    SegTree st;
    st.init(n);
    while(m--){
        cin >> a;
        if(a == 1){
            cin >> a >> b >> c;
            st.add(a, b - 1, c);
        } else {
            cin >> a >> b;
            cout << st.query(a, b - 1) << endl;
        }
    }
}
