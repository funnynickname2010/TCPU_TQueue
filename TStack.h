#pragma once
#include <iostream>

#define CONST_MEM_MULT 8
#define CONST_MEM_ADD 1

template <class T>
class TStack
{
	T* arr;
	size_t top;
	size_t mx;
	
public:

	bool Empty() const noexcept;
	bool Full() const noexcept;

	void Push(const T obj);
	T Pull();

	TStack();
	explicit TStack(size_t maxsize);
	~TStack();
};

template<class T>
inline bool TStack<T>::Empty() const noexcept
{
	return top == 0;
}

template<class T>
inline bool TStack<T>::Full() const noexcept
{
	return top == mx;
}

template<class T>
inline void TStack<T>::Push(const T obj)
{
	if (this->Full())
	{
		size_t memory_to_allocate;

		if (mx == 0) { memory_to_allocate = mx + CONST_MEM_ADD; }
		else { memory_to_allocate = mx * CONST_MEM_MULT; }

		T* temp_ptr = new T[memory_to_allocate];

		if (temp_ptr != nullptr)
		{
			for (int i = 0; i < mx; i++)
			{
				temp_ptr[i] = arr[i];
			}

			delete[] arr;

			arr = temp_ptr;

			mx = memory_to_allocate;
		}
		else
		{
			throw std::exception("void TStack<T>::Push(const T obj) error: memory allocation failure.\n");
		}
	}

	arr[top++] = obj;
}

template<class T>
inline T TStack<T>::Pull()
{
	if (!this->Empty())
	{
		top--;
		return arr[top];
	}
	else
	{
		throw std::exception("T TStack<T>::Pull() error: stack is empty.\n");
	}
}

template<class T>
inline TStack<T>::TStack()
{
	arr = nullptr;
	top = 0;
	mx = 0;
}

template<class T>
inline TStack<T>::TStack(size_t maxsize)
{
	arr = new T(maxsize);
	top = 0;
	mx = maxsize;

	if (arr == nullptr)
	{
		throw std::exception("TStack<T>::TStack(size_t maxsize) error: memory allocation failure.\n");
	}
}

template<class T>
inline TStack<T>::~TStack()
{
	delete[] arr;
	mx = 0;
	top = 0;
}
