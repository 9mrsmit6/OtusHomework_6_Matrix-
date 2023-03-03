#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <vector>
#include <map>

using ID    =std::vector<std::size_t>;

template<class T>
using MAP   =std::map<ID, T>;

template <std::size_t C, std::size_t N>
concept IndexConcept = (C<N);


template <std::size_t C, std::size_t N>
concept GetSetConcept = (C==N);



template <class T, std::size_t C, std::size_t N, T def>
struct Indexer
{
    Indexer
    (
            ID& indexVector_,
            MAP<T>& map_
    ):
        indexVector{indexVector_},
        map(map_)
    {
    }


    auto operator [](unsigned int i) requires IndexConcept<C,N>
    {
        indexVector.push_back(i);
        return Indexer<T,C+1,N, def>{indexVector, map};
    }

    auto operator =( const T& value) requires GetSetConcept<C,N>
    {
        if(value==def)
        {
            map.erase(indexVector);
        }
        else
        {
            map[indexVector]=value;
        }

        return Indexer<T,C,N, def>{indexVector, map};
    }

    operator T() const requires GetSetConcept<C,N>
    {

        if(map.contains(indexVector))
        {
            return map[indexVector];
        }
        else
        {
            return def;
        }
    }

    private:

    ID& indexVector;
    MAP<T>& map;
};


template <class T, std::size_t N, T def>
struct Matrix
{
    Matrix() = default;
    ~Matrix() = default;

    auto operator[](unsigned int i)
    {
        index.clear();
        index.push_back(i);
        return Indexer<T,1,N,def>{index, map};
    }

    std::size_t size()
    {
        return map.size();
    }

    auto begin()
    {
        return map.begin();
    }

    auto end()
    {
        return map.end();
    }


private:
    ID index;
    MAP<T> map;

};



#endif // MATRIX_HPP
