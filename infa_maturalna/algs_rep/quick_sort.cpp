#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int l, int r, vector<int>& tab){
    if(l < r){
        int pivot = tab[r], pos = l;
        
        for(int i = l; i < r; ++i)
            if(tab[i] < pivot)
                swap(tab[i], tab[pos++]);

        swap(tab[r], tab[pos]);
        quick_sort(l, pos - 1, tab);
        quick_sort(pos + 1, r, tab);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    const int N = 15;
    vector<int> tab(N);
    for(int i = 0; i < N; ++i){
        tab[i] = rand() % 50;
        cout << tab[i] << ' ';
    }
    cout << endl;
    
    quick_sort(0, N - 1, tab);
    for(int i = 0; i < N; ++i)
        cout << tab[i] << ' ';
}