#ifndef SET_H
#define SET_H

#include <exception>
#include <iostream>
#include <vector>
#include <time.h>
#include "read.hpp"
#include <string>

inline bool valid(int a){return true;}

class Set{
    public:
        Set(): cnt_evens(0){
            setEmpty();
        }
        friend std::istream& operator>>(std::istream& s, int& e)
        {
            e=read("Element: ","Integer is needed!",valid);
            s>>e;
            return s;
        }
        friend std::ostream& operator<<(std::ostream& s, const Set& e)
        {
            for(int x : e._vec){
                s<<x<<" ";
            }
            return s;
        }
        class NonExistingElementException : public std::exception{};
        class ExistingElementException : public std::exception{};
        class EmptySetException : public std::exception{};

        void setEmpty(){_vec.clear();};
        int count() const {return _vec.size();}
        void insert(int a);
        void remove(int b) throw(std::exception);
        bool isEmpty()const {return _vec.size()==0;}
        bool isIn(int c)const;
        int rand_elem()const throw(std::exception);
        int evens()const;
        int getEvens(){return cnt_evens;}

        std::vector<int> getSet() const;
        bool getSearch(int x,unsigned int& ano) const{return search(x, ano);}

    private:
        std::vector<int> _vec;
        bool search(int m, unsigned int &ind) const;
        int cnt_evens;

};
#endif // SET_H
