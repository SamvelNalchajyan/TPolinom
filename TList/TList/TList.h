#pragma once
#include <iostream>

template <class T>
struct TNode
{
	T val;
	TNode<T>* pNext;
};

template <class T>
class TList
{
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr;
	TNode<T>* pPrev;
	TNode<T>* pStop;
	int len;
	int pos;
public:
	TList();
	~TList();

	void InsFirst(T el);
	void InsLast(T el);
	void DelFirst();
	void InsCurr(T el);
	void DelCurr();
	T GetCurrEl();
	void Reset();
	void GoNext();
	bool IsEnd();
	void InsInOrder(T el);
	void DelList();
};

template <class T>
TList<T>::TList()
{
	pFirst = NULL;
	pLast = NULL;
	pCurr = NULL;
	pPrev = NULL;
	pStop = NULL;
	len = 0;
	pos = -1;
}

template <class T>
TList<T>::~TList()
{
	DelList();
}

template <class T>
void TList<T>::InsFirst(T el)
{
	TNode<T>* tmp;
	tmp = new TNode<T>;
	tmp->pNext = pFirst;
	tmp->val = el;
	pFirst = tmp;
	len++;
}

template <class T>
void TList<T>::InsLast(T el)
{
	TNode<T>* tmp;
	tmp = new TNode<T>;
	tmp->pNext = pStop;
	tmp->val = el;
	if (pLast != pStop)
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}
	else
	{
		pFirst = pLast = tmp;
	}
	len++;
}

template <class T>
void TList<T>::DelFirst()
{
	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	len--;
}

template <class T>
void TList<T>::InsCurr(T el)
{
	if (pCurr == pFirst)
	{
		InsFirst(el);
	}
	else
	{
		TNode<T>* tmp;
		tmp = new TNode<T>;
		tmp->val = el;
		pPrev->pNext = tmp;
		tmp->pNext = pCurr;
		pCurr = tmp;
		len++;
	}
	if (pCurr == pStop)
	{
		throw 1;
	}
}

template <class T>
void TList<T>::DelCurr()
{
	if (pCurr == pStop)
	{
		throw 1;
	}
	if (pCurr == pFirst)
	{
		DelFirst();
	}
	else
	{
		pCurr = pCurr->pNext;
		delete pPrev->pNext;
		pPrev->pNext = pCurr;
		len--;
	}
}

template <class T>
T TList<T>::GetCurrEl()
{
	if (pCurr == pStop)
	{
		throw 1;
	}
	return pCurr->val;
}

template <class T>
void TList<T>::Reset()
{
	pCurr = pFirst;
	pPrev = pStop;
	pos = 0;
}

template <class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurr == pStop;
}

template <class T>
void TList<T>::InsInOrder(T el)
{
	if (pFirst == pStop || el > pFirst->val)
	{
		InsFirst(el);
	}
	else
	{
		if (pLast->val > el)
		{
			InsLast(el);
		}
		else
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				if (el > pCurr->val)
				{
					InsCurr(el);
					break;
				}
			}
		}
	}
}

template <class T>
void TList<T>::DelList()
{
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}