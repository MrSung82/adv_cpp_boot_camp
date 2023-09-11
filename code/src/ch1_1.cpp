#include <iostream>
#include <cstdio>

void waitForAKey(const char* comment = nullptr)
{
    if (comment)
    {
        std::cout << comment << std::endl;
    }
    else
    {
        std::cout << "\nPress any key to continue" << std::endl;
    }
    static std::string q;
    std::cin >> q;
}

template<typename T>
void printValue(const T& val);

template<>
void printValue<int>(const int& val)
{
    printf_s("\nvalue of int variable: %d", val);
}

template<>
void printValue<float>(const float& val)
{
    printf_s("\nvalue of float variable: %.7f", val);
}

int floatAsInt(float val)
{
    int* pInt = reinterpret_cast<int*>(&val);
    return *pInt;
}

float intAsFloat(int val)
{
    float* pFlt = reinterpret_cast<float*>(&val);
    return *pFlt;
}

int main()
{
    int intVar = 1078523331;
    float fltVar = intAsFloat(1078523331);

    printValue(intVar);
    printValue(intAsFloat(intVar));

    printValue(fltVar);
    printValue(floatAsInt(fltVar));
    
    waitForAKey();
    return 0;
}

