#pragma once
#include "TList.h"

template <class T>
class THeadList :public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList() :TList<T>();
	~THeadList();

	void InsFirst(T el);
	void DelFirst();
};

template <class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>;
	pStop = pHead;
	pHead->pNext = pHead;
	pFirst = pHead;
}

template <class T>
THeadList<T>::~THeadList()
{
	TList<T>::DelList();
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(T el)
{
	TList<T>::InsFirst(el);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::DelFirst()
{
	TList<T>::DelFirst();
	pHead->pNext = pFirst;
}