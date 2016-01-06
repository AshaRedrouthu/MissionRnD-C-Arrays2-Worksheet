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
int stringCmp1(char *date1, char *date2)
{
	int i = 0;
	for (i = 0; i<10; i++){
		if (date1[i] != date2[i])
		{
			return 0;
		}
	}
	return 1;
}

int structCmp(struct transaction A, struct transaction B){
	if (A.amount == B.amount){
		if (stringCmp1(A.date, B.date)){
			if (stringCmp1(A.description, B.description)){
				return 1;
			}
		}
	}
	return 0;

}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen < 0 || B == NULL || BLen < 0)
		return NULL;
	int len = 0,k=0;
	int max = 0;
	if (ALen < BLen){
		len = ALen;
		max = BLen;
	}
	else{
		len = BLen;
		max = ALen;
	}
	struct transaction *C;
	C = (struct transaction *)malloc(sizeof(struct transaction) * len);
	for (int i = 0; i<max; i++)
	{
		for (int j = i; j < len; j++){
			if (structCmp(A[i], B[j])){
				C[k] = A[i];
				k++;

				}
		}

	}
	if (C == NULL)
		return nullptr;
	return C;

}