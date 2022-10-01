#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <format>

using namespace std;

struct msize {
    msize(int h = 1, int w = 1)
    {
        height = h;
        width = w;
    }
    int height;
    int width;
    bool operator!=(msize a)
    {
        return (height != a.height) && ( width != a.width);
    }
};

class MatrixException
{
public:
    enum class Errors
    {
        SizeError, // Несоответствие размеров
        IndexError, // Обращение к несуществующему элементу
        SumError, // Cложение матриц не соответствующих размеров
        SubError, // Разность матриц не соответствующих размеров
        MulError, // Умножение матриц не соответствующих размеров
        ZeroDivisionError, // Умножение матриц не соответствующих размеров
        DeterminantError, // Матрица не является квадратной
        ReverseMatrixError, // Определитель равен нулю
    };

    MatrixException(Errors type, msize a = {0, 0}, msize b = {0, 0});
    void printError();

private:
    string err, info;
};

class Matrix
{
public:  
    Matrix();
    Matrix(int height, int width);
    Matrix(msize);
    Matrix(const Matrix &);

    void setSize(int, int);
    void setSize(msize);
    int size() const;
    msize getSize() const;

    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix operator*(const double);
    friend Matrix operator*(const double, Matrix);
    Matrix operator/(double);
    Matrix &operator=(const Matrix);

    vector<double> getRow(int i); // Получить i строку
    vector<double> getColumn(int j); // Получить j столбец
    double getElement(int i, int j); // Получить i j элемент матрицы
    void setElement(int i, int j, double value); // Установить значение value для i j элемента матрицы

    double determinant(); // Определитель матрицы
    double algAddition(int i, int j); // Алгебраическое дополнение по i строки и j столбцу

    void transpose(); // Транспонированная матрица
    void reverse(); // Обратная матрица

    void delRow(int i); // Удалить i строку
    void delColumn(int j); // Удалить j столбец

    void addRow(int i, vector<double> row); // Добавить строку row после i строки исходной матрицы
    void addRow();
    void addColumn(int j, vector<double> column); // Добавить столбец column после j столбца исходной матрицы
    void addColumn();

    void swapRows(int i1, int i2); // Меняет местами i1 и i2 строки
    void swapColumns(int j1, int j2); // Меняет местами j1 и j2 столбцы
private:
    double det(vector<vector<double>>);
    vector<vector<double>> matrix;
};

#endif // MATRIX_H
