#include <bits/stdc++.h>

using namespace std;

bool czyPal(const string& f){
    for(size_t i = 0; i < f.size() / 2; ++i)
        if(f[i] != f[f.size() - 1 - i])
            return false;
    return true;
}

void pierwszyTestcase() {
    int n;
    string s;
    cin >> n >> s;
    if(czyPal(s)){
        cout << s << endl;
        return;
    }
    do{
        if(czyPal(s)){
            cout << s << endl;
            return;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << "NIE" << endl;
}

void wzo(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> chrs(26, 0);
    for(auto& c: s)
        chrs[c - 'a']++;

    int ileOdds = 0;
    char oddChar = ' ';
    for(size_t i = 0; i < chrs.size(); ++i){
        if(chrs[i] % 2 == 1){
            ileOdds++;
            oddChar = char(i + 'a');
        }

    }
    if(ileOdds > 1){
        cout << "NIE" << endl;
        return;
    }
    string half;
    for(size_t i = 0; i < chrs.size(); i++){
        for(int j = 0; j < chrs[i] / 2; ++j)
            half += char(i + 'a');
    }
    cout << half;
    if(ileOdds)
        cout << oddChar;
    reverse(half.begin(), half.end());
    cout << half << '\n';
}

void er() {
    int n;
    string s;
    cin >> n >> s;
    if(czyPal(s)){
        cout << s << endl;
        return;
    }
    do{
        if(!czyPal(s)){
            cout << s << endl;
            return;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << "NIE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    er();
}
