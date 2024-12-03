#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>
#include <array>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <numeric>
#include <functional>
#include <tchar.h>
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <math.h>
long int findNextSquare(long int sq) {
    //std::string str = std::to_string(std::sqrt(sq)); 
    long long squareRootN = (long long)round((sqrt(sq)));
    if (squareRootN * squareRootN != sq) {
        return -1;
    }
    int next = floor(std::sqrt(sq))+1;
    return next * next;
}

std::string reverse_words(std::string str)
{
    std::string result;
    std::string word;
    size_t start = 0, end = 0;

    while (end < str.size()) {
        if (str[end] == ' ') {
            if (start < end) {
                word = str.substr(start, end - start);
                std::reverse(word.begin(), word.end());
                result += word;
            }
            result += ' ';
            start = end + 1;
        }
        ++end;
    }

    if (start < end) {
        word = str.substr(start, end - start);
        std::reverse(word.begin(), word.end());
        result += word;
    }
    return result;
}
std::string bmi(double w, double h)
{
    double bmi = w / (h * h);
    if (bmi <= 18.5)
        return "Underweight";
    else if (bmi > 18.5 && bmi <= 25.0)
        return "Normal";
    else if (bmi > 25.0 && bmi <= 30.0)
        return "Overweight";
    else if (bmi > 30)
        return "Obese";
}
std::string findNeedle(const std::vector<std::string>& haystack)
{
    auto pos = std::find(haystack.begin(), haystack.end(), "needle");
    if (pos != haystack.end())
    {
        size_t index = std::distance(haystack.begin(), pos);
        return "found the needle at position "+std::to_string(index);
    }
    return "found the needle at position ";
}
int summation(int num) {
    if (num == 0)
        return 0;
    return num+summation(num - 1);
}
uint64_t descendingOrder(uint64_t a)
{
    std::string strNum = std::to_string(a);
    std::sort(strNum.begin(), strNum.end(), std::greater<char>());
    return std:: stoull(strNum.c_str());
}
std::string smash(const std::vector<std::string>& words)
{
    std::string res;
    for (auto&& it : words)
        res += it + ' ';
    res.pop_back();
        return res;
}

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
 /*   int sum=0;
    for (auto&& it: classPoints)
        sum += it;
    sum= sum/ classPoints.size();
    return yourPoints >= sum;*/
    return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
}
long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    return numbers[0] + numbers[1];
    //auto min_elem = *std::min_element(numbers.begin(), numbers.end());
    //auto beg = numbers.begin();
    //for (; beg!= numbers.end();++beg)
    //{
    //    if (*beg == min_elem)
    //    {
    //        numbers.erase(beg);
    //        break;
    //    } 
    //}
    //auto minelem = *std::min_element(numbers.begin(), numbers.end());
    //return min_elem + minelem;
}
std::string number_to_string(int num) {
    return std::to_string(num);
}

bool solution(std::string const& str, std::string const& ending) {
    return (std::string(str.end() - ending.size(), str.end()) == ending);
}
std::string no_space(const std::string& x)
{
        std::string res;
        for (auto&& it : x)
        {
            if (it != ' ')
                res+=it;
            else
                continue;
        }
    //std::remove_if(res.begin(), res.end(), std::isspace);
    std::cout << res << "\n";
    return res;
}
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