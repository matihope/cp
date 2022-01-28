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
    VI vals;
    vector<vector<int>> t;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        vals.assign(n, 0);
        t.assign(6, VI(size * 2));
        build(1, 0, size - 1);
    }
    
    void build(int x, int tl, int tr){
        if(tl == tr){
            FOR(i, 1, 5)
                t[i][x] = 1;
        } else {
            int m = (tl + tr) / 2;
            build(x * 2, tl, m);
            build(x * 2 + 1, m + 1, tr);
            FOR(i, 1, 5)
                t[i][x] = t[i][x * 2] + t[i][x * 2 + 1];
        }
    }    
    
    void add(int pos, int val, int x, int tl, int tr){
        if(tl == tr){
            vals[tl] += val;
            FOR(i, 1, 5) t[i][x] = (vals[tl] % i == 0);
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                add(pos, val, x * 2, tl, m);
            else
                add(pos, val, x * 2 + 1, m + 1, tr);
            FOR(i, 1, 5)
                t[i][x] = t[i][x * 2] + t[i][x * 2 + 1];
        }
    }
    
    void add(int pos, int val){
        add(pos, val, 1, 0, size - 1);
    }
    
    int query(int l, int r, int k, int x, int tl, int tr){
        if(l > r) return 0;
        if(l == tl && r == tr){
            return t[k][x];
        } else {
            int m = (tl + tr) / 2;
            return 
                query(l, min(m, r), k, x * 2, tl, m) + 
                query(max(m + 1, l), r, k, x * 2 + 1, m + 1, tr);
        }
    }
    
    int query(int l, int r, int val){
        return query(l, r, val, 1, 0, size - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q, a, b, c;
    string cmd;
    cin >> n >> q;
    segtree st;
    st.init(n + 1);
    while(q--){
        cin >> cmd >> a >> b;
        if(cmd == "DODAJ"){
            st.add(a, b);
        } else {
            cin >> c;
            cout << st.query(a, b, c) << endl;
        }
    }

    return 0;
}
