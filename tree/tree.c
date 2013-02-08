#include <stdlib.h>

struct tree_t {
    int node;
    struct tree_t *left, *right;
}

// Decide whether the given trees are isomorphic,
// i.e. have the same structure, regardless of the nodes' content
int isomorph (struct tree_t *t1, struct tree_t *t2) {
    if (t1 == NULL && t2 == NULL) {
        return 1;
    }

    if (  (t1 == NULL && t2 != NULL)
        ||(t1 != NULL && t2 == NULL)
    ) {
        return 0;
    }

    return isomporh(t1->left, t2->left) * isomporh(t1->right, t2->right);
}

// Decide whether a tree is semi-balanced,
// i.e. for all nodes, if L is the size of left subtree and
// R is the size of right subtree, then L div 2 <= R <= 2 * L
int isSemiBalanced(struct tree_t t) {
    return countSemiBalanced(t) >= 0;
}

int countSemiBalanced(struct tree_t t) {
    if (t == NULL) {
        return 0;
    }

    int lc, rc;
    lc = countSemiBalanced(t->left);
    rc = countSemiBalanced(t->right);

    if (lc < 0 || rc < 0 || lc > 2 * rc || rc > 2 * lc ) {
        return -1;
    } else {
        return lc + rc + 1;
    }
}
