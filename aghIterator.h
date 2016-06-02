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
    int ile;
    public:

        aghIterator()
        {
            Pointer = NULL;
        }

//konstruktor kopiujacy napisz
        aghIterator(aghContainer<T>* nowy)
        {
            Pointer = nowy;
            ile = 0;
        }

       /* ~aghIterator()
        {
            delete Pointer;
        }

        aghIterator<T>(const aghIterator<T> &kopia)
        {
            this -> Pointer = kopia -> Pointer;
        }
*/
		T operator*()
		{
			return Pointer -> at(ile);
		}

        T current()
		{
			return Pointer -> at(ile);
		}

		aghIterator& operator++()
		{
			Pointer = Pointer -> next;
			return *this;
		}

		aghIterator& operator++(T)
		{
		    if (ile < size())
			{
			    aghIterator tmp = *this;
                Pointer = Pointer -> next;
                return tmp;
			}
			else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

		T next()
		{
		    ile++;
			return Pointer -> at(ile);
		}

		T prev()
		{
		    if (ile > 0)
		    {
		        ile--;
                return Pointer -> at(ile);
		    }
		    else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

		aghIterator* first()
		{
			return Pointer;
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

		bool operator==(const aghContainer<T>& i)
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
