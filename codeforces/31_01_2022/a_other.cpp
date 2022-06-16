#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 7 == 0){
            cout << n << endl;
            continue;
        } else {
            int rem = n % 7;
            string s = to_string(n);
            if(to_string(n - rem)[s.size()-2] == s[s.size()-2])
                cout << n - rem << endl;
            else
                cout << n + (7 - rem) << endl;
        }
    }
}
