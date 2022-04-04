#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct segtree{
    int size;
    vector<long long> op;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(size * 2, 0);
    }

    void add(int l, int r, int val, int x, int tl, int tr){
        if(l > r) return;
        if(tl == l && tr == r){
            op[x] += val;
        } else {
            int m = (tl + tr) / 2;
            add(l, min(m, r), val, x * 2, tl, m);
            add(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
        }
    }

    void add(int l, int r, int val){
        add(l, r, val, 1, 0, size - 1);
    }

    long long get(int pos, int x, int tl, int tr){
        if(tl == tr){
            return op[x];
        }
        int m = (tl + tr) / 2;
        if(pos <= m)
            return op[x] + get(pos, x * 2, tl, m);
        return op[x] + get(pos, x * 2 + 1, m + 1, tr);
    }

    long long get(int pos){
        return get(pos, 1, 0, size - 1);   
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        int n, q;
        cin >> n >> q;

        vector<int> tab(n);
        long long sum = 0;

        segtree st;
        st.init(n + 1);

        auto adder = [&](const int& a){
            int prev = 1;
            if(a > 0)
                st.add(a, st.size - 1, 1);
            for(int j = 1; j * j <= a; ++j){
                if(a % j == 0){
                    st.op[st.size + j] += a / j;
                    st.add(a / j, a / prev - 1, j);
                    // st.add(a / prev - 1, a / j, j);
                    prev = j;
                }
            }
        };

        for(int i = 0; i < n; ++i){
            cin >> tab[i];
            sum += tab[i];
            adder(tab[i]);
        }
        
        int query, aj;
        while(q--){
            cin >> query >> aj;
            if(query == 1){
                tab[aj - 1]++;
            } else if(query == 2){
                tab[aj - 1]--;
            } else {
                if(aj == 1){
                    cout << sum << endl;
                } else {
                    cout << st.get(aj) << endl;
                }
            }
        }
    }
}