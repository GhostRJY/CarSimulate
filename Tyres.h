#ifndef TYRES
#define TYRES
#include <string>
#include <iostream>
#include <iomanip>

class Tyres
{
    friend std::ostream &operator<<(std::ostream &output, const Tyres &obj);

public:
    Tyres(const std::string &brand,
          int width,
          int height,
          int radius);

    Tyres(const Tyres &);
    ~Tyres();

    const Tyres &operator=(const Tyres &);
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

private:
    std::string m_brand;
    int m_width;
    int m_height;
    int m_radius;
};

std::ostream &operator<<(std::ostream &output, const Tyres &obj)
{
    output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << "radius " << obj.m_radius << "]\n";

    return output;
}

Tyres::Tyres(const std::string &brand,
             int width,
             int height,
             int radius)
    : m_brand{brand}, m_width{width}, m_height{height}, m_radius{radius}
{
    std::cout << "Tyres constructed\n";
}

Tyres::Tyres(const Tyres &other)
    : m_brand{other.m_brand},
      m_width{other.m_width},
      m_height{other.m_height},
      m_radius{other.m_radius}
{
}

const Tyres &Tyres::operator=(const Tyres &right)
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

Tyres::~Tyres()
{
    std::cout << "Tyres destroyed\n";
}

// Геттеры
std::string Tyres::getBrand() const
{
    return m_brand;
}

int Tyres::getWidth() const
{
    return m_width;
}

int Tyres::getHeight() const
{
    return m_height;
}

int Tyres::getRadius() const
{
    return m_radius;
}

// сеттеры
void Tyres::setBrand(const std::string &brand)
{
    m_brand = brand;
}

void Tyres::setWidth(const int width)
{
    m_width = width;
}

void Tyres::setHeight(const int height)
{
    m_height = height;
}

void Tyres::setRadius(const int radius)
{
    m_radius = radius;
}

#endif