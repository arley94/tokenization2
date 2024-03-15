/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:00:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/15 08:05:40 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_array_command_len(t_token_node *token_list)
{
	int	len;

	len = 1;
	while (token_list)
	{
		if (token_list->type == T_PIPE)
			len++;
		token_list = token_list->next;
	}
	return (len);
}

t_command	*create_blank_command(void)
{
	t_command	*new_command;

	new_command = malloc(sizeof(t_command));
	if (!new_command)
		return (NULL);
	new_command->args = NULL;
	new_command->infiles = NULL;
	new_command->outfiles = NULL;
	return (new_command);
}

int	add_arg(char **old_arg, char *to_add)
{
	char	*new_arg;

	if (!*old_arg)
	{
		new_arg = ft_strdup(to_add);
		if (!new_arg)
			return (1);
		*old_arg = new_arg;
		return (0);
	}
	new_arg = ft_strjoin_char(*old_arg, to_add, ' ');
	if (!new_arg)
		return (1);
	free(*old_arg);
	*old_arg = new_arg;
	return (0);
}

int	ft_is_infile(t_io_type type)
{
	if (type == IO_IN || type == IO_HEREDOC)
		return (1);
	return (0);
}

int	ft_is_outfile(t_io_type type)
{
	if (type == IO_OUT || type == IO_APPEND)
		return (1);
	return (0);
}

int	add_io(t_token_node *token, t_io_node **io_in, t_io_node **io_out)
{
	t_io_node	*new_io;

	new_io = ft_new_io(token->content, token->io_type);
	if (!new_io)
		return (1);
	token->content = NULL;
	if (ft_is_infile(token->io_type))
		ft_add_io(io_in, new_io);
	else if (ft_is_outfile(token->io_type))
		ft_add_io(io_out, new_io);
	return (0);
}

t_command	*parse_command(t_token_node **curr_tok)
{
	t_command	*comm;
	int			error;

	comm = create_blank_command();
	if (!comm)
		return (NULL);
	error = 0;
	while (*curr_tok && (*curr_tok)->type != T_PIPE)
	{
		if (error)
			return (free_command(comm), NULL);
		if ((*curr_tok)->io_type == IO_NONE)
			error = add_arg(&comm->args, (*curr_tok)->content);
		else
			error = add_io(*curr_tok, &comm->infiles, &comm->outfiles);
		*curr_tok = (*curr_tok)->next;
	}
	return (comm);
}

int	parse_commands_array(t_token_node	*token_list, t_commands_array *com)
{
	t_command	*new_command;
	int			i;

	i = 0;
	com->len = get_array_command_len(token_list);
	com->comm_array = malloc(sizeof(t_command *) * com->len);
	if (!com->comm_array)
		return (1);
	while (i < com->len && token_list)
	{
		if (token_list->type != T_WORD)
			return (free_commands_array(com), 1);//parse error
		new_command = parse_command(&token_list);
		if (!new_command)
			return (free_commands_array(com), 1);
		com->comm_array[i] = new_command;
		i++;
		if (token_list)
			token_list = token_list->next;
	}
	if (i != com->len)
		return (free_commands_array(com), 1); //parse error: more commands were expected
	return (0);
}
