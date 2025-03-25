#include <time.h>
#include <stdlib.h>

int main()
{
    for (int k = 0; k <= i; k++)
    {
        r = rand() % 999;
        if (!verificaArray(r, arr))
        {
            arr[k] = r;
        }
        else
        {
            k--;
        }
    }
}
int verificaArray(int val, int *arr)
{
    int i;
    for (i = 0; i < sizeof(*arr); i++)
    {
        if (*arr + i == val)
        {
            return 1;
        }
    }
    return 0;
}