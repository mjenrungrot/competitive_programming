# https://open.kattis.com/problems/ceiling
# ACM-ICPC World Finals 2016

N,K = map(int, input().split())
A = []

def constructBST(xs):
    tree = {
        "node": xs[0],
        "left": None,
        "right": None
    }
    for x in xs[1:]:
        current_node = tree
        while True:
            if x > current_node["node"]:
                if(current_node["right"] is None):
                    current_node["right"] = {
                        "node": x,
                        "left": None,
                        "right": None,
                    }
                    break
                else: current_node = current_node["right"]
            else:
                if(current_node["left"] is None):
                    current_node["left"] = {
                        "node": x,
                        "left": None,
                        "right": None,
                    }
                    break
                else: current_node = current_node["left"]
    return tree

def getTreeRepresentation(tree, parent=None):
    answerLeft = ""
    answerRight = ""
    if(tree["left"] is not None): answerLeft = getTreeRepresentation(tree["left"], "left")
    if(tree["right"] is not None): answerRight = getTreeRepresentation(tree["right"], "right")
    
    if(parent is None):
        return answerLeft + "M" + answerRight

    if(tree["left"] is None and tree["right"] is None):
        if(parent == "left"): return "L"
        else: return "R"

    if(parent == "left"): return "[" + answerLeft + "M" + answerRight + "]"
    else                : return "[" + answerLeft + "M" + answerRight + "]"

treeShapes = set()

for i in range(N):
    xs = list(map(int, input().split()))
    A.append(xs)
    tree = constructBST(xs)
    treeShape = getTreeRepresentation(tree)
    treeShapes.add(treeShape)

print(len(treeShapes))
