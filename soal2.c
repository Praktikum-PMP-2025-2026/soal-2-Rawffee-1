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
    gerbong *kru;
    scanf("%d", &N);

    kru = (gerbong*) malloc(N * sizeof(gerbong));

    for (i = 0; i < N; i++) {
        scanf("%d", &kru[i].a);
    }

    gerobak *crew;
    scanf("%d", &M);

    crew = (gerobak*) malloc(M * sizeof(gerobak));

    for (i = 0; i < M; i++) {
        scanf("%d", &crew[i].b);
    }

    qsort(kru, N, sizeof(gerbong), comp);
    qsort(crew, M, sizeof(gerobak), comp2);

    printf("MERGED");
    for (i = 0; i < N; i++) {
        printf("%d ", kru[i].a);
    }

    for (i = 0; i < M; i++) {
        printf("%d ", crew[i].b);
    }

    free(kru);
    free(crew);
    return 0;
}
