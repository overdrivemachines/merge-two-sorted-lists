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
  vector<int> v1 = {3, 6, 7, 9, 9, 9, 9, 10, 11, 12};
  vector<int> v2 = {2, 9, 10, 11};
  // creating linked lists
  ListNode* list1 = createLinkedList(v1);
  ListNode* list2 = createLinkedList(v2);
  ListNode* merge_head;

  printLinkedList(list1);
  printLinkedList(list2);

  // merging the 2 linked lists
  merge_head = mergeTwoLists(list1, list2);
  printLinkedList(merge_head);

  return 0;
}

// merges list1 and list2
// merged linked list is also sorted
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *head, *node;
  head = list1;

  // if list1 is empty, return pointer to list2
  if (list1 == nullptr)
    return list2;

  // if list2 is empty, return pointer to list1
  if (list2 == nullptr)
    return list1;

  // head is pointing to the list1 or list2 whichever one has lower value
  if (list1->val < list2->val) {
    head = list1;
    list1 = list1->next;
  } else {
    head = list2;
    list2 = list2->next;
  }

  node = head;

  // cout << "head val: " << head->val << endl;

  // cout << "merged list: " << node->val << "->";

  while ((list1 != nullptr) && (list2 != nullptr)) {
    if (list1->val < list2->val) {
      node->next = list1;
      list1 = list1->next;
    } else {
      node->next = list2;
      list2 = list2->next;
    }
    node = node->next;
    // cout << node->val << "->";
  }

  if (list1 != nullptr) {
    node->next = list1;
    // cout << node->next->val << ":rest1";
  } else if (list2 != nullptr) {
    node->next = list2;
    // cout << node->next->val << ":rest2";
  }

  // cout << endl;

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
