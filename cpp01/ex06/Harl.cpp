#include "Harl.hpp"

Harl::Harl()
{
    this->funcs[ENU_NOISE] = &Harl::noise;
    this->funcs[ENU_DEBUG] = &Harl::debug;
    this->funcs[ENU_INFO] = &Harl::info;
    this->funcs[ENU_WARNING] = &Harl::warning;
    this->funcs[ENU_ERROR] = &Harl::error;
    callers[ENU_NOISE] = "NOISE";
    callers[ENU_DEBUG] = "DEBUG";
    callers[ENU_INFO] = "INFO";
    callers[ENU_WARNING] = "WARNING";
    callers[ENU_ERROR] = "ERROR";
    this->num_levels = 5;
}

Harl::~Harl()
{
    
}

Harl::Harl(const Harl& copy)
{
    if (this == &copy)
        return ;
    this->funcs[ENU_NOISE] = copy.funcs[ENU_NOISE];
    this->funcs[ENU_DEBUG] = copy.funcs[ENU_DEBUG];
    this->funcs[ENU_INFO] = copy.funcs[ENU_INFO];
    this->funcs[ENU_WARNING] = copy.funcs[ENU_WARNING];
    this->funcs[ENU_ERROR] = copy.funcs[ENU_ERROR];
    this->callers[ENU_NOISE] = copy.callers[ENU_NOISE];
    this->callers[ENU_DEBUG] = copy.callers[ENU_DEBUG];
    this->callers[ENU_INFO] = copy.callers[ENU_INFO];
    this->callers[ENU_WARNING] = copy.callers[ENU_WARNING];
    this->callers[ENU_ERROR] = copy.callers[ENU_ERROR];
    this->num_levels = copy.num_levels;
}

Harl& Harl:: operator= (const Harl& other)
{
    if (this == &other)
        return (*this);
    this->funcs[ENU_NOISE] = other.funcs[ENU_NOISE];
    this->funcs[ENU_DEBUG] = other.funcs[ENU_DEBUG];
    this->funcs[ENU_INFO] = other.funcs[ENU_INFO];
    this->funcs[ENU_WARNING] = other.funcs[ENU_WARNING];
    this->funcs[ENU_ERROR] = other.funcs[ENU_ERROR];
    this->callers[ENU_NOISE] = other.callers[ENU_NOISE];
    this->callers[ENU_DEBUG] = other.callers[ENU_DEBUG];
    this->callers[ENU_INFO] = other.callers[ENU_INFO];
    this->callers[ENU_WARNING] = other.callers[ENU_WARNING];
    this->callers[ENU_ERROR] = other.callers[ENU_ERROR];
    this->num_levels = other.num_levels;
    return (*this);
}

void    Harl::complain(std::string level)
{
    int i;
    int call;
    
    call = 0;
    i = 1;
    while (i < this->num_levels)
    {
        call += i * (callers[i] == level);
        i++;
    }
    switch (call)
    {
        case ENU_DEBUG:
            (*this.*funcs[ENU_DEBUG])();
        case ENU_INFO:
            (*this.*funcs[ENU_INFO])();
        case ENU_WARNING:
            (*this.*funcs[ENU_WARNING])();
        case ENU_ERROR:
        {
            (*this.*funcs[ENU_ERROR])();
            break ;
        }
        default:
            (*this.*funcs[ENU_NOISE])();
    }
}


void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Ahhh, adoro estar no governo, receber guita por fora!! ";
    std::cout << "Não podia pedir mais, incrível!\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "Ai ai, estes inspectores da Policia Judiciaria já ";
    std::cout << "andam a meter o bedelho onde não são chamados... ";
    std::cout << "mas afinal não tinhamos subornado os gajos?" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "Quem é que estes gajos pensam que são??? Já não há privacidade???? ";
    std::cout << "Devem achar que se podem meter na vida das pessoas e que um gajo ";
    std::cout << "não pode fazer trafulhices \n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "ACABOU-SE!!! Vamos lá falar com o chefe do chefe do chefe do chefe ";
    std::cout << "do chefe do chefe do chefe para demitir a PJ INTEIRA!! \n" << std::endl;
}

void    Harl::noise(void)
{
    std::cout << "[ Lalala a vida é bela ]" << std::endl;
}
