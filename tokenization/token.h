/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:59 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/07 17:37:47 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_token_node
{
	char				*content;
	t_token_type		type;
	struct s_token_node	*next;
}	t_token_node;

typedef enum e_state
{
	EMPTY_TOKEN,
	RX_WORD,
	RX_OP,
	RX_SQ,
	RX_DQ
}	t_state;

typedef enum e_token_type
{
	T_WORD,
	T_LESS_THAN,
	T_MORE_THAN,
	T_D_LESS_THAN,
	T_D_GREAT_THAN,
	T_PIPE
}	t_token_type;

typedef enum e_char_type
{
	OPERATOR,
	NO_OPERATOR,
	QUOTE,
	SPACE
}	t_char_type;

t_char_type		get_type_of_character(char c);
int				ft_is_limiter(char c);
int				ft_is_quote(char c);
t_token_node	*ft_new_token(char *content, t_token_type type);
void			ft_clear_token_lst(t_token_node **lst);
t_token_node	*ft_get_last_node(t_token_node *lst);
void			ft_add_token(t_token_node **lst, t_token_node *new);
