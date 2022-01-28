#include <bits/stdc++.h>

using namespace std;

vector<long long> nums;

int get_num(long long pos){
    long long l = 0, r = nums.size() - 1, m;
    while(l < r){
        m = (l + r) / 2;
        if(nums[m] >= pos)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int B, q;
    cin >> B >> q;
    long long sum = 0, pos;
    nums.assign(B, 0);
    cin >> nums[0];
    for(long long i = 1; i < B; ++i){
        cin >> nums[i];
        sum += (i * nums[i]) % (B - 1);
        sum %= B - 1;
    }
    if(sum % (B - 1) != 0)
        nums[sum]--;
    for(long long i = 1; i < B; ++i)
        nums[i] += nums[i - 1];
    
    for(int i = 0; i < q; ++i){
        cin >> pos;
        if(nums[B - 1] < (pos + 1)) cout << -1 << endl;
        else
            cout << get_num(pos + 1) << endl;
    }
}
