// leetcode 26
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int src = 0;
	int dst = 0;
	int i = 0;
	for (i = 0; i < numsSize - 1; i++)
	{
		if (nums[src + 1] != nums[src])
		{
			nums[dst] = nums[src];
			dst++;
		}
		src++;
	}
	nums[dst] = nums[numsSize - 1];
	return dst + 1;
}

//leetcode 27
int removeElement(int* nums, int numsSize, int val) {
	if (nums == NULL || numsSize == 0)
		return 0;
	int src = 0;
	int dst = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[dst] = nums[i];
			dst++;
		}
		src++;

	}
	return dst;
}

//leetcode 989
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	int KSize = 0;
	int Kn = K;
	//求出K的长度kn
	while (Kn)
	{
		KSize++;
		Kn /= 10;
	}
	int len = KSize > ASize ? KSize : ASize;
	int *new = (int*)malloc(sizeof(int)*(len + 1));

	int ai = ASize - 1;
	int reti = 0;
	int i = 0;
	int next = 0;
	while (len--)
	{
		int a = 0;
		if (ai >= 0)
		{
			a = A[ai];
			ai--;
		}

		int ret = K % 10 + a + next;
		K /= 10;
		if (ret > 9)
		{
			next = 1;
			ret -= 10;
		}
		else
			next = 0;
		new[reti] = ret;
		reti++;
	}
	if (next == 1)
	{
		new[reti] = 1;
		reti++;
	}
	int left = 0;
	int right = reti - 1;
	while (left < right)
	{
		int temp = new[left];
		new[left] = new[right];
		new[right] = temp;
		left++;
		right--;
	}
	*returnSize = reti;
	return new;
}

//