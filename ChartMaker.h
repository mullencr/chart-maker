/* 
 * Copyright 2017 Charles Mullenix
 * 
 * Template code provided by raodm
 */

#ifndef CHART_MAKER_H
#define CHART_MAKER_H

#include <vector>
#include "Point.h"
#include "Chart.h"

/** A top-level class to perform operations on chart objects based on
	user input.

	NOTE: You may modify/add as many methods or instance variables
	as needed to design this class.
	
	Copyright (C) 2017 raodm@miamiOH.edu
*/
class ChartMaker {
    public:
        ChartMaker() {}
        ~ChartMaker() {}
        int run();
        int process(std::ostream& os, const char c);
        void help(std::ostream& os);
        void load(std::ostream& os);
        void add(std::ostream& os);
        void subtract(std::ostream& os);
        void multiply(std::ostream& os);
        void divide(std::ostream& os);
        void hist(std::ostream& os);
        void shift_left(std::ostream& os);
        void shift_right(std::ostream& os);
        void save(std::ostream& os);
        void print(std::ostream& os);
    private:
        Chart current;
};

#endif
