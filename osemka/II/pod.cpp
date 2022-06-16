#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

void solve(LL n) {
    LL n_cpy = n;
    int div_now, div_now_times, div_best = 0, div_best_times = 0;

    for(int i = 2; i <= min(1000000, (int)sqrt(n) + 1); ++i){
        div_now = i;
        div_now_times = 0;
        while(n % i == 0){
            n /= i;
            div_now_times++;
            if(div_now_times > div_best_times){
                div_best_times = div_now_times;
                div_best = div_now;
            }
        }
    }
    LL sq = sqrt(n_cpy);
    if(sq * sq == n_cpy){
        if(2 > div_best_times){
            div_best_times = 2;
            div_best = sq;
        }
    }
    cout << max(div_best_times, 1) << endl;
    for(int i = 0; i < div_best_times - 1; i++){
        cout << div_best << ' ';
        n_cpy /= div_best;
    }
    cout << n_cpy << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }

}
