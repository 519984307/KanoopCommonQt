#ifndef ANGLE_H
#define ANGLE_H

#include <QString>

class Angle
{
public:
    Angle() : _degrees(-1) {}
    Angle(double degrees) : _degrees(degrees) {}

    Angle operator+(const Angle& other) const { return *this + other._degrees; }
    Angle operator+(double degrees) const;
    Angle operator-(const Angle& other) const { return *this - other._degrees; }
    Angle operator-(double degrees) const;

    double degrees() const { return _degrees; }
    void setDegrees(double value) { _degrees = value; }

    void add(double degrees);
    void subtract(double degrees);

    QString toString() const { return QString("%1 deg").arg(_degrees); }

private:
    static double add(double degrees, double amount);
    static double subtract(double degrees, double amount);

    double _degrees;
};

#endif // ANGLE_H
