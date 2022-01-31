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
    vector<LL> operation;
    vector<bool> marked;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, 0);
        operation.assign(size * 2, 0);
        marked.assign(size * 2, false);
    }

    void push_down(int x){
        if(marked[x]){
            t[x * 2] += operation[x];
            t[x * 2 + 1] += operation[x];
            operation[x * 2] += operation[x];
            operation[x * 2 + 1] += operation[x];
            marked[x] = false;
            marked[x * 2] = marked[x * 2 + 1] = true;
        }
    }

    void set(int l, int r, int val, int x, int tl, int tr){
        if(l > r) return;
        if(tl == l && tr == r){
            t[x] += val;
            operation[x] += val;
            marked[x] = true;
        } else {
            push_down(x);
            int m = (tl + tr) / 2;
            set(l, min(m, r), val, x * 2, tl, m);
            set(max(m + 1, l), r, val, x * 2 + 1, m + 1, tr);
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }
    
    int query(int k, int pos, int x, int tl, int tr){
        if(tl == tr){
            if(k <= t[x] && pos <= tl)
                return tl;
            return -1;
        }
        push_down(x);
        int m = (tl + tr) / 2;
        if(k <= t[x * 2] && pos <= m){
            int res = query(k, pos, x * 2, tl, m);
            if(res >= 0) return res; 
        }
        return query(k, pos, x * 2 + 1, m + 1, tr);
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

    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    int a, b, c, d;
    REP(i, m){
        cin >> a >> b >> c;
        if(a == 1){
            cin >> d;
            st.set(b , c - 1, d, 1, 0, st.size - 1);
            // st.print();
        } else {
            cout << st.query(b, c, 1, 0, st.size - 1) << endl;
        }
    }

    return 0;
}