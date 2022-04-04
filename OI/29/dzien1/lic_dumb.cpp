#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, c;
    cin >> n >> k >> c;
    vector<long long> n_divs;
    for(int i = 2; i <= n; ++i)
        if(n % i == 0)
            n_divs.push_back(i);
    
    vector<int> nums;
    nums.push_back(1);
    for(int i = 2; i <= 1'000'000; ++i){
        bool good = true;
        for(auto& d: n_divs){
            if(i % d == 0){
                good = false;
                break;
            }
        }
        if(good)
            nums.push_back(i);
    }
    for(int i = 0; i < c; ++i){
        cout << nums[i + k - 1] << ' ';
    }
}