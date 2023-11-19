#include "FFT.h"
#include <stdio.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
int a[MAXN], b[MAXN], ans[MAXN];
void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
	return;
}
int main(){
	int n, m, len;
	scanf("%d%d%d", &n, &m, &len);
	--n;
	--m;
	for(int i = 0; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i <= m; ++i) scanf("%d", &b[i]);
	for(int i = 0; i <= (n >> 1); ++i) swap(&a[i], &a[n - i]);
	// for(int i = 0; i <= n; ++i) printf("%d ", a[i]);
	convolution(n, m, a, b, ans);
    for(int i = 0; i <= m - n; ++i) ans[i] = ans[i + n];
    // for(int i = 0; i <= m - n; ++i) printf("%d ", ans[i]);
	// printf("\n");
    int cnt = 0;
    for(int s = 0; s <= m - n; s += len){
        int maxx = -INF;
        for(int j = s; j <= m - n && j < s + len; ++j){
            if(ans[j] > maxx) maxx = ans[j];
        }
        ans[cnt++] = maxx;
    }
	for(int i = 0; i < cnt; ++i) printf("%d ", ans[i]);
}
/*
3 5 2
-2 2 1
3 4 1 5 6
*/