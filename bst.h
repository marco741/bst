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
#include "tinfo.h"
#include <stdbool.h>
#define COUNT 10

struct SNodeBst {
	TInfo info;
	struct SNodeBst* right;
	struct SNodeBst* left;
};

typedef struct SNodeBst TNodeBst;
typedef struct SNodeBst* TBst;
TNodeBst* bst_node_create(TInfo info);
void bst_node_destroy(TNodeBst* node);
TBst bst_insert(TBst b, TInfo info);
TBst bst_remove(TBst b, TInfo info);
TNodeBst* bst_search_max(TBst b);
TNodeBst* bst_search_min(TBst b);
void bst_visit(TBst b);
void bst_visit_contr(TBst b);
void bst_visit2d(TBst b);
void bst_visit2d_util(TBst b, int level);
void info_print2d(TInfo info, int level);
int conta_nodi(TBst b);
int conta_foglie(TBst b);
int conta_nodi_non_foglie(TBst b);
bool is_bst(TBst tree);
int bst_depth(TBst tree);
void bst_print1(TBst tree, int o, int* n);
void bst_print(TBst tree);

#endif /* BST_H */

