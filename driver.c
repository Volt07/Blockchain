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
	old = head;
	head = add(head, "hanif");
	printf("add hanif: %d\n", head->next == old);
	old = head;
	head = add(head, "gahyun");
	printf("add gahyun: %d\n", head->next == old);
	old = head;
	head = add(head, "matt");
	printf("add matt: %d\n", head->next == old);
	old = head;
	head = add(head, "sumita");
	printf("add sumita: %d\n", head->next == old);
	old = head;
	head = add(head, "james");
	printf("add james: %d\n", head->next == old);
	verify(head);

	//test 1
	printf(head);

	//test 2
	printLog(head);

	//test 4
	for (struct User* node = head; node != NULL; node = node->next) 
		printDigest(node->hash);

	//test 5
	struct User copy = *head;;
	copy.hash.hash0 += 1;
	struct Digest d1, d2;
	generateDigest(&d1, head);
	generateDigest(&d2, &copy);
	printf("digest equal: %d\n", digest_equal(d1, d2));

	//test 6
	verify(head);
	printf("verifyResult: %d\n", verifyResult(head));

	//test 7
	printf("before tamper verify: %d\n", verifyResult(head));
	tamperName(head, 2, "tampered");
	printf("after tamper verify: %d\n", verifyResult(head));
	verify(head);

}