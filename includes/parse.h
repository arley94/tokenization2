/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:07:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/13 21:24:05 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_io_array_type
{
	IN_ARRAY,
	OUT_ARRAY
}	t_io_array_type;

typedef struct s_io
{
	char	*fd;
	
}	t_io;

typedef struct s_io_array
{
	t_io_array_type		type;
	int					len;
	char				**array;
}	t_io_array;

typedef struct s_command
{
	char				*args;

	t_io_type			io_type;
	struct s_token_node	*next;
}	t_token_node;