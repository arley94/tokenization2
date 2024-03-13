/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:13:15 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/03/13 19:27:09 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*add_char_and_free(char *old_str, char c)
{
	char	*new_str;
	char	*char_to_str;

	char_to_str = malloc(sizeof(char) * 2);
	if (!char_to_str)
		return (free(old_str), NULL);
	char_to_str[0] = c;
	char_to_str[1] = '\0';
	new_str = ft_strjoin(old_str, char_to_str);
	if (!new_str)
	{
		free(old_str);
		free(char_to_str);
		return (NULL);
	}
	free(char_to_str);
	free(old_str);
	return (new_str);
}

char	*get_var_name(char **str)
{
	int		i;
	char	*var_name;

	if (*str[0] == '$')
		(*str)++;
	i = 0;
	while ((*str)[i] && !ft_is_quote((*str)[i]) && !ft_is_space((*str)[i])
			&& (*str)[i] != '$')
		i++;
	var_name = ft_substr(*str, 0, i);
	if (!var_name)
		return (NULL);
	*str = *str + i;
	return (var_name);
}

char	*add_var_and_free(char *old_str, char *var_name)
{
	char	*new_str;
	char	*var;

	var = getenv(var_name);
	if (!var)
		return (old_str);
	new_str = ft_strjoin(old_str, var);
	if (!new_str)
		return (free(old_str), NULL);
	free(old_str);
	return (new_str);
}

char	*expand_env_vars(char *word)
{
	char	*new_word;
	int		start_quote;
	char	*var_name;

	new_word = ft_get_empty_str();
	start_quote = 0;
	while (new_word && *word)
	{
		if (*word == '\'' && !start_quote)
			start_quote = 1;
		else if (*word == '\'' && start_quote)
			start_quote = 0;
		if (*word == '$' && !start_quote && *(word + 1))
		{
			var_name = get_var_name(&word);
			if (!var_name)
				return (free(new_word), NULL);
			new_word = add_var_and_free(new_word, var_name);
			free(var_name);
		}
		else
			new_word = add_char_and_free(new_word, *word++);
	}
	return (new_word);
}

char	*take_out_quotes(char *str)
{
	char	quote_char;
	int		start_quote;
	char	*new_str;

	start_quote = 0;
	new_str = ft_get_empty_str();
	while (new_str && *str)
	{
		if (ft_is_quote(*str) && !start_quote)
		{
			start_quote = 1;
			quote_char = *str;
		}
		else if (ft_is_quote(*str) && start_quote && *str == quote_char)
			start_quote = 0;
		else
			new_str = add_char_and_free(new_str, *str);
		str++;
	}
	return (new_str);
}

/* int main(int argc, char const *argv[], char const *env[])
{
	int i = 0;
	char *str;
	char *str2;

	while(argv[i])
	{
		str = expand_env_vars(argv[i]);
		str2 = take_out_quotes(str);
		printf("%s\n", argv[i]);
		printf("%s\n", str);
		printf("%s\n", str2);
		free(str);
		free(str2);
		i++;
	}
	return 0;
} */
