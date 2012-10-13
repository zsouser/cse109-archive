#include <iostream>
using namespace std;

//display the numbers 11, 8, 5, 2
void one();
void two();

//display the numbers 11, 10, 9, ... 2
void three();

int main(){
  int n;
  cout<<"This program has (at least) three bugs\n";
  do{
    cout<<"Enter 1, 2, or 3 to see a given bug in action- ";
    cin>>n;
    if(n<1 || n>3)
      cout<<"You did not enter 1, 2, or 3; please try again\n";
  }while(n<1 || n>3);
  switch(n){
    case 1: one(); break;
    case 2: two(); break;
    case 3: three();
  }
}

void one(){
  int i,x[5];

  i=11;
  while(i!=0){
    x[(11-i)/3]=i;
    i-=3;
  }

  for(i=0;i<3;i++)
    cout<<x[i]<<endl;
}

int fac(int n){
  if(n!=0)
    return n*fac(n-1);
  return 1;
}

void two(){
  int ans;
  cout<<"The factorial of 6 is ";
  ans=fac(-6);
  cout<<ans<<endl;
}

void three(){
  int i,x[5];

  //Try to display 11, 10, ... 2
  for(i=0;i<19;i++){
    x[i]=11-i;
    cout<<i<<" "<<x[i]<<endl;
  }
}

