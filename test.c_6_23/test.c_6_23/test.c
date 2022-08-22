void initboard(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        arr[i] = 0;
    }
}
void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
void Reverse(int arr[], int sz)
{
    int laft = 0;
    int right = sz - 1;

    while (laft < right)
    {
        int tem = arr[laft];
        arr[laft] = arr[right];
        arr[right] = tem;
        laft++;
        right--;
    }
}
int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    // initboard(arr,sz);
    //print(arr,sz);
    Reverse(arr, sz);
    print(arr, sz);
    return 0;
}
