#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> values);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
void printLinkedList(ListNode* head);

int main(int argc, char const* argv[]) {
  vector<int> v1 = {3, 6, 7, 9};
  vector<int> v2 = {2, 9, 10};
  ListNode* list1 = createLinkedList(v1);
  ListNode* list2 = createLinkedList(v2);
  ListNode* merge_head;

  printLinkedList(list1);
  printLinkedList(list2);

  merge_head = mergeTwoLists(list1, list2);
  printLinkedList(merge_head);

  return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *head, *node;
  head = list1;

  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  // head is pointing to the list1 or list2 whichever one has lower value
  head = (list1->val < list2->val) ? list1 : list2;
  node = head;

  cout << "merged list: " << node->val << "->";

  while ((list1->next != nullptr) && (list2->next != nullptr)) {
    if (list1->next->val < list2->next->val) {
      node->next = list1->next;
      list1 = list1->next;
      cout << list1->val << "(1)->";
    } else {
      node->next = list2->next;
      list2 = list2->next;
      cout << list2->val << "(2)->";
    }
    node = node->next;
  }

  if (list1 != nullptr) {
    node->next = nullptr;
  } else if (list2 != nullptr) {
    node->next = nullptr;
  }

  return head;
}

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}
