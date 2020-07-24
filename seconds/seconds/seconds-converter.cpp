//
//  seconds-converter.cpp
//
//  Lisa Lehrman
//  6/23/20
//  CS14E - Lab 3
//  A program that, given a number in seconds, will convert it to minutes, hours, and seconds.

#include <iostream>
using namespace std;

const int SECONDS_IN_MINUTE = 60;
const int SECONDS_IN_HOUR = 3600;

int main() {
    int seconds, cMinutes, cSeconds, nHours, nSeconds, nMinutes;
    
    cout << "Please enter a time in seconds." << endl;
    cin >> seconds;
    cout << "That is " << seconds << " seconds." << endl;
    
    if(seconds >= SECONDS_IN_MINUTE)
    {
        cMinutes = seconds / SECONDS_IN_MINUTE;
        cSeconds = seconds % SECONDS_IN_MINUTE;
        cout << "That is " << cMinutes << " minutes and " << cSeconds << " seconds." << endl;
    }
    if(seconds >= SECONDS_IN_HOUR)
    {
        
        nHours = seconds/SECONDS_IN_HOUR;
        nMinutes = (seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
        nSeconds = seconds % SECONDS_IN_MINUTE;

        cout << "That is " << nHours << " hours " << nMinutes << " minutes " << nSeconds << " seconds" << endl;
    }
    
    return 0;
}

// 3600 sec    1 hr
// 5400 sec    1.5h
// 7200 sec    2hr
// 7288 sec    2hr 1min and 28sec
// 8274 sec    2hr 17min 54sec
// 10000 sec
