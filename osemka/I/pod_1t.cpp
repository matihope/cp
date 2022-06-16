#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int getDiff(const int& org, const int& toCmp) {
    std::string o = std::to_string(org);
    std::string t = std::to_string(toCmp);
    int counter = 0;
    for(int i = 0; i < 3; ++i){
        if(o[i] != t[i])
            counter++;
    }
    return counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int now;
        cin >> now;
        int best = now;
        int minic = 3;
        for(int i = 100; i <= 999; ++i){
            if(i % 7)
                continue;
            int d = getDiff(now, i);
            if(d < minic){
                best = i;
                minic = d;
            }
        }
        cout << best << endl;

    }
}
