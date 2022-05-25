//
// Created by the80hz on 25.05.2022.
//

#include <iostream>
#include "input_errors.h"


void input_string_error::print() const
{
    printf("\nОшибка ввода строки");
}

void input_int_error::print() const
{
    printf("\nОшибка ввода целого числа");
}

void input_double_error::print() const
{
    printf("\nОшибка ввода вещественного числа");
}

void input_int_value_error::print() const
{
    printf("\nОшибка, недопустимое значение для целого числа");
}

void input_double_value_error::print() const
{
    printf("\nОшибка, недопустимое значение для вещественного числа");
}