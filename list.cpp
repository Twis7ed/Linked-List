#include <iostream>

namespace tds
{
    template<typename T, std::size_t Elements>
    class list
    {
    private:
        struct Node
        {
            T data;
            Node* tail;
        };
        
        Node* head;
        
    public:
        list()
        {
            if (Elements > 0)
            {
                head = new Node;
                Node* temp{ head };
                Node* link{ head };
                
                for (int i{}; i < Elements -1; i++)
                {
                    temp = new Node;
                    link->tail = temp;
                    link = link->tail;
                }
                
                temp->tail = nullptr;
            }
            else
                head = nullptr;
                
            return;
        }
        
        list (const std::initializer_list<T>& init)
        {
            if (Elements > 0)
            {
                head = new Node;
                Node* temp{ head };
                Node* link{ head };
                
                for (int i{}; i < Elements -1; i++)
                {
                    temp = new Node;
                    link->tail = temp;
                    link = link->tail;
                }
                
                temp->tail = nullptr;
                temp = head;
                
                for (auto data : init)
                {
                    temp->data = data;
                    temp = temp->tail;
                }
            }
            else
                head = nullptr;
                
            return;
        }
        
        list (const list& copy)
        {
            Node* temp{ copy.head };
            if (temp != nullptr)
            {
                head = new Node;
                head->data = copy.head->data;
                
                Node* point{ head };
                Node* link{ head };
                
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
        
        int size()
        {
            int elements{};
            Node* temp{ head };
            
            if (temp != nullptr)
            {
                while (temp != nullptr)
                {
                    temp = temp->tail;
                    elements++;
                }
            }
            
            return elements;
        }
        
        T& operator[] (const int& node)
        {
            Node* temp{ head };
            if (temp != nullptr)
            {
                for (int i{}; i < node; i++)
                    temp = temp->tail;
            }
            
            return temp->data;
        }
        
        ~list()
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
    };
}

int main()
{
    tds::list<int, 3> fib{ 0, 1 };
    for (int i{}; i < 10; i++)
    {
        fib[2] = fib[0] + fib[1];
        std::cout << fib[0];
        
        fib[0] = fib[1];
        fib[1] = fib[2];
        
        if (i != 9)
            std::cout << ", ";
    }
    
    std::cout << std::endl;
    tds::list<int, 3> foo{ fib };
    
    for (int i{}; i < foo.size(); i++)
        std::cout << foo[i] << ", ";
    
    return 0;
}
