# chart-maker
This was a homework assignment for High Performance Computing where I practiced operator overloading in C++. Once compiled, it provides a command-line interface with which the user can add and drop cartesian coordinate points to a Chart object, then perform certain operations on those points. The user can scale points up or down, add or subtract data from files, save the current chart to a text file, and print a histogram of the Chart's quadrant distribution.

It wasn't too advanced as far was what I've done in the class, but it was good practice with OOP in C++. Point.h and Point.cpp are both written by my professor, Dr. Rao. Otherwise, aside from twenty or so lines of code for the main method and the run method, this was all written myself.

To run this code, compile it all together using the following command in the working directory:
```
    g++ -g -Wall -std=c++14 -O3 Chart.* Point.* ChartMaker.* main.cpp -o ChartMaker
```

After that, simply run the executable and begin working with the test files included in this directory
