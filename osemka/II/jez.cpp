#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

vector<int> rep;

int Find(int a){
    if(rep[a] == a)
        return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    rep[Find(a)] = Find(b);
}

struct Jez{
    int x, y, w, h, id;
};

enum EV_TYPE{
    ADD,
    REM
};

struct Event {
    EV_TYPE type;
    Jez j;
    int get_y() const {
        if(type == EV_TYPE::ADD)
            return j.y;
        return j.y + j.h;
    }
};

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

    void _add(int l, int r, int val, int x, int tl, int tr){
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

    int n;
    cin >> n;
    rep.assign(n, 0);
    for(int i = 0; i < n; ++i)
        rep[i] = i;
    vector<Jez> jeziora(n, {0, 0, 0, 0, 0});
    auto cmp = [&](const Event a, const Event b) {
        return a.get_y() > b.get_y();
    };
    priority_queue<Event, vector<Event>, decltype(cmp)> q(cmp);
    for(int i = 0; i < n; ++i){
        cin >> jeziora[i].x >> jeziora[i].y >> jeziora[i].w >> jeziora[i].h;
        jeziora[i].id = i;
        q.push({EV_TYPE::ADD, jeziora[i]});
        q.push({EV_TYPE::REM, jeziora[i]});
    }
    cout << "Y" << endl;

    SegTree st;
    st.init(8);
    st.add(0, 7, 5);
    st.add(0, 0, -100);
    cout << st.query(0, 7) << endl;
}
