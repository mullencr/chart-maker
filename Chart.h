// Copyright 2017 Charles Mullenix

#ifndef CHART_H
#define CHART_H

#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

#include "Point.h"


class Chart {
    friend std::ostream& operator<<(std::ostream& os, const Chart& c);
    friend std::istream& operator>>(std::istream& is, Chart& c);
public:
    Chart();
    Chart(const Chart& orig);
    virtual ~Chart();
    Chart(const std::string& fileName);
    Chart& operator=(const Chart& src);
    bool contains(const Point& p) const;
    Chart operator+(const Chart& other) const;
    Chart operator-(const Chart& other) const;
    Chart operator*(const Point& scale) const;
    Chart operator/(const Point& scale) const;
    Chart operator>>(int value) const;
    Chart operator<<(int value) const;
    void analyze(std::ostream& os, const int scale) const;
private:
    std::vector<Point> pointList;
};

#endif /* CHART_H */

