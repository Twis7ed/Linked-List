#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* link;
    };
    
    Node* point = new Node;
    Node* head = point;
    Node* temp = point;
    int length{};
    
public:
    void create(int nodes)
    {
        for (int i{}; i < nodes -1; i++)
        {
            point = new Node;
            temp->link = point;
            temp = temp->link;
        }
        
        point->link = NULL;
        length = { nodes };
        return;
    }
    
    void setItem(int itemId, int newItem)
    {
        temp = head;
        for(int i{}; i < itemId -1; i++)
            temp = temp->link;
            
        temp->data = newItem;
        return;
    }
    
    T grabItem(int itemId)
    {
        temp = head;
        for (int i{}; i< itemId -1; i++)
            temp = temp->link;
            
        return temp->data;
    }
    
    void print()
    {
        temp = head;
        for (int i{}; i < length; i++)
        {
            std::cout << temp->data;
            temp = temp->link;
            
            if (i != length -1)
                std::cout << ", ";
        }
        return;
    }
    
    void print(int itemId)
    {
        temp = head;
        for (int i{}; i < itemId; i++)
            temp = temp->link;
            
        std::cout << temp->data;
        return;
    }
};

void fibSeq(int terms)
{
    List<int> list;

    list.create(3);
    list.setItem(1, 0);
    list.setItem(2, 1);
    
    for(int i{}; i < terms; i++)
    {
        list.setItem(3, list.grabItem(1) + list.grabItem(2));
        list.print(1);
        
        list.setItem(1, list.grabItem(2));
        list.setItem(2, list.grabItem(3));
        
        if (i != terms -1)
            std::cout << ", ";
    }
}

int main()
{
    fibSeq(10);
}
