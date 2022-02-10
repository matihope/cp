#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& tab){
    int n = tab.size();
    for(int i = 0; i < n; ++i){
        bool good = false;
        if(i - tab[i] >= 0){
            if(tab[i - tab[i]] == tab[i])
                good = true;
        }
        if (i + tab[i] < n){
            if(tab[tab[i] + i] == tab[i])
                good = true;
        }
        if(!good)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if((n / 2) % 2 == 1){
        cout << "NIE" << endl;
        return 0;
    }
    cout << "TAK" << endl;
    if(n > 10){
        for(int i = 0; i < 2 * n; i++){
            cout << 1 << endl;
        }
    }
    // vector<int> tab;
    // for(int i = 0; i < n; ++i){
    //     tab.push_back(i + 1);
    //     tab.push_back(i + 1);
    // }
    // do{
    //     if(check(tab)){
    //         for(int i = 0; i < 2 * n; ++i){
    //             cout << tab[i] << " ";
    //         }
    //         cout << '\n';
    //     }
    // } while(next_permutation(tab.begin(), tab.end()));
    vector<int> tab, tab2(2 * n, 0);
    set<vector<int>> s;
    for(int i = 0; i < n - 1; ++i){
        tab.push_back(i + 1);
    }
    do{
        tab2.assign(2 * n, 0);
        tab2[0] = n;
        tab2[n] = n;
        for(int j = 0; j < n - 1; j++){
            bool placed = false;
            for(int i = 1; i < 2 * n; i++){
                if(tab2[i] == 0 && i + tab[j] < 2*n && tab2[i + tab[j]] == 0){
                    tab2[i] = tab[j];
                    tab2[i + tab[j]] = tab[j];
                    placed = true;
                    break;
                }
            }
            if(!placed)
                goto end;
        }
        if(check(tab2)){
            s.insert(tab2);
            break;
        }
        end:
            continue;
    } while(next_permutation(tab.begin(), tab.end()));
    for(auto it = s.begin(); it != s.end(); ++it){
        for(auto i: *it){
            cout << i << " ";
        }
        break;
        cout << '\n';
    }
}