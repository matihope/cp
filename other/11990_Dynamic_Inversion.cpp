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

struct container{
    vector<int> items, sorted_items;

    int bin_search_pos(int value){
        int l = 0, r = sorted_items.size() - 1, m;
        while(l < r){
            m = (l + r) / 2;
            if(sorted_items[m] < value)
                l = m + 1;
            else
                r = m;
        }
        if(sorted_items[l] < value) return sorted_items.size();
        return l;
    }
};
vector<container> conts;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a;
    cin >> n >> m;
    vector<int> tab(n, 0);
    vector<int> positions(n + 1, 0);
    int k = sqrt(n * log2(n));
    int n_over_k = ceil(double(n) / k);
    conts.assign(n_over_k, {});
    int to_k = 0;
    for(int i = 0; i < n; ++i){
        cin >> tab[i];
        positions[tab[i]] = i;
        conts[to_k++ / k].items.push_back(tab[i]);
    }

    // sort items
    for(auto& c: conts){
        c.sorted_items = c.items;
        sort(c.sorted_items.begin(), c.sorted_items.end());
    }
    long long counter = 0;
    segtree st;
    st.init(n + 1);
    for(int i = 0; i < n; ++i){
        counter += st.query(tab[i]);
        st.set(tab[i]);
    }
    for(int i = 0; i < m; ++i){
        cout << counter << endl;
        cin >> a;
        // if(i == m - 1) break;
        int pos = positions[a];
        // greater
        for(int j = 0; j < (pos / k); ++j)
            counter -= conts[j].items.size() - conts[j].bin_search_pos(a);
        // smaller
        for(int j = floor(pos / k) + 1; j < conts.size(); ++j)
            counter -= conts[j].bin_search_pos(a);
        
        container& cnt = conts[pos/k];
        int pos2 = -1;
        for(int j = 0; j < cnt.items.size(); ++j){
            if(cnt.items[j] > a && pos2 == -1)
                counter--;
            else if(cnt.items[j] < a && pos2 != -1)
                counter--;
            else if(cnt.items[j] == a)
                pos2 = j;
        }
        cnt.items.erase(cnt.items.begin() + pos2);
        cnt.sorted_items.erase(cnt.sorted_items.begin() + cnt.bin_search_pos(a));
    }
}