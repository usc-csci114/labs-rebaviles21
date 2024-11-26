#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
struct Node {
	T value;
	Node* next;
};

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(size_t idx , T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:

	size_t m_size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	//constructor
	head = nullptr;
	tail = nullptr;
	m_size = 0;
}

template <typename T>
void LinkedList<T>::append(T v)
{
	Node<T>* node = new Node<T>;
	//need to set node->value?
	//need to set node->next?
	node->value = v;
	node->next = nullptr;
	if(head == nullptr) { //nothing in the linked list so you can assign to the beginning
		head = node; 
		tail = node; // assuming there is only one thing they should point to the same thing 
	}
	else{ // other nodes in the linked list (assuming head at front; tail would only change)
		tail->next = node;
		tail = node;
	}
	m_size++;

}

template <typename T>
void LinkedList<T>::insert(size_t idx, T v)
{
	Node<T>* node = new Node<T>;
	node->value = v;
	node->next = nullptr;
	//check to see if the index is valid
	if(idx >= m_size) {
		throw std::range_error("Index given is out of bounds");
	}
	//if the index walk the linked list
	if(idx ==  m_size){ //assume tail
		tail->next = node;
		tail = node;
		//keep node->next as null do not chang 
	}
	if(idx == 0) { //insert at the head (should also shift)
		node->next = head;
		head = node;
	}
	// not the beginning or the end
	else{
		Node<T>* temp = head; // allows the "head" to move
		// only insert in middle
		for(size_t i = 0; i < idx - 1; i++) {
			temp = temp-> next;  //because we cant lose head we need temp to go through list
		}
		//for loop will reach the node before the index
		node->next = temp->next; // change because the temp is there
		temp->next = node;
	}
	m_size++;

	//look over the logic one more time...(seg fault)
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	if( idx >= m_size || idx < 0) {
		throw std::range_error("Index given is out of bounds");
	}

	Node<T>* temp = head;
	for(size_t i = 0; i < idx; i++) {
		temp= temp-> next;  //because we cant lose head we need temp to go through list
	}
	// once they match
	return temp->value; // once they match; the temp grabs the given node AT function
}

template <typename T>
void LinkedList<T>::set(size_t idx, T v)
{
	if( idx >= m_size || idx < 0) {
		throw std::range_error("Index given is out of bounds");
	}

	Node<T>* temp = head;
	for(size_t i = 0; i < idx; i++) {
		temp= temp-> next;  //because we cant lose head we need temp to go through list
	}
	//temp should be index position
	temp->value = v;

}

template <typename T>
void LinkedList<T>::remove(size_t idx)
{
	if( idx >= m_size || idx < 0) {
		throw std::range_error("Index given is out of bounds");
	}

	Node<T>* temp = head;
	for(size_t i = 0; i < idx; i++) {
		temp= temp-> next;  //because we cant lose head we need temp to go through list
	}
	
	Node<T>* updatedTemp = temp->next;
	temp->next = updatedTemp->next;

	delete updatedTemp;
	m_size--;
}

template <typename T>
size_t LinkedList<T>::find(T v)
{
	Node<T>* temp = head;
	size_t count = 0; 
	while(temp != nullptr) {
		if(temp->value == v) {
			return count;
		}
		temp = temp->next;	
		count++;
	}
	return -1;
}

template <typename T>
size_t LinkedList<T>::size()
{
	return m_size;
}

template <typename T>
bool LinkedList<T>::empty()
{
	if(m_size == 0) {
		return true;
	}

	return false;
}

#endif
