/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include <stdlib.h>

struct node {
	int value;
	int count;
	struct node *next;
};

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int i;
	struct node *heads[10];
	struct node *iter;
	for (i = 0; i < 10; i++) {
		heads[i] = (struct node *) malloc(sizeof(struct node));
		heads[i]->next = NULL;
		heads[i]->value = -1;
		heads[i]->count = 0;
	}
	for (i = 0; i < len; i++) {
		iter = heads[A[i] % 10];
		while (iter->next != NULL && iter->value != A[i])
			iter = iter->next;
		if (iter->value == A[i])
			iter->count += 1;
		else {
			if (iter->value != -1) {
				iter->next = (struct node *) malloc(sizeof(struct node));
				iter = iter->next;
				iter->next = NULL;
			}
			iter->value = A[i];
			iter->count = 1;
		}
	}
	for (i = 0; i < 10; i++) {
		iter = heads[i];
		while (iter != NULL && iter->count != 1) {
			iter = iter->next;
		}
		if (iter != NULL && iter->count == 1)
			return iter->value;
	}
	return -1;
}