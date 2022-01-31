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
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
    }

    void build(VI& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(inpt.size() > tl){
                if(tl % 2 == 0)
                    t[x] = -inpt[tl];
                else
                    t[x] = inpt[tl];
            }
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void build(VI& inpt){
        build(inpt, 1, 0, size - 1);
    }

    void set(int val, int vert, int x, int tl, int tr){
        if(tl == tr){
            if(tl % 2 == 0)
                t[x] = -val;
            else
                t[x] = val;
        }
        else {
            int m = (tl + tr) / 2;
            if(vert <= m)
                set(val, vert, x * 2, tl, m);
            else
                set(val, vert, x * 2 + 1, m + 1, tr);
            t[x] = t[x * 2] + t[x * 2 + 1];
        }
    }

    void set(int val, int vert){
        set(val, vert, 1, 0, size - 1);
    }

    LL query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        if(tl == l && tr == r)
            return t[x];
        int m = (tl + tr) / 2;
        return query(l, min(r, m), x * 2, tl, m) + query(max(l, m + 1), r, x * 2 + 1, m + 1, tr);
    }

    LL query(int l, int r){
        LL res = query(l, r, 1, 0, size - 1);
        if(l == r){
            return abs(res);
        }
        if(l % 2 == 0)
            return -res;
        return res;
    }

    void print(){
        int i = 1;
        while(i <= size){
            for(int j = i; j < i * 2; ++j){
                cout << t[j] << " ";
            }
            cout << endl;
            i *= 2;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n++;
    VI inpt(n , 0);
    for(int i = 1; i < n; ++i){
        cin >> inpt[i];
    }
    
    segtree st;
    st.init(n);
    st.build(inpt);

    cin >> n;
    int a, b, c;
    REP(i, n){
        cin >> a >> b >> c;
        if(a == 0){
            st.set(c, b);
            // st.print();
        }
        else 
            cout << st.query(b, c) << endl;
    }

    return 0;
}