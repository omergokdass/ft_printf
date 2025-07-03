#include "ft_printf.h"

int verifier(char c){
    if (c == 'c' || c == 's' || c == 'p' || c == 'd'
        || c == 'i'|| c == 'u' || c == 'x' || c == 'X'|| c == '%')
    return (1);

    return (0);
}


int printer(char c, va_list args)
{
    if (c == 'c')
		return ft_putchar(va_arg(args, int));
    else if (c == 's')
        return ft_putstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        return ft_putnbr(va_arg(args, int));
    else if (c == 'x' || c == 'X')
        return ft_puthex(va_arg(args, unsigned int), c);
	else if(c == 'u')
		return ft_unbr(va_arg(args, unsigned int));
	else if(c == 'p')
		return ft_puthex((unsigned long)va_arg(args, void *), c);
	else if(c == '%')
		return ft_putchar('%');
    return (1);
}

int ft_printf(const char *s, ...)
{
    int i;
    int counter;

    va_list list;
    va_start(list, s);
    counter = 0;
    i = 0;
    while (s[i])
    {

        if (s[i] == '%' && verifier(s[i + 1]))
            counter += printer(s[++i], list);
        else if (s[i] == '%' && !(verifier(s[i + 1])))
			return (-1);	
		else
            counter += write(1, &s[i], 1);
    
        i++;

    }
    va_end(list);
    return (counter);
}