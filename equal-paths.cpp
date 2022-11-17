#include "equal-paths.h"
#include <iostream>
using namespace std;

#define INVALID -2
#define OUT_OF_TREE -1
#define LEAF 0

int lengthsIfEqual(Node* root) {
	// End of path
	if (root == NULL) {
		return OUT_OF_TREE;
	}

	// Get lengths of children
	const int leftLength = lengthsIfEqual(root->left);
	const int rightLength = lengthsIfEqual(root->right);

	// If ether child node is invalid
	if (leftLength == INVALID || rightLength == INVALID) return INVALID;

	if (leftLength == OUT_OF_TREE && rightLength == OUT_OF_TREE) {
		return 1;
	}

	if (leftLength == OUT_OF_TREE) return rightLength + 1;
	if (rightLength == OUT_OF_TREE) return leftLength + 1;

	if (leftLength == rightLength) return leftLength + 1;
	return INVALID;
}

bool equalPaths(Node* root) {
  // returns length if equal
	const int result = lengthsIfEqual(root);
	return (result != INVALID);
}

