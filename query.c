#include <stdio.h>

int main(void) {
	int n, q;
	int arr[1000];
	int i, j;
	int queryNum;
	int a, b, c, d;
	int temp;
	long long prefixSum1 = 0;
	long long prefixSum2 = 0;
	scanf("%d%d", &n, &q);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < q; i++) {
		scanf("%d", &queryNum);
		switch (queryNum) {
		case 1:
			scanf("%d%d", &a, &b);
			for (j = a - 1; j < b; j++) {
				prefixSum1 += arr[j];
			}
			printf("%lld\n", prefixSum1);
			temp = arr[a - 1];
			arr[a - 1] = arr[b - 1];
			arr[b - 1] = temp;
			prefixSum1 = 0;
			break;
		case 2:
			scanf("%d%d%d%d", &a, &b, &c, &d);
			for (j = a - 1; j < b; j++) {
				prefixSum1 += arr[j];
			}
			for (j = c - 1; j < d; j++) {
				prefixSum2 += arr[j];
			}
			printf("%lld\n", prefixSum1 - prefixSum2);
			prefixSum1 = 0;
			prefixSum2 = 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
