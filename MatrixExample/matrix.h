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

    vector<double> getRow(int i); // �������� i ������
    vector<double> getColumn(int j); // �������� j �������
    double getElement(int i, int j); // �������� i j ������� �������
    void setElement(int i, int j, double value); // ���������� �������� value ��� i j �������� �������

    double determinant(); // ������������ �������
    double algAddition(int i, int j); // �������������� ���������� �� i ������ � j �������

    void transpose(); // ����������������� �������
    void reverse(); // �������� �������

    void delRow(int i); // ������� i ������
    void delColumn(int j); // ������� j �������

    void addRow(int i, vector<double> row); // �������� ������ row ����� i ������ �������� �������
    void addRow();
    void addColumn(int j, vector<double> column); // �������� ������� column ����� j ������� �������� �������
    void addColumn();

    void swapRows(int i1, int i2); // ������ ������� i1 � i2 ������
    void swapColumns(int j1, int j2); // ������ ������� j1 � j2 �������
private:
    double det(vector<vector<double>>);
    vector<vector<double>> matrix;
};

#endif // MATRIX_H
