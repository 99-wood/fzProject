#include<stdio.h>
#include<math.h>
#define ACC 1e-11
double mysqrt(double num){
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = num * 0.5F;
	y = num;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	double ans = 1.0 / y;
    double last = -1;
    while(fabs(ans - last) > ACC){
        last = ans;
        ans = ans - (ans * ans - num) / (2 * ans);
    }
    return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double n;
	    scanf("%lf", &n);
	    printf("%.11lf\n", mysqrt(n));
	}
    
}
