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

struct el{
    LL val;
    int ile;
};
deque<el> q_min;

void push_q_min(LL& num){
    int ile = 0;
    while(!q_min.empty() && q_min.back().val >= num){
        ile += 1 + q_min.back().ile;
        q_min.pop_back();
    }
    q_min.push_back({num, ile});
}

void pop_q_min(){
    if(q_min.front().ile == 0){
        q_min.pop_front();
    } else {
        q_min.front().ile--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<LL> inpt(n);
    LL best = -__LONG_LONG_MAX__;
    FOREACH(i, inpt) {
        cin >> *i;
        best = max(*i, best);
    }
    int head = 1, tail = 0;
    LL s = 0;
    for(int i = 0; i < n; ++i) {
        push_q_min(s);
        s += inpt[i];
        if(s >= q_min.front().val)
            best = max(best, s - q_min.front().val);
    }

    for(int i = 0; i < n; ++i) {
        pop_q_min();
        push_q_min(s);
        s += inpt[i];
        if(s >= q_min.front().val)
            best = max(best, s - q_min.front().val);
    }
    cout << best << endl;

    return 0;
}
