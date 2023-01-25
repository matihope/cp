#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    char op;
    char a, b;
    int n;
    while(1){
        cin >> op;
        if(op == 'N') break;

        else if(op == 'Z'){
            cin >> a >> b;
            for(auto& c: s)
                if(c == a)
                    c = b;
        }

        else if(op == 'D'){
            cin >> a;
            s += a;
        }

        else if(op == 'U'){
            cin >> n;
            for(int i = 0; i < n; ++i)
                s.pop_back();
        }
    }
    cout << s << endl;
}
