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
    vector<LL> val;
    vector<LL> operation_set;
    vector<LL> operation_add;
    vector<bool> marked_set;
    vector<bool> marked_add;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        val.assign(size * 2, 0);
        operation_set.assign(size * 2, 0);
        operation_add.assign(size * 2, 0);
        marked_set.assign(size * 2, 0);
        marked_add.assign(size * 2, 0);
    }

    void apply_set(int x, int len){
        if(len <= 1) return;
        if(marked_set[x]){
            marked_set[x] = false;
            marked_set[x * 2] = marked_set[x * 2 + 1] = true;
            val[x * 2] = val[x * 2 + 1] = operation_set[x] * len / 2;
            operation_set[x * 2] = operation_set[x * 2 + 1] = operation_set[x];
        }
    }

    void apply_add(int x, int len){
        if(len <= 1) return;
        if(marked_add[x]){
            val[x * 2] += operation_add[x] * len / 2;
            val[x * 2 + 1] += operation_add[x] * len / 2;
            operation_add[x * 2] = operation_add[x * 2 + 1] = operation_add[x];
            operation_add[x] = 0;
            marked_add[x] = false;
            marked_add[x * 2] = marked_add[x * 2 + 1] = true;
        }
    }

    void push_down(int x, int tl, int tr){
        if(tl == tr) return;
        int len = tr - tl + 1;
        apply_add(x, len);
        apply_set(x, len);
    }

    void set(int l, int r, int new_val, int x, int tl, int tr){
        if(l > r) return;
        push_down(x, tl, tr);
        if(tl == l && r == tr){
            operation_set[x] = new_val;
            val[x] = new_val * (tr - tl + 1);
            marked_set[x] = true;
        } else {
            int m = (tl + tr) / 2;
            set(l, min(m, r), new_val, x * 2, tl, m);
            set(max(m + 1, l), r, new_val, x * 2 + 1, m + 1, tr);
            val[x] = val[x * 2] + val[x * 2 + 1];
        }
    }

    void add(int l, int r, int new_val, int x, int tl, int tr){
        if(l > r) return;
        push_down(x, tl, tr);
        if(tl == l && r == tr){
            operation_add[x] = new_val;
            val[x] += new_val * (tr - tl + 1);
            marked_add[x] = true;
        } else {
            int m = (tl + tr) /2;
            add(l, min(m, r), new_val, x * 2, tl, m);
            add(max(m + 1, l), r, new_val, x * 2 + 1, m + 1, tr);
            val[x] = val[x * 2] + val[x * 2 + 1];
        }
    }

    LL query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        push_down(x, tl, tr);
        if(tl == l && r == tr){
            return val[x];
        }
        int m = (tl + tr) / 2;
        auto r1 = query(l, min(m, r), x * 2, tl, m);
        auto r2 = query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        return r1 + r2;
    }

    void print(){
        return;
        int s = 1;
        while(s <= size){
            for(int j = s; j < s * 2; ++j){
                cout << val[j] << " ";
            }
            cout << endl;
            s *= 2;
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
            st.set(b, c - 1, d, 1, 0, st.size - 1);
            st.print();
        } else if(a == 2){
            cin >> d;
            st.add(b, c - 1, d, 1, 0, st.size - 1);
            st.print();
        } else {
            cout << st.query(b, c - 1, 1, 0, st.size - 1) << endl; 
        }
    }

    return 0;
}