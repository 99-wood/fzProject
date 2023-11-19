#include <stdio.h>
#define MAXN 200
#define INF 0x3f3f3f3f
int num[MAXN][MAXN], core[MAXN][MAXN], ans[MAXN][MAXN];
int numH, numW, coreH, coreW, H, W; //数据矩阵大小，卷积核大小，池化核大小
void input(){
	scanf("%d%d%d%d%d%d", &numH, &numW, &coreH, &coreW, &H, &W);
	for(int i = 1; i <= coreH; ++i){
		for(int j = 1; j <= coreW; ++j){
			scanf("%d", &core[i][j]);
		}
	}
	for(int i = 1; i <= numH; ++i){
		for(int j = 1; j <= numW; ++j){
			scanf("%d", &num[i][j]);
		}
	}
	return;
}
int calculate(int x, int y){
	int ans = 0;
	for(int i = 0; i < coreH; ++i){
		for(int j = 0; j < coreW; ++j){
			ans += num[x + i][y + j] * core[i + 1][j + 1];
		}
	}
	return ans;
}
void solve(){
	for(int i = 1; i <= numH - coreH + 1; ++i){
		for(int j = 1; j <= numW - coreW + 1; ++j){
			ans[i][j] = calculate(i, j);
		}
	}
    int cnt1 = 1, cnt2 = 1;
	for(int sx = 1; sx <= numH - coreH + 1; sx += H){
        cnt2 = 1;
		for(int sy = 1; sy <= numW - coreW + 1; sy += W){
            int maxx = -INF;
			for(int x = sx; x <= numH - coreH + 1; x++){
                for(int y = sy; y <= numW - coreW)
            }
		}
	}
	return;
}
void print(){
	for(int i = 1; i <= numH - coreH - H + 2; ++i){
		for(int j = 1; j <= numW - coreW - W + 2; ++j){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return;
}
int main(){
	// freopen("test.in", "r", stdin);
	input();
	solve();
	print();
}