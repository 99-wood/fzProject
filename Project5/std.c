#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAXN 1000010
#define eta 0.999
#define ACC 1e-9
double cal(double x){
	return 10 * sin(x * x) - 2 * sin(x) + 5;
}
double f(double x){
	double T = 10000;
	while(T >= ACC){
		double delta = rand() & 1 ? T : -T ;
		if(cal(x + delta) < cal(x)){
			x = x + delta;
		}
		else{
			x = x + delta * T;
		}
		T *= eta;
//		printf("%lf %lf\n", x, cal(x));
	}
	return x;
}
double pi = acos(-1.0);
int main(){
    srand(time(NULL));
	double ans = 177842369.83237848000000000000;
    long long k;
    scanf("%lld", &k);
    for(long long i = 0; i <= k; ++i){
    	double x = (pi / 2) + i * 2 * pi;
    	if(cal(x) < cal(ans)) ans = x;
	}
	printf("x = %.20lf f(x) = %.20lf", ans, cal(ans));
	return 0;
}
