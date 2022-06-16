#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, m;
    cin >> k >> n >> m;
    vector<string> tab(m);
    for(int i = 0; i < m; ++i){
        cin >> tab[i];
    }
    vector<int> heights;
    for(int i = 0; i < n; ++i){
        int height = 0;
        if(tab[0][i] == 'X')
            height = m;
        else {
            for(int j = m - 1; j >= 0; --j){
                if(tab[j][i] != 'X'){
                    height = m - 1 - j;
                    break;
                }
            }
        }
        heights.push_back(height);
    }

    int best_pole = min(k, min(m, n));
    for(int i = 0; i < n; ++i){
        int pole_za_free = 0;
        priority_queue<int> q;
        int height = min(k + heights[i], m);
        for(int j = i; j < n; ++j){
            int width = j - i + 1;
            while(width * height - pole_za_free - min(heights[j], height) > k) {
                height--;
                while(!q.empty() && q.top() > height){
                    pole_za_free -= q.top() - height;
                    if(height > 1)
                        q.push(height);
                    q.pop();
                }
            }

            pole_za_free += min(heights[j], height);
            if(heights[j] > 1)
                q.push(min(heights[j], height));

            if(k + pole_za_free >= height * width){
                best_pole = max(best_pole, height * width);
            }
        }
    }
    cout << best_pole << endl;
}
