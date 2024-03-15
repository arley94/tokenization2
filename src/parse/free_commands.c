/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:20:08 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/15 12:54:39 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_command(t_command *com)
{
	if (com->args)
		free(com->args);
	if (com->name)
		free(com->name);
	if (com->args_splitted)
		ft_free_str_array(com->args_splitted);
	if (com->infiles)
		ft_clear_io_lst(&com->infiles);
	if (com->outfiles)
		ft_clear_io_lst(&com->outfiles);
	free(com);
}

void	free_commands_array(t_commands_array *commands)
{
	int	i;

	i = 0;
	while (i < commands->len)
	{
		free_command(commands->comm_array[i]);
		i++;
	}
	free(commands->comm_array);
	free(commands);
}
