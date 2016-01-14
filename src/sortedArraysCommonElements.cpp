/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compareDate(char date1[], char date2[]) {
	int d1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	int d2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	int month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	int month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	int year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	int year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	if (year1 < year2) 
		return 1;
	else if (year1 > year2) 
		return 2;
	else if (month1 < month2) 
		return 1;
	else if (month1 > month2) 
		return 2;
	else if (d1 < d2) 
		return 1;
	else if (d1 > d2) 
		return 2;
	else 
		return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL) {
		return NULL;
	}
	int AIndex = 0;
	int BIndex = 0;
	int compare;
	while (AIndex < ALen && BIndex < BLen) {
		compare = compareDate((A + AIndex)->date, (B + BIndex)->date);
		if (compare == 0) 
			return A + AIndex;
		else if (compare == 1) 
			AIndex++;
		else 
			BIndex++;
	}
	return NULL;
}