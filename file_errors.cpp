//
// Created by the80hz on 25.05.2022.
//

#include <iostream>
#include "file_errors.h"


void open_file_error::print() const
{
    printf("\nОшибка при открытии файла");
}

void input_file_error::print() const
{
    printf("\nОшибка, файл содержит недопустимые данные или данные в недопустимом формате");
}

void output_file_error::print() const
{
    printf("\nОшибка при записи в файл");
}