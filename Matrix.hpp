#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <array>
#include <map>

template <class T, std::size_t N, T def>
struct Matrix;

template <class T, std::size_t N, T def>
struct Indexer
{

    Indexer(Matrix<T,N,def>& matrix_):
        matrix{matrix_}
    {

    }

    ~Indexer() = default;

    Indexer& operator [](unsigned int i)
    {
        if(cnt<N)
        {
            index[cnt]=i;
            cnt++;
            std::cout<<"SAVE INDEX"<<std::endl;
        }
        return *this;
    }

    Indexer& operator =( T&& value)
    {
        if(cnt>=N)
        {
            matrix.setValue(std::forward<T>(value));
            std::cout<<"SAVE VAR"<<std::endl;
        }

        return *this;


    }

    operator T() const
    {
        if(cnt>=N)
        {
            std::cout<<"PUSH VAR"<<std::endl;
            return matrix.getValue();
        }

        return matrix.defV;
    }

    void startIndexing(unsigned int i)
    {
        cnt=0;
        index[cnt]=i;
        cnt++;
    }


private:
    friend class Matrix<T,N,def>;
    std::array<unsigned int, N> index;
    unsigned int cnt{0};
    Matrix<T,N,def>& matrix;
};


template <class T, std::size_t N, T def>
struct Matrix
{
    Matrix():
        indexer(*this)
    {

    }

    Indexer<T,N,def>& operator[](unsigned int i)
    {
        indexer.startIndexing(i);
        std::cout<<"START INDEXING"<<std::endl;
        return indexer;
    }




private:
    friend class Indexer<T,N,def> ;
    Indexer<T,N,def> indexer;
    std::map<std::array<unsigned int, N>, T> data;

    const T defV{def};

    void setValue(T&& value)
    {
        if(value==def)
        {
            data.erase(indexer.index);
        }
        else
        {
            data[indexer.index]=std::forward<T>(value);
        }
    }

    const T& getValue()
    {
        if(data.contains(indexer.index))
        {
            return data[indexer.index];
        }
        else
        {
            return defV;
        }
    }

};


#endif // MATRIX_HPP