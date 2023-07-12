int singleNonDuplicate(vector<int>& arr)
{	
	int n = arr.size();
	if(n==1)
		return arr[0];
	if(arr[0] != arr[1])
		return arr[0];
	if(arr[n-1] != arr[n-2])
		return arr[n-1];

	int l=0, r=n-1;

	while(l<=r) {
		int m = (l+r)/2;

		if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]) {
			return arr[m];
		}
		if(arr[m]==arr[m-1]) {
			if((m-l+1)%2==0) {
				l=m+1;
			}else {
				r=m-2;
			}
		}
		if(arr[m]==arr[m+1]) {
			if((r-m+1)%2==0) {
				r=m-1;
			}else {
				l=m+2;
			}
		}
	}
	return -1;
}