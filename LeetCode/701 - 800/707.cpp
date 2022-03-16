// 707. Design Linked List

// my naive solution
class Node{
public:
    int val;
    Node *next;
};

class MyLinkedList {
public:
    Node* head;
    int length = -1;
    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        if(index > length){
            return -1;
        }
        int temp = 0;
        Node* ptr = head;
        while(ptr != NULL){
            if(temp == index) break;
            temp++;
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) {
        Node *newNode = new Node();
        newNode->val = val;
        length++;
        if(head == NULL){
            head = newNode;
            head->next = NULL;
            return;
        }
        else{
            Node* temp = head;
            head = newNode;
            head->next = temp;
        }
    }

    void addAtTail(int val) {
        Node *newNode = new Node();
        newNode->val = val;
        newNode->next = NULL;
        length++;
        if(head == NULL){
            head = newNode;
            return;
        }
        else{
            Node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        if(index == 0){
            Node *newNode = new Node();
            newNode->val = val;
            length++;
            newNode->next = head;
            head = newNode;
            return;
        }
        if(index == (length+1)){
            addAtTail(val);
            return;
        }
        if(index > (length + 1)){
            return;
        }
        Node *ptr = head;
        Node * prev = NULL;
        Node *newNode = new Node();
        newNode->val = val;
        length++;
        for(int i = 0; i < index;i++){
            prev = ptr;
            ptr = ptr->next;
        }
        newNode->next = ptr;
        prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        if(index > (length + 1))
            return;
        Node* ptr = head;
        if(index == 0){
            head = ptr->next;
            delete ptr;
            length--;
            return;
        }
        for(int i = 1; i < index;i++)
            ptr = ptr->next;
        if(ptr == NULL || ptr->next == NULL) return;
        length--;
        Node* temp = ptr->next->next;
        delete ptr->next;
        ptr->next = temp;
    }
};

// efficient solution using sentinel or dead node
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size=0;
    Node* head=new Node(0);
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp=head->next;
        head->next=new Node(val);
        head->next->next=temp;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=new Node(val);
        temp->next->next=temp1;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        size--;
        delete temp1;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
