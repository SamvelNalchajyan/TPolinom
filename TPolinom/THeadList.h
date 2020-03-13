#pragma once
#include "TList.h"

template <class T>
class THeadList :public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();

	void InsFirst(T el);
	void DelFirst();
};

template <class T>
THeadList<T>::THeadList() :TList<T>()
{
	pHead = new TNode<T>;
	pStop = pHead;
	pHead->pNext = pHead;
	pFirst = pHead;
	pLast = pHead;
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