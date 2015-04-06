#ifndef __DIRECTORYDATETIME_H__
#define __DIRECTORYDATETIME_H__
/*
 * This class implements the Date-Time for a Directory or a file.
 * definition is found in ISO 9660 9.1.5.
 *
 * The default constructor will set all fields to zeros.
 */
class DirectoryDateTime {
protected:
	int year, month, day, hour, minute, second, greenwichOffset;

public:
	DirectoryDateTime(char *sevenBytes="\0\0\0\0\0\0\0");
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	int getGreenwichOffset() { return greenwichOffset; }
	char *getBytes();
};

#endif