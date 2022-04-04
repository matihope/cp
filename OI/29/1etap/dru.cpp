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

string board[1000];
vector<vector<bool>> visited;
int n, m;
int additional = 0;

bool checkFit(string& a){
    visited.assign(n, vector<bool>(m, false));
    int s = a.size();
    additional++;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j]){
                if(board[i][j] != a[0])
                    return false;
                bool good = true;
                if(j + s <= m){
                    // horizontal
                    for(int k = 1; k < s; ++k){
                        if(board[i][j + k] != a[k] || visited[i][j + k]){
                            good = false;
                            break;
                        }
                    }
                    if(good)
                        for(int k = 0; k < s; ++k)
                            visited[i][j + k] = 1;
                }
                else good = false;
                if(i + s <= n && good == false){
                    // vertical
                    good = true;
                    for(int k = 1; k < s; ++k){
                        if(board[i + k][j] != a[k] || visited[i + k][j]){
                            good = false;
                            break;
                        }
                    }
                    if(good)
                        for(int k = 0; k < s; ++k)
                            visited[i + k][j] = 1;
                }
                // can't put a piece
                if(!good)
                    return false;
            }
        }
    }
    return true;
}

void add_cycle_lengths(set<int>& a, int pattern, int shortest_cycle){
    for (int i = shortest_cycle; i <= pattern; i += shortest_cycle)
    {
        if(pattern % i == 0){
            a.insert(i);
        }
    }
}

string create_shortest_cycle(string longest){
    int lon_size = longest.length();
    for(int i = 1; i <= lon_size; ++i){
        if(lon_size % i == 0){
            string sub = longest.substr(0, i);
            bool good = true;
            for(int j = 1; j < (lon_size / i); ++j){
                string new_sub = longest.substr(i * j, i);
                if(sub != new_sub){
                    good = false;
                    break;
                }
            }
            if(good)
                return sub;
        }
    }
    return longest;
}

enum DIR{
    not_set,
    up,
    down,
    left,
    right
};

void execute_for_dicrections(int dirT, int dirB, string t, string b, set<int>& answers){
    // equalize the size
    while(t.size() != b.size()){
        if(t.size() < b.size()){
            if(dirT == DIR::down)
                t += board[t.size()][0];

            else if(dirT == DIR::right)
                t += board[0][t.size()];
        } else {
            if(dirB == DIR::left)
                b = board[n - 1][m - 1 - b.size()] + b;
            
            else if (dirB == DIR::up)
                b = board[n - 1 - b.size()][m - 1] + b;
        }

    }

    string longest = "";
    string first_shortest = "";
    while(1){
        if(t == b && t.size() > longest.size()){
            if(first_shortest == ""){
                if(checkFit(t)){
                    first_shortest = t;
                    longest = t;
                }
            } else if(t.size() % first_shortest.size() == 0){
                longest = t;
            }
        }
        if((dirT == DIR::down && t.size() == n) ||
            (dirT == DIR::right && t.size() == m) || 
            (dirB == DIR::left && b.size() == m) ||
            (dirB == DIR::up && b.size() == n))
            break;
        
            if(dirT == DIR::down)
                t += board[t.size()][0];

            else if(dirT == DIR::right)
                t += board[0][t.size()];
            

            if(dirB == DIR::left)
                b = board[n - 1][m - 1 - b.size()] + b;
            
            else if (dirB == DIR::up)
                b = board[n - 1 - b.size()][m - 1] + b;
    }

    if(first_shortest.size() > 0){
        string shortest_cycle = create_shortest_cycle(longest);
        if(shortest_cycle == longest) {
            shortest_cycle = first_shortest;
            longest = first_shortest;
        }
        while(longest.size()){
            if(longest == first_shortest || checkFit(longest)){
                add_cycle_lengths(answers, longest.size(), shortest_cycle.size());
                break;
            } else {
                longest = longest.substr(0, longest.size() - shortest_cycle.size());
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if(n == 0 || m == 0){
        cout << 0 << endl;
        return 0;
    }
    REP(i, n)
        cin >> board[i];


    string t;
    string b;
    int dirT = DIR::not_set;
    int dirB = DIR::not_set;

    set<int> answers;

    // check top
    int i = 0;
    while(1){
        if(i == n || i == m)
            break;

        if(board[0][i] != board[0][0]){
            dirT = DIR::right;
            t += board[0][i];
            break;
        }
        if(board[i][0] != board[0][0]){
            dirT = DIR::down;
            t += board[i][0];
            break;
        }
        t += board[0][i];
        i++;
    }

    // check bottom
    i = 0;
    while(1){
        if(i == n || i == m)
            break;
            
        if(board[n - 1][m - 1 - i] != board[n - 1][m - 1]){
            dirB = DIR::left;
            b = board[n - 1][m - 1 - i] + b;
            break;
        }
        if(board[n - 1 - i][m - 1] != board[n - 1][m - 1]){
            b = board[n - 1 - i][m - 1] + b;
            dirB = DIR::up;
            break;
        }
        b = board[n - 1][m - 1 - i] + b;
        i++;
    }


    if(n == 1){
        dirT = DIR::right;
        dirB = DIR::left;
    }
    else if(m == 1){
        dirT = DIR::down;
        dirB = DIR::up;
    }

    if(dirB == DIR::not_set || dirT == DIR::not_set){
        if(n == m){
            execute_for_dicrections(DIR::right, DIR::left, t, b, answers);
        } else {
            if(dirB == DIR::not_set && dirT == DIR::not_set){
                string base = board[0].substr(0, 1);
                if(checkFit(base)){
                    add_cycle_lengths(answers, n, 1);
                    add_cycle_lengths(answers, m, 1);
                }
            } else {
                execute_for_dicrections(DIR::right, DIR::left, t, b, answers);
                execute_for_dicrections(DIR::down, DIR::up, t, b, answers);
            }

        }
    } else{
        execute_for_dicrections(dirT, dirB, t, b, answers);
    }
    

    cout << answers.size() << endl;
    for(auto it = answers.begin(); it != answers.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}