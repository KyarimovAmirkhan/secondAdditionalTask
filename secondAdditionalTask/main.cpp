#include "Mask.h"
#include <iostream>
#include <vector>

template<typename Container>
void printContainer(const std::string& name, const Container& container)
{
    std::cout << name << ": [";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container.at(i);
        if (i != container.size() - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    try
    {
        Mask<3> mask = {1, 0, 0};
        std::cout << "\n1) Маска размера " << mask.size() << ": [1 0 0]" << std::endl;

        std::cout << "Проверка mask.at(0): " << mask.at(0) << std::endl;
        std::cout << "Проверка mask.at(1): " << mask.at(1) << std::endl;
        std::cout << "Проверка mask.at(2): " << mask.at(2) << std::endl;

        std::cout << "\n2) Метод slice: " << std::endl;
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
        printContainer("Исходный вектор", vec);
        mask.slice(vec);
        printContainer("После slice", vec);

        std::cout << "\n3) Метод transform: " << std::endl;
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};
        printContainer("Исходный вектор", vec2);
        auto transformed = mask.transform(vec2, [](int x) 
        {
            return x * 2;
        });
        printContainer("После transform", transformed);

        std::cout << "\n4) Метод slice_and_transform: " << std::endl;
        std::vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7};
        printContainer("Исходный вектор", vec3);
        auto slicedTransformed = mask.slice_and_transform(vec3, [](int x)
        {
            return x + 10;
        });
        printContainer("После slice_and_transform", slicedTransformed);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }
    
    return 0;
}