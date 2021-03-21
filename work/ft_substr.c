/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:51:18 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 21:07:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string2;
	int			j;

	j = 0;
	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	string2 = (char*)malloc((len + 1) * sizeof(char));
	if (string2 == NULL)
	{
		return (ft_strdup(""));
	}
	while (s[j] && 0 < len)
	{
		string2[j] = (char)s[start];
		j++;
		start++;
		len--;
	}
	string2[j] = '\0';
	return (ft_strdup(string2));
}
