#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

typedef long long LL;
typedef long double LLD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;
typedef pair<int, int> PII;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define INF 1000000001
#define MP make_pair

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(LL t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(const string& t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(LLD t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ULL t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ST); cerr << ","; _print(p.ND); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int count_1_klasa = 0;

int n, m, g1, g2;

struct segtree{
    int size;
    vector<int> t, cnt, op;
    vector<bool> marked;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, -1);
        marked.assign(size * 2, 0);
        op.assign(size * 2, 0);
        cnt.assign(size * 2, 0);
    }
    
    void build(vector<int>& inpt, int min_to_be_hier, int x, int tl, int tr){
        if(tl == tr){
            if(SIZE(inpt) > tl && inpt[tl] >= min_to_be_hier){
                t[x] = inpt[tl];
                cnt[x] = 1;
                inpt[tl] = -1;
            }
        } else {
            int m = (tl + tr) / 2;
            build(inpt, min_to_be_hier, x * 2, tl, m);
            build(inpt, min_to_be_hier, x * 2 + 1, m + 1, tr);
            t[x] = max(t[x * 2], t[x * 2 + 1]);
            cnt[x] = cnt[x * 2] + cnt[x * 2 + 1];
        }
    }

    void push_down(int x, int tl, int tr){
        if(tl == tr) return;
        if(marked[x]){
            if(t[x * 2] >= 0){
                t[x * 2] += op[x];
                op[x * 2] += op[x];
                marked[x * 2] = true; 
            }
            if(t[x * 2 + 1] >= 0){
                t[x * 2 + 1] += op[x];
                op[x * 2 + 1] += op[x];
                marked[x * 2 + 1] = true; 
            }
            op[x] = 0;
            marked[x] = false;
        }
    }

    void add_on_seg(int l, int r, int val, int x, int tl, int tr){
        if(l > r || t[x] == -1) return;
        push_down(x, tl, tr);
        if(l == tl && r == tr){
            if(t[x] >= 0){
                marked[x] = true;
                op[x] += val;
                t[x] += val;
            }
        } else {
            int m = (tl + tr) / 2;
            add_on_seg(l, min(r, m), val, x * 2, tl, m);
            add_on_seg(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }

    void add_on_seg(int l, int r, int val){
        add_on_seg(l, r, val, 1, 0, size - 1);
    }

    int query_first_at_least_k(int k, int x, int tl, int tr){
        if(t[x] < k) return -1;
        push_down(x, tl, tr);
        if(tl == tr){
            return tl;
        } else {
            int m = (tl + tr) / 2;
            if(t[x * 2] >= k)
                return query_first_at_least_k(k, x * 2, tl, m);
            if(t[x * 2 + 1] >= k)
                return query_first_at_least_k(k, x * 2 + 1, m + 1, tr);
            return -1;
        }
    }

    int query_first_at_least_k(int k){
        return query_first_at_least_k(k, 1, 0, size - 1);
    }

    void set_el(int pos, int val, int x, int tl, int tr){
        push_down(x, tl, tr);
        if(tl == tr){
            t[x] = val;
            if(val >= 0) cnt[x] = 1;
            else cnt[x] = 0;
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m){
                set_el(pos, val, x * 2, tl, m);
            } else {
                set_el(pos, val, x * 2 + 1, m + 1, tr);
            }
            t[x] = max(t[x * 2], t[x * 2 + 1]);
            cnt[x] = cnt[x * 2] + cnt[x * 2 + 1];
        }
    }

    void set_el(int pos, int val){
        set_el(pos, val, 1, 0, size - 1);
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> g2 >> g1;

    vector<int> inpt(n);
    FOREACH(i, inpt) {
        cin >> *i;
        if(*i >= g1) {
            count_1_klasa++;
            *i = -1;
        }
    }
    segtree klasa2, klasa3;
    klasa2.init(n);
    klasa2.build(inpt, g2, 1, 0, klasa2.size - 1);
    klasa3.init(n);
    klasa3.build(inpt, 0, 1, 0, klasa3.size - 1);

    int a, b, x;
    REP(_, m){
        cin >> a >> b >> x;

        if (g2 > 0) g2--;
        if (g1 > 0) g1--;
        if(x > 0){
            klasa2.add_on_seg(a - 1, b - 1, x);
            klasa3.add_on_seg(a - 1, b - 1, x);
        }
        int K3toK2 = klasa3.query_first_at_least_k(g2);

        while(K3toK2 != -1){
            int marchew_to_transfer = klasa3.t[K3toK2 + klasa3.size];
            klasa3.set_el(K3toK2, -1);
            klasa2.set_el(K3toK2, marchew_to_transfer);
            K3toK2 = klasa3.query_first_at_least_k(g2);
        }

        int K2toK1 = klasa2.query_first_at_least_k(g1);
        while(K2toK1 != -1){
            count_1_klasa++;
            klasa2.set_el(K2toK1, -1);
            K2toK1 = klasa2.query_first_at_least_k(g1);
        }
        cout << count_1_klasa << " " << klasa2.cnt[1] << endl;
    }

    return 0;
}