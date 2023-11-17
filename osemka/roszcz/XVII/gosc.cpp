#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string s1;
    string s2;

    cin >> s1 >> s2;

    int offset_max = s2.size() - s1.size();

    int min_mismatch_length = s2.size() + 1;
    for(int offset = 0; offset <= offset_max; offset++) {
        int front_mismatch = -1;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i + offset]) {
                front_mismatch = i + offset;
                break;
            }
        }

        if(front_mismatch == -1) {
            cout << "0\n";
            return 0;
        }

        int back_mismatch = -1;
        for(int i = s1.size() - 1; i >= 0; i--) {
            if(s1[i] != s2[i + offset]) {
                back_mismatch = i + offset;
                break;
            }
        }

        min_mismatch_length = min(back_mismatch - front_mismatch + 1, min_mismatch_length);
    }

    cout << min_mismatch_length << '\n';
}
