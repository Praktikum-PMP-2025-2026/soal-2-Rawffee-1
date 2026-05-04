#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gerbong {
    int a;
} gerbong;

typedef struct gerobak {
    int b;
} gerobak;


int comp(const void *c, const void *d){
    gerbong *dataC = (gerbong *)c;
    gerbong *dataD = (gerbong *)d;
    return(dataC->a - dataD->a);
}

int comp2(const void *e, const void *f){
    gerobak *dataE = (gerobak *)e;
    gerobak *dataF = (gerobak *)f;
    return(dataE->b - dataF->b);
}

int main (){
    int i, N, M;
    gerbong *kru = NULL;
    gerobak *crew = NULL;

    if (scanf("%d", &N) != 1 || N <= 0) {

    } else {
        kru = (gerbong*) malloc(N * sizeof(gerbong));
        for (i = 0; i < N; i++) {
            scanf("%d", &kru[i].a);
        }
        qsort(kru, N, sizeof(gerbong), comp);
    }

    if (scanf("%d", &M) != 1 || M <= 0) {

    } else {
        crew = (gerobak*) malloc(M * sizeof(gerobak));
        for (i = 0; i < M; i++) {
            scanf("%d", &crew[i].b);
        }
        qsort(crew, M, sizeof(gerobak), comp2);
    }

    if (kru == NULL && crew==NULL) {
        printf("MERGED EMPTY");
    } else {
        for (i = 0; i < N; i++) {
            printf("%d ", kru[i].a);
        }
        for (i = 0; i < M; i++) {
            printf("%d ", crew[i].b);
        }
    }
    printf("\n");

    if (kru != NULL) free(kru);
    if (crew != NULL) free(crew);

    return 0;
}
