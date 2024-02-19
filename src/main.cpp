#include "MyString.cpp"


int main()
{
    MyString str1, str2, str3;

    std::cout << "Input 3 strings: ";

    std::cin >> str1 >> str2 >> str3;

    std::cout << "Test of output operator(<<):\nstr1 = " << str1 << ", str2 = " << str2 << ", str3 = " << str3 << "\n\n";

    MyString sumStr = str1 + str2;

    std::cout << "Test of sum operator(+): \n" << "str1 + str2 = " << sumStr << "\n\n";

    MyString subStr = str1 - str2;

    std::cout << "Test of substraction operator(-): \n" << "str1 - str2 = " << subStr << "\n\n";

    MyString multStr = str1 * 3;

    std::cout << "Test of multiply operator(*): \n" << "str1 * 3 = " << multStr << "\n\n";

    bool strCmp1 = str1 == str2;
    bool strCmp12 = str1 == str1;
    bool strCmp2 = str1 != str2;
    bool strCmp22 = str1 != str1;

    std::cout << "Test of compare operators(== and !=): \n" << "str1 == str2 = " << strCmp1 << "   str1 == str1 = " << strCmp12;
    std::cout << "\nstr1 != str2 = " << strCmp2 << "   str1 != str1 = " << strCmp22 << "\n\n";

    bool strLCmp1 = str1 < str2;
    bool strLCmp2 = str1 > str2;
    bool strLCmp3 = str1 <= str2;
    bool strLCmp4 = str1 < str2;

    std::cout << "Test of lexicographical compare operators(<(<=) and >(>=)): \n" << "str1 < str2 = " << strLCmp1 << "   str1 <= str2 = " << strLCmp3;
    std::cout << "\nstr1 > str2 = " << strLCmp2 << "   str1 >= str2 = " << strLCmp4 << "\n\n";

    MyString str123 = "aaaBBB";
    MyString str1232 = !str123;

    std::cout << "Test of ! operator: \nBefore: " << str123 << "   After: " << str1232 << "\n\n";

    std::cout << "Test of index search: \n" << "str1 = " << str1 << "\nstr1[0] = " << str1[0] << "   str1[3] = " << str1[3] << "\n\n";

    MyString mainStr = str1 + str2 + str3;
    MyString subStr1 = str2;
    MyString subStr2 = str3;
    unsigned int searchingOfSubStr1 = mainStr(subStr1);
    unsigned int searchingOfSubStr2 = mainStr(subStr2);

    std::cout << "Test of sub string searching: \n" << "String = " << mainStr << "\nsub string 1 = " << subStr1 << ",  sub string 2 = " << subStr2;
    std::cout << "\nstring(sub string 1) = " << searchingOfSubStr1 << ", string(sub string 2) = " << searchingOfSubStr2 << "\n\n";

    return 0;
}