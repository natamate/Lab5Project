#ifndef AGHITERATOR_H
#define AGHITERATOR_H
#include"aghContainer.h"

template <class T>
class aghIterator{
    protected:
	/*	struct Node
		{
			aghContainer<T>* object;
			Node* next;
			Node* prev;
		};*/
    private:
    aghContainer<T>* Pointer;
    T data;
    public:

        aghIterator()
        {
            Pointer = NULL;
        }

//konstruktor kopiujacy napisz
        aghIterator(aghContainer<T>* nowy)
        {
            Pointer = nowy;
            data = nowy -> at(0);
        }

       /* aghIterator(aghContainer NowyElement)
        {
            Pointer = NowyElement[0];
        }*/


		T operator*()
		{
			return Pointer.data;
		}

        T current()
		{
			//Pointer -> data = value;
			return Pointer -> data;
		}

		aghIterator& operator++()
		{
			Pointer = Pointer -> next;
			return *this;
		}

		aghIterator& operator++(T)
		{
			aghIterator tmp = *this;
			Pointer = Pointer -> next;
			return tmp;
		}

		aghIterator* next()
		{
			return Pointer -> next;
		}

		aghIterator* prev()
		{
			return Pointer -> prev;
		}

		aghIterator* first()
		{
			if (Pointer -> prev == NULL)
			{
				return Pointer;
			}
			else
			{
				while (Pointer -> prev != NULL)
				{
					Pointer = Pointer -> prev;
				}
				return Pointer;
			}
		}

		aghIterator* last()
		{
			if (Pointer -> next == NULL)
			{
				return Pointer;
			}
			else
			{
				while (Pointer -> next != NULL)
				{
					Pointer = Pointer -> next;
				}
				return Pointer;
			}
		 }



		void atFirst()
		{
			while (Pointer -> prev != NULL)
			{
				Pointer = Pointer -> prev;
			}
		}

		void atLast()
		{
			while (Pointer -> next != NULL)
			{
				Pointer = Pointer -> next;
			}
		}

		int size()
		{
			int licznik = 0;
			while (Pointer != NULL)
			{
				licznik ++;
				Pointer++;
			}
			return licznik;
		}

		//przypisanie
		aghIterator& operator= (const aghIterator& i)
		{
			Pointer = i.Pointer;
			return *this;
		}

		bool operator==(const aghIterator& i)
		{
			if (Pointer == i.Pointer)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator != (const aghIterator& i)
		{
			return !(*this == i);
		}


};
#endif
