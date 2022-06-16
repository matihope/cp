#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, counter = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string b;
        cin >> b;
        int c = b[0], len = 1;
        int blocks = 0;
        vector<char> kol;
        for(int j = 1; j < b.size(); ++j){
            if(b[j] == char(c)){
                len++;
            } else {
                kol.push_back(char(c));
                blocks++;
                len = 1;
                c = b[j];

            }
        }
        blocks++;
        kol.push_back(char(c));
        if(blocks == 2){
            if(kol[0] == '0' && kol[1] == '1')
                counter++;
        }
    }
    cout << counter << endl;
}