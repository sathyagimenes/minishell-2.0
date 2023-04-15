/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tml_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:53:50 by briferre          #+#    #+#             */
/*   Updated: 2023/04/14 11:59:01 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_string	*init_path(t_varlist *start)
{
	t_varlist	*temp;

	temp = start;
	while (temp && ft_strncmp(temp->name, "PATH", 4))
		temp = temp->next;
	return (ft_split(temp->value, ':'));
}

void	tml_get_uhp(t_ml *tml)
{
	tml->user = vr_get_value(tml->vars, "USER", TRUE);
	tml->host = fl_get_text("/etc/hostname");
	tml->cmd = NULL;
	tml->pp_cmd = NULL;
}

void	tml_init(int argc, t_string *argv, t_string *env, t_ml *tml)
{
	int	i;

	(void)argc;
	(void)argv;
	rl_terminal_name = "xterm-256color";
	putenv("LINES=24");
  putenv("COLUMNS=80");
	using_history();
	tml->exit_status = 0;
	i = -1;
	g_pid = 0;
	tml->vars = NULL;
	tml->env = NULL;
	tml->assigned = NULL;
	while (env[++i])
		vr_insert(&tml->vars, vr_get_name_value(env[i]));
	tml_exit_status(&tml->assigned, 0, TRUE);
	tml->paths = init_path(tml->vars);
	tml->running = RUNNIG;
	tml->cmd_vars = NULL;
	tml_get_uhp(tml);
}
