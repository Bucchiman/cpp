#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> datas, int key) {
  int left_index = 0;
  int right_index = (int)datas.size() - 1;
  while(right_index >= left_index) {
    int mid = left_index + (right_index - left_index) / 2;
    if (datas[mid] == key) {
      return mid;
    }
    else if (datas[mid] > key) {
      right_index = mid - 1;
    }
    else if (datas[mid] < key) {
      left_index = mid + 1;
    }
  }
  return -1;
}



int main() {
  vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
  cout << binary_search(a, 51) << endl; // a[4] = 51 (他に a[3], a[5] も)
  cout << binary_search(a, 1) << endl; // a[0] = 1
  cout << binary_search(a, 910) << endl; // a[9] = 910

  cout << binary_search(a, 52) << endl; // -1
  cout << binary_search(a, 0) << endl; // -1
  cout << binary_search(a, 911) << endl; // -1
}
