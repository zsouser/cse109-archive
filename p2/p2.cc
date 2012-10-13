/**
   Zach Souser
   Program #2
   zrs212

**/

#include "word.h"

void test1(); //test constructors, I/O, assignment
void test2(); //test logical comparison
void test3();  //test two forms of [] and toStr()
void test4(const Word &w);  //called by test3, looking for []const

int main(){
  test1();
  test2();
  test3();
  return 1;
}

void test1(){
  cout<<"-----------Test1()-------------------\n";
  Word a,b('a'),c("Hello there"),d(c);
  cout<<"Expect: '' 'a' 'Hello there' 'Hello there'\n";
  cout<<"        '"<<a<<"' '"<<b<<"' '"<<c<<"' '"<<d<<"'\n";
  a=a.fromInt(42);
  cout<<"Expect: '42 57': "<<a<<" "<<a.toInt()-2+17<<endl;
  cout<<"Enter a long line of text: ";
  cin>>a;
  cout<<"You entered: "<<a<<endl;
  cout<<"That line has "<<a.length()<<" characters\n";
}

void test3(){
  cout<<"-----------Test3()-------------------\n";
  Word h("This is a string");
  const char * temp;
  h[8]=' ';
  h[9]=' ';
  h[10]=' ';
  h[11]='b';
  h[12]='l';
  cout<<"Expect: 'This is    bling': "<<h<<endl;
  test4(h);
  temp=h.toString();
  cout<<"Same line again: "<<temp<<endl;
}

void test4(const Word &w){
  cout<<"Expect 'i': "<<w[2]<<endl;
}
   
void test2(){
    cout<<"-----------Test2()-------------------\n";
    Word a("one");
    char *temp;
    cout<<"---------Start testOfComparisons()-----------------------------\n";
    cout<<"Expect: 010110\n        ";
    cout<<(a<a)<<(a<=a)<<(a>a)<<(a>=a)<<(a==a)<<(a!=a)<<endl;
    cout<<"Expect: 010110\n        ";
    cout<<(a<"one")<<(a<="one")<<(a>"one")<<(a>="one")<<(a=="one")
	<<(a!="one")<<endl;
    cout<<"Expect: 010110\n        ";
    cout<<("one"<a)<<("one"<=a)<<("one">a)<<("one">=a)<<("one"==a)
	<<("one"!=a)<<endl;
    cout<<"Expect: 001101\n        ";
    cout<<(a<'a')<<(a<='a')<<(a>'a')<<(a>='a')<<(a=='a')<<(a!='a')<<endl;
    cout<<"Expect: 110001\n        ";
    cout<<('a'<a)<<('a'<=a)<<('a'>a)<<('a'>=a)<<('a'==a)<<('a'!=a)<<endl;
    temp=NULL;
    cout<<"Expect: 110001 \n        ";
    cout<<(temp<a)<<(temp<=a)<<(temp>a)<<(temp>=a)<<(temp==a)<<(temp!=a)<<endl;
}
