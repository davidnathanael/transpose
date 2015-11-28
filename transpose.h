/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:10:12 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/08/03 11:43:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSPOSE_H
# define TRANSPOSE_H

# define HIGHER 1
# define LOWER -1

void	transpose(int argc, char **argv);
int		find_diff_key(char *orig_key, char *dest_key);
char	*remove_minor(char *chord);

#endif
