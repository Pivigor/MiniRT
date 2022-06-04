/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:39 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:40 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_parser.h"

void	my_free_split(char **split)
{
	int	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int	my_split_size(char **split)
{
	int	size;

	size = 0;
	if (split == NULL)
		return (0);
	while (split[size] != NULL)
		size++;
	return (size);
}

void	my_parse_line2(char **line_split, t_parse	*parse)
{
	if (line_split[0] == NULL)
		return ;
	if (ft_strlen(line_split[0]) == 1)
	{
		if (line_split[0][0] == 'A')
			my_parse_ambient(line_split, parse);
		else if (line_split[0][0] == 'C')
			my_parse_camera(line_split, parse);
		else if (line_split[0][0] == 'L')
			my_parse_light(line_split, parse);
	}
	else if (ft_strlen(line_split[0]) == 2)
	{
		if (line_split[0][0] == 's' && line_split[0][1] == 'p')
			my_parse_sphere(line_split, parse);
		else if (line_split[0][0] == 'p' && line_split[0][1] == 'l')
			my_parse_plane(line_split, parse);
		else if (line_split[0][0] == 'c' && line_split[0][1] == 'y')
			my_parse_cylinder(line_split, parse);
	}
}

t_parse	*my_parse_line(char **line_split)
{
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	parse->type = None;
	if (line_split != NULL)
	{
		my_parse_line2(line_split, parse);
		my_free_split(line_split);
	}
	return (parse);
}

t_list	*my_minirt_parse(char *filename)
{
	char	*str;
	t_list	*list;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = NULL;
	list = NULL;
	while (get_next_line(fd, &str))
	{
		ft_lstadd_back(&list, ft_lstnew(my_parse_line(ft_split(str, '\t'))));
		free(str);
	}
	if (str != NULL)
		ft_lstadd_back(&list, ft_lstnew(my_parse_line(ft_split(str, '\t'))));
	free(str);
	close(fd);
	return (list);
}
