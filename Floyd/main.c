#include <stdio.h>

int A1_[7][6][6]={
    {{0,3,10000,10000,10000,10000},
    {3,0,9,10000,10000,10000},
    {10000,9,0,10000,10000,10000},
    {10000,10000,10000,0,10000,5},
    {10000,10000,10000,10000,0,1},
    {10000,10000,10000,5,1,0}}
};

int A2[7][6][6]={
    {{0,3,10000,10000,10000,10000},
    {3,0,7,10000,5,10000},
    {10000,7,0,9,10000,3},
    {10000,10000,9,0,25,1},
    {10000,5,10000,25,0,2},
    {10000,10000,3,1,2,0}}
};

int K5_[6][5][5]={
    {{0,96,10000,56,105},
    {96,0,10000,157,10000},
    {10000,10000,0,118,91},
    {56,157,118,0,10000},
    {105,10000,91,10000,0}}
};

int min(int a, int b)
{
    return (a<b)?a:b;
}

void print_floyd(int v) {
    for(int k=0;k<=v;k++) {
        printf("d%d\n",k);
        printf("==============\n");
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                printf("(%d) ",A2[k][i][j]);
            }
            printf("\n");
        }
    }
}

void floyd(int v) {
   for(int k=1;k<=v;k++) {
       for(int i=0;i<v;i++) {
           for(int j=0;j<v;j++) {
               int sum = A2[k-1][i][k-1] + A2[k-1][k-1][j]; 
               if(min(A2[k-1][i][j], sum) != A2[k-1][i][j])
               {
                   printf("------> Modificando k=%d [%d,%d] de valor %d a valor %d\n",k,i+1,j+1,A2[k-1][i][j],sum);
                   printf("----------> Sum = %d en [%d,%d] + %d en [%d,%d]\n",A2[k-1][i][k-1],i+1,k,A2[k-1][k-1][j],k,j+1);
               }
                   //printf("------> Modificando k=%d [%d,%d] de valor %d a valor (%d)[%d , %d] + (%d) [%d , %d]\n",k,i+1,j+1,A1[k-1][i][k-1],i+1,k,A1[k-1][k-1][j],k,j+1);
               A2[k][i][j]=min(A2[k-1][i][j], A2[k-1][i][k-1] + A2[k-1][k-1][j]);
           }
       }
   }  
}

int main(int argc, char **argv)
{
	floyd(6);
    print_floyd(6);
      getc(stdin);
	return 0;
}
