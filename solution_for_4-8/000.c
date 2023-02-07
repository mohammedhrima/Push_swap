/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:25:52 by mhrima            #+#    #+#             */
/*   Updated: 2023/02/03 20:58:22 by mhrima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define AND &&
#define DO ?
#define BUT :
#define OTHERWISE
#define JUST :
#define IF
#define OR |
#define NOT !
#define IS ==
#define print printf
// #define greater >
// #define less <
// #define than

int	main(void)
{
	int	x;

	x = 4;
	
	// IF x IS 1 OR x IS 2 DO printf("x is one or two\n") BUT IF x IS 3 DO printf("is three\n") OTHERWISE JUST printf("none of them\n");
	// x == 1 | x == 2 ? printf("message 1") : x == 3 ? printf("message 2") : printf("message 3");
	IF x IS 1 OR x IS 2 DO printf("msg 1") BUT IF x IS 3 DO print("msg 2") OTHERWISE JUST printf("msg 3");
	
	return (0);
}
