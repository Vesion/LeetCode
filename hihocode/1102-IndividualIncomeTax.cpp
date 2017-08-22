#include <iostream>
#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {

    double tax;
    double income;
    printf("请输入您的个人所得税：\n");
    scanf("%lf", &tax);

    if (tax <= 45) income = 3500 + tax / 0.03; 
    else if (tax <= 345) income = 5000 + (tax - 45) / 0.1; 
    else if (tax <= 1245) income = 8000 + (tax - 345) / 0.2; 
    else if (tax <= 7745) income = 12500 + (tax - 1245) / 0.25; 
    else if (tax <= 13745) income = 38500 + (tax - 7745) / 0.3; 
    else if (tax <= 22495) income = 58500 + (tax - 13745) / 0.35; 
    else income = 83500 + (tax - 22495) / 0.45;

    printf("您的工资为：%lf\n", income);
    return 0;
}
