#include "../includes/fillit.h"

void	ft_print_map(t_piece *list)
{
	while (list)
	{
		ft_putstr("[\n");
		ft_putstr((char*)(list->content));
		ft_putstr("\n]");
		ft_putstr(" size: ");
		ft_putchar(list->alpha);
		ft_putnbr((int)(list->content_size));
		ft_putstr("  -->  ");
		list = list->next;
	}
	ft_putstr("NULL\n");
}
