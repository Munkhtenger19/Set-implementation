#include "set.h"

using namespace std;

void Set::insert(int e)
{
    unsigned int index;
    if(!search(e,index)){
        _vec.push_back(e);
        cnt_evens=evens();
    }
    else{
        throw ExistingElementException();
    }
}

void Set::remove(int d)throw (std::exception){
    unsigned int ind;
    if(search(d,ind)){
        _vec[ind] = _vec[_vec.size()-1];
        _vec.pop_back();
        cnt_evens=evens();
    }
    else{
        throw NonExistingElementException();
    }
}

bool Set::isIn(int c)const{
    unsigned int index;
    return search(c,index);
}

int Set::rand_elem() const throw (std::exception){
    if(!isEmpty()){
        srand((unsigned) (time(0)));
        int rand_num = rand() % (_vec.size());
        return _vec[rand_num];
    }
    else{
        throw EmptySetException();
    }
}

int Set::evens() const{
    int cnt=0;
    for(unsigned int i=0; i<_vec.size(); i++){
        if(_vec[i] % 2==0) cnt++;
    }
    return cnt;
}

bool Set::search(int k, unsigned int &ind) const{
    bool g = false;
    for(unsigned int i=0; !g && i<_vec.size(); i++){
        g = (_vec[i]==k);
        ind = i;
    }
    return g;
}

vector<int> Set::getSet() const{
    vector<int> v;
    for(unsigned i=0; i<_vec.size(); ++i){
        v.push_back(_vec[i]);
    }
    return v;
}

