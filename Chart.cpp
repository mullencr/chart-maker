// Copyright 2017 Charles Mullenix

#include <string>
#include <algorithm>
#include <vector>

#include "Chart.h"

Chart::Chart() {
}

Chart::Chart(const Chart& orig) : pointList(orig.pointList) {
}

Chart::Chart(const std::string& fileName) {
    std::ifstream infile(fileName);
    Point p;
    while (infile >> p)
        this->pointList.push_back(p);
}

Chart::~Chart() {
}

std::ostream& operator<<(std::ostream& os, const Chart& c) {
    for (Point p : c.pointList)
        os << p << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Chart& c) {
    Point p;
    while (is >> p)
        c.pointList.push_back(p);
    return is;
}

Chart& Chart::operator=(const Chart& src) {
    this->pointList = src.pointList;
    return *this;
}

bool Chart::contains(const Point& p) const {
    return (std::find(this->pointList.begin(), this->pointList.end(), p)
                != this->pointList.end());
}

Chart Chart::operator+(const Chart& other) const {
    Chart c(*this);
    std::copy_if(other.pointList.begin(), other.pointList.end(), 
                std::back_inserter(c.pointList), 
                [&](Point p){return !(c.contains(p));});
    return c;
}

Chart Chart::operator-(const Chart& other) const {
    Chart c;
    std::copy_if(this->pointList.begin(), this->pointList.end(), 
                std::back_inserter(c.pointList), 
                [&](Point p){return !(other.contains(p));});
    return c;
}

Chart Chart::operator*(const Point& scale) const {
    Chart c(*this);
    std::transform(c.pointList.begin(), c.pointList.end(), c.pointList.begin(),
            [&](Point& p) -> Point {
                return Point((p.getX() * scale.getX()), 
                        (p.getY() * scale.getY()));
            });
    return c;        
}

Chart Chart::operator/(const Point& scale) const {
    Chart c(*this);
    std::transform(c.pointList.begin(), c.pointList.end(), c.pointList.begin(),
            [&](Point& p) -> Point {
                return Point((p.getX() / scale.getX()),
                        (p.getY() / scale.getY()));
            });
    return c;
}

Chart Chart::operator>>(int value) const {
    Chart c(*this);
    c.pointList.insert(c.pointList.begin(), value, Point(0, 0));
    return c;
}

Chart Chart::operator<<(int value) const {
    Chart c(*this);
    // If I make i size_t it throws a compiler warning due to type of value
    for (int i = 0; i < value; i++)
        c.pointList.erase(c.pointList.begin());
    return c;
}

void Chart::analyze(std::ostream& os, const int scale) const {
    std::vector<int> quad_count(4, 0);
    for (Point p : this->pointList)
        quad_count[(p.getQuadrant()-1)]++;
    int max = *std::max_element(quad_count.begin(), quad_count.end());
    os << "I  : " << std::string((quad_count[0]*scale/max), '*') << std::endl;
    os << "II : " << std::string((quad_count[1]*scale/max), '*') << std::endl;
    os << "III: " << std::string((quad_count[2]*scale/max), '*') << std::endl;
    os << "IV : " << std::string((quad_count[3]*scale/max), '*') << std::endl;
}


