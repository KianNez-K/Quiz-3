#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "interquartile_range.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.

	// each section runs the setup code independently to ensure that they don't affect each other

// you must write 5 unique, meaningful tests for credit on the testing portion of this quiz!

// the provided tests from edugator are below. Note that you must determine the correct output for the [output_hidden] tests yourself

TEST_CASE("Function: IQR 1", "w/ negatives & 0") {
	std::vector<int> v = {-1, 0, 0, 2, 4, 6};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "less than 4") {
	std::vector<int> v = {1, 2, 3};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 1.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


TEST_CASE("Function: IQR 3", "1 value") {
	std::vector<int> v = {3};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 0);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 4", "Unordered") {
	std::vector<int> v = {3, 5, 2, 1, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5", "Backwards") {
	std::vector<int> v = {10, 8, 6, 4, 3};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 5.5);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
