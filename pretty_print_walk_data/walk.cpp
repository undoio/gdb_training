#include <iostream>

struct Node
{
  struct Node *next;
  int i;
};

int main(void)
{
    Node *head = nullptr;

    for (int i = 0; i < 10; i++)
    {
        head = new Node{head, i};
    }

    for (Node *it = head; it; it = it->next)
    {
        std::cout << "Node @ " << it << ": i = " << it->i << std::endl;
    }

    /* BREAKPOINT HERE */

    std::cout << "All done." << std::endl;
}
