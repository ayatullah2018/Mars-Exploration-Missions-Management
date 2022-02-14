#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class PriorityQueue
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& data, int priority);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue();
};

template <typename T>
bool PriorityQueue<T>::enqueue( const T &data, int priority)
{
	Node<T>* tmp, *t;
	tmp = new Node<T>();
	tmp->setItem(data);
	tmp->setPriority(priority);
	if (frontPtr == NULL || priority < frontPtr->getPriority())
	{
		tmp->setNext(frontPtr);
		frontPtr = tmp;
	}
	else
	{
		t = frontPtr;
		while (t->getNext() != NULL && t->getNext()->getPriority() <= priority)
			t = t->getNext();
		tmp->setNext(t->getNext());
		t->setNext(tmp);
	}
	t = frontPtr;
	while (t != NULL)
	{
		
		t = t->getNext();
	}
	cout << endl;
	return true;

}

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}

template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	
	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));

	
}