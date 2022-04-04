#include <bits/stdc++.h>

using namespace std;

struct el{
    long long scanned, cost, printed;
};

vector<el> vec2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    // na itej pozycji będą ilości wydrukowanych
    vec2.assign(n + 1, {1, 1000000000000000001, 1});
    el best = {1, 1000000000000000001, 1};

    vec2[1] = {0, 0, 1};
    for(int i = 1; i <= n; ++i){
        el now = vec2[i];
        now.scanned = now.printed;
        now.cost += a;
        for(int j = 0; j < n; ++j){
            now.cost += b;
            now.printed += now.scanned;
            if(now.printed <= n){
                if(now.cost < vec2[now.printed].cost)
                    vec2[now.printed] = now;
            } else {
                if(best.cost > now.cost)
                    best = now;
                break;
            }
        }   
    }
    cout << best.cost << endl;
}
