#include <bits/stdc++.h>
using namespace std;

// A linked list node
int page_size;

class Node
{
public:
    vector<int> data;
    int size_remaining;
    int page_id;
    Node *next;
    Node *prev;
    Node(int s)
    {
        this->size_remaining = page_size - 16;
        this->next = NULL;
        this->prev = NULL;
        this->page_id = s;
    }
};

class ddl
{
public:
    Node *head;
    int page_count;
    void insert(int, int);
    ddl()
    {
        this->head = NULL;
        this->page_count = 0;
    }
    void display(int);
    void status();
};

void ddl::insert(int new_data, int size)
{
    Node *curr = head;
    if (curr == NULL)
    {
        Node *new_node = new Node(page_count);
        page_count++;
        head = new_node;
        curr = head;
        curr->data.push_back(new_data);
        curr->size_remaining -= size + 4;
    }
    else
    {
        int f = 0;
        while (curr->next != NULL)
        {
            if (curr->size_remaining >= size + 4)
            {
                curr->data.push_back(new_data);
                curr->size_remaining -= size + 4;
                f = 1;
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
        if (f == 0)
        {
            {
                if (curr->size_remaining >= size + 4)
                {
                    curr->data.push_back(new_data);
                    curr->size_remaining -= size + 4;
                }
                else
                {
                    Node *new_node = new Node(page_count);
                    page_count++;
                    curr->next = new_node;
                    curr->next->prev = curr;
                    curr = curr->next;
                    curr->data.push_back(new_data);
                    curr->size_remaining -= size + 4;
                }
            }
        }
    }
}

void ddl::display(int v)
{
    Node *temp = head;
    while (temp != NULL)
    {
        for (int i = 0; i < temp->data.size(); i++)
        {
            if (v == temp->data[i])
            {
                cout << temp->page_id << " " << i << endl;
                return;
            }
        }
        temp = temp->next;
    }
    cout << -1 << " "<< -1<< endl;
}

void ddl::status()
{
    cout << page_count<<" ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout <<temp->data.size() <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    ddl d;
    cin >> page_size;
    int n;
    while (1)
    {
        cin >> n;
        if (n == 1)
        {
            int size, data;
            cin >> size >> data;
            d.insert(data, size);
        }
        else if (n == 3)
        {
            int data;
            cin >> data;
            d.display(data);
        }
        else if (n == 2)
        {
            d.status();
        }
        else
        {
            break;
        }
    }
}