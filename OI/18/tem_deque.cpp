#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <set>
#include <deque>

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

struct temp{
    int lo, hi;
};

struct el{
    int temp, ile;
};

deque<el> q;

void remove_temp(int temp){
    if(q.front().ile == 0){
        q.pop_front();
    } else {
        q.front().ile--;
    }
}

void add_temp(int temp){
    int ile = 0;
    while(!q.empty() and q.back().temp <= temp){
        ile = ile + q.back().ile + 1;
        q.pop_back();
    }
    q.push_back({temp, ile});
}

int query(){
    return q.front().temp; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<temp> temps(n);
    REP(i, n) cin >> temps[i].lo >> temps[i].hi;
    int max_days = 1;

    int tail = 0, head = 1;
    add_temp(temps[0].lo);
    while(head < n){
        auto lo = query();
        if(lo <= temps[head].hi){
            max_days = max(max_days, head-tail + 1);
            add_temp(temps[head].lo);
            head++;
        } else {
            remove_temp(temps[tail].lo);
            if(head - 1 == tail){
                head++;
                tail++;
                add_temp(temps[tail].lo);
            }
            else
                tail++;
        }
    }

    cout << max_days << '\n';
}