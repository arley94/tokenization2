/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:54:18 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/18 08:34:04 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "token.h"

typedef enum e_io_array_type
{
	IN_ARRAY,
	OUT_ARRAY
}	t_io_array_type;

typedef struct s_io_node
{
	char				*io_arg;
	t_io_type			io_type;
	struct s_io_node	*next;
}	t_io_node;

typedef struct s_command
{
	char		*name_and_args;
	char		**args;
	char		**name_and_args_splt;
	char		*name;
	t_io_node	*infiles;
	t_io_node	*outfiles;
}	t_command;

typedef struct s_commands_array
{
	t_command	**comm_array;
	int			len;
}	t_commands_array;

t_io_node			*ft_new_io(char *io_arg, t_io_type type);
void				ft_clear_io_lst(t_io_node **lst);
void				ft_add_io(t_io_node **lst, t_io_node *new);
t_commands_array	*parse_commands_array(t_token_node *token_list);
void				free_command(t_command *com);
void				free_commands_array(t_commands_array *commands);
int					split_comds_args(t_commands_array *comds);
t_commands_array	*get_commands(char *line);
