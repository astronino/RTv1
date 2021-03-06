/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:45:27 by yoelguer          #+#    #+#             */
/*   Updated: 2021/02/09 18:45:36 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		ft_alloc_obj(t_obj **obj)
{
	(*obj) = (t_obj*)malloc(sizeof(t_obj));
	init_vect(&(*obj)->position, 0, 0, 0);
	init_vect(&(*obj)->translation, 0, 0, 0);
	init_vect(&(*obj)->rotation, 0, 0, 0);
	init_vect(&(*obj)->color, 0, 0, 0);
	init_vect(&(*obj)->axis, 0, 0, 0);
	init_vect(&(*obj)->hit, 0, 0, 0);
	init_vect(&(*obj)->norm, 0, 0, 0);
	init_vect(&(*obj)->direction, 0, 0, 0);
	(*obj)->radius = 0;
	(*obj)->t = 0;
	(*obj)->next = NULL;
}

void		ft_alloc_light(t_data_light **light)
{
	(*light) = (t_data_light*)malloc(sizeof(t_data_light));
	init_vect(&(*light)->position, 0, 0, 0);
	init_vect(&(*light)->color, 0, 0, 0);
	(*light)->intensity = 0;
	(*light)->next = NULL;
}

void		ft_alloc_camera(t_data_camera **camera)
{
	(*camera) = (t_data_camera*)malloc(sizeof(t_data_camera));
	init_vect(&(*camera)->pos, 0, 0, 0);
	init_vect(&(*camera)->dir, 0, 0, 0);
	init_vect(&(*camera)->u_dir, 0, 0, 0);
	init_vect(&(*camera)->v_dir, 0, 0, 0);
	(*camera)->dist = 0;
}

void		ft_lstdel(t_obj **alst)
{
	t_obj	*temp;

	if (!alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
	return ;
}

void		ft_free_obj(t_all *data)
{
	free(data->camera);
	ft_lstdel(&data->obj);
}
