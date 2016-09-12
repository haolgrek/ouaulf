/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:37:31 by tandrieu          #+#    #+#             */
/*   Updated: 2016/03/03 16:11:40 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./wolf3d.h"

void		music(int keycode)
{
	system("killall afplay");
	if (keycode == 83)
		system("afplay music/EminemSurvival.mp3&");
	if (keycode == 84)
		system("afplay music/Haendel-Sarabande.mp3&");
	if (keycode == 85)
		system("afplay music/ImagineDragons-BleedingOut.mp3&");
	if (keycode == 86)
		system("afplay music/KORPIKLAANI-Vodka.mp3&");
	if (keycode == 87)
		system("afplay music/MDK-PressStart.mp3&");
	if (keycode == 88)
		system("afplay music/TSFH_victory.mp3&");
	if (keycode == 89)
		system("afplay music/Whitewoods-BeachWalk.mp3&");
	if (keycode == 91)
		system("afplay music/a-ha-TakeOnMe.mp3&");
	if (keycode == 92)
		system("afplay music/Dr.Dre-TheNextEpisode.mp3&");
}
