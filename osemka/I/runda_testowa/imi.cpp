#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int ile(char x){
    if(x == 'k')
        return 1;
    if(x == 'M')
        return 2;
    if(x == 'G')
        return 3;
    if(x == 'T')
        return 4;
    return 5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string thing;
        cin >> thing;
        LL liczba = stoll(thing.substr(0, thing.size() - 2));
        liczba *= pow(1024, ile(thing[thing.size() - 2]));
        if(thing.back() == 'B'){
            liczba *= 8;
        }
        cout << liczba << endl;
    }
}
