#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

constexpr int n = 8;
int rep[n + 1]{};

int Find(int a){
    if(rep[a] == a)
        return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    rep[Find(b)] = Find(a);
}

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if(argc < 2)
        srand(5);
    else
        srand(stoi(argv[1]));

    for(int i = 1; i <= n; ++i){
        rep[i] = i;
    }

    int q = 2 * n;
    int G = 0;
    cout << n << " " << q << endl;
    for(int i = 0; i < q; ++i){

        int op = rand() % 2;
        if(G == n - 1)
            op = 0;

        int x = rand() % n + 1;
        int y = rand() % n + 1;
        if(op == 0){
            cout << 'S';
            cout << " " << x << " " << y << endl;
        } else {
            cout << 'G';
            G++;
            int k = rand() % 5 + 1;
            while(Find(x) == Find(y)){
                y = rand() % n + 1;
            }
            Union(x, y);
            cout << " " << x << " " << y << " " << k << endl;

        }
    }
}
