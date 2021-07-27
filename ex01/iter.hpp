#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, int len, void(*func)(T const &ref))
{
	if (arr == NULL || len == 0 || func == NULL)
		return ;
	
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

#endif