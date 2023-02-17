/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:00:45 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:20:35 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../push_swap.h"

int		*array_of_integers(int len);
int		*convert_to_integers(int len, char **array);
void	check_input(int there_is_numbers, char *arg);
char	**read_arguments(int argc, char **argv);

#endif
