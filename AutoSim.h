#ifndef AUTOSIM
#define AUTOSIM

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>

class Gearbox
{

    friend std::ostream &operator<<(std::ostream &output, const Gearbox &obj)
    {
        output << std::setw(15) << "Gearbox type [" << obj.m_marking << "]\n";
        return output;
    }

public:
    Gearbox(const std::string &marking)
        : m_marking{marking}
    {
        std::cout << "Gearbox constructed\n";
    }

    ~Gearbox()
    {
        std::cout << "Gearbox destroyed\n";
    }

    void setMarking(std::string &marking)
    {
        m_marking = marking;
    }

    std::string getMarking() const
    {
        return m_marking;
    }

    void shiftUp()
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

    void shiftDown()
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

    void shiftNeutral()
    {
        m_gearPos = 1;
        std::cout << "Gearbox is in neutral position\n";
    }

    void printGear()
    {
        std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
    }

    int getGearPos() const
    {
        return m_gearPos;
    }

private:
    std::string m_marking;
    std::vector<std::string> m_currentGear{"Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six"};
    int m_gearPos{1};
};

class Tyres
{
    friend std::ostream &operator<<(std::ostream &output, const Tyres &obj)
    {
        output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << "radius " << obj.m_radius << "]\n";

        return output;
    }

public:
    Tyres(const std::string &brand,
          int width,
          int height,
          int radius)
        : m_brand{brand}, m_width{width}, m_height{height}, m_radius{radius}
    {
        std::cout << "Tyres constructed\n";
    }

    ~Tyres()
    {
        std::cout << "Tyres destroyed\n";
    }

private:
    std::string m_brand;
    int m_width;
    int m_height;
    int m_radius;
};

class Rims
{
    friend std::ostream &operator<<(std::ostream &output, const Rims &obj)
    {
        output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << "radius " << obj.m_radius << "]\n";

        return output;
    }

public:
    Rims(const std::string &brand,
         int width,
         int height,
         int radius)
        : m_brand{brand}, m_width{width}, m_height{height}, m_radius{radius}
    {
        std::cout << "Rims constructed\n";
    }

    ~Rims()
    {
        std::cout << "Rims destroyed\n";
    }

    void spinWheels()
    {
        std::cout << "Wheels spinning.\n";
        for (int i{0}; i < 3; ++i)
        {
            std::cout << "faster\n";
            Sleep(500);
        }
    }

private:
    std::string m_brand;
    int m_width;
    int m_height;
    int m_radius;
};

class Motor
{
    friend std::ostream &operator<<(std::ostream &output, const Motor &obj)
    {
        output << std::setw(15) << "Motor mark [" << obj.m_marking << "] volume [" << obj.m_volume << "]\n";

        return output;
    }

public:
    Motor(const std::string &marking,
          double volume)
        : m_marking{marking}, m_volume{volume}, m_work{false}
    {
        std::cout << "Motor constructed\n";
    }

    ~Motor()
    {
        std::cout << "Motor destroyed\n";
    }

    void startEngine()
    {
        m_work = true;
        std::cout << "(Motor is started)\n";
    }

    void offEngine()
    {
        m_work = false;
        std::cout << "(Motor is off)\n";
    }

    bool getWork() const
    {
        return m_work;
    }

private:
    std::string m_marking;
    bool m_work;
    double m_volume;
};

class Auto
{
    friend std::ostream &operator<<(std::ostream &output, const Auto &obj)
    {
        output << std::setw(15) << "\nAuto brand [" << obj.m_brand << "] model [" << obj.m_model << "]\n"
               << "\t\tSpecifications\n"
               << obj.m_gearbox
               << obj.m_motor
               << obj.m_rims
               << obj.m_tyres << '\n';

        return output;
    }

    std::string m_brand;
    std::string m_model;
    Motor m_motor;
    Gearbox m_gearbox;
    Tyres m_tyres;
    Rims m_rims;

public:
    Auto(const std::string &brand,
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

        : m_brand{brand},
          m_model{model},
          m_motor(motorMarking, motorVolume),
          m_gearbox{gearBoxMarking},
          m_tyres{tyreMark, width, height, radius},
          m_rims{rimsMark, width, height, radius}
    {
        std::cout << "Auto constructed\n";
    }

    ~Auto()
    {
        std::cout << "Auto destroyed\n";
    }

    void turnOn()
    {
        m_motor.startEngine();
    }

    void turnOff()
    {
        m_motor.offEngine();
    }

    void gearUp()
    {
        m_gearbox.shiftUp();
    }

    void gearDown()
    {
        m_gearbox.shiftDown();
    }

    void startMoving()
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

    void stopMoving()
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
};

#endif