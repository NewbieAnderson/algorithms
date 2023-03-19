interface LinkedListNode<T> {
  head: LinkedListNode<T>;
  tail: LinkedListNode<T>;
  value: T;
};

interface BinaryTreeNode<T> {
  lChild: BinaryTreeNode<T>;
  rChild: BinaryTreeNode<T>;
  value: T;
};

interface GraphNode<T> {
  neighbors: GraphNode<T>[];
  value: T;
};

export { LinkedListNode, BinaryTreeNode, GraphNode };
