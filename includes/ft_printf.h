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
	int nbrvalue;
    int width;
    int minus;
    int zero;
    int dot;
    int asterisk;
    
}             t_flag;

void	put_field(t_flag *flag, int value_lenght);
int     pf_putstr(t_flag *flag);
int		pf_tohex(t_flag *flag);
int		pf_address(t_flag *flag);
void    pf_putnbr(t_flag *flag);
void	pf_putunbr(t_flag *flag);
void    pf_putchar(t_flag *flag);
void    pf_printbinary(t_flag *flag);

#endif