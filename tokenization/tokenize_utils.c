/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:05:25 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/07 17:36:40 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_char_type	get_type_of_character(char c)
{
	t_char_type	type;

	if (c == ' ')
		type = SPACE;
	else if (c == '\'' || c == '\"')
		type = QUOTE;
	else if (c == '<' || c == '>' || c == '|')
		type = OPERATOR;
	else
		type = NO_OPERATOR;
	return (type);
}

int	ft_is_limiter(char c)
{
	if (get_type_of_character(c) == OPERATOR
		|| get_type_of_character(c) == SPACE)
		return (1);
	return (0);
}

int	ft_is_quote(char c)
{
	if (get_type_of_character(c) == QUOTE)
		return (1);
	return (0);
}
