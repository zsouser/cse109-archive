#include <iostream>
using namespace std;

void intro();
void sort(int a[], int num);
void display(int a[], int num);
void sort(int a[], int first, int last);

int main(){
  int x[]={1,7,2,9,3,18,4,-22};
  intro();//explain what program does
  cout<<"The unsorted data\n";
  display(x,8);
  sort(x,8);
  cout<<"The sorted data\n";
  display(x,8);
  return 0;
}

void intro() {
  cout<<"This program sorts and displays an array of integers.\n";
}

void sort(int a[], int num) {
  sort(a,0,num-1);
}

void sort(int a[],int first, int last) {
  if (a[first] > a[last]) {
    int temp = a[last];
    a[last] = a[first];
    a[first] = temp;
  }
  if (last > first) {
    sort(a,first+1,last);
    sort(a,first,last-1);
  }
}  

void display(int a[], int num) {
  for (int i = 0; i < num; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
