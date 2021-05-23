#include <iostream>
#include <vector>
#include <list>

#ifndef DISJ_SET_HPP
#define DISJ_SET_HPP

class DisjSet
{
public:
    explicit DisjSet(int n);

    ~DisjSet()
    {
        if (K::DEBUG)
        {
            std::cout << __FILE__ << " destructor" << std::endl;
        }
    }

    int find(int x);

    void make_union(int x, int y);

    friend std::ostream &operator<<(std::ostream &out, const DisjSet &s)
    {

        for (int i = 0; i < s.size(); i++)
        {
            out << s[i] << " ";
        }
        return out;
    }

    int operator[](int i) const { return set[i]; }
    int size() const { return _size; }

private:
    int _size;
    std::vector<int> set;
};

#endif