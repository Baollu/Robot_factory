/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef MACRO
    #define MACRO

    #define ABS(value) (((value) < (0)) ? (value * -1) : (value))
    #define MAX(value1, value2) (((value1) > (value2)) ? (value1) : (value2))
    #define MIN(value1, value2) (((value1) < (value2)) ? (value1) : (value2))
    #define IS_NEG(value) ((value < 0) ? (1) : (0))
    #define HAVE_DEC(value) (((value - (int)value) == 0) ? (0) : (1))

#endif
