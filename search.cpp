int search(int* arr, int n, int key) {
    int l=0, h=n-1;
    while(h-l > 1) {
        int m = (h+l)/2;

        if(arr[m] == key) {
            return m;
        }
        if(arr[l] < arr[m]) {
            if(key >= arr[l] && key <=arr[m]) {
                h = m;
            }else {
                l = m;
            }
        }
        if(arr[m] < arr[h]) {
            if(key >= arr[m] && key <= arr[h]) {
                l = m;
            }else {
                h = m;
            }
        }
    }
    if(arr[l]==key) {
        return l;
    }
    if(arr[h]==key) {
        return h;
    }
    return -1;
}