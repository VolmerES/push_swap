/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:25:02 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/22 17:32:28 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	result;

	i = 0;
	if (str == NULL && len == 0)
		return (NULL);
	if (substr[0] == '\0')
		return ((char *)str);
	while ((str[i] != '\0') && (i + ft_strlen(substr) <= len))
	{
		result = ft_strncmp(&str[i], substr, ft_strlen(substr));
		if (result == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
