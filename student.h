//
// Created by the80hz on 25.05.2022.
//

#ifndef LABA4_VAR5_DENIS_STUDENT_H
#define LABA4_VAR5_DENIS_STUDENT_H


class student{
private:
    char _name[100] = { 0 };
    char _patronymic[100] = { 0 };
    char _surname[100] = { 0 };

    int _marks[3];
public:
    void set_name(const char* name);

    void set_patronymic(const char* patronymic);

    void set_surname(const char* surname);

    void set_mark0(int mark0);

    void set_mark1(int mark1);

    void set_mark2(int mark2);

    void set_marks(int mark0, int mark1, int mark2);

    const char* get_name() const;

    const char* get_patronymic() const;

    const char* get_surname() const;

    int get_mark0() const;

    int get_mark1() const;

    int get_mark2() const;

    void get_marks(int& mark0, int& mark1, int& mark2) const;

    student(char* surname, char* name, char* patronymic, int mark0, int mark1, int mark2);

    student();

    student(const student &st1);

    double calculate_average_mark() const;
};


#endif //LABA4_VAR5_DENIS_STUDENT_H
