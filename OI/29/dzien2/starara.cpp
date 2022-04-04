#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef long double LLD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;
typedef vector<vector<int>> VVI;
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
#define MP make_pair
#define INF 1'000'000'007

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

struct Graph {
    struct V {
        int tPozP = INF;
        int tPioP = INF;
        int t = INF;
        char tPozKier;
        char tPioKier;
        char tKier;
        int ter;
        int que;
        int tPath = INF;
        char kier;
    };
    vector<vector<V>> g;
    Graph(int n = 0) : g(n + 2, vector<V>(n + 2)) {
        REP(x, n + 2) {
            g[0][x].ter = 2;
            g[n + 1][x].ter = 2;
            g[x][0].ter = 2;
            g[x][n + 1].ter = 2;
        }
    };
    void BfsP(int x, int y) {
        queue<PII> q;
        q.push({x, y});
        g[x][y].t = 0;
        g[x][y].que = 1;
        while(!q.empty()) {
            x = q.front().ST; y = q.front().ND;
            q.pop();
            g[x][y].que--;
            if(g[x][y].que) {
                continue;
            }
            // if(g[x + 1][y].ter != 2) {
                // ------------ mur -------------
            if(g[x + 1][y].ter == 1) {
                bool change = false;
                if(g[x + 1][y].tPozP > min(g[x][y].tPozP + 1, g[x][y].t + 1)) {
                    change = true;
                    g[x + 1][y].tPozP = min(g[x][y].tPozP + 1, g[x][y].t + 1);
                    g[x + 1][y].tPozKier = 'P';
                }
                if(g[x + 1][y].tPioP > g[x][y].t + 1) {
                    change = true;
                    g[x + 1][y].tPioP = g[x][y].t + 1;
                    g[x + 1][y].tPioKier = 'P';
                }
                if(change) {
                    q.push({x + 1, y});
                    g[x + 1][y].que++;
                }
            }
            if(g[x - 1][y].ter == 1) {
                bool change = false;

                if(g[x - 1][y].tPozP > min(g[x][y].tPozP + 1, g[x][y].t + 1)) {
                    change = true;
                    g[x - 1][y].tPozP = min(g[x][y].tPozP + 1, g[x][y].t + 1);
                    g[x - 1][y].tPozKier = 'L';
                }
                if(g[x - 1][y].tPioP > g[x][y].t + 1) {
                    change = true;
                    g[x - 1][y].tPioP = g[x][y].t + 1;
                    g[x - 1][y].tPioKier = 'L';
                }
                if(change) {
                    q.push({x - 1, y});
                    g[x - 1][y].que++;
                }
            }
            if(g[x][y + 1].ter == 1) {
                bool change = false;
                if(g[x][y + 1].tPioP > min(g[x][y].tPioP + 1, g[x][y].t + 1)) {
                    change = true;
                    g[x][y + 1].tPioP = min(g[x][y].tPioP + 1, g[x][y].t + 1);
                    g[x][y + 1].tPioKier = 'D';
                }
                if(g[x][y + 1].tPozP > g[x][y].t + 1) {
                    change = true;
                    g[x][y + 1].tPozP = g[x][y].t + 1;
                    g[x][y + 1].tPozKier = 'D';
                }
                if(change) {
                    q.push({x, y + 1});
                    g[x][y + 1].que++;
                }
            }
            if(g[x][y - 1].ter == 1) {
                bool change = false;
                if(g[x][y - 1].tPioP > min(g[x][y].tPioP + 1, g[x][y].t + 1)) {
                    change = true;
                    g[x][y - 1].tPioP = min(g[x][y].tPioP + 1, g[x][y].t + 1);
                    g[x][y - 1].tPioKier = 'G';
                }
                if(g[x][y - 1].tPozP > g[x][y].t + 1) {
                    change = true;
                    g[x][y - 1].tPozP = g[x][y].t + 1;
                    g[x][y - 1].tPozKier = 'G';
                }
                if(change) {
                    q.push({x, y - 1});
                    g[x][y - 1].que++;
                }
            }

            // ---------------- teren ----------------
            if(g[x + 1][y].ter == 0) {
                bool change = false;
                if(g[x + 1][y].t > g[x][y].t + 1) {
                    change = true;
                    g[x + 1][y].t = g[x][y].t + 1;
                    g[x + 1][y].tKier = 'P';
                }
                if(g[x + 1][y].tPozP > g[x][y].tPozP + 1) {
                    change = true;
                    g[x + 1][y].tPozP = g[x][y].tPozP + 1;
                    g[x + 1][y].tPozKier = 'P';
                }
                if(change) {
                    q.push({x + 1, y});
                    g[x + 1][y].que++;
                }
            }
            if(g[x - 1][y].ter == 0) {
                bool change = false;
                if(g[x - 1][y].t > g[x][y].t + 1) {
                    change = true;
                    g[x - 1][y].t = g[x][y].t + 1;
                    g[x - 1][y].tKier = 'L';
                }
                if(g[x - 1][y].tPozP > g[x][y].tPozP + 1) {
                    change = true;
                    g[x - 1][y].tPozP = g[x][y].tPozP + 1;
                    g[x - 1][y].tPozKier = 'L';
                }
                if(change) {
                    q.push({x - 1, y});
                    g[x - 1][y].que++;
                }
            }
            if(g[x][y + 1].ter == 0) {
                bool change = false;
                if(g[x][y + 1].t > g[x][y].t + 1) {
                    change = true;
                    g[x][y + 1].t = g[x][y].t + 1;
                    g[x][y + 1].tKier = 'D';
                }
                if(g[x][y + 1].tPioP > g[x][y].tPioP + 1) {
                    change = true;
                    g[x][y + 1].tPioP = g[x][y].tPioP + 1;
                    g[x][y + 1].tPioKier = 'D';
                }
                if(change) {
                    q.push({x, y + 1});
                    g[x][y + 1].que++;
                }
            }
            if(g[x][y - 1].ter == 0) {
                bool change = false;
                if(g[x][y - 1].t > g[x][y].t + 1) {
                    change = true;
                    g[x][y - 1].t = g[x][y].t + 1;
                    g[x][y - 1].tKier = 'G';
                }
                if(g[x][y - 1].tPioP > g[x][y].tPioP + 1) {
                    change = true;
                    g[x][y - 1].tPioP = g[x][y].tPioP + 1;
                    g[x][y - 1].tPioKier = 'G';
                }
                if(change) {
                    q.push({x, y - 1});
                    g[x][y - 1].que++;
                }
            }
            // }
            
        }
    }
    void Path(int x, int y) {
        queue<PII> q;
        q.push({x, y});
        g[x][y].tPath = 0;
        while(!q.empty()) {
            x = q.front().ST;
            y = q.front().ND;
            q.pop();
            if(g[x + 1][y].tPath > g[x][y].tPath + 1 && g[x + 1][y].ter == 0) {
                q.push({x + 1, y});
                g[x + 1][y].tPath = g[x][y].tPath + 1;
                g[x + 1][y].kier = 'P';
            }
            if(g[x - 1][y].tPath > g[x][y].tPath + 1 && g[x - 1][y].ter == 0) {
                q.push({x - 1, y});
                g[x - 1][y].tPath = g[x][y].tPath + 1;
                g[x - 1][y].kier = 'L';
            }
            if(g[x][y + 1].tPath > g[x][y].tPath + 1 && g[x][y + 1].ter == 0) {
                q.push({x, y + 1});
                g[x][y + 1].tPath = g[x][y].tPath + 1;
                g[x][y + 1].kier = 'D';
            }
            if(g[x][y - 1].tPath > g[x][y].tPath + 1 && g[x][y - 1].ter == 0) {
                q.push({x, y - 1});
                g[x][y - 1].tPath = g[x][y].tPath + 1;
                g[x][y - 1].kier = 'G';
            }
        }
    }
    void printPath(int x, int y, int xk, int yk) {
        string s;
        while(x != xk || y != yk) {
            s += g[x][y].kier;
            if(g[x][y].kier == 'G') {
                ++y;
            }
            else if(g[x][y].kier == 'D') {
                --y;
            }
            else if(g[x][y].kier == 'P') {
                --x;
            }
            else
                ++x;
        }
        reverse(ALL(s));
        cout << s << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Graph gP(n), gK(n);
    PII p, k;

    FOR(y, 1, n) {
        string s;
        cin >> s;
        FOR(x, 1, n) {
            if(s[x - 1] == '.') {
                gP.g[x][y].ter = 0;
                gK.g[x][y].ter = 0;
            }
            else if(s[x - 1] == 'X') {
                gP.g[x][y].ter = 2;
                gK.g[x][y].ter = 2;
            }
            else if(s[x - 1] == '#') {
                gP.g[x][y].ter = 1;
                gK.g[x][y].ter = 1;
            }
            else if(s[x - 1] == 'P') {
                p = {x, y};
            }
            else
                k = {x, y};
        }
    }

    gP.BfsP(p.ST, p.ND);
    gK.BfsP(k.ST, k.ND);

    int minn = INF;
    PII bomb;

    FOR(y, 1, n) {
        FOR(x, 1, n) {
            int dist_start = min(min(gP.g[x][y].t, gP.g[x][y].tPioP), gP.g[x][y].tPozP);
            int dist_end = min(min(gK.g[x][y].t, gK.g[x][y].tPioP), gK.g[x][y].tPozP);
            if(dist_start + dist_end < minn) {
                minn = dist_start + dist_end;
                bomb = {x, y};
            }
        }
    }

    if(minn == INF) {
        cout << "NIE";
        return 0;
    }
    int x = bomb.ST, y = bomb.ND;
    x += 1;
    while(gP.g[x][y].ter == 1) {
        gP.g[x][y].ter = 0;
        gK.g[x][y].ter = 0;
        ++x;
    }
    x = bomb.ST; y = bomb.ND;
    --x;
    while(gP.g[x][y].ter == 1) {
        gP.g[x][y].ter = 0;
        gK.g[x][y].ter = 0;
        --x;
    }
    x = bomb.ST; y = bomb.ND;
    ++y;
    while(gP.g[x][y].ter == 1) {
        gP.g[x][y].ter = 0;
        gK.g[x][y].ter = 0;
        ++y;
    }
    x = bomb.ST; y = bomb.ND;
    --y;
    while(gP.g[x][y].ter == 1) {
        gP.g[x][y].ter = 0;
        gK.g[x][y].ter = 0;
        --y;
    }
    gP.g[bomb.ST][bomb.ND].ter = 0;
    cout << minn << '\n';
    cout << bomb.ND << " " << bomb.ST << '\n';
    gP.Path(p.ST, p.ND);
    gP.printPath(k.ST, k.ND, p.ST, p.ND);
    return 0;
}