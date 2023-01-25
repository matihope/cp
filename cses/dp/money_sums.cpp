#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> money(n);
    for(auto& i : money){
        cin >> i;
    }
    sort(money.begin(), money.end());
    set<int> sms;
    int n_beg = 0;
    sms.insert(0);
    for(int i = 0; i < n; i++){
        vector<int> neus;
        for(const auto& j : sms)
            neus.push_back(money[i] + j);
        for(const auto& j : neus)
            sms.insert(j);
    }
    sms.erase(sms.begin());
    cout << sms.size() << endl;
    for(auto& i: sms)
        cout << i << ' ';
    cout << '\n';
}
