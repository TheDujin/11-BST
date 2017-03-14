/*
 * BinaryNode.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: 293359
 */

#include <iostream>
#include "BinaryNode.h"
using namespace std;

//Constructs a Node
BinaryNode::BinaryNode(int newData) {
  data = newData;
  left = NULL;
  right = NULL;
}
//Return left
BinaryNode* BinaryNode::getLeft() {
  return left;
}
//Return right
BinaryNode* BinaryNode::getRight() {
  return right;
}
//Return data
int BinaryNode::getData() {
  return data;
}
//Sets left BinaryNode
void BinaryNode::setLeft(BinaryNode* newLeft) {
  left = newLeft;
}
//Sets right BinaryNode
void BinaryNode::setRight(BinaryNode* newRight) {
  right = newRight;
}
//Destructs the BinaryNode
BinaryNode::~BinaryNode() {
}





