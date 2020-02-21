#include<stdio.h>
#include<stdlib.h>
#define INF 99999
int min(int x,int y){
    if(x < y)
        return x;
    else
        return y;}
void makingChange(int amount,int d[],int N){
    int M[N + 1][amount  + 1],ans[amount + 1];
    for(int j = 1;j <= N;j++)
        M[j][0] = 0;
    for(int i = 1; i <= N;i++)
        for(int j = 1; j <= amount;j++){
            ans[j] = -1;
            if(i == 1 && j < d[i])
                M[i][j] = INF;
            else if(i == 1)
                M[i][j] = 1 + M[i][j - d[i]];
            else if(j < d[i])
                M[i][j] = M[i - 1][j];
            else
                M[i][j] = min(M[i - 1][j],1 + M[i][j - d[i]]);}
            int i = 1,j = N,t = amount;
            if(M[j][t] < 99999)
                while(t != 0){
                    if(M[j][t] != M[j - 1][t]){
                        t -= d[j];
                        ans[i++] = d[j];}
                    else
                        j--;}
            printf("Minimum coins required are: %d\n",M[N][amount]);
            i = 1;
                if(ans[i] != -1){
                    printf("The coins or notes used are: \n");
                    while(ans[i] != -1){
                        printf("%d-->%d\n",i,ans[i]);
                        i++;}}
                else
                    printf("NOT POSSIBLE!!\n");}
void main()
{
    int N,amount;
    printf("\nEnter no. of coins and amount: ");
    scanf("%d %d",&N,&amount);
    int d[N + 1];
    printf("\nEnter the coins or notes available: ");
    for(int i = 1;i <= N;i++)
        scanf("%d",&d[i]);
    makingChange(amount,d,N);
}
