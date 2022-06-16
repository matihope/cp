#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    stack<int> st;
    while(t--){
        size_t l;
        cin >> l;
        string a, b;
        cin >> a >> b;
        if(l == 1 && a != b){ cout << "NO" << endl; continue; }
        bool possible = true;
        int c1[26]{}, c2[26]{};
        for(size_t i = 0; i < l; ++i){
            c1[a[i] - 'a']++;
            c2[b[i] - 'a']++;
        }
        for(size_t i = 0; i < 26; ++i){
            if(c1[i] != c2[i]){
                possible = false;
                break;
            }
        }
        if(possible) {
            for(size_t i = 0; i < l - 1; ++i){
                if(a[i] != b[i]){
                    st.push(i);
                    while(!st.empty()){
                        int j = st.top();
                        const auto& a_now = a.substr(j, 2);

                        bool can_swap = true;
                        if(a_now != "ab" && a_now != "bc")
                            can_swap = false;

                        if(can_swap && (b[i] == a_now[0] || b[i] == a_now[1])){
                            st.pop();
                            swap(a[j], a[j + 1]);
                        } else {
                            if(j + 1 >= l){
                                possible = false;
                                while(!st.empty())
                                    st.pop();
                                break;
                            }
                            st.push(j + 1);
                        }
                    }
                }
            }
        }
        if(!possible){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
