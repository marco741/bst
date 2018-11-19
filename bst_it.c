#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst_it.h"

TBst bst_insert(TBst tree, TInfo info) {
    TNodeBst *node = tree, *prec = NULL;
    TNodeBst *new = bst_node_create(info);
    int right;
    while (node != NULL) {
        prec = node;
        right = is_greater(info, node->info);
        if (right)
            node = node->right;
        else
            node = node->left;
    }
    if (tree == NULL)
        return new;
    if (right)
        prec->right = new;
    else
        prec->left = new;
    return tree;
}

TNodeBst* bst_search(TBst tree, TInfo info) {
    while (tree != NULL && !is_equal(info, tree->info)) {
        if (is_greater(info, tree->info))
            tree = tree->right;
        else
            tree = tree->left;
    }
    return tree;

}

TBst bst_remove(TBst tree, TInfo info) {
    TNodeBst* prec = NULL, *node = tree, *succ;
    int right;
    while (node != NULL && !is_equal(info, node->info)) {
        //Search info
        prec = node;
        right = is_greater(info, node->info);
        if (right)
            node = node->right;
        else
            node = node->left;
    }


    if (node == NULL)
        //Caso Info Assente
        return tree;


    else if (node->left == NULL || node->right == NULL) {
        //Caso Info ha solo uno dei due sottoalberi
        if (node->right == NULL)
            succ = node->left;
        else
            succ = node->right;
        bst_node_destroy(node);
        if (prec == NULL)
            //Caso Info è la radice dell'albero ed ha solo il sottoalbero sinistro o destro
            return succ;
    }
    else {
        TNodeBst* min = bst_search_min(node->right);
        node->info = min->info;
        prec = node;
        node = node->right;
        right = 1;
        while (node->left != NULL) {
            prec = node;
            node = node->left;
            right = 0;
        }
        if (right)
            prec->right = node->right;
        else
            prec->left = node->right;
        bst_node_destroy(node);
        return tree;
    }

    if (right)
        prec->right = succ;
    else
        prec->left = succ;
    return tree;
}