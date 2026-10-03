#include <stdio.h>
#include <string.h>
#include "user.h"
void tamperName(struct User* head, int n, const char* newName);
void tamperHash(struct User* head, int n);
int hashMatches(struct User* node);
int verifyResult(struct User* head);


int main(void) {
	struct User * head = NULL;
	struct User* old = NULL;

	//TEST 3
	head = add(head, "rob");
	printf("add rob: %d\n", head->next == old);
	head = add(head, "hanif");
	printf("add hanif: %d\n", head->next == old);
	head = add(head, "gahyun");
	printf("add gahyun: %d\n", head->next == old);
	head = add(head, "matt");
	printf("add matt: %d\n", head->next == old);
	head = add(head, "sumita");
	printf("add sumita: %d\n", head->next == old);
	head = add(head, "james");
	printf("add james: %d\n", head->next == old);
	verify(head);
}