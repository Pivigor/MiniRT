/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_global_libs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:27:54 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 16:27:56 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_GLOBAL_LIBS_H
# define MY_GLOBAL_LIBS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
char			**ft_split(char const *s, char c);

__SIZE_TYPE__	ft_strlen(const char *s);
int				ft_strncmp(char *s1, char *s2, __SIZE_TYPE__ n);

int				get_next_line(int fd, char **line);

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
#endif //MINIRT_PARSER_MY_GLOBAL_LIBS_H
