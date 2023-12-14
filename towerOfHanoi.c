#include<stdio.h>
#include<stdlib.h>

void PrintHanoi(int n, int N,char* dest,int *x){
    if(dest == "A" )x[n-1]=1;
    if(dest == "B" )x[n-1]=2;
    if(dest == "C" )x[n-1]=3;

    int A[3][N];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            A[i][j] =0;
        }
    }

    for(int i = 0; i<N; i++){
        int j;
        for(j =0;A[x[N-i-1]-1][j]!=0;j++){
            ;;
        }
        A[x[N-i-1]-1][j]= N-i;
    }

    // check the position
    // for(int j = N-1; j > -1; j--){
    //     for(int i = 0; i < N; i++){
    //         printf("%d", A[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\n");
    
    for(int i = 0; i < N+1; i++)printf(" ");
    printf("|");
    for(int i = 0; i < 2*N+1; i++)printf(" ");
    printf("|");
    for(int i = 0; i < 2*N+1; i++)printf(" ");
    printf("|");
    for(int i = 0; i < N+1; i++)printf(" ");
    printf("\n");

    for(int i=0; i<N; i++){
        for(int j = 0; j < N+1-A[0][N-i-1]; j++)printf(" ");
        for(int j = 0; j < A[0][N-i-1]; j++)printf("+");
        A[0][N-i-1]!=0?printf("+"):printf("|");
        for(int j = 0; j < A[0][N-i-1]; j++)printf("+");
        for(int j = 0; j < (2*N)+1-A[0][N-i-1]-A[1][N-i-1]; j++)printf(" ");
        for(int j = 0; j < A[1][N-i-1]; j++)printf("+");
        A[1][N-i-1]!=0?printf("+"):printf("|");
        for(int j = 0; j < A[1][N-i-1]; j++)printf("+");
        for(int j = 0; j < (2*N)+1-A[1][N-i-1]-A[2][N-i-1]; j++)printf(" ");
        for(int j = 0; j < A[2][N-i-1]; j++)printf("+");
        A[2][N-i-1]!=0?printf("+"):printf("|");
        for(int j = 0; j < A[2][N-i-1]; j++)printf("+");
        for(int j = 0; j < N+1-A[2][N-i-1]; j++)printf(" ");
        printf("\n");
    }

    for(int i=0; i<6*N+7; i++)printf("¯");
    printf("\n");
    for(int i = 0; i < N+1; i++)printf(" ");
    printf("A");
    for(int i = 0; i < 2*N+1; i++)printf(" ");
    printf("B");
    for(int i = 0; i < 2*N+1; i++)printf(" ");
    printf("C");
    for(int i = 0; i < N+1; i++)printf(" ");
    printf("\n\n");

}

void Hanoi(int n, int N, char *from, char *work, char *dest,int *x){

    if(n>=2) Hanoi(n-1, N, from, dest, work,x);
    printf("Move the disc # %d from %s to %s.\n",n,from,dest,x);
    PrintHanoi(n,N,dest,x);
    if(n>=2) Hanoi(n-1, N, work, from, dest,x);
}

void main(void){
    int N;
    while(N<1){
        printf("How many disks? N : ");
        scanf("%d",&N);
    }
    int x[N];
    for(int i = 0; i < N; i++) x[i] = 1;
    printf("\n");
    for(int i=0; i<3*N; i++)printf("=");
    printf("<START>");
    for(int i=0; i<3*N; i++)printf("=");
    printf("\n");
    PrintHanoi(N, N,"skip",x);
    Hanoi(N,N,"A","B","C",x);
}