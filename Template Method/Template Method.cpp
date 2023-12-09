#include <iostream>
#include <Windows.h>

class AbstractAlgorithm {
public:
   
    void execute() {
        initialize();
        step1();
        step2();
        if (hook()) {
            step3();
        }
        finalize();
    }

  
    virtual void initialize() {
        std::cout << "AbstractAlgorithm: Ініціалізація" << std::endl;
    }

    virtual void step1() {
        std::cout << "AbstractAlgorithm: Крок 1" << std::endl;
    }

    virtual void step2() {
        std::cout << "AbstractAlgorithm: Крок 2" << std::endl;
    }

    virtual bool hook() {
        
        return true;
    }

    virtual void step3() {
        std::cout << "AbstractAlgorithm: Крок 3" << std::endl;
    }

    virtual void finalize() {
        std::cout << "AbstractAlgorithm: Фіналізація" << std::endl;
    }
};


class ConcreteAlgorithm : public AbstractAlgorithm {
public:
    
    void initialize() override {
        std::cout << "ConcreteAlgorithm: Ініціалізація конкретного алгоритму" << std::endl;
    }

    void step2() override {
        std::cout << "ConcreteAlgorithm: Специфічний крок 2" << std::endl;
    }

    bool hook() override {
        std::cout << "ConcreteAlgorithm: Перевизначений гак" << std::endl;
        
        return false;
    }

    void step3() override {
        std::cout << "ConcreteAlgorithm: Специфічний крок 3" << std::endl;
    }

    void finalize() override {
        std::cout << "ConcreteAlgorithm: Фіналізація конкретного алгоритму" << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ConcreteAlgorithm concreteAlgorithm;
    concreteAlgorithm.execute();

    return 0;
}