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

struct str {
    int f;
    int col[5]{};
};

vector<vector<str>> t;
VI depth;
VI siz;
vector<VPII> g;

void dfs(int v) {
    // REP(x, 5) {
    //     t[v][0].col[x] = 0;
    // }
    depth[v] = depth[t[v][0].f] + 1;
    FOR(x, 1, 19) {
        t[v][x].f = t[t[v][x - 1].f][x - 1].f;
        REP(j, 5) {
            t[v][x].col[j] = t[t[v][x - 1].f][x - 1].col[j] + t[v][x - 1].col[j];
            // t[v][x].col[j] = t[v][x - 1].col[j];
        }
    }

    FOREACH(it, g[v]) if(it->ST != t[v][0].f) {
        t[it->ST][0].f = v;
        REP(i, 5) {
            t[it->ST][0].col[it->ND] = 0;
        }
        t[it->ST][0].col[it->ND] = 1;
        dfs(it->ST);
        // REP(j, 5) {
            // t[it->ST][0].col[j] = it->col[j];
        // }
    }
}

void build(int x, int y, int c) {
    g[x].PB({y, c});
    g[y].PB({x, c});
    if(siz[t[x][19].f] <= siz[t[y][19].f]) {
        siz[t[y][19].f] += siz[t[x][19].f];
        t[x][0].f = y;
        REP(i, 5) {
            t[x][0].col[i] = 0;
        }
        t[x][0].col[c] = 1;
        dfs(x);
    }
    else {
        siz[t[x][19].f] += siz[t[y][19].f];
        t[y][0].f = x;
        REP(i, 5) {
            t[y][0].col[i] = 0;
        }
        t[y][0].col[c] = 1;
        dfs(y);
    }
}

void path(int x, int y, VI& res) {
    // int res[5]{};
    if(depth[x] > depth[y]) {
        FORD(i, 19, 0) {
            if(depth[t[x][i].f] >= depth[y]) {
                REP(j, 5) {
                    res[j] += t[x][i].col[j];
                }
                x = t[x][i].f;
            }
        }
    }
    else if(depth[y] > depth[x]) {
        FORD(i, 19, 0) {
            if(depth[t[y][i].f] >= depth[x]) {
                REP(j, 5) {
                    res[j] += t[y][i].col[j];
                }
                y = t[y][i].f;
            }
        }
    }
    if(x == y)
        return;
    FORD(i, 19, 0) {
        if(t[x][i].f != t[y][i].f) {
            REP(j, 5) {
                res[j] += t[x][i].col[j];
                res[j] += t[y][i].col[j];
            }
            x = t[x][i].f;
            y = t[y][i].f;
        }
    }
    REP(j, 5) {
        res[j] += t[x][0].col[j] + t[y][0].col[j];
    }
    if(t[x][0].f != t[y][0].f) {
        REP(j, 5) {
            res[j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    t.resize(n + 1, vector<str>(20));
    REP(i, n + 1) {
        REP(j, 20)
            t[i][j].f = i;
    }
    siz.resize(n + 1, 1);
    depth.resize(n + 1);
    g.resize(n + 1);

    REP(x, q) {
        char ch;
        cin >> ch;
        if(ch == 'G') {
            int x, y, c;
            cin >> x >> y >> c;
            --c;
            build(x, y, c);
        }
        else {
            VI res(5);
            int x, y;
            cin >> x >> y;
            path(x, y, res);
            REP(x, 5)
                cout << res[x] << " ";
            cout << endl;
        }
        // debug(x);
        // vector<vector<str>> tCp = t;
        // VI depthCp = depth;
        // VI sizCp = siz;
        // vector<VPII> gCp = g;
    }

    return 0;
}
