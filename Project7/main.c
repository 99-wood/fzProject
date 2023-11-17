#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAXN 110
// #define RAND_MAX 32767
struct InputLayer{
    int siz;
    double output[MAXN];
}inputLayer;
struct HiddenLayer{
    int siz;
    double w[MAXN][MAXN];
    double output[MAXN];
}hiddenLayer;
struct OutputLayer{
    int siz;
    double w[MAXN][MAXN];
    double output[MAXN];
}outputLayer;
double g[MAXN], e[MAXN];
double eta = 0.01;
double input[MAXN], output[MAXN];
void init(){
    for(int i = 1; i <= hiddenLayer.siz; ++i){
        for(int j = 0; j <= inputLayer.siz; ++j){
            hiddenLayer.w[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for(int i = 1; i <= outputLayer.siz; ++i){
        for(int j = 0; j <= hiddenLayer.siz; ++j){
            outputLayer.w[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return;
}
double f(double x){
    return 1.0 / (1.0 + exp(-x));
}
void run(){
    inputLayer.output[0] = -1;
    for(int i = 1; i <= inputLayer.siz; ++i){
        inputLayer.output[i] = input[i];
    }
    hiddenLayer.output[0] = -1;
    for(int i = 1; i <= hiddenLayer.siz; ++i){
        double ans = 0;
        for(int j = 0; j <= inputLayer.siz; ++j){
            ans += inputLayer.output[j] * hiddenLayer.w[i][j];
        }
        ans = f(ans);
        hiddenLayer.output[i] = ans;
    }
    for(int i = 1; i <= outputLayer.siz; ++i){
        double ans = 0;
        for(int j = 0; j <= hiddenLayer.siz; ++j){
            ans += hiddenLayer.output[j] * outputLayer.w[i][j];
        }
        ans = f(ans);
        outputLayer.output[i] = ans;
    }
    return;
}
void update(){
    for(int i = 1; i <= outputLayer.siz; ++i){
        g[i] = outputLayer.output[i] * (1.0 - outputLayer.output[i]) * (output[i] - outputLayer.output[i]);
    }
    for(int i = 1; i <= hiddenLayer.siz; ++i){
        double sum = 0;
        for(int j = 1; j <= outputLayer.siz; ++j){
            sum += outputLayer.w[j][i] * g[j];
        }
        e[i] = hiddenLayer.output[i] * (1.0 - hiddenLayer.output[i]) * sum;
    }
    for(int i = 1; i <= outputLayer.siz; ++i){
        for(int j = 0; j <= hiddenLayer.siz; ++j){
            outputLayer.w[i][j] += eta * g[i] * hiddenLayer.output[j];
        }
    }
    for(int i = 1; i <= hiddenLayer.siz; ++i){
        for(int j = 0; j <= inputLayer.siz; ++j){
            hiddenLayer.w[i][j] += eta * e[i] * inputLayer.output[j];
        }
    }
    return;
}
int main(){
    srand(time(NULL));
    int op;
    printf("1: new 2: read 3: train 4: predict 5: output 0: exit\n");
    while(scanf("%d", &op) != EOF){
        if(op == 1){ //新建
            printf("Please input the size of 3 layer.\n");
            scanf("%d%d%d", &inputLayer.siz, &hiddenLayer.siz, &outputLayer.siz);
            init();
        }
        else if(op == 2){ //读入
            printf("Please input the file name.\n");
            char fileName[100];
            scanf("%s", fileName);
            freopen(fileName, "r", stdin);
            scanf("%d%d%d", &inputLayer.siz, &hiddenLayer.siz, &outputLayer.siz);
            for(int i = 1; i <= hiddenLayer.siz; ++i){
                for(int j = 0; j <= inputLayer.siz; ++j){
                    scanf("%lf", &hiddenLayer.w[i][j]);
                }
            }
            for(int i = 1; i <= outputLayer.siz; ++i){
                for(int j = 0; j <= hiddenLayer.siz; ++j){
                    scanf("%lf", &outputLayer.w[i][j]);
                }
            }
            freopen("CON", "r", stdin);
        }
        else if(op == 3){ //训练
            printf("Please input how many times you want to train.\n");
            int T;
            scanf("%d", &T);
            printf("If you want to start with file? (1, 0)\n");
            int tmp;
            scanf("%d", &tmp);
            if(tmp){
                printf("Please input the file name.\n");
                char fileName[100];
                scanf("%s", fileName);
                while(T--){
                    freopen(fileName, "r", stdin);
                    int t;
                    scanf("%d", &t);
                    for(int i = 1; i <= t; ++i){
                        for(int j = 1; j <= inputLayer.siz; ++j) scanf("%lf", &input[j]);
                        for(int j = 1; j <= outputLayer.siz; ++j) scanf("%lf", &output[j]);
                        run();
                        update();
                    }
                    freopen("CON", "r", stdin);
                }
                
            }
            else{
                int t;
                scanf("%d", &t);
                for(int i = 1; i <= t; ++i){
                    for(int i = 1; i <= inputLayer.siz; ++i) scanf("%lf", &input[i]);
                    for(int i = 1; i <= outputLayer.siz; ++i) scanf("%lf", &output[i]);
                    run();
                    update();
                }
            }
        }
        else if(op == 4){ //预测
         printf("If you want to start with file? (1, 0)\n");
            int tmp;
            scanf("%d", &tmp);
            if(tmp){
                printf("Please input the file name.\n");
                char fileName[100];
                scanf("%s", fileName);
                freopen(fileName, "r", stdin);
                for(int i = 1; i <= inputLayer.siz; ++i) scanf("%lf", &input[i]);
                run();
                for(int i = 1; i <= outputLayer.siz; ++i) printf("%lf ", outputLayer.output[i]);
                freopen("CON", "r", stdin);
            }
            else{
                for(int i = 1; i <= inputLayer.siz; ++i) scanf("%lf", &input[i]);
                run();
                for(int i = 1; i <= outputLayer.siz; ++i) printf("%lf ", outputLayer.output[i]);
                printf("\n");
            }
        }
        else if(op == 5){ //导出
            printf("Please input the file name.\n");
            char fileName[100];
            scanf("%s", fileName);
            freopen(fileName, "w", stdout);
            printf("%d %d %d\n", inputLayer.siz, hiddenLayer.siz, outputLayer.siz);
            for(int i = 1; i <= hiddenLayer.siz; ++i){
                for(int j = 0; j <= inputLayer.siz; ++j){
                    printf("%.6lf ", hiddenLayer.w[i][j]);
                }
                printf("\n");
            }
            for(int i = 1; i <= outputLayer.siz; ++i){
                for(int j = 0; j <= hiddenLayer.siz; ++j){
                    printf("%.6lf ", outputLayer.w[i][j]);
                }
                printf("\n");
            }
            freopen("CON", "w", stdout);
        }
        else{ //退出
            return 0;
        }
        printf("1: new 2: read 3: train 4: predict 5: output 0: exit\n");
    }
    return 0;
}
