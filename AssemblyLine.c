#include <stdio.h>
#include <stdlib.h>
int N;
void Assembly(int e[],int A[N][N],int T[N][N- 1],int x[]){
    int F1[N],F2[N],l[2][N],f,a;
    F1[0] = e[0] + A[0][0];
    F2[0] = e[1] + A[1][0];
    int j;
    for(j = 1; j<N; ++j){
        if( (F1[j-1]+A[0][j]) <= (F2[j-1]+T[1][j-1]+A[0][j]) ){
            F1[j] = F1[j-1] + A[0][j];
            l[0][j] = 1;}
        else{
            F1[j] = F2[j-1] + T[1][j-1] + A[0][j];
            l[0][j] = 2;}
        if( (F2[j-1]+A[1][j]) <= (F1[j-1]+T[0][j-1]+A[1][j]) ){
            F2[j] = F2[j-1] + A[1][j];
            l[1][j] = 2;}
        else{
            F2[j] = F1[j-1] + T[0][j-1] + A[1][j];
            l[1][j] = 1;}}
    if( (F1[N-1] + x[0]) <= (F2[N-1] + x[1]) ){
    f = F1[N-1] + x[0];
    a = 1;}
    else{
    f = F2[N-1] + x[1];
    a = 2;}
    int i = a;
    printf("Minimal cost is: %d\n",f);
    printf("\nThe Optimal path is:\n");
    for(j=1;j<N;++j){
    i = l[i-1][j];
    printf("line: %d station: %d\n",i,j);}
    i = a;
    printf("line: %d station: %d\n",i,N);}
int main(){
    int e[2];
    printf("Enter the number of nodes: ");
    scanf("%d",&N);
    int A[2][N];
    int x[2];
    int T[2][N-1];
    int i;
    printf("Enter the entry values:\n");
    for(i=0;i<2;i++)
        scanf("%d",&e[i]);
    printf("Enter the exit values:\n");
    for(i=0;i<2;i++)
        scanf("%d",&x[i]);
    printf("\nEnter the station times of row/line S1:\n");
    for(i=0; i<N; ++i)
        scanf("%d", &A[0][i]);
    printf("\nEnter the station times of row/line S2:\n");
    for(i=0 ; i<N; ++i)
        scanf("%d", &A[1][i]);
    printf("\nEnter transaction times from row/line S1:\n");
    for(i=0; i<N-1; ++i)
        scanf("%d", &T[0][i]);
    printf("\nEnter transaction times from row/line S2:\n");
    for(i=0; i<N-1; ++i)
        scanf("%d", &T[1][i]);
    Assembly(e,A,T,x);
    return 0;
}
