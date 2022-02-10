#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int Find(int p1, int p2){
    int i = 0;
    int j = s1.size() - 1;
    while(s1[i] == s2[p1 + i] && i < s1.size()) i++;
    while(s1[j] == s2[p1 + j] && i <= j) j--;
    return j - i + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    int mini = 1000000001;
    for(int i = s1.size() - 1; i < s2.size(); ++i){
        mini = min(mini, Find(i - s1.size() + 1, i));
    }
    cout << mini << endl;
}