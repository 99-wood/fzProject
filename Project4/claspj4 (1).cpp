#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <math.h>
#include<conio.h>
#include<Windows.h>
#define MAX 5000

//微分法求解积分
int devide = 1;//devide:分割精度，越大精度越高
double answer = 1, dx = 1;

//光标移到0，0
void goto00()
{
    int xx = 0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X = 0;
    loc.Y = 0;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc); return;
}

//三角函数eq1
double EQ1(double bozo) {
    return sin(bozo);
}

//一次函数eq2
double EQ2(double bozo) {
    return (2 * bozo - 3);
}

//函数取值
double QVZHI(double negger0) {
    double negger1 = 0, negger2, negger3;//结果
    negger2 = EQ1(negger0), negger3 = EQ2(negger0);
    if (negger0 >= 3 || negger0 <= 0)return 0;
    else if (negger2 > negger3) {
        return (3 - negger2)*dx;
    }
    else return (3 - negger3)*dx;
}

//积分函数
void NIGANMA() {
    double dx = 3.0 / ((double)devide), ans0 = 0;
    //左值
    for (int cxk1 = 0; cxk1 < devide; cxk1++) {
        ans0 += QVZHI(cxk1 * dx);
    }
    answer = ans0;
    return;
}

//管显示的
void ECHO(void) {
    goto00();
    printf("****************************\n");
    printf("prominent dx:  %-8.5f\n", dx);
    printf("prominent square: %f\n", answer);
    printf("accuracy %5d[", devide);
    if (devide <= 500) {
        for (int a = 1; a <= 25; a++) {
            if (devide >= 20 * a)printf("\033[1;37m█\033[0m");
            else printf("\033[1;30m█\033[0m");
        }
    }
    else {
        for (int a = 1; a <= 25; a++) {
            if (devide >= (MAX / 25) * a)printf("\033[1;32m█\033[0m");
            else printf("\033[1;37m█\033[0m");
        }
    }
    printf("]\n");
    printf("press A/D to change the accuracy\n");
    printf("****************************");
}


//随开随用的微分变化
void DEVIDE(){
    char add;
        add = _getch();
        switch (add) {
        case 'a': {
            if (devide > 199)
                devide -= 100;
            else if (devide > 19)
                devide -= 10;
            else devide -= 1;
            dx = 3.0 / ((double)devide);
            NIGANMA();
            break;
        }
        case 'd': {
            if (devide > 99)
                devide += 100;
            else if (devide > 9)
                devide += 10;
            else devide += 1;
            dx = 3.0 / ((double)devide);
            NIGANMA();
            break;
        }
        default: {
            break; 
        }
        }
}

int main() {
    NIGANMA();
    while (1) {
        ECHO();
        DEVIDE();
        if (devide > MAX)devide = MAX;
        if (devide < 1)devide = 1;
        Sleep(100);
    }
}