#include<stdio.h>
#include<string.h>
void PRINT_LCS(int m,int n,char* b[m][n],char X[],int i,int j){
    if(i== 0 || j== 0)
        return;
    if(strcmp((char*) b[i][j], "\'") == 0){
        printf("%c\n",X[i]);
        if((i - 1  == 0|| j - 1 == 0) &&(strcmp((char*) b[i][j], "\'") == 0))
            printf("%c\n",X[i - 1]);
        PRINT_LCS(m,n,b,X,i-1,j-1);}
    else if(strcmp((char*) b[i][j],"|") == 0)
        PRINT_LCS(m,n,b,X,i-1,j);
    else
        PRINT_LCS(m,n,b,X,i,j-1);}
int LCS_LENGHT(char X[], char Y[], int m, int n ) {
   int c[m+1][n+1];
   char* b[m][n];  //pipe = up arrow, frontslash = diagonal arrow, dash = left arrow
   int i, j;
   for (i=0; i<=m; i++) {
     for (j=0; j<=n; j++) {
       if (i == 0 || j == 0)
         c[i][j] = 0;
       else if (X[i] == Y[j]) {
         c[i][j] = c[i-1][j-1] + 1;
         b[i][j] = "\'";}

       else if(c[i-1][j] >= c[i][j-1]){
           c[i][j] = c[i-1][j];
           b[i][j] = "|";}
       else{
           c[i][j] = c[i][j-1];
           b[i][j] = "-";}} }
    PRINT_LCS(m,n,b,X,m - 1,n - 1);
   return c[m][n]; }
int main()
{
  char X[] = "polynomial";
  char Y[] = "exponential";

  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d", LCS_LENGHT( X, Y, m, n ) );

  return 0;
}
