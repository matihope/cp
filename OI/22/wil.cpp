#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <queue>

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

vector<int> s;
struct okienko{
    int t = 0, h = 0;
    LL sum = 0;
    
    int add(){
        sum += s[h];
        return s[h++];
    }
    
    PII move(){
        int f = add();
        sum -= s[t];
        return {s[t++], f};
    }
};

struct gas{
    int t = 0, h = 0;
    LL sum = 0;
    
    void move_head(){
        sum += s[h++];
    }
    
    void move_back(){
        sum -= s[t++];
    }
    
    void add(int val){
        sum += val;
    }
    
    void rem(int val){
        sum -= val;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    LL n, p, d;
    cin >> n >> p >> d;
    okienko gprzod, gbest;
    gas glowna;
    int max_len = d;
    s.assign(n, 0);
    REP(i, n){
        cin >> s[i];
    }
    while(glowna.t <= glowna.h && glowna.h < n){
        if(gprzod.h < d){
            gprzod.add();
            gbest.add();
            glowna.h++;
        } else {
            while(gprzod.sum > gbest.sum){
                auto m = gbest.move();
                glowna.add(m.ST);
                glowna.rem(m.ND);
            }
            if(glowna.h + 1 < n && glowna.sum + s[glowna.h] <= p){
                glowna.move_head();
                gprzod.move();
            } else {
                if(s[gbest.h] > s[glowna.t]){
                    auto m = gbest.move();
                    glowna.add(m.ST);
                    glowna.rem(m.ND);
                    while(glowna.h < gbest.h)
                        glowna.move_head();
                    if(glowna.sum > p)
                        glowna.move_back();
                    if(glowna.h > gprzod.h){
                        gprzod.move();
                    }
                } else {
                    glowna.move_back();
                    if(gbest.t < glowna.t){
                        auto m = gbest.move();
                        glowna.add(m.ST);
                        glowna.rem(m.ND);
                    }
                    if(glowna.h > gprzod.h)
                        gprzod.move();
                }
            }
            if(glowna.sum <= p)
                max_len = max(max_len, glowna.h - glowna.t);
        }
    }
    cout << max_len << endl;

    return 0;
}
