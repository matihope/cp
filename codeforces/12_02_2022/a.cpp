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

#ifdef LOCAL_H
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

struct el{
    int val, ile;
};
deque<el> q_max, q_min;

void push_max(int val){
    int ile = 0;
    while(!q_max.empty() && q_max.back().val <= val){
        ile += 1 + q_max.back().ile;
        q_max.pop_back();
    }
    q_max.push_back({val, ile});
}

void pop_max(){
    if(q_max.front().ile-- == 0)
        q_max.pop_front();
}

void push_min(int val){
    int ile = 0;
    while(!q_min.empty() && q_min.back().val >= val){
        ile += 1 + q_min.back().ile;
        q_min.pop_back();
    }
    q_min.push_back({val, ile});
}

void pop_min(){
    if(q_min.front().ile-- == 0)
        q_min.pop_front();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i) { cin >> vec[i]; push_min(vec[i]); }
        bool good = false;
        for(int i = 0; i < n - 1; ++i){
            pop_min();
            push_max(vec[i]);
            if(q_max.front().val > q_min.front().val){
                good = true;
                break;
            }
        }
        if(good){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        q_max.clear();
        q_min.clear();
    }

    return 0;
}
