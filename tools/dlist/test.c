#include "dlist.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	t_dlist *dlst = 0;
	ft_dlstadd_sort(&dlst, ft_dlstnew("cont_5"), strcmp);
	ft_dlstadd_sort(&dlst, ft_dlstnew("cont_1"), strcmp);
	ft_dlstadd_sort(&dlst, ft_dlstnew("cont_3"), strcmp);
	t_dlist *con_2 = ft_dlstnew("cont_2");
	ft_dlstadd_sort(&dlst, con_2, strcmp);
	ft_dlstadd_sort(&dlst, ft_dlstnew("cont_4"), strcmp);
	ft_dlstadd_sort(&dlst, ft_dlstnew("cont_6"), strcmp);
	ft_dlstiter_all_left(dlst, (void (*)(void *))printf);
	return (0);
}
