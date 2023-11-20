#include<stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int cen[2][210];
int rad[210]={0};
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	freopen("test.out","r",stdin);
    int cnt = 0;
    for(int i = 1; i <= 200; ++i){
        double a;
        scanf("%lf", &a);
        if(round(a) == (i & 1)) ++cnt;
    }
    printf("%lf", (double)cnt / 200);
	return 0;
}
