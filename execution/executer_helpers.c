/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:15:22 by alamaoui          #+#    #+#             */
/*   Updated: 2024/07/22 23:29:20 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_lstsize(t_env *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

char	**env_to_array(t_env *envp)
{
	char	**env;
	int		i;

	i = 0;
	env = safe_malloc(sizeof(char *) * (ft_lstsize(envp) + 1));
	if (!env)
	{
		bye_bye1("Malloc didn't work\n");
		return (NULL);
	}
	while (envp)
	{
		if (envp->env_line)
			env[i++] = envp->env_line;
		envp = envp->next;
	}
	env[i] = NULL;
	return (env);
}

char	*get_paths(t_env *envp)
{
	char	*curr_env;

	if (!envp)
	{
		bye_bye1("PATH environment is not found\n");
		return (NULL);
	}
	while (envp)
	{
		curr_env = envp->env_line;
		if (ft_strncmp(envp->env_line, "PATH=", 5) == 0)
			return (curr_env);
		envp = envp->next;
	}
	return (NULL);
}

void	save_stdin_stdout(int *std_in, int *std_out)
{
	*std_in = dup(0);
	*std_out = dup(1);
}

void	restore_stdin_stdout(int std_in, int std_out)
{
	dup2(std_in, 0);
	dup2(std_out, 1);
	close(std_in);
	close(std_out);
}
