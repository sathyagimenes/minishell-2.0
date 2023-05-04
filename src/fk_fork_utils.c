/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_fork_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:08:06 by briferre          #+#    #+#             */
/*   Updated: 2023/05/03 22:35:49 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fk_call_new_process(t_ml *tml)
{
	int			fd;
	pid_t		pid;
	t_varlist	var;

	fd = -10;
	pid = fork();
	if (pid == -1)
		perror("Erro ao criar o processo filho\n");
	else if (pid != 0)
	{
		g_pid = pid;
		var.name = ft_strcpy("pid", FALSE);
		var.value = ft_strcpy(ft_itoa(pid), TRUE);
		vr_insert(&tml->pid_list, var, TRUE, TRUE);
		if (fd != -10)
			close(fd);
		if (tml->pp_quant != 0 && !(tml->i == tml->pp_quant))
			close(tml->pp_lpipes[tml->i][1]);
	}
	else
	{
		g_pid = G_CHILD;
		signal(SIGQUIT, SIG_DFL);
		tml->exit_status = tml_exec_child(tml, &fd);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	fk_wait_execs(t_ml *tml)
{
	int			new_exit_code;
	pid_t		pid;
	t_varlist	*temp;

	temp = tml->pid_list;
	new_exit_code = 0;
	while (temp)
	{
		if (!ft_strcmp(temp->name, "pid"))
		{
			pid = ft_atoi(temp->value);
			waitpid(pid, &new_exit_code, 0);
			new_exit_code = WEXITSTATUS(new_exit_code);
		}
		else
			new_exit_code = ft_atoi(temp->value);
		temp = temp->next;
	}
	vr_delete(&tml->pid_list);
	tml->pid_list = NULL;
	tml_exit_status(&tml->local_vars, new_exit_code, FALSE);
	tml->exit_status = new_exit_code;
}
