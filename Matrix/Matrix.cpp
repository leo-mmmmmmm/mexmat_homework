#include <iostream>
#include <string>

class Matrix
{
private:
	unsigned int size;
	double** matrix;

public:
	Matrix()
	{
		size = 1;
		matrix = new double* [size];
		matrix[0] = new double[size];
		matrix[0][0] = 0;
	}
	// _size не может быть 0?
	Matrix(const unsigned int _size)
	{
		size = _size;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	Matrix(const unsigned int _size, const char type)
	{
		size = _size;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}

		double defaultValue = 0;
		if (type == 'e' || type == 'E') defaultValue = 1;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j) matrix[i][j] = defaultValue;
				else matrix[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& other)
	{
		size = other.size;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	double getE(const unsigned int i, const unsigned int j) const
	{
		return matrix[i][j];
	}

	void setE(const unsigned int i, const unsigned int j, const double elem)
	{
		matrix[i][j] = elem;
	}

	Matrix operator+(const Matrix& other) const
	{
		if (size != other.size) return -1;
		else
		{
			Matrix newMatrix = other;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					newMatrix.matrix[i][j] += matrix[i][j];
				}
			}
			std::cout << "Matrix:!!!!!!!!!!!!!!!!" << std::endl;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					std::cout << newMatrix.matrix[i][j] << " ";
				}
				std::cout << "\n";
			}
			return Matrix(newMatrix);
		}
	}

	Matrix& operator+=(const Matrix& other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] += other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix& operator-=(const Matrix& other)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] -= other.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix& operator*=(const Matrix& other)
	{
		double elem = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					elem += matrix[i][k] *  other.matrix[k][j];
				}
				matrix[i][j] = elem;
				elem = 0;
			}
		}
		return *this;
	}

	bool operator==(const Matrix& other) const
	{
		bool flag = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (matrix[i][j] != other.matrix[i][j])
				{
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		return flag;
	}

	bool operator!=(const Matrix& other) const
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (matrix[i][j] != other.matrix[i][j])
				{
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		return flag;
	}

	void transpose()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				double elem = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = elem;
			}
		}
	}

	void matrixVector(double* vector)
	{
		double elem = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				for (int k = 0; k < size; k++)
				{
					 elem += matrix[i][k] * vector[k];
				}
				vector[i] = elem;
				elem = 0;
			}
		}
	}

	void printMatrix()
	{
		std::cout << "Matrix:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	void printSize()
	{
		std::cout << "Matrix size: " << size << std::endl;
		
	}
};