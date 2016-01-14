/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compareDate(char date1[], char *date2) {
	int d1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	int d2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	int month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	int month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	int year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	int year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	if (year1 < year2) {
		return 1;
	}
	else if (year1 > year2) {
		return 2;
	}
	else {
		if (month1 < month2) {
			return 1;
		}
		else if (month1 > month2) {
			return 2;
		}
		else {
			if (d1 < d2) {
				return 1;
			}
			else if (d1 > d2) {
				return 2;
			}
			else {
				return 0;
			}
		}
	}

}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int start = 0;
	int end = len - 1;
	int compare;
	while (start < end) {
		compare = compareDate((Arr + start)->date, date);
		if (compare == 1)
			start += 1;
		else if (compare == 0) {
			start += 1;
			break;
		}
		compare = compareDate((Arr + end)->date, date);
		if (compare == 2)
			end -= 1;
		else if (compare == 0)
			return len - end - 1;
	}
	while (start < end) {
		compare = compareDate((Arr + start)->date, date);
		if (compare == 0)
			start += 1;
		else
			return len - start;
	}
	if (start == end)
		return len - end - 1;
	return -1;
}
