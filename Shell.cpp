#include "Shell.hpp"
#include <sstream>
#include <algorithm>


namespace nts
{
    volatile sig_atomic_t stop_loop = 0;

    void signalHandler(int signum) {
        (void)signum;
        stop_loop = 1;
    }
    
    Shell::Shell(std::shared_ptr<nts::Circuit> circuit)
        : circuit(circuit) {}
    
    void Shell::run()
    {
        std::string command;
        std::cout << "> ";
        while (std::getline(std::cin, command)) {
            executeCommand(command);
            std::cout << "> ";
        }
    }

    Shell::~Shell()
    {

    }
    
    void Shell::runLoop()
    {
        stop_loop = 0;
        signal (SIGINT, signalHandler);
        while (!stop_loop) {
            circuit->simulate(1);
            circuit->display();
        }
        std::cout << std::endl;
    }
    
    void Shell::executeCommand(const std::string &command) {
        if (command == "exit") {
            exit(0);
        } else if (command == "display") {
            circuit->display();
        } else if (command == "simulate") {
            circuit->simulate(1);
        } else if (command == "loop") {
            runLoop();
        } else if (command.find('=') != std::string::npos) {
            setInputValue(command);
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }
    
    void Shell::setInputValue(const std::string &command)
    {
        std::istringstream ss(command);
        std::string name, valueStr;
        if (std::getline(ss, name, '=') && std::getline(ss, valueStr)) {
            std::transform(valueStr.begin(), valueStr.end(), valueStr.begin(), ::toupper);
            if (valueStr == "0" || valueStr == "1" || valueStr == "U") {
                std::shared_ptr<nts::InputComponent> tmp = std::dynamic_pointer_cast<nts::InputComponent>(circuit->find(name));
                tmp->setInputValue((valueStr=="0")?nts::False:(valueStr=="1")?nts::True:nts::Undefined);
            } else {
                std::cerr << "Invalid value: " << valueStr << std::endl;
            }
        } else {
            std::cerr << "Invalid command format: " << command << std::endl;
        }
    }
    
    const char *Shell::Error::what() const noexcept
    {
        return this->message.c_str();
    }
}
