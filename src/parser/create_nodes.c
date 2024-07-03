
#include "../includes/minishell.h"

void	add_back(t_token **lst, t_token *new)
{
	t_token	*new_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_node = *lst;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = new;
}

t_token	*new_node(char *content, int type, int flag)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = type;
	new->flag = flag;
	new->next = NULL;
	return (new);
}

void	create_tok_lst(t_token **tok, int type, char *content, int flag)
{
	t_token	*aux;

	if (!*tok)
		*tok = new_node(content, type, flag);
	else
	{
		aux = new_node(content, type, flag);
		add_back(tok, aux);
	}
	free(content);
}
