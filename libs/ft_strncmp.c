/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:22:18 by jgarlic           #+#    #+#             */
/*   Updated: 2021/12/02 23:22:19 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, __SIZE_TYPE__ n)
{
	long long int	i;
	long long int	j;

	if (n == 0)
		return (0);
	i = 0;
	j = (long long)n - 1;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < j))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - s2[i]);
	return (0);
}
