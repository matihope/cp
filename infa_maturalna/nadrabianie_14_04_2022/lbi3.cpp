#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    typedef pair<string, size_t> PSI;
    vector<PSI> nums;
    for(size_t i = 0; i < 1000; ++i){
        string b;
        cin >> b;
        nums.push_back({b, i + 1});
    }
    sort(nums.begin(), nums.end(), [&](const PSI a, const PSI b) {
        if(a.first.size() == b.first.size()){
            for(int i = 0; i < a.first.size(); ++i){
                if(a.first[i] != b.first[i]){
                    if(a.first[i] == '0')
                        return true;
                    if(b.first[i] == '0')
                        return false;
                }
            }
        }
        return a.first.size() < b.first.size();
    });
    cout << nums.front().second << endl;
    cout << nums.back().second << endl;
}