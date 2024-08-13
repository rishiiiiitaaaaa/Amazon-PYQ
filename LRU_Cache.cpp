class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key,int value){
            this->key=key;
            this->value=value;
            prev= NULL;
            next=NULL;
        }
    };
    Node* head= new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int n;
    unordered_map<int,Node* > ump;

    LRUCache(int capacity) {
        n=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newnode){
        Node* temp=head->next;

        newnode->next=temp;
        newnode->prev=head;

        head->next=newnode;
        temp->prev=newnode;
  
    }

    void deleteNode(Node* delnode){
        Node* tempnext = delnode->next;
        Node* temp= delnode;

        temp->prev->next = temp->next;
        tempnext->prev = temp->prev;
    
    }

    int get(int key) {
        if(ump.find(key) != ump.end()){
            
             Node* curr = ump[key];
             int ans = curr->value;

            deleteNode(curr);
            addNode(curr);
            ump[key]=curr;
            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()){
         Node* curr= ump[key];
         ump.erase(key);
         deleteNode(curr);   
        }

        if(ump.size()==n){
            ump.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key,value));
        ump[key]=head->next;
    }
};
