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
		
	}
}

TPolinom& TPolinom::operator=(TPolinom& p)
{
	return *this;
}

TPolinom& TPolinom::operator+=(TMonom& mon)
{
	return *this;
}

TPolinom TPolinom::operator+(TMonom& mon)
{
	return *this;
}

TPolinom& TPolinom::operator*=(TMonom& mon)
{
	return *this;
}

TPolinom TPolinom::operator*(TMonom& mon)
{
	return *this;
}