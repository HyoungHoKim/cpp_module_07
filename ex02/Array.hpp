#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <class T>
class Array
{
private:
	T *_arr;
	unsigned int _n;

public:
	Array() : _arr(new T[0]), _n(0)
	{ };
	~Array()
	{
		delete[] _arr;
	};
	Array(unsigned int n) : _arr(new T[n]), _n(n)
	{ };
	Array(const Array &arr)
	{
		*this = arr;
	};
	Array &operator=(const Array &ar)
	{
		if (this == &ar)
			return (*this);
		if (_n != ar._n)
		{
			if (_arr && _n > 0)
				delete[] _arr;
			_n = ar._n;
			_arr = new T[_n];
		}
		for (unsigned int i = 0; i < _n; i++)
			_arr[i] = ar._arr[i];
		return (*this);
	};

	T& operator[](const unsigned int idx)
	{
		if (idx < 0 || _n <= idx)
			throw Array::OutOfRangeException();
		return (_arr[idx]);
	};

	std::size_t size() const
	{
		return (_n);
	};

	class OutOfRangeException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Error: Out of range!!!");
		}
	};
};

#endif