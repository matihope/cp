#include <bits/stdc++.h>

using namespace std;

struct segtree{
    int size;
    vector<int> t;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
    }

    void reset(){
        t.assign(size * 2, 0);
    }

    void set(int pos, int x, int tl, int tr){
        if(tl == tr){
            t[x] = 1;
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

    int query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        if(l == tl && r == tr)
            return t[x];
        int m = (tl + tr) / 2;
        auto res1 = query(l, min(m, r), x * 2, tl, m);
        auto res2 = query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        return res1 + res2;
    }

    int query(int l){
        return query(l, size - 1, 1, 0, size - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a;
    cin >> n >> m;
    segtree st;
    st.init(n + 1);
    int counter = 0;
    vector<int> tab;
    for(int i = 0; i < n; ++i){
        cin >> a;
        counter += st.query(a);
        st.set(a);
        tab.push_back(a);
    }
    for(int i = 0; i < m; ++i){
        cout << counter << endl;
        counter = 0;
        st.reset();
        cin >> a;
        for(int j = 0; j < tab.size(); ++j){
            if(tab[j] == a){
                tab.erase(tab.begin() + j);
                j--;
            } else {
                counter += st.query(tab[j]);
                st.set(tab[j]);
            }
        }
        
    }
}