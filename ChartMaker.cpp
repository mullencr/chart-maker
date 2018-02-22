#ifndef CHART_MAKER_CPP
#define CHART_MAKER_CPP

// Copyright (C) 2017 raodm@miamiOH.edu, mullencr@miamioh.edu

/*
  "It's good to have an end goal in mind, but it's the journey that matters.
 * This is your start in the journey. Enjoy the journey."
 * - Rao, after rephrasing the following 150 lines of code in 22 lines.
 */

#include <string>
#include "ChartMaker.h"

Point get_point(std::ostream& os);

/* This method was created by raodm to get me started on the project */
int
ChartMaker::run() {
    // Listen on a loop for commands
    char c;
    std::cout << "Enter command (h for help): ";
    while (std::cin >> c) {
        // Process will return 0 for any successful operation that is not quit
        // For quit, it will return -1, which will indicate that the main method
        // should end.
        if (this->process(std::cout, c) < 0)
            return 0;
        // This should never be reached if process returns -1.
        std::cout<< "Enter command (h for help): ";
    }
    return 0;
}

/* The remainder of the code in this file was written by Charles Mullenix */
int ChartMaker::process(std::ostream& os, const char c) {
    // Pass command to process()
    // process defers to many other methods via switch
    switch (c) {
        case 'q':   return -1;    
        case 'h':   this->help(os); break;
        case 'l':   this->load(os); break;
        case '+':   this->add(os); break;
        case '-':   this->subtract(os); break;
        case '*':   this->multiply(os); break;
        case '/':   this->divide(os); break;
        case '?':   this->hist(os); break;
        case '<':   this->shift_left(os); break;
        case '>':   this->shift_right(os); break;
        case 's':   this->save(os); break;
        case 'p':   this->print(os); break;
        default: os << "Invalid command." << std::endl;
    }
    return 0;
}

void ChartMaker::help(std::ostream& os) {
    os << "All commands are single characters." << std::endl;
    os << "Valid commands are:" << std::endl;
    os << "l: Load data from file as current set of points" << std::endl;
    os << "+: Add data from another to to current points" << std::endl;
    os << "-: Subtract data from another file from current poitns" << std::endl;
    os << "*: Scale current points by given pair of values" << std::endl;
    os << "/: Scale current points by given pair of values" << std::endl;
    os << "?: Print histogram current point distribution" << std::endl;
    os << "<: Shift points to left by a given value." << std::endl;
    os << ">: Shift points to right by a given value." << std::endl;
    os << "s: Save the current set of points to a given file" << std::endl;
    os << "p: Print current set of points on screen." << std::endl;
    os << "h: Print this message" << std::endl;
    os << "q: Quit" << std::endl;
}

void ChartMaker::load(std::ostream& os) {
    // I tried to put the following file code in a different method
    // I ran into an issue where I couldn't return the stream
    // It doesn't make sense to copy it into a new variable
    // If I store a reference to the stream, the stream object is destroyed
    // when the method ends, so it would throw an error.
    std::string file_name;
    os << "Enter path to file: ";
    std::cin >> file_name;
    std::ifstream fin(file_name);
    fin >> this->current;
}

void ChartMaker::add(std::ostream& os) {
    std::string file_name;
    os << "Enter path to file: ";
    std::cin >> file_name;
    std::ifstream fin(file_name);
    Chart temp;
    fin >> temp;
    this->current = this->current + temp;
}

void ChartMaker::subtract(std::ostream& os) {
    std::string file_name;
    os << "Enter path to file: ";
    std::cin >> file_name;
    std::ifstream fin(file_name);
    Chart temp;
    fin >> temp;
    this->current = this->current - temp;
}

void ChartMaker::multiply(std::ostream& os) {
    Point p = get_point(os);
    this->current = this->current * p;
}

void ChartMaker::divide(std::ostream& os) {
    Point p = get_point(os);
    this->current = this->current / p;
}

void ChartMaker::hist(std::ostream& os) {
    int max;
    os << "Enter max size for histogram: ";
    std::cin >> max;
    this->current.analyze(os, max);
}

void ChartMaker::shift_left(std::ostream& os) {
    int shift;
    os << "Enter positions to shift: ";
    std::cin >> shift;
    this->current = this->current << shift;
}

void ChartMaker::shift_right(std::ostream& os) {
    int shift;
    os << "Enter positions to shift: ";
    std::cin >> shift;
    this->current = this->current >> shift;
}

void ChartMaker::save(std::ostream& os) {
    std::string file_name;
    os << "Enter path to file: ";
    std::cin >> file_name;
    std::ofstream fout(file_name);
    fout << this->current;
}

void ChartMaker::print(std::ostream& os) {
    os << this->current << std::endl;
}

Point get_point(std::ostream& os) {
    os << "Enter values to scale x & y coordinates: ";
    Point p;
    std::cin >> p;
    return p;
}


#endif
