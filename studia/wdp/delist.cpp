#include <cstdlib>
#include <iostream>

struct elem {
    int val;
    elem *left, *right;
};

struct lista {
    elem *left, *right;
};

void push_left(lista *l, int val) {
    elem *n = new elem;
    n->val = val;
    n->left = NULL;
    n->right = l->left;
    if (l->left) {
        l->left->left = n;
    }
    if (!l->right) {
        l->right = n;
    }
    l->left = n;
}

void push_right(lista *l, int val) {
    elem *n = new elem;
    n->val = val;
    n->right = NULL;
    n->left = l->right;
    if (l->right) {
        l->right->right = n;
    }
    if (!l->left) {
        l->left = n;
    }
    l->right = n;
}

int randint(int a, int b) {
    int res = 0;
    for (int i = 0; i < 31; i++) res |= (1 << i) * (rand() % 2);

    return res % (b + 1 - a) + a;
}

int main() {
    srand(time(NULL));
    lista *l = new lista;

    for (int i = 0; i < 9; ++i) push_left(l, randint(1, 10));
    push_left(l, 1337);
    push_right(l, 2137);

    elem *lefty = l->left;
    while (lefty) {
        std::cout << lefty->val << " ";
        lefty = lefty->right;
    }
    std::cout << "\n";

    elem *righty = l->right;
    while (righty) {
        std::cout << righty->val << " ";
        righty = righty->left;
    }
    std::cout << "\n";

    elem *lol = l->left;
    while (lol) {
        elem *lol_free = lol;
        lol = lol->right;
        delete lol_free;
    }
    delete l;
}
