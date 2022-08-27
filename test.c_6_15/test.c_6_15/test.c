#include<stdio.h>
#include<math.h>
int main()
{
    int i = 0;
    for (i = 0; i < 100000; i++)
        //确定i是几位数
    {
        int n = 1;//tmp<10n不在++
        int tmp = i;
        int sum = 0;
        while (tmp /= 10)
        {
            n++;
        }
        //各位的n次方的和
        tmp = i;
        while (tmp)
        {
            sum += pow(tmp % 10, n);
            tmp /= 10;
        }
        //判断i是否为自幂数
        if (i == sum)
        {
            printf("自幂数有%d ", i);
        }
    }
    return 0;
}
