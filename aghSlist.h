//File aghSlist.h
//Autor: N. Materek && A. Lisiecki
//Plik zawiera deklaracje klasy aghSlist ktora jest implementacja listy jednokierunkowej dziedziczacej po aghContainer

#include "aghContainer.h"
#include "aghElementS.h"
#include "aghException.h"
#ifndef AGHSLIST_H
#define AGHSLIST_H

template<class T>
class aghSlist:public aghContainer<T>{
    typedef ElementS<T>* Iterator;
protected:
    ElementS<T>* Head;
    ElementS<T>* Tail;
public:

    aghSlist()
    {
        Head = NULL;
        Tail = NULL;
    }

    ~aghSlist()
    {
        clear();
    }

    void clear()
    {
        while (Head != NULL)
        {
                ElementS<T>* tmp = Head;
                tmp = tmp -> next();
                delete(Head);
                Head = tmp;
        }
        Tail = NULL;
    }

    ElementS<T>* front()
    {
        return Head;
    }

    ElementS<T>* back()
    {
        if (Tail == NULL)
        {
            return Head;
        }
        else
        {
           return Tail;
        }
    }

    bool isEmpty()
    {
        if (Head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void append(T const& newValue)
    {
       if (Head == NULL)
        {
            Head = new ElementS<T>(newValue);
            Head -> setNext(Tail);
        }
        else if ((Head != NULL) && (Tail == NULL))
        {
            Tail = new ElementS<T>(newValue);
            Head -> setNext(Tail);
        }
        else //dodaj element na koniec
        {
            ElementS<T>* newElement = new ElementS<T>(newValue);
            Tail -> setNext(newElement);
            Tail = newElement;
        }
    }

    int size() const
    {
        int counter = 0;
        for (Iterator i = Head; i != NULL; i = i -> next())
        {
            counter ++;
        }
        return counter;
    }

    friend ostream& operator<<(ostream& os, aghSlist<T> const& right)
    {
        if (right.Head != NULL)
        {
            os << "Head: " << right.Head -> getValue() << " ... ";
            for (Iterator i = right.Head -> next(); i != NULL; i = i -> next())
            {
                os << i -> getValue() << ", ";
            }
            os << endl;
        }
        else
        {
            os << "Lista jest pusta" << endl;
        }
        return os;
    }

    bool insert(int place, T const& newValue)
    {
        if ((place >= 0) && (place <= size()))
        {
            if (isEmpty())
            {
                append(newValue);
                return true;
            }
            if (place == 0)
            {
                ElementS<T>* tmp = Head;
                ElementS<T>*  newElement = new ElementS<T>(newValue);
                newElement -> setNext(tmp);
                Head = newElement;
                if (tmp -> next() == NULL)
                {
                    Tail = tmp;
                }
                return true;
            }
            Iterator i = this -> front();
            int counter = 1;
            while (counter < place)
            {
                i = i -> next();
                counter++;
            }
            if (i -> next() == NULL)
            {
                append(newValue);
                return true;
            }
            ElementS<T>* tmp = i;
            ElementS<T>* newElement = new ElementS<T>(newValue);
            ElementS<T>* tmp2 = tmp -> next();
            newElement -> setNext(tmp2);
            tmp -> setNext(newElement);
            return true;
        }
        else
        {
            return false;
        }
    }

    T& at(int place) const
    {
        if ((place >= 0) && (place <= size()))
        {
            int counter = 0;
            for (Iterator i = Head; i != NULL; i = i->next())
            {
                if (counter == place)
                {
                    return i -> data;
                }
                counter++;
            }
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

    aghSlist<T>& operator= (aghSlist<T> const& source)
    {
        if (this == &source)
		{
		    return *this;
		}
        else
        {
            if (!isEmpty())
            {
                 clear();
            }
            Iterator i = source.Head;
            while (i != NULL)
            {
                this -> append(i -> getValue());
                i = i -> next();
            }
            return *this;
        }
    }

    aghSlist<T>(const aghSlist<T> & toCopy)
    {
        if (!isEmpty())
        {
            Head = NULL;
        }
        for (Iterator i = toCopy.Head; i != NULL; i = i -> next())
        {
            append(i -> getValue());
        }
    }

    aghSlist<T> (const aghContainer<T> &toCopy)
    {
        int counter = 0;
        Head = NULL;
        Tail = NULL;
        while (counter < toCopy.size())
        {
           append(toCopy.at(i));
           counter++;
        }
    }

    aghSlist<T>& operator<<(aghSlist<T> const& right)
    {
        clear();
        for (Iterator i = right.Head; i != NULL; i = i -> next())
        {
            append(i -> getValue());
        }
        return *this;
    }

    aghSlist<T>& operator<<(T const& newValue)
    {
        append(newValue);
        return *this;
    }

    bool replace(int place, T const& newValue)
    {
        if ((place >= 0) && (place <= size()))
        {
            int counter = 0;
            Iterator i = this -> front();
            while (counter < place)
            {
                i = i -> next();
                counter++;
            }
            i -> setValue(newValue);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int place)
    {
        if (place >= 0 && place <= size())
        {
            if (isEmpty())
            {
                return false;
            }
            else
            {
                if ((Head != NULL) && (Tail == NULL))
                {
                    Head = NULL;
                    return true;
                }
                else if ((Head != NULL) && (Head -> next() == Tail) && (Tail != NULL))
                {
                    Tail = NULL;
                    return true;
                }
                int counter = 0;
                Iterator i = this -> front();
                while (counter < place - 1)
                {
                    i = i -> next();
                    counter++;
                }
                ElementS<T> *tmpPrevious = i;
                ElementS<T> *removable = i -> next();
                ElementS<T> *tmpNext = removable -> next();
                tmpPrevious -> setNext(tmpNext);
                delete removable;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool contains(T const& _value, int _from = 0) const
    {
        for (Iterator i = Head; i != NULL; i = i -> next())
        {
            if (i -> getValue() == _value)
            {
                return true;
            }
        }
        return false;
    }

    bool operator==(aghSlist<T> const& right)
    {
        if (this -> size() != right.size())
        {
            return false;
        }
        else
        {
            Iterator j = right.Head;
            for (Iterator i = this -> front(); i != NULL; i = i -> next())
            {
                if (i -> getValue() != j -> getValue())
                {
                    return false;
                }
                j = j -> next();
            }
            return true;
        }
    }

    bool operator!=(aghSlist<T> const& right)
    {
        if (this -> size() != right.size())
        {
            return true;
        }
        else
        {
            Iterator j = right.Head;
            for (Iterator i = this -> front(); i != NULL; i = i -> next())
            {
                if (i -> getValue() != j -> getValue())
                {
                    return true;
                }
                j = j -> next();
            }
            return false;
        }
    }

    aghSlist<T>& operator+=(T const& newValue)
    {
        append(newValue);
        return *this;
    }

    aghSlist<T>& operator+=(aghSlist<T> const& right)
    {
        for (Iterator i = right.Head; i != NULL; i = i -> next())
        {
            append(i -> getValue());
        }
        return *this;
    }

    T& operator[](int n) const
    {
        if ((n >= 0) && (n <= size()))
        {
            return at(n);
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

    int indexOf(T const& _value, int _from) const
    {
        if(Head == NULL)
        {
            return -1;
        }
        Iterator i = Head;
        int counter = 0;
        while (counter < _from)
        {
            if (i -> next() != NULL)
            {
                i = i -> next();
            }
            counter ++;
        }
        if (i -> getValue() == _value)
        {
            return counter;
        }
        for (Iterator j = i; j != NULL; j = j -> next())
        {
            if (j -> getValue() == _value)
            {
                return counter;
            }
            counter++;
        }
        return -1;
    }
};
#endif // AGHSLIST_H
