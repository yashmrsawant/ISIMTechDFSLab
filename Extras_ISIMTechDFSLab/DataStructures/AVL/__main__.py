__author__ = 'yashmsawant'
__date__ = "8th Oct 2016"
__desc__ = "AVL Tree Implementation"
__acks__ = "Using Adel'son Velski properties in BST"


from AVLTree import avlTree


def rotate_left(node):
    ##
    #   Update the parent info and rotate left about node -> node.leftChild edge
    #       that is tempNode i.e. node.leftChild is edging node and node's parent become tempNode's parent
    ##
    tempNode = node.leftChild
    tempNode.parent = node.parent
    if(tempNode.rightChild != None):
        node.leftChild = tempNode.rightChild
    tempNode.rightChild = node
    node.parent = tempNode
    node.updateHeight()


def rotate_right(node):
    ##
    #   Updates the parent info and rotate right about node -> node.rightChild edge
    #       that is tempNode i.e. node.rightChild is edging node and node's parent become tempNode's parent
    ##
    tempNode = node.rightChild
    tempNode.parent = node.parent
    if(tempNode.leftChild != None):
        node.rightChild = tempNode.leftChild
    tempNode.leftChild = node
    node.parent = tempNode
    node.updateHeight()

def balance(node, case):
    ##
    #   See towards left from node if case is True
    #   No need to check node.bf = -2 and node.leftChild.bf = [0, 1, -1]
    #   No need to check node.bf = [-1, 1] and node.leftChild.bf = [0, 1, -1]
    ##
    if case == True:
        if(node.bf == 0 and abs(node.leftChild.bf) in [0, 1]):
            return node.height
        elif(node.bf == 2 and node.leftChild.bf == 1):
            rotate_left(node)
        elif(node.bf == 2 and node.leftChild.bf == -1):
            rotate_right(node.leftChild)
            rotate_left(node)
    else:
        ##
        #   See towards right from node if case is False
        #   No need to check node.bf = 2 and node.rightChild.bf = [0, 1, -1]
        #   No need to check node.bf = [-1, 1] and node.rightChild.bf = [0, 1, -1]
        ##
        if(node.bf == 0 and abs(node.rightChild.bf) in [0, 1]):
            return
        elif(node.bf == -2 and node.rightChild.bf == 1):
            rotate_left(node.rightChild)
            rotate_right(node)
        elif(node.bf == -2 and node.rightChild.bf == -1):
            rotate_right(node)

    if(node.parent == None):
        return
    else:
        balance(node.parent, node.isLeftChild())


def updateHeightFrom(node):
    while(node.parent != None):
        node = node.parent
        if(node.leftChild == None):
            node.height = node.rightChild.height + 1
        elif(node.rightChild == None):
            node.height = node.leftChild.height + 1
        else:
            node.height = max(node.leftChild, node.rightChild) + 1


def insert(avlTree, node):
    if(avlTree == None):
        avlTree = node


    else:
        ## Find a node down the avlTree where node can be inserted satisfying BST property

        node1 = avlTree

        while(node1 != None):
            if(node1.val > node.val):
                if(node1.leftChild == None):
                    ##
                    #   Inserting node
                    ##
                    node1.addLeftChild(node)
                    break
                else:
                    node1 = node1.leftChild

            elif(node1.val < node.val):
                if(node1.rightChild == None):
                    ##
                    #   Inserting node
                    ##
                    node1.addRightChild(node)
                    break
                else:
                    node1 = node1.rightChild
        balance(node.parent, node.isLeftChild())

def updateHeightAt(node):
    stack = []
    stack.append(node)
    while(len(stack) > 0):
        node1 = stack[len(stack) - 1]
        if(node1.leftChild == None):
            if(node1.rightChild == None):
                node1.height = 0
                stack.pop()
            else:
                stack.append(node1.rightChild)
        elif(node1.rightChild == None):
            stack.append(node1.leftChild)
        else:
            node1.height = node1.leftChild.height - node1.rightChild
            stack.pop()

def delete(node):
    node1 = node
    if(node1.leftChild == None):
        ##
        # By AVL property we know that the balance structure has to be same in either case
        #   therefore, just popping the successor in this case and inserting into the
        #   node's position
        ##
        if(node1.rightChild != None):
            node1 = node.rightChild
            while(node1.leftChild != None):
                node1 = node1.leftChild
    else:
        ##
        #   Similarly popping the predecessor and inserting into the node's position
        #
        ##
        while(node1.leftChild != None):
            node1 = node1.leftChild

    ##
    #   By this time we know the successor or predecessor in inorder bst
    #   insert it into node's position
    ##

    parent = node1.parent
    node.parent.replace(node1)

    while(True):
        if(node1.bf - (node1.leftChild.height - node1.rightChild.height) != 0):
            ##
            #   Do all the balancing operation here
            #   If this condition holds then there is height change
            ##
            if(node1.isLeftChild == True):
                parent = node1.parent
                parentBalanceFactor = parent.leftChild.height - parent.rightChild.height
                sibling = parent.rightChild
                if(sibling != None):
                    if(parentBalanceFactor == -2 and sibling.bf == 1):
                        rotate_left(sibling)
                        rotate_right(parent)
                    elif(parentBalanceFactor == -2 and sibling.bf == -1):
                        rotate_right(parent)
                else:
                    node1 = parent

            else:
                parent = node1.parent
                parentBalanceFactor = parent.leftChild.height - parent.rightChild.height
                sibling = parent.leftChild
                if(sibling != None):
                    if(parentBalanceFactor == 2 and sibling.bf == 1):
                        rotate_left(parent)
                    elif(parentBalanceFactor == -2 and sibling.bf == -1):
                        rotate_right(sibling)
                        rotate_left(parent)
                else:
                    node1 = parent
        else:
            break

def find(node, val):
    found = False
    position = None
    if(node.val == None):
        return [found, position]
    while(node != None):
        if(node.val > val):
            node = node.leftChild
        elif(node.val < val):
            node = node.rightChild
        else:
            found = True
            position = node
            break
    return [found, position]


def execs(root):
    while(True):
        input = raw_input().split(' ')
        input[0] = str(input[0])
        input[1] = int(input[1])

        if(find(root, input[1])[0] == True):
            if(input[0].lower() == 'insert'):
                print("Insert Not Valid as ", str(input[1]), " found in tree having root ", str(root))
            elif(input[0].lower == 'delete'):
                delete(find(root, input[1])[1])
            else:
                print("Type Exit for Exiting...")
        else:
            if(input[0].lower() == 'insert'):
                if(root.val == None):
                    root.val = input[1]
                else:
                    node = avlTree.AVL()
                    node.val = input[1]
                    insert(root, node)
            elif(input[0].lower == 'delete'):
                print("Delete Not Valid as ", str(input[1]), " not found in tree having root ", str(root))
            else:
                print("Type Exit for Exiting...")

root = avlTree.AVL()
execs(root)