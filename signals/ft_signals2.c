/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:51:07 by younajja          #+#    #+#             */
/*   Updated: 2024/07/25 06:20:01 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	signal_herdoc(int sig)
{
	(void)sig;
	printf("\n");
	g_global.status = 130;
	*return_value() = dup(0);
	close(0);
}

void	ctrl_c_handler2(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	check_signal_heredoc(void)
{
	dup2(*return_value(), 0);
	close(*return_value());
	signal(SIGINT, ctrl_c_handler2);
	*return_value() = -1;
}

void	signal_l7ma9(void)
{
	if (g_global.heredoc == 1)
		signal(SIGINT, ctrl_c_handler2);
	else
		signal(SIGINT, ctrl_c_handler);
}
