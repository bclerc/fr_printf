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
	int precision;
    int width;
    int minus;
    int zero;
    int dot;
    int asterisk;
	int total;
}             t_flag;


void	pf_str(t_flag *flag, char *str, int length);
void	pf_write(t_flag *flag, char c);
int		ft_printf(char* text, ...);
void	put_field(t_flag *flag, int value_length, int zero);
int		pf_precision(t_flag *flag, int value_length);
int     pf_putstr(t_flag *flag);
int		pf_tohex(t_flag *flag);
int		pf_address(t_flag *flag);
void	pf_percent(t_flag *flag);
void    pf_putnbr(t_flag *flag);
void	pf_putunbr(t_flag *flag);
void    pf_putchar(t_flag *flag);
void    pf_printbinary(t_flag *flag);

#endif