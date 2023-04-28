#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TimeSpan {
public:
    unsigned int hours_;
    unsigned int minutes_;
    unsigned int seconds_; 
    TimeSpan(unsigned int seconds) {
        hours_ = seconds / 3600;
        minutes_ = (seconds % 3600) / 60;
        seconds_ = seconds % 60;
    }

    unsigned int getHours() const { return hours_; }
    unsigned int getMinuts() const { return minutes_; }
    unsigned int getSeconds() const { return seconds_; }

    void print() {
        cout << getHours() << ":" << setfill('0') << setw(2) << getMinuts() << ":" << setfill('0') << setw(2) << getSeconds() << setfill('0') << setw(2);
    }
};