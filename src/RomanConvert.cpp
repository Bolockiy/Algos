#include "RomanConvert.h"
#include <iostream>
bool RomanHelper::check(unsigned int* _number)
{
    if (m.find(*_number) != m.end())
        return true;
    return false;
}
void RomanHelper::alg(unsigned int _ch, std::string& _str, int _minus)
{
    if (_ch == 0)
        return;
    int count = 0;
    while (true)
    {
        if (check(&_ch))
        {
            _str.insert(0, m.at(_ch));
            int pos = _str.find_first_of(m.at(_ch));
            if (count == 0)
            {
                break;
            }
            for (int i{ 0 }; i < count; ++i)
            {
                _str.insert(pos + 1, m.at(_minus));
            }
            break;
        }
        _ch -= _minus;
        ++count;
    }
}
std::string RomanHelper::to_roman(unsigned int n) {
    if (n == 0)
        return std::string();
    if (check(&n))
    {
        return m.at(n);
    }
    std::string str = std::to_string(n);
    std::string res;
    const int ln = str.length();
    int i = ln - 1;
    int minus = 1;
    int a = n % 10;
    while (true)
    {
        if (n == 0)
            break;
        str = std::to_string(n);
        alg(a, res, minus);
        str[i] = '0';
        if (i == 0)
            break;
        std::string tm = str.substr(i - 1, ln);
        a = std::stoi(tm);
        n = std::stoi(str);
        minus *= 10;
        --i;
    }
    return res;
}
int RomanHelper::from_roman(std::string rn) {
    std::map<char, int> roman_to_int{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int prev_value = 0;

    for (auto it = rn.rbegin(); it != rn.rend(); ++it) {
        int current_value = roman_to_int[*it];

        if (current_value < prev_value) {
            total -= current_value;
        }
        else {
            total += current_value;
        }

        prev_value = current_value;
    }

    return total;
}