#ifndef AGHITERATOR_H
#define AGHITERATOR_H
#include"aghContainer.h"

template <class T>
class aghIterator{
public:
    aghContainer<T>* pointerToContainer;
    int presentElementNumber;

    aghIterator()
    {
       pointerToContainer  = NULL;
    }

    aghIterator(aghContainer<T>* newIter)
    {
        pointerToContainer = newIter;
        presentElementNumber = 0;
    }

    aghIterator<T> &operator= (aghIterator<T> const &assignedIter)
    {
        if (this == &assignedIter)
        {
            return *this;
        }
        else
        {
            presentElementNumber = assignedIter.presentElementNumber;
            pointerToContainer = assignedIter.pointerToContainer;
            return *this;
        }
    }
    T& current()
    {
        return pointerToContainer -> at(presentElementNumber);
    }

    aghIterator& next()
    {
        presentElementNumber ++;
        return *this;
    }

    aghIterator& prev()
    {
        presentElementNumber --;
        return *this;
    }

    aghIterator first()
    {
        aghIterator<T> returnedIer;
        returnedIer.pointerToContainer = this->pointerToContainer;
        returnedIer.presentElementNumber = 0;
        return returnedIer;
    }

    aghIterator last()
    {
        aghIterator<T> returnedIer;
        returnedIer.pointerToContainer = this->pointerToContainer;
        returnedIer.presentElementNumber = this->pointerToContainer->size()-1;
        return returnedIer;
    }

     aghIterator& atFirst()
    {
        presentElementNumber = 0;
        return *this;
    }

    aghIterator& atLast()
    {
        presentElementNumber = pointerToContainer->size()-1;
        return *this;
    }

    int size() const
    {
        return this -> pointerToContainer -> size() - presentElementNumber;
    }

    const T& operator[] (int shiftIter) const
    {
        return pointerToContainer->at(presentElementNumber+shiftIter);
    }

    operator int ()
    {
        if ((presentElementNumber < 0 ) || (presentElementNumber > this -> size()))
        {
            return NULL;
        }
        else
        {
            return 1;
        }
    }

    T& operator [] (int shiftIter)
    {
        return pointerToContainer->at(presentElementNumber+shiftIter);
    }

    const T& operator*() const
    {
        return pointerToContainer -> at(presentElementNumber);
    }

    T& operator* ()
    {
        return pointerToContainer -> at(presentElementNumber);
    }

    aghIterator operator+(int shiftIter)
    {
        aghIterator<T> returnedIer = *this;
        returnedIer.presentElementNumber = presentElementNumber + shiftIter;
        return returnedIer;
    }

    aghIterator operator +=(int shiftIter)
    {
        presentElementNumber = presentElementNumber + shiftIter;
        return *this;
    }

    aghIterator operator -=(int shiftIter)
    {
        presentElementNumber = presentElementNumber - shiftIter;
        return *this;
    }

    aghIterator operator-(int shiftIter)
    {
        aghIterator<T> returnedIer = *this;
        returnedIer.presentElementNumber = presentElementNumber - shiftIter;
        return returnedIer;
    }
		aghIterator& operator++()
		{
			presentElementNumber++;
			return *this;
		}

		aghIterator operator++(int)
		{
            aghIterator<T> returnedIer = *this ;
             presentElementNumber ++ ;
             return returnedIer;
        }
        		aghIterator& operator--()
		{
			presentElementNumber--;
			return *this;
		}

		aghIterator operator--(int)
		{
            aghIterator<T> returnedIer = *this ;
             presentElementNumber -- ;
             return returnedIer;
        }
        bool operator==(const aghIterator& comperedIter)
        {
            if (pointerToContainer->at(presentElementNumber) == comperedIter.pointerToContainer->at(comperedIter.presentElementNumber))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator!=(const aghIterator& comperedIter)
        {
            if (pointerToContainer->at(presentElementNumber) != comperedIter.pointerToContainer->at(comperedIter.presentElementNumber))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
#endif
