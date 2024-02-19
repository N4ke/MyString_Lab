#ifndef MYSTRING_H
#define MYSTRING_H


#include <string>
#include <cstring>
#include <iostream>
#include <unordered_set>


class MyString
{
    private:
        char* string;

    public:
        MyString();

        MyString(const char* inputStr);

        MyString(std::string inputStr);

        MyString(const MyString& inputStr);

        MyString(MyString&&);

        ~MyString();

        int length();

        char* get();

        MyString operator+ (const MyString& str) const;

        MyString operator- (const MyString& str) const;

        MyString operator* (unsigned int number) const;

        MyString& operator= (const MyString& str);

        MyString& operator= (MyString&& str);

        bool operator== (const MyString& str) const;

        bool operator!= (const MyString& str) const;

        bool operator> (const MyString& str) const;

        bool operator>= (const MyString& str) const;
        
        bool operator< (const MyString& str) const;

        bool operator<= (const MyString& str) const;

        MyString operator! () const;

        char& operator[] (unsigned int index);

        unsigned int operator() (const MyString& str) const;

        friend std::istream& operator>> (std::istream& is, MyString& str);

        friend std::ostream& operator<< (std::ostream& os, MyString& str);

};


#endif