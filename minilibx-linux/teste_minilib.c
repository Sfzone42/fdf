/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_minilib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchissal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:09:52 by dchissal          #+#    #+#             */
/*   Updated: 2024/05/31 12:10:14 by dchissal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int handle_input(int key, void *param)
{
     // Handle the input based on the keycode.
     return (0);
}
int main(void)
{
     void *mlx;
     void *win;
 
     mlx = mlx_init();
     win = mlx_new_window(mlx, 800, 600, "My first window");
 
     mlx_key_hook(win, handle_input, NULL);
     //create also an clean_up hook
     //i.e. press ESC will call all the destroy functions 

    // Wait for events.
     mlx_loop(mlx);
     return (0);
}
