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
        SizeError, // �������������� ��������
        IndexError, // ��������� � ��������������� ��������
        SumError, // C������� ������ �� ��������������� ��������
        SubError, // �������� ������ �� ��������������� ��������
        MulError, // ��������� ������ �� ��������������� ��������
        ZeroDivisionError, // ��������� ������ �� ��������������� ��������
        DeterminantError, // ������� �� �������� ����������
        ReverseMatrixError, // ������������ ����� ����
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
    void resize(int height) // ��������� ������� �������� �������
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

    vector<Type> getRow(int i); // �������� i ������
    vector<Type> getColumn(int j); // �������� j �������
    Type getElement(int i, int j); // �������� i j ������� �������
    void setElement(int i, int j, Type value); // ���������� �������� value ��� i j �������� �������

    double determinant(); // ������������ �������
    double algAddition(int i, int j); // �������������� ���������� �� i ������ � j �������

    void transpose(); // ����������������� �������
    void reverse(); // �������� �������

    void delRow(int i); // ������� i ������
    void delColumn(int j); // ������� j �������

    void addRow(int i, vector<Type> row); // �������� ������ row ����� i ������ �������� �������
    void addRow();
    void addColumn(int j, vector<Type> column); // �������� ������� column ����� j ������� �������� �������
    void addColumn();

    void swapRows(int i1, int i2); // ������ ������� i1 � i2 ������
    void swapColumns(int j1, int j2); // ������ ������� j1 � j2 �������
private:
    Type det(Type *);
    Type **matrix;
    int reserved = 0;
    msize size;
};

#endif // MATRIX_H
