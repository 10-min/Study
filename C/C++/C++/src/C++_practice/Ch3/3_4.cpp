#include <iostream>
int main() {
    using namespace std;

    const int HoursPerDay {24};
    const int MinutesPerHour {60};
    const int SecondsPerMinutes {60};

    long time;

    cout << "초 수를 입력하십시오: ";
    cin >> time;

    int days, hours, minutes, seconds;
    minutes = time / SecondsPerMinutes;
    seconds = time % SecondsPerMinutes;
    hours = minutes / MinutesPerHour;
    minutes %= MinutesPerHour;
    days = hours / HoursPerDay;
    hours %= HoursPerDay;

    cout << time << "초" << " = " << days <<"일, "
    << hours << "시간, " << minutes << "분, "
    << seconds << "초";
    
    return 0;
}