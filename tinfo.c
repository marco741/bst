/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tinfo.h"

bool info_greater(TInfo a, TInfo b) {
    return strcmp(a.codvolo, b.codvolo)>0;
}

bool info_equals(TInfo a, TInfo b) {
    return strcmp(a.codvolo, b.codvolo)==0;
}

void info_print(TInfo info) {
    printf("------------ Volo %s ---------------\n", info.codvolo);
    printf("Partenza: %2d:%2d %s\n",info.hpartenza,info.mpartenza, info.lpartenza);
    printf("Arrivo: %2d:%2d %s\n", info.harrivo, info.marrivo, info.larrivo);
    printf("Posti disponibili: ");
    for(int i=0;i<info.n_posti;i++){
        if(info.mappa_posti[i])
            printf("%d ", i);}
    puts("\n-----------------------------------------");
}


