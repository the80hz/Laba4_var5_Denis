//
// Created by the80hz on 25.05.2022.
//

#ifndef LABA4_VAR5_DENIS_STUDENTS_FUNCTIONS_H
#define LABA4_VAR5_DENIS_STUDENTS_FUNCTIONS_H

#include <iostream>
#include "students_functions.h"
#include "strings.h"
#include "input_errors.h"
#include "file_errors.h"
#include "menu.h"
#include "student.h"
#include "students_collection.h"
#include "pause.h"
#include "student.h"
#include "students_collection.h"

void take_str_for_student(char* str);

int take_mark_for_student();

double take_double_for_student();

void take_data_for_student(char* surname, char* name, char* patronymic, int& mark0, int& mark1, int& mark2);

void change_student(student* object);

void print_student(student* object);

void print_collection(collection_of_students* collection);

//int take_int_for_d();

void file_output(collection_of_students* collection);


#endif //LABA4_VAR5_DENIS_STUDENTS_FUNCTIONS_H
