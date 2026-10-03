//
// Created by attam on 20/04/2024.
//

#ifndef UNTITLED2_SCHEDULING_H
#define UNTITLED2_SCHEDULING_H


#include <iostream>

#include "chrono"
#include "ctime"
// include json file
#include"./../../nlohmann/json.hpp"

using json = nlohmann::json;

using namespace std;

// Struct named time to get current time and display time in format of Hours : minutes: seconds: timeZone
struct Time {
    int hour;
    int min;
    int sec;
    string timeZone;


json toJson(){
    json j;
    j["hour"] = hour;
    j["min"] = min;
    j["sec"] = sec;
    j["timeZone"] = timeZone;
    return j;
}
static Time fromJson(const json & j){
    Time time;

    time.hour = j["hour"] ;
    time.min = j["min"] ;
    time.sec =  j["sec"] ;
    time.timeZone = j["timeZone"] ;
    return time;

}
    Time() {

        // Using chrono to obtain the current system time reliably and accurately,
        auto now = chrono::system_clock::now();
        time_t t = chrono::system_clock::to_time_t(now);
        tm local_tm = *localtime(&t);
        // set time
        hour = local_tm.tm_hour;
        // Extract hour from local time and convert to 12-hour format
        int hour24 = local_tm.tm_hour;
        hour = hour24 % 12;
        if (hour == 0) {
            hour = 12; // 12 AM
        }

        min = local_tm.tm_min;
        sec = local_tm.tm_sec;
        // Determine time zone (AM or PM)
        timeZone = (hour24 < 12) ? "AM" : "PM";

    }

    // Parameterized Constructor
    Time(int hour, int min, int sec, string timeZone) {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->timeZone = timeZone;
    }

    // Display Function
    void display() const {
        cout << "Hours: " << hour << " : " << min << " : " << sec << " " << timeZone << endl;
    }
};

// class using objects of Time
class Attendance {
    // objects of struct Time
    Time leavingTime;
    Time reportingTime;
    double thisDayHours;

public:


json toJson(){
    json j;
    j["leavingTime"] = leavingTime.toJson();
    j["reportingTime"] = reportingTime.toJson();
    j["thisDayHours"] = thisDayHours;
    return j;
}

static Attendance fromJson(const json & j){
    Attendance temp;
    temp.leavingTime = Time::fromJson( j["leavingTime"]);
    temp.reportingTime = Time::fromJson(j["reportingTime"]);
    temp.thisDayHours = j["thisDayHours"];
    return temp;
}
    //  Default Constructor
    Attendance() {
    }

    // Parameterized Constructor
    Attendance(const Time &leavingTime, const Time &reportingTime, int thisDayHours);

    // Getters
    Time getReportingTime();

    Time getLeavingTime();

    double getThisDayHours();

    // Setters
    void setReportingTime(Time &t);

    void setLeavingTime(Time &t);

    void setThisDayHours(double thisDayHours1);

    // Display Function to display attendance
    void displayAttendance();

    // Function to calculate hours of the day
    double calculateThisDayHours();

    
};

#endif //UNTITLED2_SCHEDULING_H