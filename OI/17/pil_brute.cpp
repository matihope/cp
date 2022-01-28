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
#define INF 2000000002
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

struct el{
    int mi, ma;
};

struct segtree{
    int size;
    vector<el> t;

    el NEUTRAL_EL = {INF, -INF};

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, NEUTRAL_EL);
    }

    void build(VI& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(tl < inpt.size()){
                t[x] = {inpt[tl], inpt[tl]};
            }
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
            t[x].mi = min(t[x * 2].mi, t[x * 2 + 1].mi);
            t[x].ma = max(t[x * 2].ma, t[x * 2 + 1].ma);
        }
    }

    int query_min(int l, int r, int x, int tl, int tr){
        if(l > r) return NEUTRAL_EL.mi;
        if(l == tl && r == tr){
            return t[x].mi;
        } else {
            int m = (tl + tr) / 2;
            return min(
                query_min(l, min(r, m), x * 2, tl, m),
                query_min(max(l, m + 1), r, x * 2 + 1, m + 1, tr)
            );
        }
    }

    int query_max(int l, int r, int x, int tl, int tr){
        if(l > r) return NEUTRAL_EL.ma;
        if(l == tl && r == tr){
            return t[x].ma;
        } else {
            int m = (tl + tr) / 2;
            return max(
                query_max(l, min(r, m), x * 2, tl, m),
                query_max(max(l, m + 1), r, x * 2 + 1, m + 1, tr)
            );
        }
    }

    int query_min(int l, int r){
        return query_min(l, r, 1, 0, size - 1);
    }

    int query_max(int l, int r){
        return query_max(l, r, 1, 0, size - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t >> n;
    segtree st;
    st.init(n);
    VI poms(n);
    REP(i, n) cin >> poms[i];
    st.build(poms, 1, 0, st.size - 1);
    int max_len = 1;
    int head = 1;
    for(int tail = 0; tail < n; ++tail) {
        if(head == tail) head++;
        while(head < n && abs(st.query_min(tail, head - 1) - poms[head]) <= t && abs(st.query_max(tail, head - 1) - poms[head]) <= t)
            head++;
        
        max_len = max(max_len, head - tail);
    }
    cout << max_len << endl;


    return 0;
}