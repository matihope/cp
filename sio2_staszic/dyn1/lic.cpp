#include <bits/stdc++.h>

using namespace std;

struct segtree{
    vector<int> maxis;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        maxis.assign(size * 2, 0);
    }

    void set(int val, int pos, int x, int tl, int tr){
        if(tl == tr){
            maxis[x] = val;
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                set(val, pos, x * 2, tl, m);
            else
                set(val, pos, x * 2 + 1, m + 1, tr);
            maxis[x] = max(maxis[x * 2], maxis[x * 2 + 1]);
        }
    }

    void set(int val, int pos){
        set(val, pos, 1, 0, size - 1);
    }

    int query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        if(tl == l && tr == r)
            return maxis[x];
        int m = (tl + tr) / 2;
        int q1 = query(l, min(r, m), x * 2, tl, m); 
        int q2 = query(max(m + 1, l), r, x * 2 + 1, m + 1, tr); 
        return max(q1, q2);
    }

    int query(int l, int r){
        return query(l, r, 1, 0, size - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    typedef tuple<int, int, int> TP;
    vector<TP> v(n); // value, index_read, index_scaled
    segtree st;
    st.init(n);
    for(int i = 0; i < n; ++i){
        cin >> get<0>(v[i]);
        get<1>(v[i]) = i;
        get<2>(v[i]) = 0;
    }
    sort(v.begin(), v.end(), [&](const TP a, const TP b){ return get<0>(a) < get<0>(b); });
    for(int i = 1; i < v.size(); i++){
        get<2>(v[i]) = get<2>(v[i - 1]);
        if(get<0>(v[i]) != get<0>(v[i - 1]))
            get<2>(v[i])++;
    }
    sort(v.begin(), v.end(), [&](const TP a, const TP b){ return get<1>(a) < get<1>(b); });
    for(int i = 0; i < n; ++i){
        st.set(st.query(0, get<2>(v[i]) - 1) + 1, get<2>(v[i]));
    }
    cout << st.maxis[1] << endl;
}