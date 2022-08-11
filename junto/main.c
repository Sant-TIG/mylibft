/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:12:04 by sperez-p          #+#    #+#             */
/*   Updated: 2022/08/01 11:31:36 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

typedef struct s_map
{
	char	*tmp_map;
	char	**char_map;
	int		rows;
	int		columns;
	int		**int_map;
	int		min;
	int		max;
}	t_map;

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

typedef struct s_mlx
{
	int		zoom;
	int		**z_matrix;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_holder
{
	t_map	map_utils;
	t_mlx	mlx;
	t_str	*linked_map;
}	t_holder;

void	ft_print_2d_str(char **str)
{
	printf("CADENA 2D\n");
	ssize_t	i;

	i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

void	ft_print_str(char *str)
{
	printf("CADENA\n");
	while (*str)
		printf("%c", *str++);
	printf("\n");
}

void	ft_print_list(t_str *str)
{
	printf("LISTAS\n");
	while (str)
	{
		printf("%c", str->c);
		str = str->next;
	}
	printf("\n");
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
Comprueba si los ultimos n caracteres de una cadena son iguales a otra cadena.
*/

int	ft_strrncmp(const char *str1, const char *str2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str1) - ft_strlen(str2);
	while (n--)
		if (str1[len++] == str2[i++])
			;
	if (str1[len - 1] != str2[i - 1])
		return (0);
	return (1);
}

/*
Comprueba que el mapa que se pasa como argumento tenga la extension .fdf y en ese caso intenta abrirlo.
*/

void	ft_open(char *arg, int mode, int *fd)
{
	if (ft_strrncmp(arg, ".fdf", 4) == 0)
	{
		printf("Wrong file extension\n");
		exit (1);
	}
	*fd = open(arg, mode);
	if (*fd == -1)
	{
		perror("");
		exit (1);
	}
}

void	ft_free_list(t_str *linked_map)
{
	t_str	*tmp;

	tmp = linked_map;
	while (tmp)
	{
		tmp = tmp->next;
		free(linked_map);
		linked_map = tmp;
	}
}

char	*ft_splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	**ft_process_string(char **dest, const char *str, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			if (str[i] == c || i == ft_strlen(str))
				dest[p1++] = ft_splitdup(str, start, i);
		}
		while (str[i] == c && str[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

size_t	ft_line_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		count++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**dest;

	if (!str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		return (NULL);
	ft_process_string(dest, str, c);
	return (dest);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	result;
	ssize_t	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	return (result * sign);
}

int	ft_get_columns(char *str)
{
	int	columns;

	columns = 0;
	while (*str != '\n')
	{
		while (ft_isdigit(*str))
		{
			str++;
			if (*str == ' ')
				columns++;
		}
		if (*str == '\n')
			break ;
		str++;
	}
	return (columns);
}

int	ft_get_rows(char  *str)
{
	int	rows;

	rows = 0;
	while (*str)
	{
		if (*str == '\n')
			rows++;
		str++;
	}
	return (rows);
}

void	ft_treat_empty_map(t_str **linked_map, char *tmp_map)
{
	if (!*linked_map)
	{
		ft_free_list(*linked_map);
		free(tmp_map);
		printf("Invalid map (Empty map)\n");
		exit (1);
	}
}

void	ft_insert_empty_char(char c, t_str **linked_map)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		exit (1);
	new->c = c;
	new->next = NULL;
	*linked_map = new;
}

void ft_insert_end_char(char c, t_str **linked_map)
{
	t_str	*tmp;
	t_str	*new;

	tmp = *linked_map;
	if (!*linked_map)
	{
		ft_insert_empty_char(c, linked_map);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		exit (1);
	new->c = c;
	new->next = NULL;
	tmp->next = new;
}

char	*ft_read_map(int fd, t_str **linked_map)
{
	t_str	*tmp;
	size_t	len;
	ssize_t	i;
	char	c;
	char	*tmp_map;

	len = 0;
	i = -1;
	while (read(fd, &c, 1) != 0 && ++len)
		ft_insert_end_char(c, linked_map);
	ft_print_list(*linked_map);
	tmp_map = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp_map)
		return (NULL);
	tmp = *linked_map;
	while(tmp)
	{
		*(tmp_map + ++i) = tmp->c;
		tmp = tmp->next;
	}
	*(tmp_map + ++i) = '\0';
	ft_treat_empty_map(linked_map, tmp_map);
	ft_free_list(*linked_map);
	return (tmp_map);
}

char	*ft_transform_string(char *str)//plantear sustuir todos los posibles espacios en blanco(isblank()) por espacios
{
	ssize_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
	}
	return (str);
}

size_t	ft_str2dlen(char **str)
{
	ssize_t	i;
	size_t	len;

	i = -1;
	len = 0;
	while (str[++i])
		len++;
	return (len);
}

void	ft_print_int(t_map *map_utils)
{
	printf("LISTA DE NUMEROS\n");
	int	i = -1;
	int	j;

	while (++i < map_utils->rows)
	{
		j = -1;
		while (++j < map_utils->columns)
			printf("%3d ", map_utils->int_map[i][j]);
		printf("\n");
	}
}

int	**ft_convert_int(t_map *map_utils)
{
	int	**int_map;
	int	i;
	int	j;
	int	k;;

	i = -1;
	k = -1;
	int_map = (int **)malloc(sizeof(int *) * map_utils->rows);
	if (!int_map)
		exit (1);
	while (++i < map_utils->rows)
	{
		int_map[i] = (int*)malloc(sizeof(int) * map_utils->columns);
		if (!int_map[i])
			exit (1);
		j = -1;
		while (++j < map_utils->columns)
			int_map[i][j] = ft_atoi(map_utils->char_map[++k]);
	}
	return (int_map);
}

int	ft_get_max(double nbr1, double nbr2) //
{
	int	mod_nbr1;
	int	mod_nbr2;

	mod_nbr1 = nbr1;
	mod_nbr2 = nbr2;
	if (nbr1 < 0)
		mod_nbr1 = -nbr1;
	if (nbr2 < 0)
		mod_nbr2 = -nbr2;
	if (mod_nbr1 > mod_nbr2)
		return (mod_nbr1);
	return (mod_nbr2);
}

void	ft_isometric(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	ft_bresenham(double x, double y, double x1, double y1, t_mlx *mlx, t_map *map_utils)
{
	double	x_step;
	double	y_step;
	int		max;
	int		z;
	int		z1;

	z = map_utils->int_map[(int)y][(int)x];
	z1 = map_utils->int_map[(int)y1][(int)x1];

	x *= mlx->zoom;
	y *= mlx->zoom;
	x1 *= mlx->zoom;
	y1 *= mlx->zoom;
	z *= mlx->zoom;
	z1 *= mlx->zoom;

	//mlx->color = (z || z1) ? 0xe80c0c : 0xffffff;

	ft_isometric(&x, &y, z);
	ft_isometric(&x1, &y1, z1);

	x += 250;
	y += 250;
	x1 += 250;
	y1 += 250;
	
	x_step = x1 - x;
	y_step = y1 - y;
	//printf("%f y %f\n", x_step, y_step);
	max = ft_get_max(x_step, y_step); //calcula cual de las diferencias es mayor
	//printf("max = %d\n", max);
	x_step /= max;
	y_step /= max;
	//printf("%f y %f\n", x_step, y_step);
	//size_t i = 2;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

double	*ft_get_win_size(int columns, int rows, int max_height, int min_height)
{
	double	*win_size;

	win_size = (double *)malloc(sizeof(double) * 2);
	if (!win_size)
		exit (1);
	win_size[0] = round ((columns + rows) * cos (0.523599) * cos (0.523599));
	win_size[1] = round (((columns + rows) * sin (0.523599) * cos (0.523599)) + (max_height - min_height));
	return (win_size);
}

double	ft_get_scale(double *size)
{
	double	x_scale;
	double	y_scale;

	x_scale = 900 / size[0];
	y_scale = 450 / size[1];
	if (x_scale >= size[0])
		return (x_scale);
	return (y_scale);
		
}

void	ft_set_origin(int *x, int *y, double *win_size, int max, int min)
{
	*x = (win_size[0] * 0.1) + (*y * 0.75);
	if (max == 0 && min == 0)
		*y = ((win_size[1] * 1.3) - win_size[1]) / 2;
	else if (max != 0 && min == 0)
		*y = (((win_size[1] * 1.3) - win_size[1]) / 2) + max;
	else if (max == 0 && min != 0)
		*y = (((win_size[1] * 1.3) - win_size[1]) / 2);
	else
		*y = (((win_size[1] * 1.3) - win_size[1]) / 2) + max;
}

void	ft_draw_vectors(t_mlx *mlx, t_map *map_utils)
{
	int		x;
	int		y;
	double	*win_size;
	double	scale;

	x = 0;
	win_size = ft_get_win_size(map_utils->columns, map_utils->rows, map_utils->max, map_utils->min);
	scale = ft_get_scale(win_size);
	ft_set_origin(x, y, win_size, map_utils->max, map_utils->min);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (win_size[0] * 1.3) * scale, (win_size[1] * 1.3) * scale, "fdf");
	//crear imagen
	while (x < map_utils->columns)
	{
		y = 0;
		while (y < map_utils->rows)
		{
			if (x < map_utils->columns - 1)
				ft_bresenham(x, y, x + 1, y, mlx, map_utils);
			if (y < map_utils->rows - 1)
				ft_bresenham(x, y, x, y + 1, mlx, map_utils);
			y++;
		}
		x++;
	}
}
/*
void	ft_check_columns(char *tmp_map, int columns, int rows)
{
	int		columns2;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	columns2 = 0;
	while (i < columns
	{
		columns2++;
	}
}*/

void	ft_check_map(t_holder *holder)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(holder->map_utils.tmp_map);
	printf("%zu\n", len);
	if (((int)len / holder->map_utils.columns) != holder->map_utils.rows)
	{
		printf("Error. Wrong columns\n");
		exit (1);
	}
	while (ft_isdigit(holder->map_utils.tmp_map[i]) || holder->map_utils.tmp_map[i] == 32)
		i++;
	if (holder->map_utils.tmp_map[i] != '\0')
	{
		printf("Error. Wrong columns\n");
		exit (1);	
	}
}

void	ft_get_max_min(t_holder *holder)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	holder->map_utils.max = 0;
	holder->map_utils.min = 0;
	while (holder->map_utils.int_map[++i])
	{
		j = -1;
		while (holder->map_utils.int_map[++j])
		{
			if (holder->map_utils.int_map[i][j] > holder->map_utils.max)
				holder->map_utils.max = holder->map_utils.int_map[i][j];
			if (holder->map_utils.int_map[i][j] < holder->map_utils.min)
				holder->map_utils.min = holder->map_utils.int_map[i][j];
		}
	}
}

void	ft_get_map(int fd, t_holder *holder)
{
	holder->linked_map = NULL;
	holder->map_utils.tmp_map = ft_read_map(fd, &holder->linked_map);
	ft_print_str(holder->map_utils.tmp_map);
	holder->map_utils.rows = ft_get_rows(holder->map_utils.tmp_map);
	printf("rows = %d\n", holder->map_utils.rows);
	//comprobar que cada linea tiene los mismos elementos
	holder->map_utils.columns = ft_get_columns(holder->map_utils.tmp_map);//almacenamos la cantidad de columnas que tiene el mapa
	printf("columns = %d\n", holder->map_utils.columns);
	holder->map_utils.tmp_map = ft_transform_string(holder->map_utils.tmp_map);//eliminamos los saltos de linea de la cadena anterior para poder almacenar cada numero en una lista de listas de numeros
	ft_print_str(holder->map_utils.tmp_map);
	//ft_check_map(holder);
	holder->map_utils.char_map = ft_split(holder->map_utils.tmp_map, ' ');//cada numero del mapa metido como una cadena en una lista de cadenas
	ft_print_2d_str(holder->map_utils.char_map);
	//comprobar que solo haya digitos
	holder->map_utils.int_map = ft_convert_int(&holder->map_utils);
	ft_get_max_min(holder);
	ft_print_int(&holder->map_utils);
}

int	main(int argc, char **argv)
{
	int	fd;
	//t_map	map_utils;
	t_mlx	*mlx;
	t_holder	holder;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit (1);
	if (argc == 2)
	{
		ft_open(argv[1], O_RDONLY, &fd);//
		ft_get_map(fd, &holder);

		//mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 1, 1, 0xffffff);
		//ft_bresenham(10, 10, 600, 300, mlx);
		//mlx_key_hook(mlx->win_ptr, deal_key, NULL);
		mlx->zoom = 50;
		ft_draw_vectors(mlx, &holder.map_utils);
		mlx_loop(mlx->mlx_ptr);
		return (0);
	}
	printf("Invalid arguments\n");
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc == 2)
	{
		ft_open(argv[1], O_RDONLY, &fd);
	}
}*/