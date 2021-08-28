//
// Created by מוחמד עבידאת on 25/08/2021.
//

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H


template<class T>
struct Node{
    T data;
    Node *next;
    Node *prev;


};


template<typename T>
class List{
private:
    Node<T> *head;
    int length;
    Node<T> *iterator;
    void add_first(T e){
        head = new Node<T>;
        head->next= nullptr;
        head->prev = nullptr;
        head->data = e;
        iterator = head;
        length = 0;
    }
    void add_end(T e) {
        Node<T> *temp = end();
        temp->next = new Node<T>;
        //temp->next = nullptr;
        temp->next->prev = temp;
        temp->next->data = e;
        temp->next->next = nullptr;
        iterator = head;
        length ++;
    }



    public:
    explicit List(): head(nullptr), length(-1),iterator(nullptr){
    }
    ~List(){
        while(head != nullptr){
            iterator = head;
            head = head->next;
            delete iterator;
        }
    }
    List(const List &other):length(other.length), head(nullptr),iterator(nullptr){
        for(int i=0; i < length; i++){
            if(head == nullptr && other.head!= nullptr){
                head = new Node<T>;
                head->prev = nullptr;
                head->next = nullptr;
                head->data = other.head->data;
                iterator = head;
            }
            iterator->next = new Node<T>;
            Node<T> temp = iterator->next;
            temp.prev = iterator;
            temp.next = nullptr;
            temp.data = other.iterator->data;
            iterator = iterator->next;
            other.iterator = other.iterator->next;
        }
        iterator = head;
        other.iterator = other.begin();
    }

    List& operator=(const List& other){
        if(other == *this){
            return *this;
        }
        delete *this;
        length(other.length);
        head(nullptr);
            for(int i=0; i < length; i++){
                if(head == nullptr && other.head!= nullptr){
                    head = new Node<T>;
                    head->prev = nullptr;
                    head->next = nullptr;
                    head->data = other.head->data;
                    iterator = head;
                }
                iterator->next = new Node<T>;
                Node<T> temp = iterator->next;
                temp.prev = iterator;
                temp.next = nullptr;
                temp.data = other.iterator->data;
                iterator = iterator->next;
                other.iterator = other.iterator->next;
            }
            iterator = head;
            other.iterator = other.begin();

        return *this;
    }

    Node<T>* begin(){
        return head;
    }

    Node<T>* end(){
        if(length == -1) throw error_throw("null pointer");
        while(iterator->next != nullptr){
            iterator= iterator->next;
        }
        Node<T> *temp = new Node<T>;
        temp = iterator;
        iterator = head;
        return temp;
    }

    T& operator[](int i) const{
        if(i > length || i <0){
            throw error_throw("out of list length");
        }
        Node<T> *tmp = head;
        for(int j =0 ; j<i ;j++)
            tmp = tmp->next;

        return tmp->data;
    }
     const T& operator[](int i){
        if(i > length || i <0){
           throw error_throw("out of list length");
        }
        Node<T> *tmp = head;
        for(int j =0 ; j<i ;j++)
            tmp = tmp->next;

        return tmp->data;
    }
    bool is_empty(){
        return head == nullptr;
    }

    void push_back(T e) {
        if (is_empty()) {
            add_first(e);

        } else {
            add_end(e);
        }
        iterator = head;
    }

    void remove(T e){
        if(is_empty()){
            error();
            return;
        }
        while(iterator->next != nullptr && iterator->data != e){
            iterator=iterator->next;
        }
        if(iterator->data == e) {
            if (iterator == head)
                remove_first();
            else if (iterator == end())
                remove_end();
            else {
                iterator->next->prev = iterator->prev;
                iterator->prev->next = iterator->next;
                delete iterator;
                iterator = head;
        }
            iterator = head;
            length--;
        }


        error("this element does not exist");
    }
    void remove_first(){
        if(length ==-1) return;
        if(length ==0){
            //there are just one element
            delete head;
            length = -1;
            head = nullptr;
            iterator = nullptr;
            return;
        }
        iterator = head;
        head = head->next;
        head->prev= nullptr;
        delete iterator;
        iterator = head;
        length--;
    }
    void remove_end(){
        if(length ==-1) return;
            if(length ==0){
            //there are just one element
            delete head;
            head = nullptr;
            iterator = nullptr;
            length = -1;
            return;
        }
        //assert(iterator == end());
        Node<T> *tmp = end();
        tmp = tmp->prev;
        tmp->next= nullptr;
        delete iterator;
        iterator = head;
        length--;
    }

    friend ostream& operator<<(ostream& os, List& c);
};

ostream& operator<<(ostream& os, List<string>& c) {
    int i =0;
    while(c.iterator != nullptr){
        os << print_board(c[i]);
        int x = (int(c[i].length()/2));
        if(c.iterator->next != nullptr)
            os<<string(" ")*(x) +""+u8"║\n"
            <<string(" ")*(x) +""+u8"║\n"
            <<string(" ")*(x) +""+u8"║\n";
        c.iterator = c.iterator->next;
        i++;
    }
    c.iterator = c.head;
    return os;
}


#endif //DATA_STRUCTURE_LIST_H
