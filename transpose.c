/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 16:59:55 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/06/16 12:00:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transpose.h"

void	transpose(int argc, char **argv)
{
	char	*keys[] = {	"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
						"A", "A#", "B",
						"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
						"A", "A#", "B",
						"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
						"A", "A#", "B"};
	char	*orig_key;
	char	*dest_key;
	int		diff_key;
	int		direction;
	int		minor;
	int		i;
	int		j;

	orig_key = argv[1];
	dest_key = argv[2];
	diff_key = find_diff_key(orig_key, dest_key);
	direction = 0;
	minor = 0;
	i = 12;
	j = 3;
	if (diff_key)
		direction = (diff_key < 0) ? HIGHER : LOWER;
	diff_key = (diff_key < 0) ? -(diff_key) : diff_key;
	printf("From key of %s to key of %s\n\n", orig_key, dest_key);
	while (j < argc)
	{
		char *chord = argv[j];
		if (chord[strlen(chord) - 1] == 'm')
		{
			chord = remove_minor(chord);
			minor++;
		}
		while (strcmp(keys[i], chord))
			i++;
		if (minor == 1)
		{
			printf("%sm -> ", chord);
			printf("%sm\n", keys[i + (diff_key * direction)]);
		}
		else
		{
			printf("%s -> ", chord);
			printf("%s\n", keys[i + (diff_key * direction)]);
		}
		minor = 0;
		i = 12;
		j++;
	}
}

int		find_diff_key(char *orig_key, char *dest_key)
{
	char *keys[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
					"A", "A#", "B"};
	int	diff_key;
	int	index_orig_key;
	int	index_dest_key;

	diff_key = 0;
	index_orig_key = 0;
	index_dest_key = 0;
	while (strcmp(orig_key, keys[index_orig_key]))
		index_orig_key++;
	while (strcmp(dest_key, keys[index_dest_key]))
		index_dest_key++;
	diff_key = index_orig_key - index_dest_key;
	return (diff_key);
}

char	*remove_minor(char *chord)
{
	int		i;
	char	*new_chord;

	i = 0;
	new_chord = (char *)malloc(sizeof(char) * strlen(chord));
	while (chord[i] && chord[i] != 'm')
	{
		new_chord[i] = chord[i];
		i++;
	}
	new_chord[i] = '\0';
	return (new_chord);
}
