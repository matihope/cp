#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

uint xy_to_pos(const uint x, const uint y) { return y * 7 + x; }

struct State {
    long long bitmask;
    string path;
    uint x, y;
    State() {
        bitmask = 0;
        x = y = 0;
    }

    bool get_pos(const uint x, const uint y) { return bitmask & (1 << xy_to_pos(x, y)); }
    void set_pos(const uint x, const uint y) { bitmask |= (1 << xy_to_pos(x, y)); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<State> possible;
    possible.push(State());
    vector<State> correct;
    while (correct.size() < 88418) {
        State curr = possible.front();
        possible.pop();

        bool to_rem = false;

        if (curr.path.size() == 49) {
            correct.push_back(curr);
            to_rem = true;
        }

        if (curr.get_pos(0, 7)) {
            to_rem = true;
        }

        if (to_rem) {
            continue;
        }

        if (curr.x + 1 < 7 && !curr.get_pos(curr.x + 1, curr.y)) {
            State r(curr);
            r.set_pos(curr.x + 1, curr.y);
            r.x++;
            r.path += "R";
            possible.push(r);
        }

        if (curr.y + 1 < 7 && !curr.get_pos(curr.x, curr.y + 1)) {
            State u(curr);
            u.set_pos(curr.x, curr.y + 1);
            u.y++;
            u.path += "U";
            possible.push(u);
        }

        if (curr.x - 1 >= 0 && !curr.get_pos(curr.x - 1, curr.y)) {
            State l(curr);
            l.set_pos(curr.x - 1, curr.y);
            l.x--;
            l.path += "L";
            possible.push(l);
        }

        if (curr.y - 1 >= 0 && !curr.get_pos(curr.x, curr.y - 1)) {
            State d(curr);
            d.set_pos(curr.x, curr.y - 1);
            d.y--;
            d.path += "D";
            possible.push(d);
        }
    }
    cout << "DON!" << endl;
}
