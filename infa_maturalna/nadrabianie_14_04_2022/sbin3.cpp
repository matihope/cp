#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, curr_best = 0;
    vector<string> bins;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string b;
        cin >> b;
        int c = b[0], len = 1;
        vector<char> kol;
        for(int j = 1; j < b.size(); ++j){
            if(b[j] == char(c)){
                len++;
            } else {
                if(char(c) == '0'){
                    if(curr_best < len){
                        curr_best = len;
                        bins.clear();
                    }
                    if(curr_best == len){
                        bins.push_back(b);
                    }
                }
                len = 1;
                c = b[j];
            }
        }
        if(char(c) == '0'){
            if(curr_best < len){
                curr_best = len;
                bins.clear();
            }
            if(curr_best == len){
                bins.push_back(b);
            }
        }
    }
    cout << curr_best << endl;
    for(auto& b: bins)
        cout << b << endl;
}