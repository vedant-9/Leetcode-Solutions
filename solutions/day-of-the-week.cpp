// https://leetcode.com/problems/day-of-the-week

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int daysInMonths [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string daysInWeek [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int sumOfDays = 0;
        
        // add the days in the year counting from 1971/1/1, Friday
        for(int i = 1971; i < year; i++)
        {
            sumOfDays += 365;
            if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) // check if it's leap year
                sumOfDays += 1; // there's an extra day in a leap year
        }
        
        // add the days in the month
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonths[1] = 29;
        for(int i = 0; i < month - 1; i++)
            sumOfDays += daysInMonths[i];
        
        // add the days in the day
        sumOfDays += day - 1;
        return daysInWeek[(sumOfDays+5) % 7]; // +5 because 1971/1/1 is Friday
    }
};