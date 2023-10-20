// Define the NestedIterator class if it's not already defined

class NestedIterator {
    constructor(nestedList) {
        this.nodes = [];
        for (let i = nestedList.length - 1; i >= 0; i--) {
            this.nodes.push(nestedList[i]);
        }
    }

    next() {
        return this.nodes.pop().getInteger();
    }

    hasNext() {
        while (this.nodes.length > 0) {
            const current = this.nodes[this.nodes.length - 1];
            if (current.isInteger()) {
                return true;
            }
            this.nodes.pop();
            const adjs = current.getList();
            for (let i = adjs.length - 1; i >= 0; i--) {
                this.nodes.push(adjs[i]);
            }
        }
        return false;
    }
}
