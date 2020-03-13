#include "TPolinom.h"

TMonom::TMonom()
{
	coeff = 0;
	px = 0;
	py = 0;
	pz = 0;
}

bool TMonom::operator<(TMonom mon)
{
	if (px < mon.px)
	{
		return true;
	}
	else
	{
		if (px > mon.px)
		{
			return false;
		}
	}
	if (py < mon.py)
	{
		return true;
	}
	else
	{
		if (py > mon.py)
		{
			return false;
		}
	}
	if (pz < mon.pz)
	{
		return true;
	}
	else
	{
		if (pz > mon.pz)
		{
			return false;
		}
	}
	return false;
}

bool TMonom::operator<=(TMonom mon)
{
	if (px < mon.px)
	{
		return true;
	}
	else
	{
		if (px > mon.px)
		{
			return false;
		}
	}
	if (py < mon.py)
	{
		return true;
	}
	else
	{
		if (py > mon.py)
		{
			return false;
		}
	}
	if (pz < mon.pz)
	{
		return true;
	}
	else
	{
		if (pz > mon.pz)
		{
			return false;
		}
	}
	return true;
}

bool TMonom::operator>(TMonom mon)
{
	if (px > mon.px)
	{
		return true;
	}
	else
	{
		if (px < mon.px)
		{
			return false;
		}
	}
	if (py > mon.py)
	{
		return true;
	}
	else
	{
		if (py < mon.py)
		{
			return false;
		}
	}
	if (pz > mon.pz)
	{
		return true;
	}
	else
	{
		if (pz < mon.pz)
		{
			return false;
		}
	}
	return false;
}

bool TMonom::operator>=(TMonom mon)
{
	if (px > mon.px)
	{
		return true;
	}
	else
	{
		if (px < mon.px)
		{
			return false;
		}
	}
	if (py > mon.py)
	{
		return true;
	}
	else
	{
		if (py < mon.py)
		{
			return false;
		}
	}
	if (pz > mon.pz)
	{
		return true;
	}
	else
	{
		if (pz < mon.pz)
		{
			return false;
		}
	}
	return true;
}

bool TMonom::operator==(TMonom mon)
{
	if (px == mon.px && py == mon.py && pz == mon.pz)
	{
		return true;
	}
	return false;
}

bool TMonom::operator!=(TMonom mon)
{
	if (px != mon.px || py != mon.py || pz != mon.pz)
	{
		return true;
	}
	return false;
}

/*..........................................*/

TPolinom::TPolinom() :THeadList<TMonom>()
{
	pHead->val.pz = -1;
}

TPolinom::TPolinom(TPolinom& p) :THeadList<TMonom>()
{
	pHead->val.pz = -1;
	TMonom tmp;
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		tmp = p.pCurr->val;
		InsLast(tmp);
	}
}

TPolinom::TPolinom(int arr[][2], int size) :THeadList<TMonom>()
{
	pHead->val.pz = -1;
	TMonom mon;
	for (int i = 0; i < size; i++)
	{
		TMonom mon;
		mon.coeff = arr[i][0];
		mon.px = arr[i][1] / 100;
		mon.py = arr[i][1] / 10 % 10;
		mon.pz = arr[i][1] % 10;
		InsLast(mon);
	}
}

TPolinom& TPolinom::operator=(TPolinom& p)
{
	DelList();
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		InsLast(p.pCurr->val);
	}
	return *this;
}

TPolinom& TPolinom::operator+=(TMonom& mon)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (mon == pCurr->val)
		{
			double tmp = mon.coeff + pCurr->val.coeff;
			if (tmp != 0)
			{
				pCurr->val.coeff = tmp;
				return *this;
			}
			else
			{
				DelCurr();
				return *this;
			}
		}
		if (mon > pCurr->val)
		{
			InsCurr(mon);
			return *this;
		}
	}
	InsLast(mon);
	return *this;
}

TPolinom TPolinom::operator+(TMonom& mon)
{
	TPolinom tmp(*this);
	tmp += mon;
	return tmp;
}

TPolinom& TPolinom::operator*=(TMonom& mon)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= mon.coeff;
		pCurr->val.px += mon.px;
		pCurr->val.py += mon.py;
		pCurr->val.pz += mon.pz;
	}
	return *this;
}

TPolinom TPolinom::operator*(TMonom& mon)
{
	TPolinom tmp(*this);
	tmp *= mon;
	return tmp;
}

TPolinom& TPolinom::operator+=(TPolinom& p)
{
	TMonom pm, qm, rm;
	Reset();
	p.Reset();
	while (!p.IsEnd())
	{
		pm = pCurr->val;
		qm = p.pCurr->val;
		if (pm > qm)
		{
			GoNext();
		}
		else
		{
			if (pm < qm)
			{
				InsCurr(qm);
				p.GoNext();
			}
			else
			{
				rm = pm;
				rm.coeff += qm.coeff;
				if (rm.coeff == 0)
				{
					DelCurr();
					p.GoNext();
				}
				else
				{
					pCurr->val = rm;
					p.GoNext();
					GoNext();
				}
			}
		}
	}
	return *this;
}

TPolinom TPolinom::operator+(TPolinom& p)
{
	TPolinom tmp(*this);
	tmp += p;
	return tmp;
}

bool TPolinom::operator==(TPolinom& p)
{
	p.Reset();
	if (len != p.len)
	{
		return false;
	}
	for (Reset(); !IsEnd(); GoNext())
	{
		if (pCurr->val != p.pCurr->val)
		{
			return false;
		}
	}
	return true;
}

bool TPolinom::operator!=(TPolinom& p)
{
	if (*this == p)
	{
		return false;
	}
	else
	{
		return true;
	}
}

TPolinom& TPolinom::operator*=(double a)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= a;
	}
	return *this;
}

TPolinom TPolinom::operator*(double a)
{
	TPolinom tmp(*this);
	tmp *= a;
	return tmp;
}