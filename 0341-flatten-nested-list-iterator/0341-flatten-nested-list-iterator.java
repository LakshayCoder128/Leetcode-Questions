// Import necessary libraries and classes

public class NestedIterator {
    private Stack<NestedInteger> nodes;

    public NestedIterator(List<NestedInteger> nestedList) {
        nodes = new Stack<>();
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; i--) {
            nodes.push(nestedList.get(i));
        }
    }

    public int next() {
        NestedInteger current = nodes.pop();
        return current.getInteger();
    }

    public boolean hasNext() {
        while (!nodes.isEmpty()) {
            NestedInteger current = nodes.peek();
            if (current.isInteger()) {
                return true;
            }
            nodes.pop();
            List<NestedInteger> adjs = current.getList();
            int size = adjs.size();
            for (int i = size - 1; i >= 0; i--) {
                nodes.push(adjs.get(i));
            }
        }
        return false;
    }
}
