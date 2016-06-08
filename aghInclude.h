// File: aghInclude.h
// Author: Natalia Materek, Aleksander Lisiecki
// v 2.1 15.05.2016
// Plik zawiera deklaracje szablonu klasy aghVector
// wraz z implementacja metod klasy

#ifndef AGHINCLUDE_H
#define AGHINCLUDE_H
#include "aghException.h"
#include "aghContainer.h"
#include "aghIterator.h"
#include <iostream>
using namespace std;

template <class T>
class aghVector: public aghContainer<T>
{
public:
    T *tab;
    int sizeTab;
    int lastFree; //to zmienna przechowujaca indeks miejsca gdzie moze zostac wstawiony kolejny element, wykorzystywana m. in w metodzie append

    aghVector() //ten konstruktor przyjmuje wartosc 1 zeby pominac resize przy dodawaniu pierwszego elementu
    {
        sizeTab = 1;
        tab = new T [sizeTab];
        lastFree = 0;
    }

    aghVector(int newSizetab)
    {
        if (newSizetab >= 0)
        {
            sizeTab = newSizetab;
            tab = new T [sizeTab];
            lastFree = 0;
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

    aghVector<T> &operator= (aghVector<T> const &toCopy)
    {
        if (this == &toCopy)
        {
            return *this;
        }
        else
        {
            if (tab != NULL)
            {
                delete [] tab;
            }
            sizeTab = toCopy.sizeTab;
            lastFree = toCopy.lastFree;
            tab = new T [sizeTab];
            copyTab(toCopy.tab, tab, sizeTab);
            return *this;
        }
    }

    aghVector<T> (const aghVector<T> &toCopy)
    {
        sizeTab = toCopy.sizeTab;
        lastFree = toCopy.lastFree;
        delete [] tab;
        tab = new T [sizeTab];
        copyTab(toCopy.tab, tab, sizeTab);
    }

    aghVector<T> (const aghContainer<T> &ToCopy)
    {
        sizeTab = ToCopy.size();
        lastFree = 0;
        tab = new T [sizeTab];
        for (int i = 0; i < sizeTab; ++i)
        {
            this->append(ToCopy.at(i));
        }
    }

    void clear()
    {
        delete [] tab;
        sizeTab = 0;
        lastFree = 0;
    }

    ~aghVector()
    {
        clear();
    }

    //funkcja przepisuje zawartosc tablicy source do tablicy destination
    void copyTab(T *source, T *destination, int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            destination[i] = source[i];
        }
    }

    void resize(int tmpSize)
    {
        if (tmpSize >= 0)
        {
            aghVector<T> *tmpTab = new aghVector<T>(sizeTab);
            copyTab(tab, tmpTab -> tab, sizeTab);
            int tmpFree = lastFree;
            clear();
            lastFree = tmpFree;
            sizeTab = tmpSize;
            tab = new T [sizeTab];
            copyTab(tmpTab -> tab, tab, sizeTab);
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

    virtual bool insert(int place, T const &newValue)
    {
        if ((place >= 0) && (place <= sizeTab))
        {
            aghVector<T> *tmpTab = new aghVector<T>(sizeTab);
            copyTab(tab, tmpTab -> tab, sizeTab);
            sizeTab++;
            resize(sizeTab);
            for (int i = sizeTab; i > place; i--)
            {
                tab[i] = tab [i - 1];
            }
            tab[place] = newValue;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool replace(int place, T const &newValue)
    {
        if ((place >= 0) && (place <= sizeTab))
        {
            tab[place] = newValue;
            return true;
        }
        else
        {
            return false;
        }
    }

    aghContainer<T> &operator+=(T const &newValue)
    {
        append(newValue);
        return *this;
    }

    void append(T const &newValue)
    {
        if (lastFree < sizeTab)
        {
            tab[lastFree] = newValue;
            lastFree++;
        }
        else
        {
            resize(++sizeTab);
            tab[lastFree] = newValue;
            lastFree++;
        }
    }

    int size() const
    {
        int counter = 0;
        while (tab[counter] != 0)
        {
            counter ++;
        }
        return counter;
    }

    friend ostream &operator << (ostream &os, aghVector &vect)
    {
        for (int i = 0; i < vect.sizeTab; i++)
        {
            os << vect.tab[i] << ", ";
        }
        os << endl;
        return os;
    }

    aghVector<T> &operator<<(T const &newValue)
    {
        append(newValue);
        return *this;
    }

    aghVector<T> &operator<<(aghVector<T> const &right)
    {
        for (int i = 0; i < right.sizeTab; i++)
        {
            append(right.tab[i]);
        }
        return *this;
    }

    T &at(int place) const
    {
        if ((place >= 0) && (place <= size()))
        {
            return tab[place];
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

    bool remove(int place)
    {
        if ((place >= 0) && (place < sizeTab))
        {
            sizeTab--;
            for (int i = place; i < sizeTab; i++)
            {
                tab[i] = tab [i + 1];
            }
            resize(sizeTab);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (sizeTab == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int indexOf(T const &_value, int _from = 0) const
    {
        for (int i = _from; i < sizeTab; i++)
        {
            if (tab[i] == _value)
            {
                return i;
            }
        }
        return -1;
    }

    bool contains(T const &_value, int _from = 0) const
    {
        for (int i = _from; i < sizeTab; i++)
        {
            if (tab[i] == _value)
            {
                return true;
            }
        }
        return false;
    }

    bool operator==(aghVector<T> const &right)
    {
        if ((sizeTab != right.sizeTab) && (lastFree != right.lastFree))
        {
            return false;
        }
        for (int i = 0; i < sizeTab; i++)
        {
            if (tab[i] != right.tab[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(aghVector<T> const &right)
    {
        if ((sizeTab != right.sizeTab) && (lastFree != right.lastFree))
        {
            return true;
        }
        for (int i = 0; i < sizeTab; i++)
        {
            if (tab[i] != right.tab[i])
            {
                return true;
            }
        }
        return false;
    }

    T &operator[](int n) const
    {
        if ((n >= 0) && (n <= sizeTab))
        {
            return tab[n];
        }
        else
        {
            throw aghException(0, "Index out of range", __FILE__, __LINE__);
        }
    }

};

#endif




