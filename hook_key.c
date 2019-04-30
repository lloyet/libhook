/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook_key.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 02:53:12 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 04:25:02 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libhook.h"

void			register_new_key(t_keyboard *keyboard, int key)
{
	if (keyboard->reg_size < REG_KMASK_MAX)
		keyboard->reg_id[key] = ++keyboard->reg_size;
	return ;
}

uint8_t			key_is_pressed(t_keyboard *keyboard, int key)
{
	return (keyboard->reg_key & (1 << keyboard->reg_id[key]) ? 1 : 0);
}

int				key_press_hook(int key, t_keyboard *keyboard)
{
	keyboard->reg_key |= 1 << keyboard->reg_id[key];
	return (0);
}

int				key_release_hook(int key, t_keyboard *keyboard)
{
	keyboard->reg_key &= keyboard->reg_key ^ (1 << keyboard->reg_id[key]);
	return (0);
}
