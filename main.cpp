//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
    
//    return a.exec();
//}
//########################################################################################################
#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <memory> // Для std::unique_ptr
// Реализация make_unique для C++11
namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Инициализация умного указателя на std::vector<long long>
    std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();

    // Добавление элементов в вектор через умный указатель
    list_of_synapses->push_back(100LL);
    list_of_synapses->push_back(200LL);
    list_of_synapses->push_back(300LL);

    // Доступ к элементам вектора через умный указатель
    for (size_t i = 0; i < list_of_synapses->size(); ++i) {
        std::cout << "Element " << i << ": " << list_of_synapses->at(i) << std::endl;
    }

    // Память будет автоматически освобождена при выходе из блока
    return a.exec();
}
