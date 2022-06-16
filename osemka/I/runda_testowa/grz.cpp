#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a;
    vector<int> tab(1000001, 0);
    vector<int> pierwszy(1000001, 1000000000);
    vector<int> ostatni(1000001, -1);
    int maxi = 0;
    int jaki = 0;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a <= 0)
            continue;

        tab[a]++;
        if(tab[a] > maxi){
            maxi = tab[a];
            jaki = a;
        }
        pierwszy[a] = min(pierwszy[a], i);
        ostatni[a] = max(ostatni[a], i);
    }
    cout << jaki << " " << pierwszy[jaki] + 1 << " " << ostatni[jaki] + 1 << endl;
}
