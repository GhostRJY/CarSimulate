#ifndef RIMS
#define RIMS

#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h>

class Rims
{
    friend std::ostream &operator<<(std::ostream &output, const Rims &obj);

public:
    Rims(const std::string &,
         int,
         int,
         int);

    Rims(const Rims &);

    ~Rims();

    const Rims &operator=(const Rims &);

    // Геттеры
    std::string getBrand() const;
    int getWidth() const;
    int getHeight() const;
    int getRadius() const;

    // сеттеры
    void setBrand(const std::string &);
    void setWidth(const int);
    void setHeight(const int);
    void setRadius(const int);

    // вращаю колеса
    void spinWheels();

private:
    std::string m_brand;
    int m_width;
    int m_height;
    int m_radius;
};

std::ostream &operator<<(std::ostream &output, const Rims &obj)
{
    output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << "radius " << obj.m_radius << "]\n";

    return output;
}

Rims::Rims(const std::string &brand,
           int width,
           int height,
           int radius)

    : m_brand{brand},
      m_width{width},
      m_height{height},
      m_radius{radius}
{
    std::cout << "Rims constructed\n";
}

Rims::Rims(const Rims &other)
    : m_brand{other.m_brand},
      m_width{other.m_width},
      m_height{other.m_height},
      m_radius{other.m_radius}
{
}

Rims::~Rims()
{
    std::cout << "Rims destroyed\n";
}

const Rims &Rims::operator=(const Rims &right)
{
    if (this != &right)
    {
        m_brand = right.m_brand;
        m_width = right.m_width;
        m_height = right.m_height;
        m_radius = right.m_radius;
    }

    return *this;
}

// Геттеры
std::string Rims::getBrand() const
{
    return m_brand;
}

int Rims::getWidth() const
{
    return m_width;
}

int Rims::getHeight() const
{
    return m_height;
}

int Rims::getRadius() const
{
    return m_radius;
}

// сеттеры
void Rims::setBrand(const std::string &brand)
{
    m_brand = brand;
}

void Rims::setWidth(const int width)
{
    m_width = width;
}

void Rims::setHeight(const int height)
{
    m_height = height;
}

void Rims::setRadius(const int radius)
{
    m_radius = radius;
}

void Rims::spinWheels()
{
    std::cout << "Wheels spinning.\n";
    for (int i{0}; i < 3; ++i)
    {
        std::cout << "faster\n";
        Sleep(500);
    }
}

#endif