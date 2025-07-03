#include "ft_printf.h"
#include <stdio.h>
int main()
{
    int a = ft_printf("kajshdakjdskdjasdja%");
    ft_printf("\n");
    int b=printf("kajshdakjdskdjasdja%");
    
    printf("\n");
    ft_printf("%d\n%d\n",a,b);
    printf("\n");

    int c = ft_printf("%");
    ft_printf("\n");
    int d=printf("%");
    printf("\n");
    ft_printf("%d\n%d\n",c,d);
    printf("\n");
}
