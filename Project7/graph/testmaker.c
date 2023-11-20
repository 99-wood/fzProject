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
	freopen("test.in","w",stdout);
	printf("200\n");
	int len;
	srand((unsigned int)(time(NULL)));
	for(int i=0;i<=200;i++){//生成半径
		while(rad[i]<1){
			rad[i]=rand()%(5-1)+1;
		}
	}
	
	for(int i=0;i<2;i++){//生成圆心 
		for(int j=0;j<=200;j++){
				cen[i][j]=rand()%((10-rad[j])-rad[j]+1)+rad[j];
		}
	}
	
	for(int i=1;i<=200;i++){//第i个圆 
		if(i & 1) {
			for(int j=1;j<=10;j++){//x轴 
				for(int k=1;k<=10;k++){//y轴 
					len=(cen[0][i]-j)*(cen[0][i]-j)+(cen[1][i]-k)*(cen[1][i]-k);
					if(len-rad[i]*rad[i]<=0){
						printf("1 ");
					}else{
						printf("0 ");
					}
				}
				printf("\n");
			}
		}
		else{
			int ax = (rand() % 10) + 1, ay = (rand() % 10) + 1, bx = (rand() % 10) + 1, by = (rand() % 10) + 1;
			if(ax > bx){
				ax ^= bx;
				bx ^= ax;
				ax ^= bx;
			}
			if(ay > by){
				ay ^= by;
				by ^= ay;
				ay ^= by;
			}
			for(int x = 1; x <= 10; ++x){
				for(int y = 1; y <= 10; ++y){
					if(ax <= x && x <= bx && ay <= y && y <= by) printf("1 ");
					else printf("0 ");
				}
				printf("\n");
			}
		}
		printf("\n") ;
	}
	return 0;
}
