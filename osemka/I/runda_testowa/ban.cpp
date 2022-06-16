#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

constexpr int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    LL suma = 0;
    cin >> n;
    for(auto& c: n){
        suma += c - '0';
    }
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        int x;
        cin >> x;
        LL ilo = 1;
        int a;
        for(int i = 0; i < x; ++i){
            cin >> a;
            ilo = ilo * (n[a - 1] - '0') % mod;
        }
        if(m == (ilo * suma % mod)){
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
}
