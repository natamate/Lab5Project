//File: aghInclude.h
// Plik zawiera deklaracje klasy aghDlist i opis metod listy dwukierunkowej bazujacej na aghContainer
// Autor: N. Materek && A. Lisiecki
// v 1.2 do poprawki (powtorki kosu w niektorych metodach) bez wyciekow pamieci
// 21.05.2016
#include "aghContainer.h"
#include "aghElement.h"
#include "aghException.h"
#ifndef AGHDLIST_H
#define AGHDLIST_H

template <class T>
class aghDlist:public aghContainer<T>{
    typedef Element<T>* Iterator;
protected:
    Element<T> *Head;
    Element<T> *Tail;
public:

    aghDlist()
    {
        Head = NULL;
        Tail = NULL;
    }

    ~aghDlist()
    {
        clear();
    }

    Element<T>* front()
    {
            return Head;
    }

    Element<T>* back()
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

    void clear()
    {
        while (Head!= NULL)
        {
            Element<T>* tmp = this -> front();
            Element<T>* tmpNext = tmp -> next();
            delete tmp;
            Head = tmpNext;
        }
        Tail = NULL;
    }

    void append(T const& value)
    {
        if (Head == NULL)
        {
            Head = new Element<T>(value);
        }
        else if (Tail == NULL)
        {
            Tail = new Element<T>(Head, value);
            Head->setNext(Tail);
        }
        else //dodaj element na koniec
        {
            Element<T>* newElement = new Element<T>(Tail, value);
            Tail->setNext(newElement);
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

    T& at(int place) const
    {
        int conter = 0;
        if ((place >= 0) && (place <= size()))
        {
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

    aghDlist<T>& operator= (aghDlist<T> const& source)
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

    aghDlist<T>(aghDlist<T> const& toCopy)
    {
        if (!isEmpty())
        {
            clear();
        }
        for (Iterator i = toCopy.Head; i != NULL; i = i -> next())
        {
            append(i -> getValue());
        }
    }

    aghDlist<T> (aghContainer<T> const& toCopy)
    {
        int counter = 0;
        Head = NULL;
        Tail = NULL;
        while (counter < toCopy.size())
        {
           append(toCopy.at(counter));
           counter++;
        }
    }

    aghDlist<T>& operator<<(aghDlist<T> const& right)
    {
        for (Iterator i = right.Head; i != NULL; i = i -> next())
        {
            append(i -> getValue());
        }
        return *this;
    }

    aghDlist<T>& operator<<(T const& newValue)
    {
        append(newValue);
        return *this;
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
                Element<T>* tmp = Head;
                Element<T>* newElement = new Element<T>(newValue);
                tmp -> setPrev(newElement);
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
            Element<T>* tmpPrev = i;
            Element<T>* newElement = new Element<T>(newValue);
            Element<T>* tmpNext = tmpPrev -> next();
            newElement -> setNext(tmpNext);
            newElement -> setPrev(tmpPrev);
            tmpNext -> setPrev(newElement);
            tmpPrev -> setNext(newElement);
            return true;
        }
        else
        {
            return false;
        }
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

    friend ostream& operator<<(ostream& os, aghDlist<T> const& right)
    {
        if (right.Head != NULL)
        {
            os << "Head: " << right.Head -> getValue() << endl;
        }
        for (Iterator i = right.Head -> next(); i != NULL; i = i -> next())
        {
            os << i -> getValue() << ", ";
        }
        if (right.Tail != NULL)
        {
            os << "Tail: " << right.Tail -> getValue() << endl;
        }
        os << endl;
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
                while (counter < place)
                {
                    i = i -> next();
                   counter++;
                }
                Element<T> *removable = i;
                Element<T> *tmpPrevious = removable -> prev();
                Element<T> *tmpNext = removable -> next();
                tmpPrevious -> setNext(tmpNext);
                tmpNext -> setPrev(tmpPrevious);
                delete removable;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool contains(T const& _value, int _from) const
    {
        if ((_from >= 0) && (_from <= size()))
        {
            if (!Head)
            {
                Iterator i = Head;
            }
            else
            {
                return false;
            }
            int counter = 0;
            Iterator i = Head;
            while (counter != _from)
            {
                i = i -> next();
                counter++;
            }

            for (Iterator j = i; j != NULL; j = j -> next())
            {
                if (j -> getValue() == _value)
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }

    bool operator==(aghDlist<T> const& right)
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

    bool operator!=(aghDlist<T> const& right)
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

    aghDlist<T>& operator+=(T const& newValue)
    {
        append(newValue);
        return *this;
    }

    aghDlist<T>& operator+=(aghDlist<T> const& right)
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
        int counter = 0;
        if(Head == NULL)
        {
            return -1;
        }
        Iterator i = Head;
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
#endif // AGHDLIST_H
