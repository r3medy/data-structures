/* Deleting a node cases:
 * 1. If leaf node: just delete
 * 2. If has 1 child: اعدل التوصيلة وامسح
 * 3. If has 2 children: Delete and replace with Minimum of right subtree
 * 
 * Finding successor:
 * 1. If node has a right subtree: We take the minimum of that right subtree
 * 2. If node doesn't have right subtree and it's the right child of a subtree: We go up the tree until we 
 * find a parent that's the left child of a parent root. That parent root is the successor
 * 3. If node doesn't have right subtree and it's the left child of a subtree: Its parent is the successor
 * 
 * Finding predessor:
 * 1. If node has a left subtree: We take the maximum of that left subtree
 * 2. If node doesn't have a left subtree and it's the left child of a subtree: We look up the tree until we find a reach a node
 * that our subtree was the right branch of it
 * 3. If node doesn't have a left subtree and it's the right child of a subtree: Its parent is the predessor
 */
