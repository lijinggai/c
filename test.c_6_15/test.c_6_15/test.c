#include<stdio.h>
#include<math.h>
int main()
{
    int i = 0;
    for (i = 0; i < 100000; i++)
        //ȷ��i�Ǽ�λ��
    {
        int n = 1;//tmp<10n����++
        int tmp = i;
        int sum = 0;
        while (tmp /= 10)
        {
            n++;
        }
        //��λ��n�η��ĺ�
        tmp = i;
        while (tmp)
        {
            sum += pow(tmp % 10, n);
            tmp /= 10;
        }
        //�ж�i�Ƿ�Ϊ������
        if (i == sum)
        {
            printf("��������%d ", i);
        }
    }
    return 0;
}
