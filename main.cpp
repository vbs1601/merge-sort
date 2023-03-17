#include <iostream>
using namespace std;
void me(int *arr, int s, int e) {
  int m = (s + e) / 2;
  int l1 = m - s + 1;
  int l2 = e - m;

  int *l = new int[l1];
  int *r = new int[l2];

  int k = s;
  for (int i = 0; i < l1; i++) {
    l[i] = arr[k];
    k++;
  }
  k = m + 1;
  for (int i = 0; i < l2; i++) {
    r[i] = arr[k];
    k++;
  }
  // merge
  int li = 0;
  int ri = 0;
  int mi = s;
  while (li < l1 && ri < l2) {
    if (l[li] < r[ri]) {
      arr[mi] = l[li];
      mi++;
      li++;

    } else {
      arr[mi++] = r[ri++];
    }
  }
  while (li < l1) {
    arr[mi] = l[li];
    mi++;
    li++;
  }
  while (ri < l2) {
    arr[mi] = r[ri];
    mi++;
    ri++;
  }
}

void ms(int *arr, int s, int e) {
  if (s >= e) {
    return;
  }
  int m = s + (e - s) / 2;

  // left
  ms(arr, s, m);

  // right
  ms(arr, m + 1, e);

  me(arr, s, e);
}

int main() {
  int arr[] = {4, 3, 56, 67, 7, 8};
  int n = 6;
  int s = 0;
  int e = n - 1;
  ms(arr, s, e);
  for (int i = 0; i < 6; i++) {
    cout << arr[i];
  }
  return 0;
}