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

struct el{
    long long scanned, cost, printed;
};
vector<el> vec2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vec2.assign(n + 1, {1, 1000000000000000001, 1});
    vec2[1] = {1, a, 1};
    // na itej pozycji będą ilości wydrukowanych
    el best = {1, 1000000000000000001, 1};
    // fill
    {
        el now = vec2[1];
        for(int j = 1; j - 1 <= n; ++j){
            now.cost += b;
            now.printed += now.scanned;
            if(now.printed <= n){
                if(now.cost < vec2[now.printed].cost)
                    vec2[now.printed] = now;
            } else {
                if(best.cost > now.cost){
                    best = now;
                }
                break;
            }
        }
    }

    for(int i = 2; i <= n; ++i){
        el now = vec2[i];
        now.scanned = now.printed;
        now.cost += a;
        for(int j = 1; j - 1 <= n; ++j){
            now.cost += b;
            now.printed += now.scanned;
            if(now.printed <= n){
                vec2[now.printed] = now;
            } else {
                if(best.cost > now.cost){
                    best = now;
                }
                break;
            }
        }   
    }
    cout << best.cost << endl;
}
