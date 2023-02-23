#include <iostream>
#include <array>

using namespace std;


template <class T, std::size_t N>
struct Indexer
{

private:
    std::array<unsigned int, N> index;
    unsigned int cnt{0};
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
