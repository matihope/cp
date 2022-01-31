#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <cmath>
 
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
 
struct item {
    LL pref, seg, suf, sum;
};
 
struct segtree{
    LL size;
    vector<item> t;
    vector<bool> marked;
 
    const item NEUTRAL_ELEMENT = {0, 0, 0, 0};
 
    void init(LL n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, NEUTRAL_ELEMENT);
        marked.assign(size * 2, false);
    }
 
    item div_by_2(LL v){
        item cpy = t[v];
        cpy.pref /= 2;
        cpy.seg /= 2;
        cpy.suf /= 2;
        cpy.sum /= 2;
        return cpy;
    }

    void push_down(LL x){
        if(marked[x]){
            t[x * 2] = t[x * 2 + 1] = div_by_2(x);
            marked[x * 2] = marked[x * 2 + 1] = true;
            marked[x] = false;
        }
    }

    item single(LL v, LL len){
        v *= len;
        if (v > 0) 
            return {v, v, v, v};
        return {0, 0, 0, v};
    }
 
    const item merge(item& a, item& b){
        return {
            max(a.pref, a.sum + b.pref), // pref
            max(a.seg, max(b.seg, a.suf + b.pref)), // seg
            max(b.suf, b.sum + a.suf), // suf
            a.sum + b.sum
        };
    }
 
    void set(LL l, LL r, LL val, LL x, LL tl, LL tr){
        if(l > r) return;
        if(l == tl && tr == r) {
            t[x] = single(val, r - l + 1);
            marked[x] = true;
        } else {
            push_down(x);
            LL m = (tl + tr) / 2;
            set(l, min(m, r), val, x * 2, tl, m);
            set(max(l, m + 1), r, val, x * 2 + 1, m + 1, tr);
            t[x] = merge(t[x * 2], t[x * 2 + 1]);
        }
    }
 
    void set(LL l, LL r, LL val){
        set(l, r, val, 1, 0, size - 1);
    }
 
    LL query(){
        return t[1].seg;
    }
};
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    LL a, b, c;
    REP(i, m){
        cin >> a >> b >> c;
        st.set(a, b - 1, c);
        cout << st.query() << endl;
    }
    return 0;
}