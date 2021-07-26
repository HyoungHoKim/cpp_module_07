#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &max(T &a, T &b)
{
	return (a > b) ? a : b;
}

template <typename T>
T &min(T &a, T &b)
{
	return (a < b) ? a : b;
}

class Awesome
{
public:
	Awesome(int n) : _n(n) {}
	
	int getN(void) const { return (this->_n); }

	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
private:
	int _n;
};

std::ostream &operator<<(std::ostream &os, const Awesome &_as)
{
	os << _as.getN();
	return (os);
}

#endif 