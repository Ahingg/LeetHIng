int check2[14] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int parse(char* s) {
    int month, day;
    sscanf(s, "%d-%d", &month, &day);
    return check2[month-1] + day;
}
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}
int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
        int aliceStart = parse(arriveAlice), aliceEnd = parse(leaveAlice);
        int bobStart = parse(arriveBob), bobEnd = parse(leaveBob);
        if(bobStart > aliceEnd || aliceStart > bobEnd) return 0;
        return max(0, min(bobEnd, aliceEnd) - max(bobStart, aliceStart) + 1);
}