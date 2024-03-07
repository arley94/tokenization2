/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:57:20 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/07 19:51:18 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	go_next_state(t_token_node	**token_list, t_token_type *current_state,
						char c, int *index)
{
	t_char_type	char_type;

	char_type = get_type_of_character(c);
	if (*current_state == EMPTY_TOKEN && char_type == OPERATOR)
		empty_to_rx_word()
}

void	tokenize(char *line)
{
	t_token_node	*token_list;
	int				i;
	t_state			current_state;
	t_state			next_state;

	i = 0;
	current_state = EMPTY_TOKEN;
	token_list = NULL;
	while (line[i])
	{
		go_next_state(&token_list, &current_state, line[i], &i);
		i++;
	}
	
}