/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flag
{
    va_list flags;
    char *args;
    char type;
    char *formats;
    int field_size;
    int minus;
    int zero;
    int dot;
    int asterisk;
    
}             t_flag;

int     pf_putstr(t_flag *flag);
void    pf_putnbr(t_flag *flag);
void    pf_putchar(t_flag *flag);
void    pf_printbinary(t_flag *flag);

#endif