#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <random>

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
template <class T> void _print(T arr[]) {cerr << "[ "; for (int i = 0; i < 13; ++i) {_print(arr[i]); cerr << " ";} cerr << "]";}

bool check_7(VI arr, int start){
    int sum = 0;
    for(int i = 0; i < 7; ++i)
        sum += arr[i + start];
    return (sum % 3 == 0);
}

bool check(VI arr){
    for(int i = 0; i < 7; ++i){
        if(!check_7(arr, i)) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    VI nums = {21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81};
    // VI numsX = {21, 36, 51, 66, 81};
    // VI nums1 = {26, 41, 56, 71};
    // VI nums2 = {31, 46, 61, 76};

    LL possibilities = 0;
    VI tab;
    auto rng = default_random_engine(1);
    while(true){
        // shuffle(numsX.begin(), numsX.end(), rng);
        // shuffle(nums1.begin(), nums1.end(), rng);
        // shuffle(nums2.begin(), nums2.end(), rng);
        // tab = {
        //     numsX[0],
        //     nums1[0], // 1
        //     nums1[3], // 1
        //     numsX[1],
        //     nums1[1], // 1
        //     nums1[2], // 1
        //     numsX[2], 
        //     nums2[1], // 2
        //     nums2[2], // 2
        //     numsX[3],
        //     nums2[0], // 2
        //     nums2[3], // 2
        //     numsX[4],
        // };
        // debug(tab);
        shuffle(nums.begin(), nums.end(), rng);

        if(check(nums)){
            possibilities++;
            cout << possibilities << endl;
        }
        
    }


    return 0;
}