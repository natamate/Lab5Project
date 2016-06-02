#ifndef AGHITERATOR_H
#define AGHITERATOR_H
#include"aghContainer.h"

template <class T>
class aghIterator{
    //protected:
	/*	struct Node
		{
			aghContainer<T>* object;
			Node* next;
			Node* prev;
		};*/
    //private:
    public:
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

		aghIterator<T>& next() //trzeba sprawdzic czy poza zakres nie wychodizmy (ile < Pointer->size()) czy (ile < Pointer->size() - 1)
		{
            if (ile < Pointer->size())
            {
                ++ile;
                return *this;
            }
            else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

        aghIterator<T>& prev() //trzeba sprawdzic czy poza zakres nie wychodizmy (ile < Pointer->size()) czy (ile < Pointer->size() - 1)
		{
            if (ile < Pointer->size())
            {
                --ile;
                return *this;
            }
            else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

		aghIterator first()
		{
		    aghIterator<T> zwracany;
		    zwracany.Pointer = this->Pointer;
		    zwracany.ile = 0;
			return zwracany;
		}

		aghIterator last()
		{
		    aghIterator<T> zwracany;
		    zwracany.Pointer = this->Pointer;
		    zwracany.ile = this->Pointer->size()-1;
			return zwracany;
		}



		void atFirst()
		{
			ile = 0;
		}

		void atLast()
		{
			ile = Pointer->size()-1;
		}

		int size()
		{
			return Pointer->size()-2;
		}
		aghIterator& operator= (const aghIterator& i)
		{
			Pointer = i.Pointer;
			return *this;
		}

		T operator[] (const int &i)
		{
		    return Pointer->at(i);
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
