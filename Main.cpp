/*
 * Heap.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: Kevin Jin
 */
//Import everything I need
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "BinaryNode.h"

using namespace std;

//Function prototypes
void add(BinaryNode* & root, int newNode);
//void pop_off(int* & heap, int iterator);
//void down_heap(int* & heap, int pos, int iterator);
void print(BinaryNode* root);

//Main method which does pretty much everything
int main () {
	//Checks for valid input ("file" or "console).
	bool valid = false;
	while (!valid) {
		//Initializes heap as an int* and initialize iterator as a way of finding the size of the heap.
//		int* heap = new int[101];
//		int iterator = 0;
		BinaryNode* root = NULL;
		char choose;
		//Input the first char of what the user types. If it's a c or f, choose console or file respectively.
		cout << "Do you want to enter the numbers through the console or through a file?" << endl << "Choose: ";
		cin >> choose;
		cin.ignore(256, '\n');
		//They gave us valid input, so we ask them for the file.
		if (choose == 'f') {
			valid = true;
			char fileIn[81];
			cout << "Input the path to the input file." << endl << "Path: ";
			cin >> fileIn;
			//Attempt to open file. If it opens, read contents and create heap. Otherwise, program kills itself.
			ifstream input (fileIn);
			if (input.is_open()) {
				char* nums = new char[501];
				//If file isn't empty, get and print contents.
				if (!input.eof()) {
					input.getline(nums, 500);
					cout << "File contents:" << endl;
					cout << nums;
					//We walk through the input from the file and add numbers as we find them to the heap.
					int temp = 0;
					bool isNum = false;
					//If it's a digit, multiply temp (the preexisting portion of the number) by 10 then add the digit.
					for (int i = 0; i < strlen(nums); i++) {
						if (isdigit(nums[i])) {
							temp *= 10;
							temp += nums[i] - '0';
							isNum = true;
						}
						//Otherwise if it's whitespace, add the number to heap and then up-heap.
//						else if (nums[i] != '\0' && nums[i] != '\n'){
//							heap[iterator] = temp;
//							up_heap(heap, iterator);
//							temp = 0;
//							iterator++;
//							isNum = false;
//						}
					}
					//This here is a workaround to deal with loose zeroes being appended to input.
//					if (isNum) {
//						heap[iterator] = temp;
//						up_heap(heap, iterator);
//						temp = 0;
//					}
//					if (!isNum) {
//						iterator--;
//					}
//					//Print the heap.
//					cout << endl << "This is the heap:" << endl;
//					print_heap(heap, iterator);
//					//We make one call to pop-off and we're done.
//					cout << endl << "After sort:" << endl;
//					pop_off(heap, iterator);
//
				}

				input.close();
			}
			else cout << "Unable to open file";
		}
		//If they want to input from console, read their input from console then proceed the exact same way as in file.
		else if (choose == 'c') {
			valid = true;
			char* nums = new char[501];
			cout << "Input the numbers, each separated by a space." << endl << "Numbers: ";
			cin.getline(nums, 500);
			cout << "File contents:" << endl;
			cout << nums;
			//Creates heap the same way as if input was from file.
			int temp = 0;
			bool isNum = false;
			for (int i = 0; i < strlen(nums); i++) {
				if (isdigit(nums[i])) {
					temp *= 10;
					temp += nums[i] - '0';
					isNum = true;
				}
//				else if (nums[i] != '\0' && nums[i] != '\n'){
//					heap[iterator] = temp;
//					up_heap(heap, iterator);
//					temp = 0;
//					iterator++;
//					isNum = false;
//				}
			}
//			if (isNum) {
//				heap[iterator] = temp;
//				up_heap(heap, iterator);
//				temp = 0;
//			}
//			if (!isNum) {
//				iterator--;
//			}
//			cout << "This is the heap:" << endl;
//			print_heap(heap, iterator);
//			cout << endl << "After sort:" << endl;
//			pop_off(heap, iterator);
		}
		else
			cout << "That input is invalid." << endl;
	}
	return 0;
}
//Checks if the specific node in the heap is larger than its parent, and if so switch them and call up-heap recursively.
//Otherwise if the node is already the root or the node is not larger than parent, do nothing.
void add(BinaryNode* & root, int newNode) {
	BinaryNode* current = root;
	if (root == NULL)
		root = new BinaryNode(newNode);
	else {
		bool hasAdded = false;
		while (!hasAdded) {
			if (newNode > current->getData()) {
				if (current->getRight() == NULL) {
					current->setRight(new BinaryNode(newNode));
					hasAdded = true;
				}
				else
					current = current->getRight();
			}
			else {
				if (current->getLeft() == NULL) {
					current->setLeft(new BinaryNode(newNode));
					hasAdded = true;
				}
				else
					current = current->getLeft();
			}
		}
	}
}
////Prints the current root, replaces it with the node at the bottom-right, then down-heaps. Then it recursively calls itself.
////If iterator is 0 (tree has only one node on it) then print that node.
//void pop_off(int* & heap, int iterator) {
//	if (iterator > 0) {
//		cout << heap[0] << " ";
//		heap[0] = heap[iterator];
//		iterator--;
//		down_heap(heap, 0, iterator);
//		pop_off(heap, iterator);
//	}
//	else
//		cout << heap[0] << " ";
//}
////We take the node and switch it with the larger of its children IF one or more of its children is larger than it.
////If the node is larger than both of its children or the node is at the bottom-most level of the tree, we do nothing.
//void down_heap(int* & heap, int pos, int iterator) {
//	if ((int)log2(pos + 1) < (int)log2(iterator + 1)) {
//		if (heap[pos] < heap[pos * 2 + 1]) {
//			if (heap[pos] < heap[pos * 2 + 2]) {
//				if (heap[pos * 2 + 1] > heap[pos * 2 + 2]) {
//					int temp = heap[pos];
//					heap[pos] = heap[pos * 2 + 1];
//					heap[pos * 2 + 1] = temp;
//					down_heap(heap, pos * 2 + 1, iterator);
//				}
//				else {
//					int temp = heap[pos];
//					heap[pos] = heap[pos * 2 + 2];
//					heap[pos * 2 + 2] = temp;
//					down_heap(heap, pos * 2 + 2, iterator);
//				}
//			}
//			else {
//				int temp = heap[pos];
//				heap[pos] = heap[pos * 2 + 1];
//				heap[pos * 2 + 1] = temp;
//				down_heap(heap, pos * 2 + 1, iterator);
//			}
//		}
//		else if (heap[pos] < heap[pos * 2 + 2]) {
//			int temp = heap[pos];
//			heap[pos] = heap[pos * 2 + 2];
//			heap[pos * 2 + 2] = temp;
//			down_heap(heap, pos * 2 + 2, iterator);
//		}
//	}
//}
//Prints heap. If the node is on a new layer, add a new line then the node, otherwise add a space then the node.
void print(BinaryNode* root) {
	bool left = false;
	bool right = false;
	cout << "Node: " << root->getData() << endl;
	if (root->getLeft() != NULL) {
		cout << "Left child: " << root->getLeft()->getData() << endl;
		left = true;
	}
	else
		cout << "Left child: None" << endl;
	if (root->getRight() != NULL) {
		cout << "Right child: " << root->getRight()->getData() << endl;
	}
	else
		cout << "Right child: None" << endl;
	if (left)
		print(root->getLeft());
	if (right)
		print(root->getRight());
}
