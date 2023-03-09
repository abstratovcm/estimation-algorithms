// #pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
private:
    std::vector<T> matrix;
    int rows;
    int cols;

public:
    Matrix(int m, int n);

    Matrix(int m, int n, int value);

    T &operator()(int m, int n);

    const T &operator()(int m, int n) const;

    Matrix &operator=(const Matrix &other);

    void printSize();

    void print();

    void printTranspose();

    std::vector<int> getSize()
    {
        return {rows, cols};
    }

    void reshape()
    {
        int aux = cols;
        cols = rows;
        rows = aux;
    }
};

#include "../tpl/matrixConstructors.tpp"
#include "../tpl/matrixOperators.tpp"
#include "../tpl/matrixPrintFunctions.tpp"

#endif