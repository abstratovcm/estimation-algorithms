template <typename T>
T &Matrix<T>::operator()(int m, int n)
{
    return matrix[m * rows + n];
}
template <typename T>
const T &Matrix<T>::operator()(int m, int n) const
{
    return matrix[m * rows + n];
}
template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other)
{
    if (rows == other.rows && cols == other.cols)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i] = other.matrix[i];
        }
    }
    else
    {
        std::cerr << "Matrix doesn't have the same size." << std::endl;
    }
    return *this;
}

// TODO: implement and debug operator+
// Matrix operator+(const MyClass &other)
//{
//     if ()
//         MyClass result;
//     result.value = this->value + other.value;
//     return result;
// }
