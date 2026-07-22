/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:28:07 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:46:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*extract_texture_path(char *line)
{
	char	**tab;
	char	*tmp;

	tmp = clean_str(line, 0);
	if (!tmp)
		return (err_parser(2), NULL);
	tab = ft_split(tmp, SPACE);
	if (!tab)
		return (err_parser(2), free(tmp), NULL);
	free(tmp);
	if (array_size(tab) != 2)
	{
		free_char_array(&tab);
		return (err_parser(4), NULL);
	}
	if (check_filename(tab[1], ".xpm"))
		return (free_char_array(&tab), NULL);
	tmp = ft_strdup(tab[1]);
	free_char_array(&tab);
	if (!tmp)
		return (err_parser(2), NULL);
	return (tmp);
}

static char	**extract_color(char *line)
{
	char	**tab;
	char	*tmp;
	int		i;

	tmp = clean_str(line, 0);
	if (!tmp)
		return (err_parser(2), NULL);
	i = 1;
	while (tmp[i] && tmp[i] == SPACE)
		i++;
	if (tmp[i] == '\0' || !ft_isdigit(tmp[i]))
		return (free(tmp), err_parser(4), NULL);
	if (!is_rgb(tmp + i))
		return (free(tmp), err_parser(5), NULL);
	tab = ft_split(tmp + i, ',');
	free(tmp);
	if (!tab)
		return (err_parser(2), NULL);
	return (tab);
}

static int	get_texture(t_game *game, char *line, int ret)
{
	char	*tmp;
	void	*img;
	int		width;
	int		height;

	tmp = extract_texture_path(line);
	if (!tmp)
		return (-1);
	width = TEXWIDTH;
	height = TEXHEIGHT;
	img = mlx_xpm_file_to_image(game->mlx, tmp, &width, &height);
	free(tmp);
	if (!img)
		return (-1);
	if (ret == 1 && !game->tex.no_texture.img)
		game->tex.no_texture.img = img;
	else if (ret == 2 && !game->tex.so_texture.img)
		game->tex.so_texture.img = img;
	else if (ret == 3 && !game->tex.we_texture.img)
		game->tex.we_texture.img = img;
	else if (ret == 4 && !game->tex.ea_texture.img)
		game->tex.ea_texture.img = img;
	else
		return (err_parser(9), mlx_destroy_image(game->mlx, img), -1);
	return (0);
}

static int	get_color(t_texture *tex, char *line, int ret)
{
	char	**tmp;

	tmp = extract_color(line);
	if (!tmp)
		return (-1);
	if (ret == 5 && tex->floor == -1)
		tex->floor = get_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else if (ret == 6 && tex->ceiling == -1)
		tex->ceiling = get_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
				ft_atoi(tmp[2]));
	else
		return (err_parser(9), free_char_array(&tmp), -1);
	free_char_array(&tmp);
	return (0);
}

int	load_elements(t_game *game, int fd)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && !is_space(line))
		{
			ret = is_element(line);
			if (ret > 0 && ret < 5 && !is_element_complete(&game->tex))
				ret = get_texture(game, line, ret);
			else if ((ret == 5 || ret == 6) && !is_element_complete(&game->tex))
				ret = get_color(&game->tex, line, ret);
			else if (!is_map_element(game, line))
				return (err_parser(5), close(fd), free(line), get_next_line(-1),
					1);
			if (ret == -1)
				return (close(fd), free(line), get_next_line(-1), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
