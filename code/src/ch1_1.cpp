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
    printf_s("\nvalue of variable: %d", val);
}

template<>
void printValue<float>(const float& val)
{
    printf_s("\nvalue of variable: %.7f", val);
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
    float fltVar = 3.14f;

    printValue(floatAsInt(fltVar));
    printValue(intAsFloat(intVar));
    waitForAKey();
    return 0;
}

