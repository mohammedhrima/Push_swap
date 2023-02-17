/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:44 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/15 20:52:15 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_num
{
	int		value;
	int		index;
}			t_num;

typedef struct s_stack
{
	t_num	*array_of_nums;
	int		lenght;
}			t_stack;

#endif