/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:06:40 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/18 08:06:29 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

int g_fail_after = 0;
int g_num_allocs = 0;

int	main(int argc, char *argv[])
{
	t_token_node		*token_list;
	t_commands_array	*commands;
	int					error;
	int					i;
	int					fail_after_limit;

	if (argc != 2)
		exit(EXIT_FAILURE);
	fail_after_limit = atoi(argv[1]);
	i = 0;
	while (i++ < fail_after_limit)
	{
		g_fail_after = i;
		g_num_allocs = 0;
		token_list = tokenize("echo $var'hola mundo' > file1 | ls -la");
		if (!token_list)
			continue ;
		error = format_tokens(&token_list);
		if (error)
		{
			ft_clear_token_lst(&token_list);
			continue ;
		}
		error = get_expanded_tokens(token_list);
		if (error)
		{
			ft_clear_token_lst(&token_list);
			continue ;
		}
		commands = parse_commands_array(token_list);
		ft_clear_token_lst(&token_list);
		if (!commands)
			continue ;
		error = split_comds_args(commands);
		free_commands_array(commands);
		if (error == 0)
			printf("success without failure\n");
	}
	printf("final\n");
	return (0);
}
