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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL n;
    int a, b;
    cin >> n >> a >> b;
    vector<LL> vec(n + 2, INF);
    vector<LL> mno(n + 2);
    mno[2] = a + b;
    FOR(x, 3, n + 1)
        mno[x] = mno[x - 1] + b;
    vec[1] = 0;
    int minn{};
    if(n == 1) {
        cout << a + b;
        return 0;
    }
    FOR(i, 1, n - 1) {
        while(i * (SIZE(mno) - 1) > n) {
            if(vec[i] + mno.back() < vec[n + 1]) {
                vec[n + 1] = vec[i] + mno.back();
                minn = i * (SIZE(mno) - 1);
            }
            if(SIZE(mno) && (SIZE(mno) - 2) * i > n)
                mno.pop_back();
            else
                break;
        }
        FORD(j, SIZE(mno) - 1, 2) {
            if(i * j <= n && vec[i * j] > mno[j] + vec[i]) {
                vec[i * j] = mno[j] + vec[i];
            }
        }
    }

    cout << vec[n + 1];

    return 0;
}