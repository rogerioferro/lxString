// Copyright (C) 2022 - Rogerio Ferro do Nascimento.
//
// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#ifndef LX_STRING_H
#define LX_STRING_H

#include <cctype>
#include <cmath>
#include <algorithm>
#include <string>
#include <locale>
#include <vector>

namespace lx
{
  // Extends std::basic_string and adds more functionality
  class string : public std::basic_string<char>
  {
  public:
    typedef std::basic_string<char> string_type;

  public:
    /**
     *  @brief  Default constructor creates an empty string.
     */
    string() : string_type() {}
    /**
     *  @brief  Construct string with copy of value of @a __str.
     *  @param  __str  Source string.
     */
    string(const string_type &str) : string_type(str) {}
    /**
     *  @brief  Construct string initialized by a null-terminated character sequence (C-string).
     *  @param  __s  Source null-terminated character sequence (C-string).
     */
    string(const char *str) : string_type(str) {}
    /**
     *  @brief  Construct string initialized by a character %array.
     *  @param  __s  Source character %array.
     *  @param  __n  Number of characters to copy.
     *
     *  NB: @a __s must have at least @a __n characters, &apos;\\0&apos;
     *  has no special meaning.
     */
    string(const char *str, size_t n) : string_type(str, n) {}
    /**
     *  @brief  Construct string with the representation of @a __value.
     *  @param  __value  Numerical value.
     */
    /**
     *  @brief  Construct string as multiple characters.
     *  @param  __n  Number of characters.
     *  @param  __c  Character to use.
     */
    string(size_t n, char c) : string_type(n, c) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(int value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(long value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(long long value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(unsigned value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(unsigned long value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(unsigned long long value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(float value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(double value) : string_type(std::to_string(value)) {}
    /**
     *  @brief  Construct string with the representation of @a __value .
     *  @param  __value  Numerical value.
     */
    string(long double value) : string_type(std::to_string(value)) {}

  public:
    /**
     *  @brief  Converts lowercase letters to uppercase.
     *  @return  The new string.
     *
     *  Return a new string converted to uppercase.
     */
    string toUpper() const { return _apply(std::toupper); }
    /**
     *  @brief  Converts uppercase letters to lowercase.
     *  @return  The new string.
     *
     *  Return a new string converted to lowercase.
     */
    string toLower() const { return _apply(std::tolower); }
    /**
     *  @brief  Removes all spaces from the start of the current string.
     *  @return  The new string.
     */
    string trimStart() const { return string_type(_firstNonSpace(), end()); }
    /**
     *  @brief  Removes all spaces from the end of the current string.
     *  @return  The new string.
     */
    string trimEnd() const { return string_type(begin(), _lastNonSpace()); }
    /**
     *  @brief  Removes all spaces from the start and the end of the current string.
     *  @return  The new string.
     */
    string trim() const { return string_type(_firstNonSpace(), _lastNonSpace()); }
    /**
     *  @brief  Gets all the characters after the first occurrence of @a __s .
     *  @param  __s  Another string with the subject to search for.
     *  @return  The new string.
     */
    string after(string s) const { return skip(find(s) + s.size()); }
    /**
     *  @brief  Gets all the characters before the first occurrence of @a __s .
     *  @param  __s  Another string with the subject to search for.
     *  @return  The new string.
     */
    string before(string s) const { return take(find(s)); }
    /**
     *  @brief  Gets all the characters after the firsts @a __n characters.
     *  @param  __n  Number of characters to skip.
     *  @return  The new string.
     */
    string skip(size_t n) const { return substr(n); }
    /**
     *  @brief  Gets the firsts @a __n characters.
     *  @param  __n  Number of characters to take.
     *  @return  The new string.
     */
    string take(size_t n) const { return substr(0, n); }
    /**
     *  @brief  Check if the string is a valid number.
     */
    bool isDigits() const { return _isAllDigits(); }
    /**
     *  @brief  Check if all characters is lowercase.
     */
    bool isLower() const { return _checkIf(std::islower); }
    /**
     *  @brief  Check if all characters is uppercase.
     */
    bool isUpper() const { return _checkIf(std::isupper); }
    /**
     *  @brief  Check if all characters is alphabetic.
     */
    bool isAlpha() const { return _checkIf(std::isalpha); }
    /**
     *  @brief  Check if string starts with @a __s .
     *  @param  __s  Another string with the subject to search for.
     */
    bool startsWith(const string &preFix) const
    {
      return take(preFix.size()) == preFix;
    }
    /**
     *  @brief  Check if string ends with @a __s .
     *  @param  __s  Another string with the subject to search for.
     */
    bool endsWith(const string &suffix) const
    {
      return skip(size() - suffix.size()) == suffix;
    }
    /**
     *  @brief  Splits a string into substrings based on a 
     *  specified delimiting character.
     *  @param  __delimiters  delimiting characters.
     *  @return  A vector of strings.
     */
    std::vector<string> split(string_type delimiters)
    {
      std::vector<string> result;
      size_t current;
      size_t next = -1;
      do
      {
        current = next + 1;
        next = find_first_of(delimiters, current);
        result.push_back(substr(current, next - current));
      } while (next != string_type::npos);
      return result;
    }

    /**
     *  @brief  shuffle the characters of the string.
     */
    void shuffleIt()
    {
      std::random_shuffle(begin(), end());
    }

    /**
     *  @brief  return a copy of string with the characters shuffled.
     */
    string shuffled() const
    {
      string tmp = *this;
      tmp.shuffleIt();
      return tmp;
    }

    /**
     *  @brief  Parses string interpreting its content as an integral number 
     *  of the specified base, which is returned as an int value.
     */
    int toInt(int base = 10) const { return std::stoi(*this, 0, base); }
    /**
     *  @brief  Parses string interpreting its content as an integral number 
     *  of the specified base, which is returned as an long int value.
     */
    long toLong(int base = 10) const { return std::stol(*this, 0, base); }
    /**
     *  @brief  Parses string interpreting its content as an integral number 
     *  of the specified base, which is returned as an long long int value.
     */
    long long toLongLong(int base = 10) const { return std::stoll(*this, 0, base); }
    /**
     *  @brief  Parses string interpreting its content as an integral number 
     *  of the specified base, which is returned as an unsigned long int value.
     */
    unsigned long toULong(int base = 10) const { return std::stoul(*this, 0, base); }
    /**
     *  @brief  Parses string interpreting its content as an integral number 
     *  of the specified base, which is returned as an unsigned long long int value.
     */
    unsigned long long toULongLong(int base = 10) const { return std::stoull(*this, 0, base); }
    /**
     *  @brief  Parses str interpreting its content as a floating-point number, 
     *  which is returned as a value of type float.
     */
    float toFloat() const { return std::stof(*this); }
    /**
     *  @brief  Parses str interpreting its content as a floating-point number, 
     *  which is returned as a value of type double.
     */
    double toDouble() const { return std::stod(*this); }
    /**
     *  @brief  Parses str interpreting its content as a floating-point number, 
     *  which is returned as a value of type long double.
     */
    long double toLongDouble() const { return std::stold(*this); }

    // conversion function
    operator const char *()
    {
      return c_str();
    }

    template <typename T>
    string operator+(const T &other)
    {
      string tmp = *this;
      tmp.append(string(other));
      return tmp;
    }

    template <typename T>
    void operator+=(const T &other)
    {
      *this = *this + other;
    }

  private:
    // helpers
    typedef int (*ApplyFunc)(int);
    // takes in a function and returns a string with that function applied to the whole string
    string _apply(const ApplyFunc &Applier) const
    {
      string str;
      str.reserve(size());
      std::transform(begin(), end(),                              // from start to end
                     std::back_insert_iterator<string_type>(str), // adjust str size
                     Applier);                                    // while applying a function to it
      return str;
    }

    const_iterator _firstNonSpace() const
    {
      return std::find_if(begin(), end(),
                          [](unsigned char ch)
                          { return !std::isspace(ch); });
    }

    const_iterator _lastNonSpace() const
    {
      return std::find_if(rbegin(), rend(),
                          [](unsigned char ch)
                          { return !std::isspace(ch); })
          .base();
    }
    // takes in a function and checks if it passes the function checking
    bool _checkIf(const ApplyFunc &Applier) const
    {
      for (size_t indx = 0; indx != size(); ++indx)
      {
        if (!Applier((*this)[indx]))
          return false;
      }
      return true;
    }
    // A valid digit is 0-9, with the expection of '.' for floating point, and '-' for negative digits
    // A valid here cannot end with any post-fix, ex : 3.14f or 124L is invalid!
    bool _isAllDigits() const
    {
      size_t start = 0;
      if ((*this)[0] == '-')
        start = 1;
      for (; start < size(); ++start)
      {
        char value = (*this)[start];
        if (!isdigit(value) && value != '.')
          return false;
      }
      return true;
    }
  };

} // namespace lx

#endif // LX_STRING_H