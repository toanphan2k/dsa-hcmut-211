//BEGIN QUESTION 2.1
void walk(Node* root){
     /*YOUR CODE HERE*/
    if(root == NULL) return;

    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        Node* curr = nodeQueue.front();
        nodeQueue.pop();
        cout<< curr->data << " ";
        if(curr->pLeft != NULL){
            nodeQueue.push(curr->left);
        }
        if(curr->pRight != NULL){
            nodeQueue.push(curr->right);
        }
    }
}

//END QUESTION 2.1

//BEGIN QUESTION 2.2
int sumRecur(Node* root){
    if(root == NULL) return 0;

    else{
        return root->data + sumRecur(root->right) + sumRecur(root->left);
    }   
}
int sum(Node* root){
    return sumRecur(root);
}
//END QUESTION 2.2

//BEGIN QUESTION 2.3

int heightNode(Node* root){
    if(root == NULL) return 0;
    return 1 + max(heightNode(root->left), heightNode(root->right));
}

int height(Node* root){
     /*YOUR CODE HERE*/
    return heightNode(root);
}

//END QUESTION 2.3

//BEGIN QUESTION 2.4
XArrayList<int> collect(Node* root, int level){
      /*YOUR CODE HERE*/
     //Guideline: Use Queue to implement breadth-first traversal
    if(root == NULL) return;

    queue<Node*> nodeQueue;
    // abc
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        level--;
        if(level == 0 && !nodeQueue.empty()){
            cout <<"[";
            while(!nodeQueue.empty()){
                Node* temp = nodeQueue.front();
                nodeQueue.pop();
                cout<< temp->data << " ";
            }
            cout <<"]";
            return;
        }
        if(level == 0 && nodeQueue.empty()){
            return;
        }
        Node* curr = nodeQueue.front();
        nodeQueue.pop();
        if(curr->pLeft != NULL){
            nodeQueue.push(curr->left);
        }
        if(curr->pRight != NULL){
            nodeQueue.push(curr->right);
        }
    }
}

//END QUESTION 2.4

//BEGIN QUESTION 2.5
SNode* reverse(SNode *head){
      /*YOUR CODE HERE*/
    //Guideline: Using stack of snodes: push all and then pop all to create the result/
    if(head == NULL) return;
    stack<SNode* node> stack;
    SNode * temp = head;
    while(temp){
        stack.push(temp);
        temp= temp->next;
    }
    Snode* temp2 = stack.pop();
    while (!stack.empty()){
        temp2->next = stack.pop();
        temp2 = temp2->next;
    }
}
//END QUESTION 2.5
