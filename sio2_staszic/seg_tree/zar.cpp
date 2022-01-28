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

struct segtree{
    int size;
    vector<int> t;
    vector<int> marked;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        marked.assign(size * 2, 0);
        t.assign(size * 2, 0);
    }
    
    void push_down(int x){
        if(marked[x]){
            t[x * 2] ^= true;
            t[x * 2 + 1] ^= true;
            marked[x * 2] ^= true;
            marked[x * 2 + 1] ^= true;
            marked[x] = false;
        }
    }
    
    void build(VI& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(SIZE(inpt) > tl)
                t[x] = inpt[tl];
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
        }
    }
    
    void build(VI& inpt){
        build(inpt, 1, 0, size - 1);
    }
    
    void swi(int l, int r, int x, int tl, int tr){
        if(l == tl && r == tr){
            marked[x] ^= true;
            t[x] ^= true;
        } else {
            push_down(x);
            int m = (tl + tr) / 2;
            if(l <= min(r, m))
                swi(l, min(r, m), x * 2, tl, m);
            if(max(m + 1, l) <= r)
                swi(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        }
    }
    
    void swi(int l, int r){
        swi(l, r, 1, 0, size - 1);
    }
    
    int query(int p, int x, int tl, int tr){
        if(tl == tr){
            return t[x];
        } else {
            push_down(x);
            int m = (tl + tr) / 2;
            if(p <= m)
                return query(p, x * 2, tl, m);
            else
                return query(p, x * 2 + 1, m + 1, tr);
        }
    }
    
    int query(int p){
        return query(p, 1, 0, size - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q, a, b;
    cin >> n >> q;
    string init, cmd;
    cin >> init;
    segtree st;
    st.init(n);
    VI inpt(n);
    REP(i, n) inpt[i] = (init[i] == 'o');
    st.build(inpt);
    
    while(q--){
        cin >> cmd >> a;
        if(cmd == "Q"){
            if(st.query(a - 1))
                cout << "ON" << endl;
            else
                cout << "OFF" << endl;
        } else {
            cin >> b;
            st.swi(a - 1, b - 1);
        }
    }

    return 0;
}
