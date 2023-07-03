int removeDuplicates(vector<int> &arr, int n) {
	int i=0, j=0;
	int cnt = 0;
	while(j < n) {
		arr[i++] = arr[j++];
		cnt++;
		while(j < n && arr[j]==arr[j-1])
			j++;
	}
	return cnt;
}