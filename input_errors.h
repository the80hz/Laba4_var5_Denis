//
// Created by the80hz on 25.05.2022.
//

#ifndef LABA4_VAR5_DENIS_INPUT_ERRORS_H
#define LABA4_VAR5_DENIS_INPUT_ERRORS_H


#include "error.h"


class input_string_error : public error
{
public:
    void print() const override;
};

class input_int_error : public error
{
public:
    void print() const override;
};

class input_double_error : public error
{
public:
    void print() const override;
};

class input_int_value_error : public error
{
public:
    void print() const override;
};

class input_double_value_error : public error
{
public:
    void print() const override;
};


#endif //LABA4_VAR5_DENIS_INPUT_ERRORS_H
