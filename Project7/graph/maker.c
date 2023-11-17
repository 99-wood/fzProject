#include<stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int cen[2][100];
int rad[100]={0};
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	freopen("graph.in","w",stdout);
	printf("100\n");
	int len;
	srand((unsigned int)(time(NULL)));
	
	for(int i=0;i<100;i++){//生成半径
		while(rad[i]<1){
			rad[i]=rand()%(5-1)+1;
		}
	}
	
	for(int i=0;i<2;i++){//生成圆心 
		for(int j=0;j<100;j++){
				cen[i][j]=rand()%((10-rad[j])-rad[j]+1)+rad[j];
		}
	}
	
//	for(int i=0;i<100;i++){
//		printf("%d %d %d\n",cen[0][i],cen[1][i],rad[i]);
//	} 
	
	for(int i=1;i<=100;i++){//第i个圆 
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
		printf("0 1\n");
//		printf("%d %d %d\n",cen[0][i],cen[1][i],rad[i]);
	}
//	for(int i = 1; i <= 100; ++i){
//		int ax = (rand() % 10) + 1, ay = (rand() % 10) + 1, bx = (rand() % 10) + 1, by = (rand() % 10) + 1;
//		if(ax > bx){
//			ax ^= bx;
//			bx ^= ax;
//			ax ^= bx;
//		}
//		if(ay > by){
//			ay ^= by;
//			by ^= ay;
//			ay ^= by;
//		}
//		for(int x = 1; x <= 10; ++x){
//			for(int y = 1; y <= 10; ++y){
//				if(ax <= x && x <= bx && ay <= y && y <= by) printf("1 ");
//				else printf("0 ");
//			}
//			printf("\n");
//		}
//		printf("1 0\n");
//	}
	
	return 0;
}
