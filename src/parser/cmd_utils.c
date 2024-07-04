#include "../includes/minishell.h"

int	get_cmd_len(t_token *tok)
{
	t_token	*aux;
	int		len;

	aux = tok;
	len = 0;
	while (aux && aux->type != T_PIPE)
	{
		if (aux->type == T_G || aux->type == T_DG
			|| aux->type == T_L || aux->type == T_DL)
			aux = aux->next;
		else
			len++;
		aux = aux->next;
	}
	return (len);
}
