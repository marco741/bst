#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinfo.h"

bool info_greater(TInfo l, TInfo r)
{
    return strcmp(l.cognome, r.cognome) ? strcmp(l.cognome, r.cognome) > 0 : strcmp(l.nome, r.nome) > 0;
}

bool info_less(TInfo l, TInfo r)
{
    return strcmp(l.cognome, r.cognome) ? strcmp(l.cognome, r.cognome) < 0 : strcmp(l.nome, r.nome) < 0;
}

bool info_equal(TInfo l, TInfo r)
{
    return strcmp(l.cognome, r.cognome) ? !strcmp(l.cognome, r.cognome) : !strcmp(l.nome, r.nome);
}

void info_print(TInfo info)
{
    printf("Matricola: %-10s\t-\t Cognome: %-20s\t-\tNome: %-20s\n", info.matricola, info.cognome, info.nome);
}

void info_copy(TInfo *l, TInfo *r)
{
    strcpy(l->matricola, r->matricola);
    strcpy(l->cognome, r->cognome);
    strcpy(l->nome, r->nome);
}

void info_swap(TInfo *l, TInfo *r)
{
    TInfo temp;
    info_copy(&temp, l);
    info_copy(l, r);
    info_copy(r, &temp);
}
