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
#define INF 2000000002
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

struct el{
    int p, ile;
};
deque<el> q_min, q_max;

void push_max(int p){
    int ile = 0;
    while(!q_max.empty() && q_max.back().p <= p){
        ile = ile + 1 + q_max.back().ile;
        q_max.pop_back();
    }
    q_max.push_back({p, ile});
}

void pop_from_max(){
    if(q_max.front().ile == 0){
        q_max.pop_front();
    } else {
        q_max.front().ile--;
    }
}

void push_min(int p){
    int ile = 0;
    while(!q_min.empty() && q_min.back().p >= p){
        ile = ile + 1 + q_min.back().ile;
        q_min.pop_back();
    }
    q_min.push_back({p, ile});
}

void pop_from_min(){
    if(q_min.front().ile == 0){
        q_min.pop_front();
    } else {
        q_min.front().ile--;
    }
}

void push(int p){
    push_min(p);
    push_max(p);
}
void pop(){
    pop_from_max();
    pop_from_min();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t >> n;
    VI poms(n);
    REP(i, n) cin >> poms[i];
    int max_len = 1;
    int tail = 0, head = 1;
    push(poms[0]);
    while(head < n){
        if(abs(q_min.front().p - poms[head]) <= t && abs(q_max.front().p - poms[head]) <= t){
            push(poms[head]);
            head++;
        } else {
            pop();
            tail++;
            if(head == tail){
                head++;
                push(poms[tail]);
            }
        }
        max_len = max(max_len, head - tail);
    }
    cout << max_len << endl;


    return 0;
}