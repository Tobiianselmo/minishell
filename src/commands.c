
#include "../includes/minishell.h"

static void	set_fd(t_token **tok, t_cmd *new, t_msh *msh)
{
	while (*tok && (*tok)->type != T_PIPE)
	{
		if ((*tok)->type == T_G)
			set_outfile(tok, new, msh);
		else if ((*tok)->type == T_DG)
			set_append(tok, new, msh);
		else if ((*tok)->type == T_L)
			set_infile(tok, new, msh);
		else if ((*tok)->type == T_DL)
			set_heredoc(tok, new, msh);
		else if ((*tok)->type == T_WORD)
			*tok = (*tok)->next;
	}
}

static void	set_cmd(t_msh *msh, t_token **tokens)
{
	t_cmd	*new_cmd;
	t_token	*tok;
	int		len;

	tok = *tokens;
	len = get_cmd_len(*tokens);
	new_cmd = new_node_cmd();
	new_cmd->argv = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_cmd->argv)
		return ;
	if (len > 0)
	{
		if (cmd_content(new_cmd, *tokens) == 0)
		{
			error_msh("Malloc fail", msh, 2);
			new_cmd->error = 1;
		}
	}
	else
		new_cmd->argv[0] = NULL;
	set_fd(tokens, new_cmd, msh);
	msh->cmd_len += 1;
	create_cmd_lst(&msh->cmd, new_cmd);
}

void	get_cmd(t_msh *msh)
{
	t_token *tmp;

	tmp = msh->tokens;
	while (tmp)
	{
		if (tmp->type != T_PIPE)
			set_cmd(msh, &tmp);
		else
			tmp = tmp->next;
	}
}
