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

int n, m;

struct el{
    char cmd;
    int a, b;
};

struct t_el{
    int state = 1, range = 1;
};

unordered_map<int, int> vert_pos;

struct segtree{
    int size;
    VI marked;
    vector<t_el> vals;
    VI sums;
    VI range;
    
    void init(int n, vector<t_el>& inpt){
        size = 1;
        while(size < n) size *= 2;
        marked.assign(size * 2, 0);
        vals.assign(size, {});
        sums.assign(size, 0);
        range.assign(size, 2);
        build(inpt, 1, 0, size - 1);
    }
    
    void build(vector<t_el>& inpt, int x, int tl, int tr){
        if(tl == tr){
            if(SIZE(inpt) > tl){
                vals[x - size].range = inpt[tl].range;
            }
        } else {
            int m = (tl + tr) / 2;
            build(inpt, x * 2, tl, m);
            build(inpt, x * 2 + 1, m + 1, tr);
            if(tr - tl == 1){
                sums[x] = vals[x * 2 - size].range + vals[x * 2 + 1 - size].range;
                range[x] = sums[x];
            }
            else{
                range[x] = range[x * 2] + range[x * 2 + 1];
                sums[x] = sums[x * 2] + sums[x * 2 + 1];
            }
        }
    }
    
    void push_down(int x, int tl, int tr){
        if(tl == tr) return;
        if(marked[x]){
            marked[x * 2] ^= 1;
            marked[x * 2 + 1] ^= 1;
            if(tr - tl == 1){
                vals[x * 2 - size].state ^= true;
                vals[x * 2 + 1 - size].state ^= true;
            } else {                
                sums[x * 2] = range[x * 2] - sums[x * 2];
                sums[x * 2 + 1] = range[x * 2 + 1] - sums[x * 2 + 1];
            }
            marked[x] = false;
        }
    }
    
    void swi(int l, int r, int x, int tl, int tr){
        if(l > r) return;
        push_down(x, tl, tr);
        if(l == tl && r == tr){
            if(tl == tr)
                vals[x - size].state ^= true;
            else
                sums[x] = range[x] - sums[x];
            marked[x] = true;
        } else {
            int m = (tl + tr) / 2;
            swi(l, min(r, m), x * 2, tl, m);
            swi(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
            if(tr - tl == 1)
                sums[x] = (vals[x * 2 - size].range * vals[x * 2 - size].state) + (vals[x * 2 + 1 - size].range * vals[x * 2 + 1 - size].state);
            else
                sums[x] = sums[x * 2] + sums[x * 2 + 1];
        }
    }
    
    void swi(int l, int r){
        swi(vert_pos[l], vert_pos[r], 1, 0, size - 1);
    }
    
    int query(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        push_down(x, tl, tr);
        if(l == tl && r == tr){
            if(tl == tr){
                return vals[x - size].state * vals[x - size].range;
            }
            return sums[x];
        } else {
            int m = (tl + tr) / 2;
            return query(l, min(m, r), x * 2, tl, m) + query(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        }
    }
    
    int query(int l, int r){
        return query(vert_pos[l], vert_pos[r], 1, 0, size - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    vector<el> qs(m);
    
    set<int> verts;
    FOREACH(i, qs){        
        cin >> i->cmd >> i->a >> i->b;
        verts.insert(i->a);
        verts.insert(i->b);
    }
    VI verts_vec(verts.begin(), verts.end());
    vector<t_el> pos_range;
    int new_indexes = 0;
    vert_pos[verts_vec[0]] = 0;
    pos_range.push_back({1, 1});
    for(int i = 1; i < verts_vec.size(); ++i){
        if(verts_vec[i] - verts_vec[i - 1] > 1){
            pos_range.push_back({1, verts_vec[i] - verts_vec[i - 1] - 1});
            new_indexes++;
        }
        pos_range.push_back({1, 1});
        vert_pos[verts_vec[i]] = i + new_indexes;
    }    
    
    segtree st;
    st.init(SIZE(pos_range), pos_range);
    
    FOREACH(q, qs){
        if(q->cmd == '*'){
            st.swi(q->a, q->b);
        } else {
            cout << st.query(q->a, q->b) << endl;
        }
    }
    

    return 0;
}
