/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_double_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:22:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

int digits_only(char *s)
{
    int i;
    
    i = 0;
    while (s[i] != '\0') 
    {
        if(s[i] == '.')
            i++;
        if (ft_isdigit(s[i])  == 0) 
            return 0;
        i++;
    }   
    return 1;
}

double after_point(char *string, int moy)
{
    double decimal;
    double dexieme;
    double dec;

    dec = 0.0;
    decimal = 0.0;
    dexieme = 10;
    while (*string >= '0' && *string <= '9' && *string != '\0')
    {
        dec = *string - '0';
        decimal = decimal + dec / dexieme;
        dexieme *= 10;
        string++;
    }
    decimal += moy;
    return (decimal);
}

double convert_to_double(char *string)
{
    int sign;
    int moy;
    double decimal;

    moy = 0;
    sign = 1;
    if (string[0] == '-' && ft_isdigit(string[1]) == 1)
    {
        sign = -1;
        string++;
    }
    if (string[0] == '+')
        string++;
    if (digits_only(string) == 0)
    {
        other_errors(01);
        exit(1);
    }
    while (*string >= '0' && *string <= '9')
        moy = moy * 10 + (*(string)++ - '0');
    while (*string == '.')
        (string)++;
    if (*string == '.' && *string++ != '\0')
    {
        other_errors(01);
        exit(1);
    }
    decimal = after_point(string, moy);
    return ((decimal)*sign);
}
