#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long a;
        cin >> a;
        typedef pair<long long, int> DV;
        vector<DV> divs; // div, times
        DV div = {0, 0};
        for(int i = 2; i <= min(1000000LL, (long long)(sqrt(a)) + 1); ++i){
            while(a % i == 0){
                if(div.first != i){
                    if(div.second > 0)
                        divs.push_back(div);
                    div = {i, 0};
                }
                div.second++;
                a /= i;
            }
        }
        long long s = sqrt(a);
        if(a != 1 && a ==  s * s){
            divs.push_back({s, 2});
            a = 1;
        } 
        if(div.second > 0)
            divs.push_back(div);
        sort(divs.begin(), divs.end(), [&](const DV a, const DV b){ return a.second > b.second; });
        vector<long long> ans(1, 1);
        if(divs.size())
            ans.assign(divs[0].second, 1);
        for(int i = 0; i < divs.size(); i++){
            for(int j = 0; j < divs[i].second; j++){
                ans[ans.size() - 1 - j] *= divs[i].first;
            }
        }
        ans.back() *= a;
        cout << ans.size() << '\n';
        for(auto& i: ans)
            cout << i << " ";
        cout << '\n';
    }
}