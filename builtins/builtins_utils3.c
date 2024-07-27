/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:49:29 by younajja          #+#    #+#             */
/*   Updated: 2024/07/25 05:27:56 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_exit_helper1(void)
{
	free_garbage(&g_global.garbage_list);
	printf("exit\n");
	exit(g_global.status);
}

void	ft_exit_helper2(void)
{
	bye_bye1("minishell: exit: : numeric argument require\n");
	g_global.status = 2;
	free_garbage(&g_global.garbage_list);
	exit(2);
}

void	ft_exit_helper3(int nb)
{
	g_global.status = nb;
	free_garbage(&g_global.garbage_list);
	printf("exit\n");
	exit(nb);
}

void	ft_exit_helper4(int nb)
{
	g_global.status = nb % 256;
	free_garbage(&g_global.garbage_list);
	printf("exit\n");
	exit(nb % 256);
}
