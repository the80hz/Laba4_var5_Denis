//
// Created by the80hz on 25.05.2022.
//

#include <iostream>
#include <string.h>
#include "file_errors.h"
#include "input_errors.h"
#include "menu.h"
#include "strings.h"
#include "students_functions.h"
#include "students_collection.h"


void collection_of_students::delete_index(int index)
{
    if (index >= 0 && index < _size)
    {
        delete array[index];

        for (int i = index; i < _size - 1; ++i)
        {
            array[i] = array[i + 1];
        }

        --_size;
    }
}

void collection_of_students::delete_all()
{
    {
        for (int i = 0; i < _size; ++i)
        {
            delete array[i];
        }

        _size = 0;
        _capacity = 0;
        free(array);
        array = NULL;
    }
}

collection_of_students::~collection_of_students()
{
    delete_all();
}

int collection_of_students::get_size() const
{
    return _size;
}

void collection_of_students::add_last(student* object)
{
    ++_size;

    if (_size > _capacity)
    {
        array = (student * *)realloc(array, (_capacity + _d) * sizeof(student*));

        _capacity += _d;
    }

    array[_size - 1] = object;
}

void collection_of_students::add_prev_index(int index, student* object)
{
    if (index >= 0)
    {
        ++_size;

        if (_size > _capacity)
        {
            array = (student**)realloc(array, (_capacity + _d) * sizeof(student*));

            _capacity += _d;
        }

        for (int i = _size - 1; i > index; --i)
        {
            array[i] = array[i - 1];
        }

        array[index] = object;
    }
}

int collection_of_students::search_in_surname_from_index(int index, char* frag) const
{
    //int len = strlen(frag);
    //char tmp[100] = { 0 };
    //for (int i = 0; i < len; ++i)
    //{
    //	tmp[i] = tolower_rus(frag[i]);
    //}

    for (int i = index + 1; i < _size; ++i)
    {
        //char tmp1[100] = { 0 };

        //strcpy_s(tmp1, 100, array[i]->get_surname());

        //int len1 = strlen(tmp1);

        //for (int i = 0; i < len1; ++i)
        //{
        //		tmp1[i] = tolower_rus(tmp1[i]);
        //}

        char tmp[100] = { 0 };
        strcpy_s(tmp, 100, array[i]->get_surname());

        if (search_in_string(array[i]->get_surname(), frag) == true)
        {
            return i;
        }
    }

    return -1;
}

void collection_of_students::bubble_stort(int(*student_cmp)(const student&, const student&))
{
    for (int i = 0; i < _size - 1; ++i)
    {
        bool swapped = false;

        for (int j = 0; j < _size - i - 1; ++j)
        {
            if ((*student_cmp)(*array[j], *array[j + 1]) > 0)
            {
                student* tmp = array[j];

                array[j] = array[j + 1];
                array[j + 1] = tmp;

                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void collection_of_students::fileinput(FILE* input)
{
    char alf1[] = { "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz\n\r" };
    char alf2[] = { "12345\n\r" };

    while (!feof(input))
    {
        char surname[100] = { 0 };
        char name[100] = { 0 };
        char patronymic[100] = { 0 };
        char mark0[100] = { 0 };
        char mark1[100] = { 0 };
        char mark2[100] = { 0 };
        char space[100] = { 0 };

        fgets(surname, 100, input);
        fgets(name, 100, input);
        fgets(patronymic, 100, input);
        fgets(mark0, 100, input);
        fgets(mark1, 100, input);
        fgets(mark2, 100, input);
        fgets(space, 100, input);

        if (space[0] != '\n' && space[0] != 0 && space[0] != '\r')
        {

            throw input_file_error();
        }

        if (atoi(surname) != 0 || atoi(name) != 0 || atoi(patronymic) != 0)
        {

            throw input_file_error();
        }

        if (alf(surname, alf1) == 0 || alf(name, alf1) == 0 || alf(patronymic, alf1) == 0)
        {

            throw input_file_error();
        }

        if (alf(mark0, alf2) == 0 || alf(mark1, alf2) == 0 || alf(mark2, alf2) == 0)
        {

            throw input_file_error();
        }

        int a = atoi(mark0);
        int b = atoi(mark1);
        int c = atoi(mark2);

        if (a < 1 || b < 1 || c < 1 || a > 5 || b > 5 || c > 5)
        {

            throw input_file_error();
        }

        student* tmp = new student(surname, name, patronymic, a, b, c);
        add_last(tmp);
    }
}

void collection_of_students::fileoutput(FILE* output) const
{
    char end[2] = { '\n', 0 };

    for (int i = 0; i < _size; i++)
    {
        fputs(array[i]->get_surname(), output);
        fputs(array[i]->get_name(), output);
        fputs(array[i]->get_patronymic(), output);

        int a = 0;
        int b = 0;
        int c = 0;
        array[i]->get_marks(a, b, c);
        char mark0[100] = { 0 };
        char mark1[100] = { 0 };
        char mark2[100] = { 0 };

        _itoa_s(a, mark0, 10);
        _itoa_s(b, mark1, 10);
        _itoa_s(c, mark2, 10);

        strcat_s(mark0, 100, end);
        strcat_s(mark1, 100, end);
        strcat_s(mark2, 100, end);

        fputs(mark0, output);
        fputs(mark1, output);
        fputs(mark2, output);

        if (i != _size - 1)
        {
            fputs(end, output);
        }
    }
}

student* collection_of_students::get_student(int index)
{
    {
        return array[index];
    }
}

collection_of_students::collection_of_students(int value, int d)
{
    if (value > 0)
    {
        _capacity = value;
        _d = d;

        array = (student**)realloc(array, _capacity * sizeof(student*));
    }
}

collection_of_students::collection_of_students(int d)
{
    _d = d;
}

collection_of_students::collection_of_students()
{
    _d = 5;
}

collection_of_students* collection_of_students::create_filtred_collection(double value) const
{
    collection_of_students* filtred_coll = new collection_of_students(_d);

    for (int i = 0; i < _size; ++i)
    {
        if (array[i]->calculate_average_mark() >= value)
        {
            student* tmp = new student(*array[i]);

            filtred_coll->add_last(tmp);
        }
    }

    return filtred_coll;
}