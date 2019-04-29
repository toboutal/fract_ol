/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_islowercase.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:38:29 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 16:49:56 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_islowercase(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}
