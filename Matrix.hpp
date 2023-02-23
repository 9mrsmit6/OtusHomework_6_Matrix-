#ifndef MATRIX_HPP
#define MATRIX_HPP

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
        }
        return *this;
    }

    Indexer& operator =( const T& value)
    {
        if(cnt>=N)
        {
            matrix.setValue(value);
        }

        return *this;


    }

    operator T() const
    {
        if(cnt>=N)
        {
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

    ~Matrix() = default;

    Indexer<T,N,def>& operator[](unsigned int i)
    {
        indexer.startIndexing(i);
        return indexer;
    }

    std::size_t size()
    {
        return data.size();
    }

    const T& getFirst()
    {
        iterator=data.cbegin();
        return *iterator;
    }

    auto begin()
    {
        return data.begin();
    }

    auto end()
    {
        return data.end();
    }




private:
    friend class Indexer<T,N,def> ;
    Indexer<T,N,def> indexer;
    std::map<std::array<unsigned int, N>, T> data;

    decltype(data.cbegin()) iterator;

    const T defV{def};

    void setValue(const T& value)
    {
        if(value==def)
        {
            data.erase(indexer.index);
        }
        else
        {
            data[indexer.index]=value;
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
