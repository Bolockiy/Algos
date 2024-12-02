#include <map>
#include <string>
#include <algorithm>
#pragma once
class RomanHelper {
    std::map<int, std::string> m{ {1000,"M"},{900,"CM"},{500,"D"},
        {400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},
        {9,"IX"},{5,"V"},{4,"IV"},{ 1,"I"},{2,"II"},{3,"III"},
        {6,"VI"},{7,"VII"},{8,"VIII"} };
public:
    bool check(unsigned int* _number);
    void alg(unsigned int _ch, std::string& _str, int _minus);
    std::string to_roman(unsigned int n);
    int from_roman(std::string rn);
};