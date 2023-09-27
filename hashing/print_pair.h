#include <utility>
#include <iostream>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T,U>& p){
    os << "(" << p.first << "," << p.second << ")";
    return os;
}