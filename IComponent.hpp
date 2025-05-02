#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
    public :
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute (std::size_t pin) = 0;
        virtual void setLink (std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) = 0;
    };

    class AComponent;
    class AndComponent;
    class ClockComponent;
    class FalseComponent;
    class InputComponent;
    class NotComponent;
    class OrComponent;
    class OutputComponent;
    class TrueComponent;
    class XorComponent;
    class Circuit;
    class Shell;
    class Factory;
    class Component4001;
    class Component4011;
    class Component4071;
    class Component4008;
    class Component4017;
}
