/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bst.h
 * Author: marco
 *
 * Created on 14 novembre 2018, 18.13
 */

#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef int TInfo;

struct SNodeBst {
	TInfo info;
	struct SNodeBst* right;
	struct SNodeBst* left;
};

typedef struct SNodeBst TNodeBst;
typedef struct SNodeBst* TBst;

bool is_greater(int a, int b);
void print_info(TInfo info);
TNodeBst* bst_node_create(TInfo info);
void bst_node_destroy(TNodeBst* node);
TBst bst_insert(TBst b, TInfo info);
TBst bst_remove(TBst b, TInfo info);
TNodeBst* bst_search_max(TBst b);
void bst_visit(TBst b);
void bst_visit_contr(TBst b);
int conta_nodi(TBst b);
int somma_valori(TBst b);
int conta_foglie(TBst b);
int conta_nodi_non_foglie(TBst b);

#endif /* BST_H */

