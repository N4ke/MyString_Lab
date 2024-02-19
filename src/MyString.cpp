// Copyright 2024 Nikitos

#include "include\MyString.h"


MyString::MyString() : string(nullptr) {}

MyString::MyString(const char* inputStr) {
    string = new char[strlen(inputStr) + 1];
    snprintf(string, strlen(inputStr) + 1, "%s", inputStr);
}

MyString::MyString(std::string inputStr) {
    string = new char[inputStr.size() + 1];
    snprintf(string, inputStr.size() + 1, "%s", inputStr);
}

MyString::MyString(const MyString& inputStr) {
    if (inputStr.string) {
        string = new char[strlen(inputStr.string) + 1];
        snprintf(string, strlen(inputStr.string) + 1, "%s", inputStr.string);
    }
}

MyString::MyString(MyString&& inputStr) {
    if (inputStr.string) {
        string = inputStr.string;
        inputStr.string = nullptr;
    }
}

MyString::~MyString() {
    delete[] string;
}

int MyString::length() {
    return strlen(string);
}

char* MyString::get() {
    return string;
}


MyString MyString::operator+ (const MyString& str) const {
    char* newStr = new char[strlen(this->string) + strlen(str.string) + 1];

    unsigned int length1 = strlen(str.string);
    unsigned int length2 = strlen(this->string);
    unsigned int length = length1 + length2 + 1;

    snprintf(newStr, length, "%s", this->string);
    snprintf(newStr + length2, length - length2, "%s", str.string);

    MyString result(newStr);
    delete[] newStr;

    return result;
}

MyString MyString::operator- (const MyString& str) const {
    std::unordered_set<char> chars;
    std::string result;

    for (int i = 0; i < strlen(str.string); i++) {
        chars.insert(str.string[i]);
    }

    for (int i = 0; i < strlen(this->string); i++) {
        if (chars.find(this->string[i]) == chars.end()) {
            result += this->string[i];
        }
    }

    MyString msresult(result);

    return msresult;
}

MyString MyString::operator* (unsigned int number) const {
    std::string result;

    if (number == 0) {
        MyString msresult;
        return msresult;
    }

    for (int i = 0; i < number; i++) {
        result += this->string;
    }

    MyString msresult = result;

    return result;
}

bool MyString::operator== (const MyString& str) const {
    if (this == &str) return true;

    return strcmp(this->string, str.string) == 0;
}

bool MyString::operator!= (const MyString& str) const {
    return !(*this == str);
}

MyString& MyString::operator= (const MyString& str) {
    if (this != &str) {
        delete[] this->string;

        this->string = new char[strlen(str.string) + 1];
        snprintf(this->string, strlen(this->string) + 1, "%s", str.string);
    }
    return *this;
}

MyString& MyString::operator= (MyString&& str) {
    if (this != &str) {
        delete[] this->string;

        this->string = str.string;
        str.string = nullptr;
    }

    return *this;
}

bool MyString::operator> (const MyString& str) const {
    return strcmp(this->string, str.string) > 0;
}
bool MyString::operator>= (const MyString& str) const {
    return strcmp(this->string, str.string) >= 0;
}

bool MyString::operator< (const MyString& str) const {
    return strcmp(this->string, str.string) < 0;
}
bool MyString::operator<= (const MyString& str) const {
    return strcmp(this->string, str.string) <= 0;
}

MyString MyString::operator! () const {
    MyString result(*this);

    for (int i = 0; i < strlen(result.string); i++) {
        if (islower(result.string[i])) {
            result.string[i] = toupper(result.string[i]);
        } else if (isupper(result.string[i])) {
            result.string[i] = tolower(result.string[i]);
        }
    }
    return result;
}

char& MyString::operator[] (unsigned int index) {
    if (index >= strlen(this->string)) {
        return string[strlen(this->string) - 1];
    }
    return string[index];
}

unsigned int MyString::operator() (const MyString& str) const {
    char* searching = std::strstr(this->string, str.string);

    if (searching != 0) {
        return (int&)searching - (int&)this->string;
    } else {
        return 0;
    }
}

std::istream& operator>> (std::istream& is, MyString& str) {
    const int size = 256;
    char* buf = new char[size];

    is >> buf;

    str = MyString(buf);

    delete[] buf;

    return is;
}

std::ostream& operator<< (std::ostream& os, MyString& str) {
    os << str.get();
    return os;
}
