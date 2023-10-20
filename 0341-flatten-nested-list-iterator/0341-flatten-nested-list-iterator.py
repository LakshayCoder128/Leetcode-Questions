# Define the NestedInteger class if it's not already defined

class NestedIterator:
    def __init__(self, nestedList: List[NestedInteger]):
        self.nodes = list(reversed(nestedList))
    
    def next(self) -> int:
        return self.nodes.pop().getInteger()

    def hasNext(self) -> bool:
        while self.nodes:
            curr = self.nodes[-1]
            if curr.isInteger():
                return True
            self.nodes.pop()
            self.nodes.extend(reversed(curr.getList()))
        return False
