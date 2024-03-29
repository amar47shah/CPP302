/*
 * DLList.h
 *
 *  Created on: Oct 12, 2012
 *      Author: amar
 */

#ifndef DLLIST_H_
#define DLLIST_H_

template<typename Object>
class DLList
{
    private:
        struct Node
        {
                Object data;
                Node *prev;
                Node *next;

                Node(const Object & d = Object(), Node *p = NULL, Node *n = NULL) :
                    data(d), prev(p), next(n)
                {
                }
        };

    public:
        class const_iterator
        {
            public:
                const_iterator() :
                    current(NULL)
                {
                }

                const Object & operator*() const
                {
                    return retrieve();
                }

                const_iterator & operator++()
                {
                    current = current->next;
                    return *this;
                }

                const_iterator operator++(int)
                {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                const_iterator & operator--()
                {
                    current = current->prev;
                    return *this;
                }

                const_iterator operator--(int)
                {
                    const_iterator old = *this;
                    --(*this);
                    return old;
                }

                bool operator==(const const_iterator & rhs) const
                {
                    return current == rhs.current;
                }
                bool operator!=(const const_iterator & rhs) const
                {
                    return !(*this == rhs);
                }

            protected:
                Node *current;

                Object & retrieve() const
                {
                    return current->data;
                }

                const_iterator(Node *p) :
                    current(p)
                {
                }

                friend class DLList<Object> ;
        };
        class iterator : public const_iterator
        {
            public:
                iterator()
                {
                }

                Object & operator*()
                {
                    return this->retrieve();
                }

                const Object & operator*() const
                {
                    return const_iterator::operator*();
                }

                iterator & operator++()
                {
                    this->current = this->current->next;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }

                iterator & operator--()
                {
                    this->current = this->current->prev;
                    return *this;
                }

                iterator operator--(int)
                {
                    iterator old = *this;
                    --(*this);
                    return old;
                }

            protected:
                iterator(Node *p) :
                    const_iterator(p)
                {
                }

                friend class DLList<Object> ;
        };

    public:
        DLList()
        {
            init();
        }

        ~DLList()
        {
            clear();
            delete head;
            delete tail;
        }

        DLList(const DLList & rhs)
        {
            init();
            *this = rhs;
        }

        const DLList & operator=(const DLList & rhs)
        {
            if (this == &rhs)
                return *this;
            clear();
            for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
                push_back(*itr);
            return *this;
        }

        iterator begin()
        {
            return iterator(head->next);
        }

        const_iterator begin() const
        {
            return const_iterator(head->next);
        }

        iterator end()
        {
            return iterator(tail);
        }

        const_iterator end() const
        {
            return const_iterator(tail);
        }

        int size() const
        {
            return theSize;
        }

        bool empty() const
        {
            return size() == 0;
        }

        void clear()
        {
            while (!empty())
                pop_front();
        }

        Object & front()
        {
            return *begin();
        }
        const Object & front() const
        {
            return *begin();
        }
        Object & back()
        {
            return *--end();
        }
        const Object & back() const
        {
            return *--end();
        }
        void push_front(const Object & x)
        {
            insert(begin(), x);
        }
        void push_back(const Object & x)
        {
            insert(end(), x);
        }
        void pop_front()
        {
            erase(begin());
        }
        void pop_back()
        {
            erase(--end());
        }
        // Insert x before itr.
        iterator insert(iterator itr, const Object & x)
        {
            Node *p = itr.current;
            theSize++;
            return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
        }
        // Erase item at itr.
        iterator erase(iterator itr)
        {
            Node *p = itr.current;
            iterator retVal(p->next);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;

            return retVal;
        }
        iterator erase(iterator start, iterator end)
        {
            for (iterator itr = start; itr != end;)
                itr = erase(itr);

            return end;
        }

        const_iterator find(const_iterator start, const_iterator end, const Object& x)
        {
            const_iterator iter = start;
            while (iter != end && *iter != x)
                iter++;
            //cout << *iter << endl;
            return iter;
        }


        void swapWithNextDLL(const_iterator itr)
        {
            Node *p = itr.current;
            Node *beforep, *afterp;
            beforep = p->prev;
            afterp = p->next;

            p->next = afterp->next;
            beforep->next = afterp;
            afterp->next = p;

            p->next->prev = p;
            p->prev = afterp;
            afterp->prev = beforep;

        }

        void swapBeforeAndAfter(const_iterator itr)
        {
            if (itr != begin() && itr != end())
            {
                        Node *p = itr.current;
                        Node *beforep, *afterp, *twoBeforep, *twoAfterp;
                        beforep = p->prev;
                        afterp = p->next;
                        twoBeforep = beforep->prev;
                        twoAfterp = afterp->next;

                        twoBeforep->next = afterp;
                        afterp->prev = twoBeforep;
                        afterp->next = p;
                        p->prev = afterp;
                        p->next = beforep;
                        beforep->prev = p;
                        beforep->next = twoAfterp;
                        twoAfterp->prev = beforep;
            }
        }


    private:
        int theSize;
        Node *head;
        Node *tail;
        void init()
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
};



#endif /* DLLIST_H_ */
