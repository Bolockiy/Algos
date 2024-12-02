#include <iostream>
#include "RomanConvert.h"
#include "Algos.h"
int main()
{
    std::setlocale(LC_ALL, "RUS");
    push(1,"One");
    push(2,"Two");
    auto returnVector = vecRet();
    std::cout<<returnVector.size() << "\n";
    for (auto&& it : returnVector)
    {
        push(it.first,it.second);
    }

    std::cout<<duplicate_encoder(" ( ( )")<<"\n";
    countWorlds("One TWO!");
    for (auto i = worlds.begin(); i != worlds.end(); ++i)
    {
        std::cout << i->first << ": " << i->second << "\n";
    }
    std::vector<int> vect{ 1, 0, 1, 2, 0, 1, 3 };
    vect = move_zeroes(vect);
    for (int i{}; i < vect.size(); ++i)
        std::cout << vect[i] << " ";
    RomanHelper v;
    std::cout << v.to_roman(1990) << "\n";
    std::cout << v.to_roman(2008) << "\n";
    std::cout << v.to_roman(1666) << "\n";

    std::map<int, std::string> pa{};
    pa.emplace(255, "30");
    std::cout << fact(5);
    std::vector<int> vec1{ 3,66,44,11,88,55,43,876,12,345,76,222 };
    bublesort(vec1);
    for (int i{}; i < vec1.size() - 1; ++i)
        std::cout << vec1[i] << " ";
}
