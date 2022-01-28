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
    vector<LL> muls;
    vector<LL> sums;

    long long NEUTRAL_ELEMENT = 0;

    LL modifying_operation(LL a, LL b, LL seg_len){
        return a + b * seg_len;
    }

    LL calculating_operation(LL a, LL b){
        return a + b;
    }

    void apply_modifying_operation(LL& a, LL b, LL seg_len){
        a = modifying_operation(a, b, seg_len);
    }

    // void build(int x, int tl, int tr){
    //     if(tl == tr){
    //         sums[x] = 0;
    //     } else {
    //         int m = (tl + tr) / 2;
    //         build(x * 2, tl, m);
    //         build(x * 2 + 1, m + 1, tr);
    //         sums[x] = calculating_operation(sums[x * 2], sums[x * 2 + 1]);
    //     }
    // }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        muls.assign(size * 2, 0);
        sums.assign(size * 2, 0);
        // build(1, 0, size - 1);
    }

    void set(int l, int r, int val, int x, int tl, int tr){
        if(l > r) return;
        if(tl == l && tr == r){
            apply_modifying_operation(muls[x], val, 1);
            apply_modifying_operation(sums[x], val, tr - tl + 1);
        } else {
            int m = (tl + tr) / 2;
            set(l, min(r, m), val, x * 2, tl, m);
            set(max(l, m + 1), r, val, x * 2 + 1, m + 1, tr);
            sums[x] = calculating_operation(sums[x * 2], sums[x * 2 + 1]);
            apply_modifying_operation(sums[x], muls[x], tr - tl + 1);
        }
    }

    LL get(int l, int r, int x, int tl, int tr){
        if(l > r) return NEUTRAL_ELEMENT;
        if(tl == l && tr == r){
            return sums[x];
        }
        int m = (tl + tr) / 2;
        LL res1 = get(l, min(r, m), x * 2, tl, m);
        LL res2 = get(max(l, m + 1), r, x * 2 + 1, m + 1, tr);
        LL res3 = calculating_operation(res1, res2);
        apply_modifying_operation(res3, muls[x], r - l + 1);
        return res3;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, c, d;
    cin >> n >> m;
    segtree st;
    st.init(n);
    REP(_, m){
        cin >> a >> b >> c;
        if(a == 1){
            cin >> d;
            st.set(b, c - 1, d, 1, 0, st.size - 1);
        } else {
            cout << st.get(b, c - 1, 1, 0, st.size - 1) << " ";
        }
    }

    return 0;
}