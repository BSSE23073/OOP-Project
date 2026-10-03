//
// Created by attam on 20/04/2024.
//

#include "Attendence.h"

Attendance::Attendance(const Time &leavingTime, const Time &reportingTime, int thisDayHours) : leavingTime(
        leavingTime), reportingTime(reportingTime), thisDayHours(thisDayHours) {}

Time Attendance::getReportingTime() {
    return reportingTime;
}

void Attendance::setReportingTime(Time &t) {
    reportingTime = t;
}

Time Attendance::getLeavingTime() {
    return leavingTime;
}

void Attendance::setLeavingTime(Time &t) {
    leavingTime = t;
}


double Attendance::getThisDayHours() {
    return thisDayHours;
}

void Attendance::setThisDayHours(double thisDayHours1) {
    thisDayHours = thisDayHours1;
}

void Attendance::displayAttendance() {
    cout << "Reporting Time: ";
    reportingTime.display();
    cout << "Leaving Time: ";
    leavingTime.display();
}

double Attendance:: calculateThisDayHours() {
    if(reportingTime.hour == leavingTime.hour && leavingTime.timeZone == reportingTime.timeZone){
        // add  min in total time
        setThisDayHours(0.0);
        return thisDayHours;
    }
    // hour has 60 min
    Time start = reportingTime;
    Time leave = leavingTime;
    int min = 60 - start.min;
    int hourCount = 0;
    start.hour++;

    // bound that employee must leave at 9pm
    if (leave.hour > 9 && leave.timeZone == "pm") {
        // not include that time hour
        leave.hour = 9;
    }

    while (true) {

        start.hour++;
        hourCount++;
        if (start.hour >= 12) {
            start.hour = 0;
            start.timeZone="PM";
        }
        if (start.hour == leave.hour && start.timeZone == leave.timeZone) {
            break;
        }
    }
    min += leave.min;
    if (min >= 60) {
        hourCount++;
        min -= 60;
    }
    double count = hourCount + (static_cast<double >(min) /
                                60.0); //static cast method to change data type of min from int to double
    // add  min in total time
    setThisDayHours(count);
    return thisDayHours;
}