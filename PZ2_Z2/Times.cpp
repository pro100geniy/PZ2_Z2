#include <iostream>
#include <iomanip>
using namespace std;
class Time {
private:
    int hrs;
    int mins;  
    int secs;  

public:
    Time() : hrs(0), mins(0), secs(0) {}
    Time(int h, int m, int s) {
        hrs = h % 24;   
        mins = m % 60;  
        secs = s % 60;  
    }

    
    void display() const {
       cout << setfill('0') << setw(2) << hrs << ":" << setfill('0') << setw(2) << mins << ":" << setfill('0') << setw(2) << secs << endl;
    }

   
    Time add_time(const Time& t) const {
        int total_secs = (hrs * 3600 + mins * 60 + secs) + (t.hrs * 3600 + t.mins * 60 + t.secs);
        return Time(total_secs / 3600 % 24, (total_secs / 60) % 60, total_secs % 60);
    }

    
    Time ded_time(const Time& t) const {
        int total_secs1 = hrs * 3600 + mins * 60 + secs;
        int total_secs2 = t.hrs * 3600 + t.mins * 60 + t.secs;
        int diff = total_secs1 - total_secs2;

        if (diff < 0) {
            diff += 24 * 3600;
        }

        return Time(diff / 3600 % 24, (diff / 60) % 60, diff % 60);
    }
};

int main() {
    
    const Time time1(10, 22, 33);
    const Time time2(10, 44, 44);

    
    Time time3; 
    Time time4; 

    
    time3 = time1.add_time(time2);
    time4 = time1.ded_time(time2);

    
    cout << "Time1: ";
    time1.display();

    cout << "Time2: ";
    time2.display();

    cout << "Time3: ";
    time3.display();

    cout << "Time4: ";
    time4.display();

    return 0;
}