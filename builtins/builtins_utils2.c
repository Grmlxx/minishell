/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:31:00 by younajja          #+#    #+#             */
/*   Updated: 2024/07/22 21:39:32 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_exit_b(t_tree *tree)
{
	int	nb;

	if (!tree->next)
		ft_exit_helper1();
	tree = tree->next;
	if (tree->type != TOKEN_WORD)
		return ;
	if (tree->next)
		return (bye_bye1("minishell: exit: too many arguments\n"));
	if (!check_digit(tree->value))
		ft_exit_helper2();
	nb = ft_atoi(tree->value);
	if (nb >= 0 && nb <= 255)
		ft_exit_helper3(nb);
	else if (nb > 255)
		ft_exit_helper4(nb);
	else
	{
		g_global.status = (256 + nb) % 256;
		free_garbage(&g_global.garbage_list);
		printf("exit\n");
		exit((256 + nb) % 256);
	}
}

void	ft_cd(t_tree *tree, t_env *env)
{
	if (!tree->next || !ft_strcmp(tree->next->value, "~"))
	{
		chdir(getenv("HOME"));
		ft_change_old_path(env);
		return ;
	}
	tree = tree->next;
	if (tree->next)
	{
		g_global.status = 1;
		return (bye_bye1("minishell: cd: too many arguments\n"));
	}
	if (chdir(tree->value))
	{
		g_global.status = 1;
		printf("minishell: cd: %s: No such file or directory\n", tree->value);
	}
	else
		ft_change_old_path(env);
}
