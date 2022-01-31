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
void _print(string t) {cerr << t;}
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

struct segtree{
    int size;
    vector<LL> t;
    vector<LL> lazy;

    LL NEUTRAL_ELEMENT = 0;
    LL NO_OPERATION = __LONG_LONG_MAX__ - 1;

    void assign_op(LL& a, LL b, LL len){
        if(b == NO_OPERATION) return;
        a = b * len;
    }

    LL calc_op(LL a, LL b){
        return a + b;
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0LL);
        lazy.assign(size * 2, 0LL);
    }

    void push_down(int x, int tl, int tr){
        if(tl == tr) return;
        int m = (tr - tl + 1) / 2;
        assign_op(t[x * 2], lazy[x], m);
        assign_op(t[x * 2 + 1], lazy[x], m);
        assign_op(lazy[x * 2], lazy[x], 1);
        assign_op(lazy[x * 2 + 1], lazy[x], 1);
        lazy[x] = NO_OPERATION;
    }

    void set(int l, int r, int val, int x, int tl, int tr){
        if(l > r)
            return;
        if(tl == l && tr == r){
            assign_op(lazy[x], val, 1);
            assign_op(t[x], val, tr - tl + 1);
        } else {
            push_down(x, tl, tr);
            int m = (tl + tr) / 2;
            set(l, min(r, m), val, x * 2, tl, m);
            set(max(l, m + 1), r, val, x * 2 + 1, m + 1, tr);
            t[x] = calc_op(t[x * 2], t[x * 2 + 1]);
        }
    }

    LL get(int l, int r, int x, int tl, int tr){
        if(l > r)
            return NEUTRAL_ELEMENT;
        if(tl == l && tr == r)
            return t[x];
        push_down(x, tl, tr);
        int m = (tl + tr) / 2;
        return calc_op(
            get(l, min(r, m), x * 2, tl, m),
            get(max(l, m + 1), r, x * 2 + 1, m + 1, tr)
        );
    } 

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, c, d;
    cin >> n >> m;
    segtree st;
    st.init(n);
    REP(_, m){
        cin >> a >> b >> c;
        --c;
        if(a == 1){
            cin >> d;
            st.set(b, c, d, 1, 0, st.size - 1);
        } else {
            cout << st.get(b, c, 1, 0, st.size - 1) << " ";
        }
    }

    return 0;
}