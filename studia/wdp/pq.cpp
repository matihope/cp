#include <cstdlib>
#include <iostream>
#include <vector>

void pq_insert(std::vector<int> &q, int val) {
    q.push_back(val);
    int p = q.size() - 1;
    while (p / 2 >= 1) {
        if (q[p / 2] > val) {
            std::swap(q[p / 2], q[p]);
            p /= 2;
        } else {
            break;
        }
    }
}

void pq_pop(std::vector<int> &q) {
    if (q.size() > 1) {
        q[1] = q.back();
        q.pop_back();
        int p = 1;
        while (p * 2 < q.size()) {
            int right = 0;
            if (p * 2 + 1 < q.size())
                if (q[p * 2] > q[p * 2 + 1]) right = 1;
            if (q[p * 2 + right] < q[p]) std::swap(q[p * 2 + right], q[p]);
            p = p * 2 + right;
        }
    }
}

int randint(int a, int b) {
    int res = 0;
    for (int i = 0; i < 31; i++) res |= (1 << i) * (rand() % 2);

    return res % (b + 1 - a) + a;
}

int main() {
    // int seed;
    // std::cin >> seed;
    // srand(seed);
    srand(time(NULL));

    std::vector<int> pq_int(1);
    for (int i = 0; i < 1000000; ++i) pq_insert(pq_int, randint(1, 100000));

    std::vector<int> sorted;
    while (pq_int.size() > 1) {
        sorted.push_back(pq_int[1]);
        pq_pop(pq_int);
    }
    bool good = true;
    for (int i = 1; i < sorted.size(); ++i) {
        if (sorted[i - 1] > sorted[i]) good = false;
    }
    if (good) {
        std::cout << "Sorted well\n";
    } else {
        std::cout << "Sorted not so well\n";
    }

    // for()
    return 0;
}
