/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:09:17 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 17:29:02 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	win_create(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->str = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_l),
	&(mlx->endian));
}

void	fail(int i)
{
	if (i == 1)
	{
		write(1, "incorrect file\n", 15);
		exit(0);
	}
	else if (i == 2)
	{
		write(1, "usage: ./rtv1 <file>\n", 21);
		exit(0);
	}
	else if (i == 3)
	{
		write(1, "fail to malloc obj tab\n", 23);
		exit(0);
	}
	else if (i == 4)
	{
		write(1, "ERROR: problem occurs during data procurement\n", 46);
		exit(0);
	}
}

void	closest_point(t_tools tools, t_base base, t_mlx mlx, t_object object)
{
	if (tools.p < tools.s1 && tools.p < tools.s2 && tools.p <= 5000
	&& tools.p < tools.c && tools.p < tools.cy)
		draw_plane(base, object, mlx, tools);
	if (tools.s1 < tools.p && tools.s1 < tools.s2
	&& tools.s1 < tools.c && tools.s1 < tools.cy)
		draw_sphere(base, object, mlx, tools);
	if (tools.s2 < tools.s1 && tools.s2 < tools.p
	&& tools.s2 < tools.c && tools.s2 < tools.cy)
		draw_sphere(base, object, mlx, tools);
	if (tools.c < tools.s1 && tools.c < tools.p
	&& tools.c < tools.s2 && tools.c < tools.cy)
		draw_cone(base, object, mlx, tools);
	if (tools.cy < tools.s1 && tools.cy < tools.p
	&& tools.cy < tools.c && tools.cy < tools.s2)
		draw_cyl(base, object, mlx, tools);
}

void	init_struct(t_base *base, t_tools *tools, t_object *object, t_mlx mlx)
{
	tools->p = 200000;
	tools->s1 = 200000;
	tools->s2 = 200000;
	tools->c = 200000;
	tools->cy = 200000;
	base->ray.dir.x = tools->x - base->ray.origin.x;
	base->ray.dir.y = tools->y - base->ray.origin.y;
	base->ray.dir.z = 0 - base->ray.origin.z;
	base->ray.dir = normalize(base->ray.dir);
	tools->p = plane_intersect(object->plane, base->ray, tools->p);
	tools->s1 = sphere_intersect(object->sphere, base->ray, tools->s1);
	tools->s2 = sphere_intersect(object->sphere2, base->ray, tools->s2);
	tools->c = cone_intersect(object->cone, base->ray, tools->c);
	tools->cy = cylinder_intersect(object->cyl, base->ray, tools->cy);
	closest_point(*tools, *base, mlx, *object);
}

int		main(int ac, char **av)
{
	t_all		data;
	t_prim		*prim;
	int			nb_obj;

	if (ac != 2)
		fail(2);
	nb_obj = lexer(av[1], 0);
	prim = create_tab(nb_obj);
	prim = parser(av[1], nb_obj, prim);
	win_create(&data.mlx);
	geo_init(&data.object, &data.base, &data.tools, prim);
	while (++data.tools.y < HEIGHT)
	{
		data.tools.x = -1;
		while (++data.tools.x < WIDTH)
			init_struct(&data.base, &data.tools, &data.object, data.mlx);
	}
	mlx_hook(data.mlx.win, KEYPRESS, KEYPRESSMASK, key, 0);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.mlx.img, 0, 0);
	mlx_loop(data.mlx.ptr);
}
