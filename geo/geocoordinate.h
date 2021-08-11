#ifndef GEOCOORDINATE_H
#define GEOCOORDINATE_H
#include "geotypes.h"

#include <QString>

class GeoCoordinate
{
public:
    GeoCoordinate() :
        _latitude(0),
        _longitude(0),
        _altitude(0),
        _precision(6),
        _cardinalLatitude(Geo::InvalidCardinalDirection),
        _cardinalLongitude(Geo::InvalidCardinalDirection) {}

    GeoCoordinate(double latitude, double longitude, double altitude = 0) :
        _latitude(latitude),
        _longitude(longitude),
        _altitude(altitude),
        _precision(6),
        _cardinalLatitude(Geo::InvalidCardinalDirection),
        _cardinalLongitude(Geo::InvalidCardinalDirection) {}

    GeoCoordinate(const QString& value);

    bool operator==(const GeoCoordinate& other);
    bool operator!=(const GeoCoordinate& other) { return !(*this == other); }

    double latitude() const { return _latitude; }
    void setLatitude(double value) { _latitude = value; }

    double longitude() const { return _longitude; }
    void setLongitude(double value) { _longitude = value; }

    double altitude() const { return _altitude; }
    void setAltitude(double value) { _altitude = value; }

    int precision() const { return _precision; }
    void setPrecision(int value) { _precision = value; }

    bool isNorthOfOrEqualTo(const GeoCoordinate& other);
    bool isNorthOf(const GeoCoordinate& other);
    bool isSouthOfOrEqualTo(const GeoCoordinate& other);
    bool isSouthOf(const GeoCoordinate& other);
    bool isWestOfOrEqualTo(const GeoCoordinate& other);
    bool isWestOf(const GeoCoordinate& other);
    bool isEastOfOrEqualTo(const GeoCoordinate& other);
    bool isEastOf(const GeoCoordinate& other);

    bool isEmpty() { return *this == GeoCoordinate(); }

    QString toString(int precision = 0);

    static bool tryParse(const QString& stringValue, GeoCoordinate &point);
    static GeoCoordinate empty() { return GeoCoordinate(); }

private:
    static bool equalAtPrecision(double v1, double v2, int precision);

    double _latitude;
    double _longitude;
    double _altitude;

    int _precision;

    Geo::CardinalDirection _cardinalLatitude;
    Geo::CardinalDirection _cardinalLongitude;

    static QString TOSTRING_DELIM;
};

#endif // GEOCOORDINATE_H
