#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long min_num = 1;
    long long max_num = 1e6;
    cin >> min_num >> max_num;
    int s = log10(max_num) + 1;

    vector<vector<pair<long long, long long>>> nums(s + 1); // num = i, sum of all
    long long ans = 0;
    for(int i = 1; i <= 9; ++i){
        nums[1].push_back({i, i});
        if(min_num <= i * i && i * i <= max_num)
            ans++;
    }
    for(int i = 2; i <= s; ++i){
        for(auto& num : nums[i - 1]){
            for(long long j = 1; j <= 9; ++j){
                pair<long long, long long> l = num;
                l.first *= 10;
                l.first += j;
                l.second *= j;
                long long a;
                if(!__builtin_mul_overflow(l.first, l.second, &a)){
                    if(a <= max_num){
                        nums[i].push_back(l);
                        if(min_num <= a)
                            ans++;
                    } else break;

                } else break;
            }
        }
    }
    cout << ans << endl;
}