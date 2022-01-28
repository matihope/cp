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

struct thing{
    int start, end, len;
};

bool cmp(const thing& a, const thing& b){
    return a.len > b.len;
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
        string miasta;
        cin >> n >> miasta;
        multiset<thing, decltype(cmp)*> one_sided(cmp);
        multiset<thing, decltype(cmp)*> both_sided(cmp);
        int len = 0;
        int ill = 0;
        for(int i = 0; i < n; ++i){
            if(miasta[i] == '1'){
                ill++;
                if(len > 0){
                    if(i - len == 0){
                        one_sided.insert({i - len, i - 1, len});
                    } else {
                        both_sided.insert({i - len, i - 1, len});
                    }
                    len = 0;
                }
            } else {
                len++;
            }
        }
        if(len > 0) one_sided.insert({n - len, n - 1, len});
        auto one_s_pos = one_sided.begin();
        auto both_s_pos = both_sided.begin();
        int days = 0;
        while(true){
            int now_len_one = 0;
            int now_len_both = 0;
            if(one_s_pos != one_sided.end())   now_len_one = one_s_pos->len - days;
            if(both_s_pos != both_sided.end())  now_len_both = both_s_pos->len - days * 2;
            if(now_len_one <= 0){
                one_s_pos = one_sided.end();
            }
            if(now_len_both <= 0){
                both_s_pos = both_sided.end();
            }
            if(now_len_both <= 0 && now_len_one <= 0){
                break;
            }
            
            if(now_len_one >= 2 || now_len_both <= 0) {
                one_sided.erase(one_s_pos);
                one_s_pos = one_sided.begin();
            } else if(now_len_both >= 1){
                if(now_len_both > 1){
                    thing new_thing = *both_s_pos;
                    new_thing.len -= days;
                    one_sided.insert(new_thing);
                }
                both_sided.erase(both_s_pos);
                both_s_pos = both_sided.begin();
            }

            if(both_s_pos != both_sided.end() || one_s_pos != one_sided.end()){
                auto count_one = one_sided.begin();
                auto count_both = both_sided.begin();
                while(true){
                    if(count_one != one_sided.end() && count_one->len - days > 0){
                        ill++;
                        count_one++;
                    } else {
                        count_one = one_sided.end();
                    }
                    if(count_both != both_sided.end() && count_both->len - days * 2 > 0){
                        if(count_both->len - days * 2 >= 2)
                            ill++;
                        ill++;
                        count_both++;
                    } else {
                        count_both = both_sided.end();
                    }
                    if(count_one == one_sided.end() && count_both == both_sided.end()){
                        break;
                    }
                }
                days++;
            }
            else
                break;

        }
        cout << ill << endl;
    }

    return 0;
}