#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>

class Printer
{
public:
    static std::string printerError(const std::string& s)
        {
        const std::string alph = "abcdefghjijklm";
        std::string res;
            int count = 0;
            for (char it : s)
            {
                if (alph.find(it) == std::string::npos)
                    ++count;
            }
            res += std::to_string(count) + "/" + std::to_string(s.length());
            return res;
        }
};

std::vector<std::pair<int,std::string>> Texts;

int positive_sum(const std::vector<int>& arr) {
    int sum = 0;
    if (!arr.empty())
    {
        for (auto&& it : arr)
            if (it >= 0)
                sum += it;
    }
    return sum;
}
void push(const int num, const std::string& _str)
{
    Texts.emplace_back(std::make_pair(num, _str));
}
std::vector<std::pair<int, std::string>>& vecRet()
{
    return Texts;
}

std::string duplicate_encoder(const std::string& word) {
    std::string word2 = word;
    std::transform(word2.begin(), word2.end(), word2.begin(), [](unsigned char c) {return std::tolower(c); });
    std::map<char,int> Characters;
    for (auto& it : word2)
    {
        ++Characters[it];
    }
    std::string wordres = "";
    for (int i{};i< word2.size();++i)
    {
        if (Characters.at(word2[i]) >= 2)
            wordres += ')';
        else
            wordres += '(';
    }
    return wordres;
}

std::string bool_to_word(bool value)
{
    return value?"Yes":"No";
}
template <typename Func>
void search(Func oper)
{
}
void binary_search(std::vector<int>& vec, int key)
{
    if (vec.empty())
        return;
    int left = 0;
    int right = vec.size() - 1;
    int mid = (right + left) / 2;
    while (true)
    {
        if (vec[mid] == key)
        {
            std::cout << "found" << std::endl;
            return;
        }
        if (vec[mid] > key)
            mid = --right;
        else if (vec[mid] < key)
            mid = ++left;
    }
}
template <typename T>
void quicksort(std::vector<T>& vec, size_t left, size_t right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int pivot = vec[(left + right) / 2];
    while (i <= j)
    {
        while (vec[i] < pivot)
            ++i;
        while (vec[j] > pivot)
            --j;
        if (i <= j)
        {
            std::swap(vec[i], vec[j]);
            ++i;
            --j;
        }
    }
    quicksort(vec, left, j);
    quicksort(vec, i, right);
}

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

void bublesort(std::vector<int>& vec)
{
    for (int i{}; i < vec.size(); ++i)
        for (int j{}; j < vec.size() - i - 1; ++j)
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
}

std::vector<int> move_zeroes(std::vector<int>& input) {
    std::vector<int> vec = std::move(input);
    for (int i{}; i < vec.size(); ++i)
        for (int j{}; j < vec.size() - i - 1; ++j)
            if (vec[j] == 0)
                std::swap(vec[j], vec[j + 1]);
    return vec;
}
std::map<std::string, int> worlds;
std::list<std::string> _vec;
void countWorlds(const std::string& _text)
{
    // auto it = _text.begin();
    std::string str;
    int count = 0;
    for (const auto& it : _text)
    {
        if (it == ' ' || it == '.' || it == '!')
        {
            if (str.empty())
                continue;
            if (worlds.find(str) != worlds.end())
            {
                worlds.emplace(str, ++worlds.at(str));
                str.clear();
                continue;
            }
            worlds.emplace(str, ++count);
            count = 0;
            str.clear();
            continue;
        }
        else if (it == ',' || it == '(' || it == ')')
            continue;
        str += it;
    }
}
template <typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
    if (input.empty())
        return input;
    std::list<T> res;
    res.splice(res.begin(), res, input.end());
    const T piv = std::move(res.front());
}