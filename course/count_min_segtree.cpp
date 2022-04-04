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
    VPII t;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, {INF, 1});
    }

    void build(vector<int>& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(tl < inpt.size())
                t[x] = {inpt[tl], 1};
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);

            if(t[x * 2].first == t[x * 2 + 1].first)
                t[x] = {t[x * 2].first, t[x * 2].second + t[x * 2 + 1].second};
            else
                t[x] = min(t[x * 2], t[x * 2 + 1]);
        }
    }

    void build(vector<int>& inpt){
        build(inpt,1, 0, size - 1);
    }

    void set(int v, int val, int x, int tl, int tr){
        if(tl == tr){
            t[x] = {val, 1};
        } else {
            int m = (tl + tr) / 2;
            if(v <= m)
                set(v, val, x * 2, tl, m);
            else
                set(v, val, x * 2 + 1, m + 1, tr);

            if(t[x * 2].first == t[x * 2 + 1].first)
                t[x] = {t[x * 2].first, t[x * 2].second + t[x * 2 + 1].second};
            else
                t[x] = min(t[x * 2], t[x * 2 + 1]);
        }
    }

    void set(int v, int val){
        set(v, val, 1, 0, size - 1);
    }

    PII query(int l, int r, int x, int tl, int tr){
        if(l > r) return {INF, INF};
        if(l == tl && r == tr)
            return t[x];
        int m = (tl + tr) / 2;
        PII q1 = query(l, min(m, r), x * 2, tl, m);
        PII q2 = query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        if(q1.first == q2.first){
            return {q1.first, q1.second + q2.second};
        }
        return min(q1, q2);
    }

    PII query(int l, int r){
        return query(l, r, 1, 0, size - 1);
    }

    void print(){
        int i = 1;
        int spaces = size;
        while(i <= size){
            if(spaces == 0)
                cout << " ";
            for(int j = i; j < i * 2; ++j){
                REP(_, spaces) cout << " ";
                cout << "(" << t[j].first << ", " << t[j].second << ") ";
            }
            cout << endl;
            spaces /= 2;
            if(spaces == 1) spaces /= 2;
            i *= 2;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> inpt(n);
    for(auto& x : inpt) cin >> x;

    segtree st;
    st.init(n);
    st.build(inpt);

    int a, b, c;
    REP(i, m){
        cin >> a >> b >> c;
        if(a == 1){
            st.set(b, c);
        } else {
            PII x = st.query(b, c - 1);
            cout << x.first << " " << x.second << "\n";
        }
    }

    return 0;
}