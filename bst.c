/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <assert.h>

bool is_greater(int a, int b) {
    return a>b;
}

void info_print(TInfo info) {
    printf("%d ", info);
}

TNodeBst* bst_node_create(TInfo info) {
    TNodeBst* new_node;
    new_node = malloc(sizeof (TNodeBst));
    if (new_node == NULL)
        return NULL;
    else {
        new_node->info = info;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
}

void bst_node_destroy(TNodeBst* node) {
    free(node);
    node = NULL;
}

TBst bst_insert(TBst b, TInfo info) {
    if (b == NULL) {
        TNodeBst* new = bst_node_create(info);
        return new;
    } else if (is_greater(info, b->info)) {
        b->right = bst_insert(b->right, info);
        return b;
    } else {
        b->left = bst_insert(b->left, info);
        return b;
    }
}

TBst bst_remove(TBst b, TInfo info) {
    if (b == NULL) //Albero vuoto
        return b;
    if (b->info == info) {
        if (b->left == NULL && b->right == NULL) { //Cancellazione foglia
            bst_node_destroy(b);
            return NULL;
        }
        if (b->right == NULL) {
            TNodeBst* np = b->left;
            bst_node_destroy(b);
            return np;
        }
        if (b->left == NULL) {
            TBst np = b->right;
            bst_node_destroy(b);
            return np;
        }
        //left & right != NULL + ToBeRemovedRoot case
        TNodeBst* max_dx = bst_search_max(b->left);
        b->info = max_dx->info;
        b->right = bst_remove(b->right, info);
        return b;
    }
    if (is_greater(info, b->info))
        return bst_remove(b->right, info);
    if (is_greater(b->info, info))
        return bst_remove(b->left, info);
}

/*
TBst bst_remove(TBst b, TInfo info) {
    if (b == NULL)
        return b;
    if (b->info == info) {
        if (b->left == NULL)
            if (b->right == NULL) {
                bst_node_destroy(b);
                return NULL;
            } else
                TNodeBst
            }
}
 */
TNodeBst* bst_search_max(TBst b) {
    if (b == NULL || b->right == NULL)
        return b;
    return bst_search_max(b->right);
}

TNodeBst* bst_search_min(TBst b) {
    if (b == NULL || b->left == NULL)
        return b;
    return bst_search_min(b->left);
}

void bst_visit(TBst b) {
    if (b != NULL) {
        bst_visit(b->left);
        info_print(b->info);
        bst_visit(b->right);
    }
}

void bst_visit_contr(TBst b) {
    if (b != NULL) {
        bst_visit_contr(b->right);
        info_print(b->info);
        bst_visit_contr(b->left);
    }
}

int conta_nodi(TBst b) {
    if (b == NULL)
        return 0;
    else
        return 1 + conta_nodi(b->left) + conta_nodi(b->right);
}

int somma_valori(TBst b) {
    if (b == NULL)
        return 0;
    else
        return b->info + somma_valori(b->left) + somma_valori(b->right);
}

int conta_foglie(TBst b) {
    if (b == NULL)
        return 0;
    else if (b->left == NULL && b->right == NULL)
        return 1;
    else
        return conta_foglie(b->left) + conta_foglie(b->right);
}

int conta_nodi_non_foglie(TBst b) {
    if (b == NULL || (b->left == NULL && b->right == NULL))
        return 0;
    else
        return 1 + conta_nodi_non_foglie(b->left) + conta_nodi_non_foglie(b->right);
}

int bst_numOddOdd(TBst tree) {
    //Conta i nodi di valore dispari e valore dispari
    if (NULL == tree)
        return 0;
    int count = 0;
    if (tree->left != NULL) {
        if (tree->left->info % 2)
            count++;
        count += bst_numOddOdd(tree->left->left) + bst_numOddOdd(tree->left->right);
    }
    if (tree->right != NULL) {
        if (tree->right->info % 2)
            count++;
        count += bst_numOddOdd(tree->right->left) + bst_numOddOdd(tree->right->right);
    }

    return count;
}

bool is_bst(TBst tree) {
    //Dato un albero verificare se è un bst
    bool check = true;
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return true;
    if (tree->left != NULL)
        if (is_greater(tree->left->info, tree->info)||is_greater(bst_search_max(tree->left)->info, tree->info))
            check = false;
    if (tree->right != NULL)
        if (!is_greater(tree->right->info, tree->info)||!is_greater(bst_search_min(tree->right)->info, tree->info))
            check=false;
    return check && is_bst(tree->left) && is_bst(tree->right);



    /*
    if (tree->left != NULL||!is_greater(tree->left->info, tree->info))
        if (tree->right != NULL&&!is_greater(tree->info, tree->right->info))
            if (!is_greater(bst_search_max(tree->left)->info, tree->info) && !is_greater(tree->info, bst_search_min(tree->right)->info))
                return is_bst(tree->left) && is_bst(tree->right);*/




}