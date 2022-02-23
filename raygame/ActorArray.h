#pragma once
#include <exception>

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	/// <summary>
	/// Add a new item to the end of the array
	/// </summary>
	/// <param name="item">The item to add</param>
	void addItem(T item);

	void addItems(T items[], int size);

	/// <summary>
	/// Remove a item from the array
	/// </summary>
	/// <param name="item">The item to remove</param>
	bool removeItem(T item);

	/// <summary>
	/// Removes an actor from the array
	/// </summary>
	/// <param name="index">The index to remove from the array</param>
	/// <returns>False if the index is out of bounds</returns>
	bool removeItem(int index);

	/// <summary>
	/// Insertion sort items
	/// </summary>
	void sortItems();

	/// <summary>
	/// Gets an item at a specific index
	/// </summary>
	/// <param name="index">The index in the array</param>
	/// <returns>The item</returns>
	T getItem(int index);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	/// <returns>Array length</returns>
	int getLength() { return m_length; }

	/// <summary>
	/// Checks if the item is in the array
	/// </summary>
	/// <param name="item">A reference to the item to use to check</param>
	/// <returns>False of the item is not in the array</returns>
	bool contains(T item);

	T operator [](int index);

private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* newArray = new T[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
	{
		newArray[i] = m_items[i];
	}

	newArray[getLength()] = item;
	delete[] m_items;
	m_items = newArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int size)
{
	for (int i = 0; i < size; i++)
		addItem(items[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	if (!item || getLength() <= 0)
		return false;

	bool itemRemoved = false;

	T* newArray = new T[getLength() - 1];

	int j = 0;

	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i] || itemRemoved)
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		delete[] m_items;
		m_items = newArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(int index)
{
	//Check to see if the index is outside the bounds of our array
	if (index < 0 || index >= getLength())
	{
		return false;
	}

	bool actorRemoved = false;

	//Create a new array with a size one less than our old array 
	T* newArray = new T[getLength() - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		//If the current index is not the index that needs to be removed,
		//add the value into the old array and increment j
		if (i != index)
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			delete &m_items[i];
			actorRemoved = true;
		}
	}
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T key;
	int j = 0;

	//For each value in array
	for (int i = 1; i < getLength(); i++)
	{
		//Set key to value at the current index
		key = m_items[i];
		//Set j to be the previous index
		j = i - 1;

		//While j is greater than or equal to 0 and the value at j is greater than the key
		while (j >= 0 && m_items[j] > key)
		{
			//Set value at the index of j + 1 to be the value at the index of j
			m_items[j + 1] = m_items[j];
			//Decrement j
			j--;
		}
		//Set value at the index of j + 1 to be the key
		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= getLength())
		return m_items[index];

	return 0;
}

template<typename T>
inline bool DynamicArray<T>::contains(T item)
{
	//Iterate through actor array
	for (int i = 0; i < m_length; i++)
	{
		//return the current actor if it matches the argument
		if (m_items[i] == item)
			return true;
	}

	return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= getLength())
		return m_items[index];

	throw std::exception("Index was outside the bounds of the array");
}
