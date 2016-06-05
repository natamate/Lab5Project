#ifndef AGHITERATOR_H
#define AGHITERATOR_H
#include"aghContainer.h"

template <class T>
class aghIterator{
public:
    aghContainer<T>* wsk;
    int ile;

    aghIterator()
    {
        wsk = NULL;
    }

    aghIterator(aghContainer<T>* nowy)
    {
        wsk = nowy;
        ile = 0;
    }

    aghIterator<T> &operator= (aghIterator<T> const &w)
    {
        if (this == &w)
        {
            return *this;
        }
        else
        {
            ile = w.ile;
            wsk = w.wsk;
            return *this;
        }
    }
    //Test 1
    T& current()
    {
        return wsk -> at(ile);
    }

    aghIterator<T>& next()
    {
        ile ++;
        return *this;
    }

    aghIterator<T>& prev()
    {
        ile --;
        return *this;
    }

    aghIterator first()
    {
        aghIterator<T> zwracany;
        zwracany.wsk = this->wsk;
        zwracany.ile = 0;
        return zwracany;
    }

    aghIterator last()
    {
        aghIterator<T> zwracany;
        zwracany.wsk = this->wsk;
        zwracany.ile = this->wsk->size()-1;
        return zwracany;
    }

    void atFirst()
    {
        ile = 0;
    }

    void atLast()
    {
        ile = wsk->size()-1;
    }

    int size() const
    {
        return this -> wsk -> size() - ile;
    }

    const T& operator[] (int i) const
    {
        return wsk->at(ile+i);
    }

    operator int ()
    {
        if ((ile < 0 ) || (ile > this -> size()))
        {
            return NULL;
        }
        else
        {
            return 1;
        }
    }

    T& operator [] (int i)
    {
        return wsk->at(ile+i);
    }

    const T& operator*() const
    {
        return wsk -> at(ile);
    }

    T& operator* ()
    {
        return wsk -> at(ile);
    }

    aghIterator& operator+(int i)
    {
        int tmp = ile + i;
        aghIterator <T> kopia = *this;
        while (ile < tmp)
            kopia = kopia.next();
        return kopia;
    }

};
#endif
