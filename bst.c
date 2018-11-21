/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <assert.h>
#include <math.h>
#include <limits.h>

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
    /*Caso Base*/
    if (tree == NULL)
        return true;
    
    /* Combina */
    bool check = true;   
    if (tree->left != NULL)
        if (is_greater(bst_search_max(tree->left)->info, tree->info))
            check = false;
    if (tree->right != NULL)
        if (!is_greater(bst_search_min(tree->right)->info, tree->info))
            check = false;
    
    /* Impera et combina */
    return is_bst(tree->left) && is_bst(tree->right) && check;
}

void bst_visit2d(TBst b){
    //Questa funzione l'ho fatta io e non è male
    //Funzione d'appoggio per chiamare una funzione con un parametro in più
    bst_visit2d_util(b,1);
}

void bst_visit2d_util(TBst b,int level) {
    //Funzione per stampare un bst in due dimensioni
    //In pratica è la copia di bst_visit_contr, ma con due parametri
    if (b != NULL) {
        //Processo prima il figlio destro in modo da stampare il tutto in verticale, da sinistra verso destra
        bst_visit2d_util(b->right,level+1);
        info_print2d(b->info,level);
        bst_visit2d_util(b->left,level+1);
    }
}

void info_print2d(TInfo info, int level){
    //Stampa il nodo corrente a distanza level*COUNT dal bordo sinistro
    //dopo e prima di una riga vuota.
    puts("");
    for (int i = COUNT; i < level*COUNT; i++)//ATTENZIONE vedi costante COUNT nell'header. Predefinito 10.
        printf(" ");
    printf("%4d\n", info);
} 

//INIZIO STAMPA DI CAPUANO
int bst_depth(TBst tree){
    if(tree == NULL)
        return -1;
    int hl = bst_depth(tree->left);
    int hr = bst_depth(tree->right);
    return (hl > hr)?(hl + 1):(hr + 1);
}
 
 void bst_print1(TBst tree, int o, int* n) {
    if (tree != NULL) {
        n[o] = tree->info;
        bst_print1(tree->left, (o+1)*2-1, n);
        bst_print1(tree->right, (o+1)*2, n);
    }
}

void bst_print(TBst tree) {
    int d = bst_depth(tree)+1, s = pow(2,d)-1, n[s], i, j, b;
    for (i = 0; i < s; ++i) // annulla elementi
        n[i] = INT_MIN;
    bst_print1(tree, 0, n);
    for (i = 0; i < d; ++i) { // stampa albero
        for (j = pow(2,i)-1; j < pow(2,i+1)-1; ++j) {
            b = (pow(2,(d-i-1))-1)*4;
            if (n[j] != INT_MIN)
                printf("%*d%*s", b/2+4, n[j], b/2, "");
            else
                printf("%*s", b+4,  "");
        }
        printf("\n");
    }
}
//FINE STAMPA DI CAPUANO