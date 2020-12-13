//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//	struct ListNode* slow = pListHead;
//	struct ListNode* fast = pListHead;
//
//	while (k--)
//	{
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//
//	return slow;
//}


//leetcode21
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

	if (l1)
		return l2;
	if (l2)
		return l1;
	Node *newnode = NULL;
	Node *tail = NULL;
	newnode = tail = (Node *)malloc(sizeof(Node));
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
		tail->next = l1;
	else
		tail->next = l2;
	Node *rehead = newnode->next;
	free(newnode);
	return rehead;

}

//
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (pHead)
			return NULL;
		ListNode *head1 = NULL;
		ListNode *tail1 = NULL;
		head1 = tail1 = (ListNode *)malloc(sizeof(ListNode));
		ListNode *head2 = NULL;
		ListNode *tail2 = NULL;
		head2 = tail2 = (ListNode *)malloc(sizeof(ListNode));
		while (pHead)
		{
			if (pHead->val < x)
			{
				tail1->next = pHead;
				tail1 = tail1->next;
			}
			else
			{
				tail2->next = pHead;
				tail2 = tail2->next;
			}
			pHead = pHead->next;
		}
		if (head2)
		{
			ListNode *head = head1->next;
			free(head1);
			free(head2);
		}
		else {
			ListNode *head = head2->next;
			free(head1);
			free(head2);
		}
		tail1->next = head2->next;
		free(head2);
		ListNode *head = head1->next;
		free(head1);
		return head;
	}
};
