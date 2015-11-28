/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 16:52:39 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/08/08 20:00:46 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "transpose.h"

int main(int argc, char **argv)
{
	if (argc >= 4)
	{
		transpose(argc, argv);
	}
	else
	{
		printf("Incorrect argument.\n");
	}
}
