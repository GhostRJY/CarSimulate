#ifndef AUTO
#define AUTO

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "Gearbox.h"
#include "Tyres.h"
#include "Rims.h"
#include "Motor.h"

class Auto
{
    // фун-и€ вывода информации на экран
    friend std::ostream &operator<<(std::ostream &output, const Auto &obj);

    // пол€ класса
    std::string m_brand;
    std::string m_model;
    Motor m_motor;
    Gearbox m_gearbox;
    Tyres m_tyres;
    Rims m_rims;

public:
    // конструктор класса
    Auto(const std::string &,
         const std::string &,
         const std::string &,
         double motorVolume,
         const std::string &,
         short,
         const std::string &,
         const std::string &,
         int,
         int,
         int);
    Auto(const Auto &);

    // деструктор
    ~Auto();

    const Auto &operator=(const Auto &);

    std::string getBrand() const;
    std::string getModel() const;
    Motor getMotor() const;
    Gearbox getGearbox() const;
    Tyres getTyres() const;
    Rims getRims() const;

    void setBrand(const std::string &);
    void setModel(const std::string &);
    void setMotor(const Motor &);
    void setGearbox(const Gearbox &);
    void setTyres(const Tyres &);
    void setRims(const Rims &);

    // завожу машину
    void turnOn();

    // глушу машину
    void turnOff();

    // переключаю передачу вверх
    void gearUp();

    // переключаю передачу вниз
    void gearDown();

    // начинаю движение
    void startMoving();

    // останавливаю машину
    void stopMoving();
};

std::ostream &operator<<(std::ostream &output, const Auto &obj)
{
    output << std::setw(15) << "\nAuto brand [" << obj.m_brand << "] model [" << obj.m_model << "]\n"
           << "\t\tSpecifications\n"
           << obj.m_gearbox
           << obj.m_motor
           << obj.m_rims
           << obj.m_tyres << '\n';

    return output;
}

Auto::Auto(const std::string &brand,
           const std::string &model,
           const std::string &motorMarking,
           double motorVolume,
           const std::string &gearBoxMarking,
           short gearCount,
           const std::string &rimsMark,
           const std::string &tyreMark,
           int width,
           int height,
           int radius)

    : // инициализирую пол€ класса
      m_brand{brand},
      m_model{model},
      m_motor(motorMarking, motorVolume),
      m_gearbox{gearBoxMarking},
      m_tyres{tyreMark, width, height, radius},
      m_rims{rimsMark, width, height, radius}
{
    std::cout << "Auto constructed\n";
}

Auto::Auto(const Auto &other)
    : m_brand{other.m_brand},
      m_model{other.m_model},
      m_motor{other.m_motor},
      m_gearbox{other.m_gearbox},
      m_rims{other.m_rims},
      m_tyres{other.m_tyres}
{
}

Auto::~Auto()
{
    std::cout << "Auto destroyed\n";
}

const Auto &Auto::operator=(const Auto &right)
{
    if (this != &right)
    {
        m_brand = right.m_brand;
        m_model = right.m_model;
        m_motor = right.m_motor;
        m_gearbox = right.m_gearbox;
        m_rims = right.m_rims;
        m_tyres = right.m_tyres;
    }
    return *this; // позвол€ет использовать присваивание типа a=b=c
}

std::string Auto::getBrand() const
{
    return m_brand;
}

std::string Auto::getModel() const
{
    return m_model;
}

Motor Auto::getMotor() const
{
    return m_motor;
}

Gearbox Auto::getGearbox() const
{
    return m_gearbox;
}

Tyres Auto::getTyres() const
{
    return m_tyres;
}

Rims Auto::getRims() const
{
    return m_rims;
}

void Auto::setBrand(const std::string &brand)
{
    m_brand = brand;
}

void Auto::setModel(const std::string &model)
{
    m_model = model;
}

void Auto::setMotor(const Motor &motor)
{
    m_motor = motor;
}

void Auto::setGearbox(const Gearbox &gearbox)
{
    m_gearbox = gearbox;
}

void Auto::setTyres(const Tyres &tyres)
{
    m_tyres = tyres;
}

void Auto::setRims(const Rims &rims)
{
    m_rims = rims;
}

void Auto::turnOn()
{
    m_motor.startEngine();
}

void Auto::turnOff()
{
    m_motor.offEngine();
}

void Auto::gearUp()
{
    m_gearbox.shiftUp();
}

void Auto::gearDown()
{
    m_gearbox.shiftDown();
}

void Auto::startMoving()
{
    if (m_motor.getWork())
    {
        while (m_gearbox.getGearPos() < 7)
        {

            gearUp();
            if (m_gearbox.getGearPos() == 2)
                std::cout << "Auto start moving\n";

            m_rims.spinWheels();
            Sleep(700);
        }
    }
    else
    {
        std::cout << "Your motor is off!!!\n";
    }
}

void Auto::stopMoving()
{
    m_gearbox.printGear();

    while (m_gearbox.getGearPos() > 1)
    {
        std::cout << "Auto slowing\n";
        gearDown();
        Sleep(700);
    }

    std::cout << "Auto is stopped\n";
}

#endif