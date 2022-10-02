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

template <typename Type>
class Matrix
{
public:
    Matrix()
    {
        this->setSize(1, 1);
    }
    Matrix(int height, int width)
    {
        this->setSize(height, width);
    }
    Matrix(msize)
    {
        this->setSize(size);
    }
    Matrix(const Matrix &)
    {
        matrix = a.matrix;
    }
    ~Matrix()
    {
        for (int i = 0; i < size.height, i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    void setSize(int height, int width)
    {
        if (height <= 0 || width <= 0)
            throw MatrixException(MatrixException::Errors::IndexError, msize(height, width));

        matrix.resize(height);
        for (int i = 0; i < height; i++)
            matrix[i].resize(width);
        this->size = msize(height, width);
    }
    void setSize(msize size)
    {
        if (size.height <= 0 || size.width <= 0)
            throw MatrixException(MatrixException::Errors::IndexError, size);

        this->setSize(size.height, size.width);
        this->size = size;
    }
    int size() const
    {
        return this->size.height;
    }
    void resize(int height) // Изменение размера внешнего массива
    {
        if (height > size.height)
        {
            if (height >= reserved / size.width)
        }
    }
    msize getSize() const
    {
        return msize(matrix.size(), matrix[0].size());
    }

    Matrix operator+(Matrix matrix)
    {
        if (this->getSize() != matrix.getSize())
            throw MatrixException(MatrixException::Errors::SumError, this->getSize(), matrix.getSize());

        Matrix temp(this->getSize());
        for (int i = 0; i < this->matrix.size(); i++)
            for (int j = 0; j < this->matrix[i].size(); j++)
                temp.matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
        return temp;
    }
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix operator*(const Type);
    friend Matrix operator*(const Type, Matrix);
    Matrix operator/(double);
    Matrix &operator=(const Matrix);

    vector<Type> getRow(int i); // Получить i строку
    vector<Type> getColumn(int j); // Получить j столбец
    Type getElement(int i, int j); // Получить i j элемент матрицы
    void setElement(int i, int j, Type value); // Установить значение value для i j элемента матрицы

    double determinant(); // Определитель матрицы
    double algAddition(int i, int j); // Алгебраическое дополнение по i строки и j столбцу

    void transpose(); // Транспонированная матрица
    void reverse(); // Обратная матрица

    void delRow(int i); // Удалить i строку
    void delColumn(int j); // Удалить j столбец

    void addRow(int i, vector<Type> row); // Добавить строку row после i строки исходной матрицы
    void addRow();
    void addColumn(int j, vector<Type> column); // Добавить столбец column после j столбца исходной матрицы
    void addColumn();

    void swapRows(int i1, int i2); // Меняет местами i1 и i2 строки
    void swapColumns(int j1, int j2); // Меняет местами j1 и j2 столбцы
private:
    Type det(Type *);
    Type **matrix;
    int reserved = 0;
    msize size;
};

#endif // MATRIX_H
