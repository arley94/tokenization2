/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:06:40 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/14 16:38:59 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

int	main(void)
{
	t_token_node		*token_list;
	t_commands_array	commands;

	token_list = tokenize("echo 'hola mundo' > file1 | ls -la");
	int error = format_tokens(&token_list);

	parse_commands_array(token_list, &commands);
	printf("%d\n", error);

	ft_clear_token_lst(&token_list);
	return (0);
}
