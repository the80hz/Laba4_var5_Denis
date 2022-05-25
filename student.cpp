//
// Created by the80hz on 25.05.2022.
//

#include <iostream>
#include <string.h>
#include "student.h"


void student::set_name(const char* name)
{
    strcpy_s(_name, 100, name);
}

void student::set_patronymic(const char* patronymic)
{
    strcpy_s(_patronymic, 100, patronymic);
}

void student::set_surname(const char* surname)
{
    strcpy_s(_surname, 100, surname);
}

void student::set_mark0(int mark0)
{
    _marks[0] = mark0;
}

void student::set_mark1(int mark1)
{
    _marks[1] = mark1;
}

void student::set_mark2(int mark2)
{
    _marks[2] = mark2;
}

void student::set_marks(int mark0, int mark1, int mark2)
{
    _marks[0] = mark0;
    _marks[1] = mark1;
    _marks[2] = mark2;
}

const char* student::get_name() const
{
    return _name;
}

const char* student::get_patronymic() const
{
    return _patronymic;
}

const char* student::get_surname() const
{
    return _surname;
}

int student::get_mark0() const
{
    return _marks[0];
}

int student::get_mark1() const
{
    return _marks[1];
}

int student::get_mark2() const
{
    return _marks[2];
}

void student::get_marks(int& mark0, int& mark1, int& mark2) const
{
    mark0 = _marks[0];
    mark1 = _marks[1];
    mark2 = _marks[2];
}

student::student(char* surname, char* name, char* patronymic, int mark0, int mark1, int mark2)
{
    set_name(name);
    set_patronymic(patronymic);
    set_surname(surname);
    set_marks(mark0, mark1, mark2);
}

student::student()
{
    char name[] = "Ivan";
    char patronymic[] = "Ivanovich";
    char surname[] = "Ivanov";

    set_name(name);
    set_patronymic(patronymic);
    set_surname(surname);
    _marks[0] = 5;
    _marks[1] = 5;
    _marks[2] = 5;
}

student::student(const student& st1)
{
    set_marks(st1.get_mark0(), st1.get_mark1(), st1.get_mark2());

    set_name(st1.get_name());
    set_surname(st1.get_surname());
    set_patronymic(st1.get_patronymic());
}

double student::calculate_average_mark() const
{
    double a = _marks[0] + _marks[1] + _marks[2];
    return a / 3;
}