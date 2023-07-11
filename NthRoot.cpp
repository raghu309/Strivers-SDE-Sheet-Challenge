int pwr(long long a, long long b, long long val) {
  long long ans = 1;
  while(b) {
    ans *= a;
    if(ans > val) {
      return 1;
    }
    b--;
  }
  if(ans == val)
    return 0;
  return -1;
}

int NthRoot(int n, int m) {
  long long lo = 1;
  long long hi = m;

  while(hi - lo > 1) {
    long long mid = (lo+hi)/2;

    if(pwr(mid, n, m)==-1) {
      lo = mid;
    }else if(pwr(mid, n, m)==1) {
      hi = mid;
    }else {
      return mid;
    }
  }
  if(pwr(lo, n, m)==0) {
    return lo;
  }else if(pwr(hi, n, m)==0) {
    return hi;
  }
  return -1;
}