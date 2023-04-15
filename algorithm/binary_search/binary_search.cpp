/*
 * FileName:     binary_search
 * Author: 8ucchiman
 * CreatedDate:  2023-02-25 00:08:00 +0900
 * LastModified: 2023-02-25 00:22:30 +0900
 * Reference: 8ucchiman.jp
 */


#include <iostream>
#include <vector>
using namespace std;


class BinarySearch {
  public:
    int casual_binary_search(vector<int> datas, int key) {
      /// <summary>
      /// [left_idx, right_idx]
      /// </summary>
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
    int meguru_binary_search(vector<int> datas, int key) {
      /// <summary>
      /// [left_idx, right_idx>
      /// </summary>
      int left_idx = -1;
      int right_idx = (int)datas.size();
      while(right_idx-left_idx > 1) {
        int mid = left_idx + (right_idx - left_idx) / 2;
        if (datas[mid] >= key) {
          right_idx = mid;
        }
        else {
          left_idx = mid;
        }
      }
      return right_idx;
    }
};


int main() {
  BinarySearch bs;
  vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
  cout << bs.meguru_binary_search(a, 51) << endl; // a[4] = 51 (他に a[3], a[5] も)
  cout << bs.meguru_binary_search(a, 1) << endl; // a[0] = 1
  cout << bs.meguru_binary_search(a, 910) << endl; // a[9] = 910

  cout << bs.meguru_binary_search(a, 52) << endl; // -1
  cout << bs.meguru_binary_search(a, 0) << endl; // -1
  cout << bs.meguru_binary_search(a, 911) << endl; // -1
  return 0;
}
