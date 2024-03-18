/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:18:54 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/18 08:26:31 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_commands_array	*get_commands(char *line)
{
	t_token_node		*token_list;
	t_commands_array	*commands;
	int					error;

	token_list = tokenize(line);
	if (!token_list)
		return (NULL);
	error = format_tokens(&token_list);
	if (error)
		return (ft_clear_token_lst(&token_list), NULL);
	error = get_expanded_tokens(token_list);
	if (error)
		return (ft_clear_token_lst(&token_list), NULL);
	commands = parse_commands_array(token_list);
	ft_clear_token_lst(&token_list);
	if (!commands)
		return (NULL);
	error = split_comds_args(commands);
	if (error)
		return (free_commands_array(commands), NULL);
	return (commands);
}
