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
    VI t;
    int size;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        t.assign(size * 2, INF);
    }   
    
    void build(VI& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(SIZE(inpt) > tl){
                t[x] = inpt[tl];
            }
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }
    
    void build(VI& inpt){
        build(inpt, 1, 0, size - 1);
    }
    
    void set(int pos, int val, int x, int tl, int tr){
        if(tl == tr){
            t[x] = val;
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                set(pos, val, x * 2, tl, m);
            else
                set(pos, val, x * 2 + 1, m + 1, tr);
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }
    
    void set(int pos, int val){
        set(pos, val, 1, 0, size - 1);
    }
    
    int query(int lowest_val, int x, int tl, int tr){
        if(tl == tr){   
            return tl;
        } else {
            int m = (tl + tr) / 2;
            if(t[x * 2] > lowest_val)
                return query(lowest_val, x * 2, tl, m);
            return query(lowest_val, x * 2 + 1, m + 1, tr);
        }
    }
    
    int query(int lowest_val){
        return query(lowest_val, 1, 0, size - 1);
    }
    
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, counter = 0;
    cin >> n;
    segtree st;
    st.init(n);
    VI inpt(n);
    FOREACH(i, inpt) cin >> *i;
    st.build(inpt);
    for(int i = 0; i < n; ++i){
        int val = inpt[i];
        int pos = st.query(val);
        while(pos < i){
            if(inpt[pos++] > val){
                counter++;
            }
        }
    }
    
    cout << counter << endl;
    

    return 0;
}
