#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<string, string>> tab(n);
    for(auto& s: tab) {
        cin >> s.second;
        s.first = s.second;
        sort(s.first.begin(), s.first.end());
    }
    sort(tab.begin(), tab.end());
    vector<vector<string>> words(n, vector<string>());
    int pos = 0;
    words[pos].push_back(tab[0].second);
    for(int i = 1; i < n; ++i){
        if(tab[i].first == tab[i - 1].first){
            if(tab[i].second != tab[i - 1].second)
                words[pos].push_back(tab[i].second);
        }
        else
            words[++pos].push_back(tab[i].second);
    }
    sort(words.begin(), words.end());
    for(auto& x: words){
        if(x.size() > 0){
            for(auto& w: x)
                cout << w << " ";
            cout << '\n';
        }
    }
}