int calc(int x) {
    int min = x%100;
    int hr = x/100;
    return hr*100+min;
}

int calculateMinPatforms(int at[], int dt[], int n) {

    for(int i=0; i<n; i++) {
        at[i] = calc(at[i]);
        dt[i] = calc(dt[i]);
    }

    sort(at, at+n);
    sort(dt, dt+n);

    int i=0, j=0;
    int cur = 0;
    int ans = 0;

    while(i < n) {
        if(at[i] <= dt[j]) {
            cur++;
            i++;
        }else {
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }

    return ans;
}