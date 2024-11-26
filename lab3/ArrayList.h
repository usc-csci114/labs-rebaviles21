#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
	ArrayList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(size_t idx, T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:
	void resize(); //double the size of the array and copy the items
	size_t m_capacity;
	size_t m_size;
	T* data;
};

template <typename T>
ArrayList<T>::ArrayList()
{
    // constructor
    m_capacity = 10;
    m_size = 0;
    data = new T[m_capacity]; // the original array list and allocate the data
}

template <typename T>
void ArrayList<T>::append(T v)
{
	if(m_size == m_capacity) {
		resize(); // readapt what is there
	}
    data[m_size] = v; // append at the m_size (which is the end and )
	m_size++; // increase the size	
}

template <typename T>
void ArrayList<T>::insert(size_t idx, T v)
{
	if(m_size == m_capacity) { // always check to see if the array is full
		resize();
	}
	//once check if full (check if idx is valid)
	if(idx >= m_size || idx >= m_capacity) {
		throw std::range_error("Index given is out of bounds");
	}
	for(size_t i = m_size; i > idx; i--) { // everything must shift to allocate space until its inserted
		data[i] = data[i-1];
	}
	//once shifted we can insert in the given space
	data[idx] = v;
	m_size++;

}

template <typename T>
T ArrayList<T>::at(size_t idx)
{
	// no need to resize here because it justs wants to grab
	if(idx > m_size || idx > m_capacity) {
		throw std::range_error("Index given is out of bounds");
	}
	return data[idx];
}

template <typename T>
void ArrayList<T>::set(size_t idx, T v) 
{
	if(idx > m_size || idx > m_capacity) {
		throw std::range_error("Index given is out of bounds");
	}
	data[idx] = v;
}

template <typename T>
void ArrayList<T>::remove(size_t idx)
{
	if(idx >= m_size || idx > m_capacity) {
		throw std::range_error("Index given is out of bounds");
	}
	for(size_t i = idx; i < m_size -1 ; i++) {
		data[i] = data[i+1]; // should just change the insert automatically
	}
	m_size--;
}	

template <typename T>
size_t ArrayList<T>::find(T v)
{
	for(size_t i = 0; i < m_size;i++) {
		if(data[i] == v) {
			return i;
		}
	}
	return -1;
}

template <typename T>
size_t ArrayList<T>::size()
{
	return m_size;
}

template <typename T>
bool ArrayList<T>::empty()
{
	if(m_size == 0) {
		return true;
	}
	return false;
}

template <typename T>
void ArrayList<T>::resize()
{
	m_capacity = m_capacity*2; // double the number and update
	T* updatedData = new T[m_capacity]; // allocate new data

	for(size_t i = 0; i < m_size; i++) {
		updatedData[i] = data[i]; //add the stuff that was in original array
	}

	delete[] data; // need to delete allocated data because we need to update storage
	data = updatedData; // makes this the new allocated
}
#endif
