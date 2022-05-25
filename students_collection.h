//
// Created by the80hz on 25.05.2022.
//

#ifndef LABA4_VAR5_DENIS_STUDENTS_COLLECTION_H
#define LABA4_VAR5_DENIS_STUDENTS_COLLECTION_H

#include "student.h"

class collection_of_students
{
private:
    int _capacity = 0;

    int _size = 0;

    int _d = 0;

    student** array = NULL;
public:
    void delete_index(int index);

    void delete_all();

    ~collection_of_students();

    int get_size() const;

    void add_last(student* object);

    void add_prev_index(int index, student* object);

    int search_in_surname_from_index(int index, char* frag) const;

    void bubble_stort(int(*student_cmp)(const student&, const student&));

    void fileinput(FILE* input);

    void fileoutput(FILE* output) const;

    student* get_student(int index);

    collection_of_students(int value, int d);

    collection_of_students(int d);

    collection_of_students();

    collection_of_students* create_filtred_collection(double value) const;
};


#endif //LABA4_VAR5_DENIS_STUDENTS_COLLECTION_H
