#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long player_hp, player_dmg, monster_hp, monster_dmg;
        cin >> player_hp >> player_dmg >> monster_hp >> monster_dmg;

        long long coins, weapon_upgrade_val, hp_upgrade_val;
        cin >> coins >> weapon_upgrade_val >> hp_upgrade_val;

        bool possible = false;
        
        for(long long add_hp = coins, add_dmg = 0; add_dmg <= coins; add_hp--, add_dmg++){
            long long hp_before = player_hp + add_hp * hp_upgrade_val;
            long long dmg = player_dmg + add_dmg * weapon_upgrade_val;
            if(dmg >= monster_hp){
                possible = true;
                break;
            }
            if(hp_before <= monster_dmg){
                continue;
            }
            long long attacks_not_to_kill = hp_before / monster_dmg;
            if(hp_before - monster_dmg * attacks_not_to_kill <= 0)
                attacks_not_to_kill--;
            if(attacks_not_to_kill < 0) continue;
            long long hp_now = hp_before - monster_dmg * attacks_not_to_kill;
            long long monster_hp_now = monster_hp - (attacks_not_to_kill + 1) * dmg;
            if(monster_hp_now <= 0){
                possible = true;
                break;
            }
        }

        if(possible){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}