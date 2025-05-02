#include <iostream>
#include <memory>

#include "IComponent.hpp"
#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "ClockComponent.hpp"
#include "FalseComponent.hpp"
#include "InputComponent.hpp"
#include "NotComponent.hpp"
#include "OrComponent.hpp"
#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "XorComponent.hpp"
#include "Factory.hpp"
#include "Shell.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"

std::ostream &operator <<(std::ostream &out, nts::Tristate v)
{
    if (v == nts::True)
        return out << 1;
    if (v == nts::False)
        return out << 0;    
    return out << "Undefined"; 
}

void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl;
    std::cout << "filepath:\t Path to your config file. Must be written in the .nts format." << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    nts::parse::Parser parser;
    std::shared_ptr circuit =std::make_shared<nts::Circuit>();


    if (ac != 2) {
        std::cout << "Invalid number of argument." << std::endl;
        return 84;
    }

    if (ac == 2 && !std::string(av[1]).compare("-h")) printUsage();

    try {
        
        parser.openFile(av[1]);
        
        parser.buildCircuit(circuit);
       
    } catch (const std::exception &except) {
        if (except.what() != std::string("EOF")) {
            std::cerr << except.what() << std::endl;
            return 84;
        }
    };
    try {
        nts::Shell shell(circuit);
        shell.run();
    } catch (const std::exception &exception) {
        if (exception.what() == std::string("EOF")) return 0;
        std::cerr << exception.what() << std::endl;
        return 84;
    }

    return 0;
}