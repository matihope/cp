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
    vector<int> t;
    int ones;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
    }
    
    void build(vector<int>& inpt, int x, int tl, int tr){
        if (tl == tr){
            if(tl < inpt.size())
                t[x] = inpt[tl];
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void build(vector<int>& inpt, int ons){
        ones = ons;
        build(inpt, 1, 0, size - 1);
    }

    void set(int v, int x, int tl, int tr){
        if (tl == tr){
            t[x] = !t[x];
        } else {
            int m = (tl + tr) / 2;
            if(v <= m)
                set(v, x * 2, tl, m);
            else
                set(v, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int v){
        set(v, 1, 0, size - 1);
    }

    int query(int kth, int x, int tl, int tr, int l, int r){
        if(tl == tr)
            return tl;
        
        int left = t[x * 2];
        int right = t[x * 2 + 1];
        int m = (tl + tr) / 2;
        if(kth < l + left)
            return query(kth, x * 2, tl, m, l, r - right);
        else
            return query(kth, x * 2 + 1, m + 1, tr, l + left, right);
    }

    int query(int kth){
        return query(kth, 1, 0, size - 1, 0, ones - 1);
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ones = 0;
    cin >> n >> m;
    vector<int> inpt(n);
    for(auto& x : inpt){
        cin >> x;
        ones += x;
    }

    segtree st;
    st.init(n);
    st.build(inpt, ones);

    int a, b;
    REP(i, m){
        cin >> a >> b;
        if(a == 1){
            st.set(b);
        } else {
            cout << st.query(b) << "\n";
        }
    }

    return 0;
}