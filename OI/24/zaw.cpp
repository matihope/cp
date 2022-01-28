#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

constexpr LL MOD = 1e9 + 7;

struct dude{
    int spot = -1;
    vector<int> places;
};

int deps = 0;
vector<dude> dudes;
vector<vector<int>> places;
vector<bool> visited;
queue<int> q;
stack<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b;
    cin >> n;
    dudes.assign(n + 1, {});
    places.assign(n + 1, vector<int>());
    char op;
    for(int i = 1; i <= n; ++i){
        cin >> op;
        cin >> a;
        places[a].push_back(i);
        dudes[i].places.push_back(a);
        if(op == 'N'){
            cin >> b;
            places[b].push_back(i);
            dudes[i].places.push_back(b);
        }
    }
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        if(dudes[i].places.size() == 1){
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()){
        int d = q.front(); q.pop();
        if(!dudes[d].places.empty()){
            dudes[d].spot = dudes[d].places.front();
            for(auto other: places[dudes[d].spot]){
                if(other != d){
                    if(dudes[other].places.front() == dudes[d].spot){
                        q.push(other);
                        dudes[other].places.erase(dudes[other].places.begin());
                    }
                    else if(dudes[other].places.back() == dudes[d].spot){
                        q.push(other);
                        dudes[other].places.pop_back();
                    }
                }
            }
        }
    }
    int not_sure = 0;
    int pos = -1;
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        if(dudes[i].spot == -1) not_sure++, pos = i;
        else visited[dudes[i].spot] = true;
    }

    if(not_sure == 1)
        for(int i = 1; i <= n; ++i)
            if(!visited[i]){
                dudes[pos].spot = i;
            }

    cout << (not_sure <= 1 ? "TAK" : "NIE") << endl;
    if(not_sure <= 1)
        for(int i = 1; i <= n; ++i)
            cout << dudes[i].spot << endl;
    else {
        LL count = 0;
        int free_agents = 0;
        visited.assign(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            if(places[i].size() == 0){
                free_agents++;
            }
            if(dudes[i].places.size() == 2){
                if(!visited[i]){
                    deps++;
                    st.push(i);
                    while(st.size() > 0){
                        auto v = st.top(); st.pop();
                        for(auto p: dudes[v].places){
                            for(auto d: places[p]){
                                if(!visited[d]){
                                    visited[d] = true;
                                    st.push(d);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(free_agents){
            cout << 0 << endl;
        } else {
            count = 2;
            deps--;
            while(deps > 0){
                count *= 2;
                count %= MOD;
                deps--;
            }
            cout << count << endl;
        }
    }

}