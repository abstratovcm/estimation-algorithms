template <typename T>
Matrix<T>::Matrix(int m, int n)
{
    rows = m;
    cols = n;
    matrix.resize(m * n);
};

template <typename T>
Matrix<T>::Matrix(int m, int n, int value)
{
    rows = m;
    cols = n;
    matrix.resize(m * n, value);
};