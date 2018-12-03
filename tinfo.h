/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TInfo.h
 * Author: marco
 *
 * Created on 3 dicembre 2018, 14.44
 */

#ifndef TINFO_H
#define TINFO_H
#include <stdbool.h>
#define LENGTH 256
#define DIM_CODVOLO 5
#define DIM_LUOGO 4

typedef struct SVolo{
    char codvolo[DIM_CODVOLO+1];
    int hpartenza;
    int mpartenza;
    char lpartenza[DIM_LUOGO+1];
    int harrivo;
    int marrivo;
    char larrivo[DIM_LUOGO+1];
    int n_posti;
    bool* mappa_posti;
        
} TVolo;
typedef TVolo TInfo;

bool info_greater(TInfo a, TInfo b);
bool info_equals(TInfo a, TInfo b);
void info_print(TInfo info);

#endif /* TINFO_H */

