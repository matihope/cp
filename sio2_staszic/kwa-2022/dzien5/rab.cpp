#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i) cin >> p[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    stack<int> st;
    vector<int> res;
    long long len = 0;
    for(int i = 0; i < n; ++i) {
        len += abs(b[i] - p[i]);
        if(!st.empty()){
            if(abs(p[i] - b[st.top()]) < abs(p[st.top()] - b[st.top()])){
                if(b[i] < p[i])
                    res.push_back(i);
                else
                    st.push(i);
            } else {
                while(!st.empty() && abs(p[i] - b[st.top()]) >= abs(p[st.top()] - b[st.top()])){
                    res.push_back(st.top());
                    st.pop();
                }
                if(b[i] < p[i])
                    res.push_back(i);
                else
                    st.push(i);
            }
        }
        else {
            if(b[i] < p[i])
                res.push_back(i);
            else
                st.push(i);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    cout << len << endl;
    for(auto i: res){
        cout << i + 1 << " ";
    }
}