#ifndef MOTOR
#define MOTOR

#include <string>
#include <iostream>
#include <iomanip>

class Motor
{
    friend std::ostream &operator<<(std::ostream &output, const Motor &obj);

public:
    Motor(const std::string &, double);

    // конструктор копирования
    Motor(const Motor &);
    ~Motor();

    // оператор присваивания
    const Motor &operator=(const Motor &);

    void startEngine();

    void offEngine();

    // геттеры
    bool getWork() const;
    std::string getMarking() const;
    double getVolume() const;

    // сеттеры
    void setMarking(const std::string &);
    void setWork(const bool);
    void setVolume(const double);

private:
    std::string m_marking;
    bool m_work;
    double m_volume;
};

std::ostream &operator<<(std::ostream &output, const Motor &obj)
{
    output << std::setw(15) << "Motor mark [" << obj.m_marking << "] volume [" << obj.m_volume << "]\n";

    return output;
}

Motor::Motor(const std::string &marking,
             double volume)
    : m_marking{marking},
      m_volume{volume},
      m_work{false}
{
    std::cout << "Motor constructed\n";
}

Motor::Motor(const Motor &other)
    : m_marking{other.m_marking},
      m_volume{other.m_volume},
      m_work{other.m_work}
{
}

Motor::~Motor()
{
    std::cout << "Motor destroyed\n";
}

const Motor &Motor::operator=(const Motor &right)
{
    if (this != &right)
    {
        m_marking = right.m_marking;
        m_volume = right.m_volume;
        m_work = right.m_work;
    }

    return *this;
}

void Motor::startEngine()
{
    m_work = true;
    std::cout << "(Motor is started)\n";
}

void Motor::offEngine()
{
    m_work = false;
    std::cout << "(Motor is off)\n";
}

bool Motor::getWork() const
{
    return m_work;
}

std::string Motor::getMarking() const
{
    return m_marking;
}

double Motor::getVolume() const
{
    return m_volume;
}

// сеттеры
void Motor::setMarking(const std::string &mark)
{
    m_marking = mark;
}

void Motor::setWork(const bool state)
{
    m_work = state;
}

void Motor::setVolume(const double volume)
{
    m_volume = volume;
}

#endif