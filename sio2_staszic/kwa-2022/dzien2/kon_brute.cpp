#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t, a, b, c;
    vector<tuple<int, int, int>> inpt;
    unordered_map<int, int> czas_prowadzenia;
    unordered_map<int, long long> punkty;
    cin >> n >> m >> t;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        inpt.push_back({b, c, a});
        punkty[a] = 0;
        czas_prowadzenia[a] = 0;
    }
    sort(inpt.begin(), inpt.end());
    vector<pair<int, int>> leaders; // dodaj do liderow kiedy ktoś stał się liderem
    long long leader_points = 0;
    for(int i = 0; i < m; ++i){
        auto& [time, points, user_id] = inpt[i];
        if(points == 0) continue;
        long long& pkt = punkty[user_id];
        pkt += points;
        if(leader_points < pkt){
            for(auto& p : leaders)
                czas_prowadzenia[p.second] += time - p.first;
            leaders.clear();
            leader_points = pkt;
        }
        if(leader_points == pkt)
            leaders.push_back({time, user_id});
    }
    for(auto& p : leaders){

        czas_prowadzenia[p.second] += t - p.first + 1;
    }
    
    pair<int, int> best = {1, 0}; // id, time
    for(auto it = czas_prowadzenia.begin(); it != czas_prowadzenia.end(); ++it){
        if(it->second > best.second || (it->second == best.second && it->first < best.first)){
            best = {it->first, it->second};
        }
    }
    cout << best.first << endl;
}