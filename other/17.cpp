#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<vector<int>> vs;
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            for(int k = 1; k <= 3; ++k){
                for(int l = 1; l <= 3; ++l){
                    if(i + j + k + l == 7)
                        vs.insert({i, j, k, l});
                }
            }
        }
    }
    cout << vs.size() << endl;
}