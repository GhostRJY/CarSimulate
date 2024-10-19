#ifndef GEARBOX
#define GEARBOX
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Gearbox
{

    friend std::ostream &operator<<(std::ostream &output, const Gearbox &obj);

public:
    Gearbox(const std::string &);
    Gearbox(const Gearbox &);

    ~Gearbox();

    const Gearbox &operator=(const Gearbox &);

    void setMarking(std::string &);

    std::string getMarking() const;

    std::vector<std::string> getGears() const;

    void setGearPos(const int);

    int getGearPos() const;

    void shiftUp();

    void shiftDown();

    void shiftNeutral();

    void printGear();

private:
    std::string m_marking;
    const std::vector<std::string> m_currentGear{"Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six"};
    int m_gearPos;
};

std::ostream &operator<<(std::ostream &output, const Gearbox &obj)
{
    output << std::setw(15) << "Gearbox type [" << obj.m_marking << "]\n";
    return output;
}

Gearbox::Gearbox(const std::string &marking)
    : m_marking{marking},
      m_gearPos{1},
      m_currentGear{"Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six"}
{
    std::cout << "Gearbox constructed\n";
}

Gearbox::Gearbox(const Gearbox &other)
    : m_marking{other.m_marking},
      m_gearPos{other.m_gearPos},
      m_currentGear{"Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six"}
{
}

const Gearbox &Gearbox::operator=(const Gearbox &right)
{
    if (this != &right)
    {
        m_marking = right.m_marking;
        m_gearPos = right.m_gearPos;
    }

    return *this;
}

Gearbox::~Gearbox()
{
    std::cout << "Gearbox destroyed\n";
}

void Gearbox::setMarking(std::string &marking)
{
    m_marking = marking;
}

std::string Gearbox::getMarking() const
{
    return m_marking;
}

std::vector<std::string> Gearbox::getGears() const
{
    return m_currentGear;
}

void Gearbox::setGearPos(const int position)
{
    if (position >= 0 && position <= 7)
        m_gearPos = position;
    else
        m_gearPos = 1;
}

int Gearbox::getGearPos() const
{
    return m_gearPos;
}

void Gearbox::shiftUp()
{
    if (m_gearPos < 7)
    {
        ++m_gearPos;
        std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
    }
    else
    {
        std::cout << "you can't shift up!!!" << '\n';
    }
}

void Gearbox::shiftDown()
{
    if (m_gearPos > 0)
    {
        --m_gearPos;
        std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
    }
    else
    {
        std::cout << "you can't shift down!!!\n";
    }
}

void Gearbox::shiftNeutral()
{
    m_gearPos = 1;
    std::cout << "Gearbox is in neutral position\n";
}

void Gearbox::printGear()
{
    std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
}

#endif