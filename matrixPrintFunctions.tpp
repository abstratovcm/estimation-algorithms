template <typename T>
void Matrix<T>::printSize()
{
    std::cout << "size: (" << rows << ", " << cols << ")" << std::endl;
}

template <typename T>
void Matrix<T>::print()
{
    std::cout << "[";
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < cols - 1; j++)
    {
        std::cout << matrix[(rows - 1) * cols + j] << " ";
    }
    std::cout << matrix[(rows - 1) * cols + cols - 1] << "]" << std::endl;
}

template <typename T>
void Matrix<T>::printTranspose()
{
    std::cout << "[";
    for (int j = 0; j < cols - 1; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            std::cout << matrix[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows - 1; i++)
    {
        std::cout << matrix[i * cols + (cols - 1)] << " ";
    }
    std::cout << matrix[(rows - 1) * cols + cols - 1] << "]" << std::endl;
}
