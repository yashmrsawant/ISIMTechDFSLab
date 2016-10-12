__author__ = 'yashmsawant'

class AVL:
    def __init__(self):
        self.val = None
        self.parent = None
        self.leftChild = None
        self.rightChild = None
        self.height = None
        self.bf = None
    def updateHeight(self):
        node = self
        while(node != None):
            if(node.leftChild == None):
                if(node.rightChild == None):
                    node.height = 0
                    node.bf = 0
                else:
                    node.height = node.rightChild.height + 1
                    node.bf = 0 - (node.rightChild.height + 1)
            elif(node.rightChild == None):
                node.height = node.leftChild.height + 1
                node.bf = node.leftChild.height + 1
            else:
                node.height = max(node.leftChild.height, node.rightChild.height) + 1
                node.bf = node.leftChild.height - node.rightChild.height
            node = node.parent
    def isLeftChild(self):
        if(self.parent != None and self.parent.leftChild == self):
            return True
    def addLeftChild(self, node):
        self.leftChild = node
        node.parent = self
        node.updateHeight()
    def addRightChild(self, node):
        self.rightChild = node
        node.parent = self
        node.updateHeight()

    def replace(self, nodetoBeReplace, nodetoReplace):
        if(nodetoBeReplace.isLeftChild() == True):
            self.leftChild = nodetoReplace
        else:
            self.rightChild = nodetoReplace

        if(nodetoReplace.rightChild == None):
            nodetoReplace.leftChild = nodetoBeReplace.leftChild
            nodetoReplace.rightChild = nodetoBeReplace.rightChild
        else:
            nodetoReplace.parent.rightChild = nodetoReplace.rightChild
            nodetoReplace.leftChild = nodetoBeReplace.leftChild
            nodetoReplace.rightChild = nodetoBeReplace.rightChild
