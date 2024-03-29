double median(vector<int>& a, vector<int>& b) {
	if(a.size() > b.size()) {
		return median(b, a);
	}
	int n1 = a.size();
	int n2 = b.size();
	int isOdd = (n1+n2)%2==1;

	int l=0;
	int h=n1;
	int half = (n1+n2+1)/2;

	while(l <= h) {
		int cut1 = (l+h)/2;
		int cut2 = half - cut1;

		int l1 = cut1==0?INT_MIN:a[cut1-1];
		int l2 = cut2==0?INT_MIN:b[cut2-1];
		int r1 = cut1==n1?INT_MAX:a[cut1];
		int r2 = cut2==n2?INT_MAX:b[cut2];

		if(l1<=r2 && l2<=r1) {
			if(isOdd) {
				return max(l1, l2);
			}else {
				return (max(l1, l2) + min(r1, r2))/2.0;
			}
		}else if(l1 > r2) {
			h = cut1-1;
		}else {
			l = cut1+1;
		}
	}
	return 1;
}