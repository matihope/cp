#include <cassert>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

void merge(int l, int m, int r, std::vector<int> &v) {
    // left = [l, m], sorted
    // right = [m + 1, r], sorted
    std::vector<int> sorted(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (v[i] <= v[j])
            sorted[k++] = v[i++];
        else
            sorted[k++] = v[j++];
    }
    while (i <= m) sorted[k++] = v[i++];
    while (j <= r) sorted[k++] = v[j++];
    for (int q = 0; q < sorted.size(); ++q) v[l + q] = sorted[q];
}

void merge_sort(int l, int r, std::vector<int> &v) {
    int m = (l + r) / 2;
    if (l < r) {
        merge_sort(l, m, v);
        merge_sort(m + 1, r, v);
        merge(l, m, r, v);
    }
}

void quick_sort(int l, int r, std::vector<int> &v) {
    if (r - l <= 0) return;
    int ind = rand() % (r - l + 1) + l;
    int val = v[ind];
    int i = l, j = l, k = r;

    // mniejsze na lewo
    // wieksze rowne na prawo
    while (i < k) {
        while (v[i] < val && i < r) i++;
        while (v[k] >= val && k > l) k--;
        if (i < k) std::swap(v[i], v[k]);
    }

    // j - beginning of = range

    j = l;
    while (v[j] < val) j++;
    i = j;
    k = r;
    // make [<, =, >]
    while (i < k) {
        while (v[i] == val && i < r) i++;
        while (v[k] != val && k > l) k--;
        if (i < k) std::swap(v[i], v[k]);
    }
    // find end of = range, i = end
    i = j;
    while (i + 1 <= r && v[i + 1] == val) i++;
    quick_sort(l, j - 1, v);
    quick_sort(i + 1, r, v);
}

// return random number between a and b inclusive
int randint(int a, int b) {
    assert(b >= a);
    int res = 0;
    for (int i = 0; i < 31; i++) res |= (1 << i) * (rand() % 2);

    return res % (b + 1 - a) + a;
}

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

void heap_sort(int l, int r, std::vector<int> &v) {
    std::vector<int> heap;
    for (const auto &a : v) {
        pq_insert(heap, a);
    }
    v.clear();
    while (heap.size() > 1) {
        v.push_back(heap[1]);
        pq_pop(heap);
    }
}

void test(std::vector<int> v, void (*sorter)(int, int, std::vector<int> &)) {
    (*sorter)(0, v.size() - 1, v);

    bool good = true;
    for (int i = 1; i < v.size(); ++i)
        if (v[i - 1] > v[i]) good = false;
    if (good)
        std::cout << "Sorted well\n";
    else
        std::cout << "Sorted not well\n";
    // for (const int &i : v) std::cout << i << " ";
    // std::cout << "\n";
}

struct el {
    int ile, val;
};

void push_min(std::deque<el> &minq, int val) {
    int ile = 0;
    while (minq.size() && minq.back().val >= val) {
        ile += minq.back().ile + 1;
        minq.pop_back();
    }
    minq.push_back({ile, val});
}

void pop_min(std::deque<el> &minq) {
    if (minq.front().ile-- == 0) minq.pop_front();
}

int main() {
    int seed;
    std::cin >> seed;
    srand(seed);
    std::vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(randint(1, 600000));
        // std::cout << v[i] << " ";
    }
    std::cout << "\nStart sorting!\n";
    test(v, &merge_sort);
    test(v, &quick_sort);
    test(v, &heap_sort);
}
