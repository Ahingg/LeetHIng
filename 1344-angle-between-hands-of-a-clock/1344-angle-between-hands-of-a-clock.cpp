class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        // anggap jam 12 itu sebagai pivot.
        double dHour = (double)hour;
        double dMin = (double)minutes / ((double)5);
        double minDeg = (abs((dMin > dHour) ? dMin - dHour : dHour - dMin) * 30.0); 
        double extraDeg = (dMin / 12.0) * 30.0;

        double r = abs(minDeg - extraDeg);
        if(hour < 1.0) return (min(360.0 - r, r));
        if(dHour >= dMin) return min(minDeg + extraDeg, 360.0 - (minDeg + extraDeg));
        return min(360.0 - r, r);
    }
};