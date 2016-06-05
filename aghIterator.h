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
    aghContainer<T>* wskDoPoj;
    int ile;
    public:

        aghIterator()
        {
            wskDoPoj = NULL;
        }

//konstruktor kopiujacy napisz
        aghIterator(aghContainer<T>* nowy)
        {
            wskDoPoj = nowy;
            ile = 0;
        }

       /* ~aghIterator()
        {
            delete wskDoPoj;
        }
        aghIterator<T>(const aghIterator<T> &kopia)
        {
            this -> wskDoPoj = kopia -> wskDoPoj;
        }
*/
		T operator*()
		{
			return wskDoPoj -> at(ile);
		}

        T& current()
		{
			return wskDoPoj -> at(ile);
		}

		aghIterator& operator++()
		{
			wskDoPoj = wskDoPoj -> next;
			return *this;
		}

		aghIterator& operator++(T)
		{
		    if (ile < size())
			{
			    aghIterator tmp = *this;
                wskDoPoj = wskDoPoj -> next;
                return tmp;
			}
			else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

		aghIterator<T>& next() //trzeba sprawdzic czy poza zakres nie wychodizmy (ile < wskDoPoj->size()) czy (ile < wskDoPoj->size() - 1)
		{
            if (ile < wskDoPoj->size())
            {
                ++ile;
                return *this;
            }
            else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
            }
		}

        aghIterator<T>& prev() //trzeba sprawdzic czy poza zakres nie wychodizmy (ile < wskDoPoj->size()) czy (ile < wskDoPoj->size() - 1)
		{
            if (ile >= 0)
            {
                --ile;
                return *this;
            }
            else
            {
                throw aghException(0, "Index out of range", __FILE__, __LINE__);
               //  *this = NULL;
              //  --ile;
               // return *this;
            }
		}

		aghIterator first()
		{
		    aghIterator<T> zwracany;
		    zwracany.wskDoPoj = this->wskDoPoj;
		    zwracany.ile = 0;
			return zwracany;
		}

		aghIterator last()
		{
		    aghIterator<T> zwracany;
		    zwracany.wskDoPoj = this->wskDoPoj;
		    zwracany.ile = this->wskDoPoj->size()-1;
			return zwracany;
		}



		void atFirst()
		{
			ile = 0;
		}

		void atLast()
		{
			ile = size()-1;
		}

int size() const
    {
        return this -> wskDoPoj -> size() - ile;
    }
		aghIterator& operator= (const aghIterator& przypisana)
		{
			wskDoPoj = przypisana.wskDoPoj;
			return *this;
		}
        aghIterator& operator+= (const T& dodana)
		{
		    T pom = wskDoPoj->at(ile);
			wskDoPoj->replace(ile,dodana+pom);
			return *this;
		}
		T operator[] (const int &i)
		{
		    return wskDoPoj->at(ile+i);
		}

		bool operator==(const aghContainer<T>& i)
		{
			if (wskDoPoj == i.wskDoPoj)
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
