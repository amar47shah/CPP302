/*
 * SLLink.cpp
 *
 *  Created on: Feb 23, 2011
 *      Author: Ibrahim Imam
 */

#include <assert.h>
#include <iostream>
#include "SLList.h"

using namespace std;

Boolean SLList::isEmpty()
{
	return list == 0 ? True : False;
}

void SLList::insert(Type val)
{
	Item *pt = new Item(val, list); // create new item put it in front of list
	assert(pt != 0);
	if (list == 0)
	{
		atEndItem = pt;
	}
	list = pt; // and point next top the list
}

Item *SLList::atEnd()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::tail()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::head()
{
	if (list == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	else
	{
		return list;
	} // end if
	return list;
}

void SLList::append(Type val)
{
	Item *pt = new Item(val);
	assert(pt != 0);
	if (list == 0)
	{
		list = pt;
	}
	else
	{
		atEndItem->next = pt;
	}
	atEndItem = pt;
}

void SLList::push_front(Type val)
{
    Item *p = new Item(val, list);
    if (list == 0)
        atEndItem = p;
    list = p;
}

void SLList::display()
{
	cout << "( ";
	for (Item *pt = list; pt; pt = pt->next)
	{
		cout << pt->val << " ";
	} // end for
	cout << ")" << endl;
}

void SLList::remove()
{
	Item *pt = list;
	while (pt)
	{
		Item *temp = pt;
		pt = pt->next;
		delete temp;
	} // end while
	list = atEndItem = 0;
}

Boolean SLList::isPresent(Type item)
{
	Boolean rc = False;
	if (list != 0)
	{
		if (list->val == item || atEndItem->val == item)
		{
			rc = True;
		}
		else
		{
			Item *pt = list->next;
			for (; pt != atEndItem; pt = pt->next)
			{
				if (pt->val == item)
				{
					rc = True;
				} // end if
			} // end for
		} // end if
	} // end if
	return rc;
}
int SLList::remove(Type val)
{
	Item *pt = list;
	int cnt = 0;

	while (pt && pt->val == val)
	{
		Item *tmp = pt->next;
		delete pt;
		cnt++;
		pt = tmp;
	} // end while

	if ((list = pt) == 0)
	{
		atEndItem = 0;
		return cnt;
	} // end if

	Item *prv = pt;
	pt = pt->next;

	while (pt)
	{
		if (pt->val == val)
		{
			prv->next = pt->next;
			if (atEndItem == pt)
			{
				atEndItem = prv;
			} // end if
			delete pt;
			++cnt;
			pt = prv->next;
		}
		else
		{
			prv = pt;
			pt = pt->next;
		} // end if else
	} // end while
	return cnt;
}

Item *SLList::previous (Item *p)
{
    if (p == list)
        return 0;

    Item *prev = list;
    while (prev->next != p)
        prev = prev->next;
    return prev;
}

void SLList::swapTwo (Iterator loc)
{
    Item *p = loc.current;
    Item *afterp = p->next; // 0 if list == 0 or p is at end
    Item *beforep = previous(p); // 0 if p == list

    // if p is at end or list == 0 we can't swap p with afterp
    if (!afterp) return;

    p->next = afterp->next;
    afterp->next = p;

    if (!beforep)
        list = afterp;
    else
        beforep->next = afterp;
}

void SLList::swapBeforeAndAfter (Iterator loc)
{
    if (loc == begin() || loc == end())
        return;

    Item *p = loc.current;
    Item *afterp = p->next;
    Item *beforep = previous(p);
    Item *twoBeforep = previous(beforep);

    beforep->next = afterp->next;
    afterp->next = p;
    p->next = beforep;

    if (!twoBeforep)
        list = afterp;
    else
        twoBeforep->next = afterp;
}
