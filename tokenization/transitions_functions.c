/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:37:53 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/07 19:51:12 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	there_is_quote_par(char *line)
{
	char	quote_char;

	quote_char = *line;
	line++;
	while (*line && *line != quote_char)
		line++;
	if (*line == quote_char)
		return (1);
	return (0);
}

int	get_word_last_index(char *line)
{
	int	i;
	int	start_quote;

	i = 0;
	start_quote = 0;
	while (*line && !ft_is_limiter(*line))
	{
		if (!start_quote && ft_is_quote(*line))
		{
			start_quote = 1;
			if (!there_is_quote_par(line))
				return (-1);
		}
		line++;
		i++;
	}
	return i;
}

void	rx_word(char *line, t_token_node **token_list)
{
	t_token_node	new_token;
	int i;

	i = get_word_last_index(line); 

	new_token = ft_new_token()
}
