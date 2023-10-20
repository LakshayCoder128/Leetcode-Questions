// Import necessary libraries and classes

public class NestedIterator {
    private Stack<NestedInteger> nodes;

    public NestedIterator(IList<NestedInteger> nestedList) {
        nodes = new Stack<NestedInteger>();
        int size = nestedList.Count;
        for (int i = size - 1; i >= 0; i--) {
            nodes.Push(nestedList[i]);
        }
    }

    public int Next() {
        NestedInteger current = nodes.Pop();
        return current.GetInteger();
    }

    public bool HasNext() {
        while (nodes.Count > 0) {
            NestedInteger current = nodes.Peek();
            if (current.IsInteger()) {
                return true;
            }
            nodes.Pop();
            List<NestedInteger> adjs = new List<NestedInteger>(current.GetList()); // Explicit cast here
            int size = adjs.Count;
            for (int i = size - 1; i >= 0; i--) {
                nodes.Push(adjs[i]);
            }
        }
        return false;
    }
}
