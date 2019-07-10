/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** sqrt
*/

#include <stdlib.h>

double my_sqrt(double max)
{
    double result = 0;
    double val = 1;
    double i = val;
    int stop = 8;

    if (max <= 0)
        return (-1);
    while (stop) {
        if ((result + val) * (result + val) > max) {
            val *= 0.1;
            --stop;
        }
        else
            result += val;
    }
    return (result);
}