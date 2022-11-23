#include <iostream>

namespace tds 
{
    template <typename T>
    class linklist
    {
    private:
        struct Node
        {
            T data;
            Node* tail;
        };
        
        Node* head;
        
    public:
        linklist (int nodes)
        {
            if (nodes != 0)
            {
                head = new Node;
                Node* point{ head };
                Node* link{ point };
                
                for (int i{}; i < nodes; i++)
                {
                    point = new Node;
                    link->tail = point;
                    link = link->tail;
                }
                
                point->tail = nullptr;
            }
            else
                head = nullptr;
            
            return;
        }
        
        linklist (const linklist& copy)
        {
            Node* temp{ copy.head };
            if (temp != nullptr)
            {
                head = new Node;
                Node* point{ head };
                Node* link{ point };
                point->data = copy.head->data;
                
                while (temp->tail != nullptr)
                {
                    point = new Node;
                    temp = temp->tail;
                    point->data = temp->data;
                    link->tail = point;
                    link = link->tail;
                }
                
                point->tail = nullptr;
            }
            else
                head = nullptr;
            
            return;
        }
        
        ~linklist()
        {
            while (head != nullptr)
            {
                Node* temp{ head };
                head = head->tail;
                delete temp;
            }
            
            delete head;
            return;
        }
        
        T grabItem (int node)
        {
            Node* temp{ head };
            for (int i{}; i < node; i++)
                temp = temp->tail;
                
            return temp->data;
        }
        
        void setItem (int node, T data)
        {
            Node* temp{ head };
            for (int i{}; i < node; i++)
                temp = temp->tail;
                
            temp->data = data;
            return;
        }
        
        void print (int node)
        {
            Node* temp{ head };
            for (int i{}; i < node; i++)
                temp = temp->tail;
            
            std::cout << temp->data;
            return;
        }
    };
}

int main()
{
    tds::linklist<int> list1(1);
    list1.setItem(0, 1);
    
    tds::linklist<int> list2{ list1 };
    list2.print(0);
    
    return 0;
}
