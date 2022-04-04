#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;
    while(z--){
        int a, b, counter = 0;
        cin >> a >> b;
        vector<int> tab_1, tab_2;
        for(int i = 0; i < a; i++)
            tab_1.push_back(i + 1);
        tab_2 = tab_1;
        do{
            do{
                long long ans = 0;
                for(int i = 0; i < a; i++)
                    ans += max(tab_2[i], tab_1[i]);
                if(ans == b)
                    counter++;
            }while(next_permutation(tab_2.begin(), tab_2.end()));
        }while(next_permutation(tab_1.begin(), tab_1.end()));
        cout << counter << endl;
    }
}