#include <iostream>
using namespace std;
class Time {
private:
    int hour;
    int minute;

public:

    Time() : hour(0), minute(0) {}


    Time(int h, int m)
    {
        setHour(h);
        setMinute(m);
    }


    void setHour(int h) {
        if (h >= 0 && h < 24) {
            hour = h;
        }
    }

    void setMinute(int m) {
        if (m >= 0 && m < 60) {
            minute = m;
        }
    }


    int getHour() const { return hour; }

    int getMinute() const { return minute; }

    Time& operator++() {
        if(hour == 24)
        {
            hour = 1;
        }else if(hour == 23){
            hour = 0;
        }else{
            hour += 1;
        }
        return *this;
    }


    Time operator++(int) {
        Time temp(*this);
        ++(*this);
        return temp;
    }


    friend istream& operator>>(istream& in, Time& time) {
        in >> time.hour;
        in >> time.minute;
        return in;
    }


    friend ostream& operator<<(ostream& out, const Time& time) {
            out << time.hour <<":"<<time.minute<<endl;
        return out;
    }


    Time& operator=(const Time& other) {
        if (this != &other) {
            hour = other.hour;
            minute = other.minute;
        }
        return *this;
    }
};
int main() {
    int n;
    cin >> n;
    int counter = 0;
    Time total_time[n];
    for(int i=0;i<n;i++)
    {
        cin >> total_time[i];
        ++total_time[i];
        
        if(total_time[i].getHour() > 12)
        {
            counter++;
        }
    }

    if(counter > 0)
    {
        for(int i=0;i<n;i++)
        {
            if(total_time[i].getHour() > 12)
            {
                cout << total_time[i];
            }
        }
    }
    if(counter == 0)
    {
        cout <<"Morning";
    }

    return 0;
}