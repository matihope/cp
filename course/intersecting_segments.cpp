#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

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

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
    }

    void set(int vert, int val, int x, int tl, int tr){
        if(tl == tr){
            t[x] = val;
        } else {
            int m = (tl + tr) / 2;
            if(vert <= m){
                set(vert, val, x * 2, tl, m);
            } else
                set(vert, val, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int vert, int val){
        set(vert, val, 1, 0, size - 1);
    }

    LL query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        if(tl == l && tr == r)
            return t[x];
        int m = (tl + tr) / 2;
        return query(l, min(r, m), x * 2, tl, m) + query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
    }

    LL query(int l, int r){
        return query(l, r, 1, 0, size - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;
    VI ans(n, 0);
    VI inpt(2 * n);
    for(auto& x: inpt) cin >> x;
    REP(_, 2){
        segtree st;
        VI first_time(n + 1, -1);
        st.init(n * 2);
        REP(i, n * 2){
            a = inpt[i];
            if(first_time[a] == -1){
                first_time[a] = i;
                st.set(i, 1);
            } else {
                int res = st.query(first_time[a] + 1, i);
                ans[a - 1] += res;
                st.set(first_time[a], 0);
            }
        }
        cout << endl;
        reverse(ALL(inpt));
    }
    for(auto x: ans){
        cout << x << " ";
    }


    return 0;
}