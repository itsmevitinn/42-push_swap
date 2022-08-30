// int main(int *stack)
// {
//     int len;
//     int start;
//     int q;
//     start = 0;
//     len = count_len(stack)
//     if (start < end)
//     {
//         q = partition(stack);
//     }
// }
#include <stdio.h>
int ft_strlen(int *stack);
void partition(int *stack);

int main(void)
{
    int stack[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int j = 0;
    while (stack[j])
        printf("Valor da stack %i\n", stack[j++]);
    partition(stack);
    j = 0;
    while (stack[j])
        printf("Valor da stack %i\n", stack[j++]);
}

int ft_strlen(int *stack)
{
    int i;

    i = 0;
    while(stack[i])
        i++;
    return (i);
}

void partition(int *stack)
{
    int start;
    int smallests_index; 
    int pivot;
    int offset;

    pivot = ft_strlen(stack);
    pivot--;
    start = 0;
    smallests_index = -1;
    offset = start;
    
    while(offset < pivot)
    {
        if (stack[offset] < stack[pivot])
        {
            smallests_index++;
            stack[smallests_index] = stack[offset];
        }
        offset++;
    }
    stack[smallests_index + 1] = stack[pivot];
}