#ifndef Array_h__
#define Array_h__
#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	T* m_Arr;
	int m_size;
public:
	Array();
	Array(int init_size);
	Array(const Array& init);
	~Array();
	template <class T> friend ostream& operator<<(ostream& output, const Array<T>& matr);
	Array& operator=(Array<T>& rhs);
	void init_Array();
	T count_difference_of_averages();
};

template <class T>
Array<T>::Array()
{
	m_size = 6;
	m_Arr = new T[m_size];
	for (int i = 0; i < m_size; i++)
	{
		cout << "Item of array number " << i << " = ";
		cin >> m_Arr[i];
	}
}

template <class T>
Array<T>::Array(int init_size)
{
	m_size = init_size;
	m_Arr = new T[m_size];
	for (int i = 0; i < m_size; i++)
	{
		cout << "Item of array number " << i << " = ";
		cin >> m_Arr[i];
	}
}

template<class T>
Array<T>::Array(const Array<T>& init)
{
	delete[] m_Arr;
	m_size = init.m_size;
	m_Arr = new T[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_Arr[i] = init.m_Arr[i];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] m_Arr;
}

template <class T>
ostream& operator<<(ostream& output, const Array<T>& matr)
{
	for (int i = 0; i < matr.m_size; i++)
	{
		output << matr.m_Arr[i] << " ";
	}
	output << endl;
	return output;
}

template<class T>
Array<T>& Array<T>::operator=(Array<T>& matr)
{
	if (this != &matr)
	{
		delete[] m_Arr;
		m_size = matr.m_size;
		m_Arr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_Arr[i] = matr.m_Arr[i];
		}
	}
	cout << "Operator =" << endl;
	return *this;
}

template<class T>
void Array<T>::init_Array()
{
	delete[] m_Arr;
	cout << "enter size of array: ";
	cin >> m_size;
	m_Arr = new T[m_size];
	for (int i = 0; i < m_size; i++)
	{
		cout << "Item of array number " << i << " = ";
		cin >> m_Arr[i];
	}
}

template<class T>
T Array<T>::count_difference_of_averages()
{
	T positive_sum = 0;
	int positive_count = 0;
	T negative_sum = 0;
	int negative_count = 0;

	for (int i = 0; i < m_size; i++)
	{
		if (m_Arr[i] > 0)
		{
			positive_sum += m_Arr[i];
			positive_count++;
		}
		if (m_Arr[i] < 0)
		{
			negative_sum += m_Arr[i];
			negative_count++;
		}
	}

	T positive_average = positive_sum / positive_count;
	T negative_average = negative_sum / negative_count;
	T result = positive_average - negative_average;
	cout << "Count difference of averages: " << result << endl;

	return result;

}

#endif Array_h__
