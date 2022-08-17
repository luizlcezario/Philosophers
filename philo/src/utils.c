/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:27:58 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/17 18:30:48 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	current_timestamp() {
	struct timeval te;
	gettimeofday(&te, NULL); // get current time.
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return milliseconds;
}

void	mssleep(long long mile)
{
	long long	microsec;

	microsec = mile * 1000;
	usleep(microseconds);
}