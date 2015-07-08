//#include <iostream>
//#include <string>

//LocCase 1: 函数隐藏
//using namespace std;

//class B
//{
	//public:
		//virtual void SendFile(std::string str){}
		//virtual void SendFile() = 0;
//};

//class D : public B
//{
	//public:
		//virtual void SendFile(){}
		
//};

//int main()
//{
	//D d;
	//d.SendFile("aa");
	//return 0;
//}

//LocCase 2: Enum 中含有相同的值
//using namespace std;

//enum TestEnum
//{
	//A = 1,
	//B = 2,
	//C = B
//};

//int main()
//{
	//enum TestEnum aa = C;
	//std::cout << aa << std::endl;
	//return 0;
//}


//LocCase 3: 测试虚函数绑定
//using namespace std;

//class BD
//{
	//public:
		//void f(int)
		//{
			//cout << "BD::f(int)" << endl;
		//}

//};

//class CD : public BD
//{
	//public:
		//virtual void f(int)
		//{
			//cout << "CD::f(int)" << endl;	//} //}; //int main()
//{
	//BD * pD = new CD();
	//pD->f(1); //output: "BD::f(int)"
			  ////reason: for class BD, there is not virtual table
	//return 0;
//}

//LocCase 4: 测试纯虚函数
//class aa
//{
	//public:
		//aa(){}
		//virtual void bb() = 0;
//};

//class testaa
//{
	//public:
		//void test()
		//{
			//m_aa->bb();
		//}

		//aa * m_aa;
//};

//int main()
//{
	//testaa tt;
	//tt.test(); //可以编译过，但是运行会crash
	//return 0;
//}


//LocCase 5: 测试boost::shared_ptr多态

//#include <boost/shared_ptr.hpp>
//using namespace std;

//class basetest
//{
	//public:
		//basetest(int data):mData(data){}
		//virtual void testout()
		//{
			//std::cout<<"3"<<std::endl;
		//}
		//int mData;
//};

//class derivedtest:
	//public basetest
//{
	//public:
		//derivedtest(int data):basetest(data){}
		//virtual void testout()
		//{
			//std::cout<<"4"<<std::endl;
		//}
//};

//void foo(boost::shared_ptr<basetest> data)
//{
	//data->testout();
//}

//int main()
//{
	//boost::shared_ptr<basetest> basePtr(new basetest(3));
	//boost::shared_ptr<derivedtest> derivedPtr(new derivedtest(4));

	//foo(basePtr);
	//foo(derivedPtr);
	//return 0;
//}

//LocCase 6: 测试传递饮用
//using namespace std;

//class aa
//{
	//public:
		//aa(int i):
			//mInt(i)
			//{}

		//void set(int i)
		//{
			//mInt = i;
		//}

		//int get()
		//{
			//return mInt;
		//}

	//private:
		//int mInt;
//};

//class test
//{
	//public: 
		//test(aa &i):
			//mInt(i)
			//{}

		//int get()
		//{
			//return mInt.get();
		//}

	//private:
		//aa &mInt;
//};

//int main()
//{
	//aa *a1 = new aa(1);
	//cout << "a1 value: "<< a1->get() << endl;

	//test t1(*a1);
	//a1->set(2);
	//cout << "t1 value: " << t1.get() << endl;
	
	//delete a1;
	//a1 = NULL;
	//cout << "t1 value after delete: " << t1.get() << endl; //output: 1, wiried
	

	//return 0;
//}

//LocCase 7:

//LocCase 7: 测试数组的sizeof
//#include<iostream>
//using namespace std;
//void theFun(char a[])
//{
   //cout << "2:" << sizeof(a) << endl; //output: 4
//}

//int main()
//{
   //char a[100]="";
   //cout << "1:" << sizeof(a) << endl; //output: 100
   //theFun(a);
   //return 0;
//}

//LocCase 8: vector 的remove 和 erase
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
   //int myints[] = {1,2,3,4};
   //vector<int> myvector (myints, myints+4);
   //cout<<"before remove, the size is:" << myvector.size() << endl; //output: 4
   //vector<int>::iterator it;

   //vector<int>::iterator ret = std::remove(myvector.begin(), myvector.end(), 1);
   //cout << "after remove before erase, the size is: " << myvector.size() << endl;

   //if(ret != myvector.end())
   //{
           //myvector.erase(ret);
   //}
   //cout<<"after remove, the size is:" << myvector.size() << endl;
//}

//LocCase 9: 在构造函数中调用虚函数
//using namespace std;

//class aa
//{
	//public:
		//aa()
		//{
			//func();	
		//}

		//virtual void func() = 0;
//};

//class bb : public aa
//{
	//public:
		//bb()
		//{
			//func();
		//}

		//virtual void func()
		//{
			//cout<<"bb"<<endl;
		//}
//};

//int main()
//{
	//bb b;//crash	

	//return 0;
//}

//LocCase 10: 测试exception
//#include <iostream>

//using namespace std;

//class exceptiontt
//{
	//public:
		//exceptiontt()
		//{}
//};

//class BD
//{
	//public:
		//void f()
		//{
			//g();
			//std::cout<<"after exception been throw"<<std::endl; //it will not be output
		//}

		//void g()
		//{
			//throw exceptiontt();	
		//}

//};


//int main()
//{
	//BD tt;
	//try
	//{
		//tt.f();
	//}
	//catch(const exceptiontt &)
	//{
		//std::cout<<"catch an exception"<<std::endl;	
	//}

	//return 0;
//}

//LocCase 11: 测试 !!
//#include <iostream>
//#include <string>

//using namespace std;

//int main()
//{
	//int n = 100;
	//if(!!n)
	//{
		//cout<<"loc debug"<<endl;
	//}
	//return 0;
//}

//LocCase 12: typedef 用于类用私有成员,但是typedef需要public
//#include <iostream>
//#include <string>

//using namespace std;

//class Base
//{
	//class B {};
	//public:
	//typedef B aa;
//};


//int main()
//{
	//Base::aa x; // can be compiled successfully
	//return 0;
//}

//LocCase 13: 虚函数与各种cast
//#include <iostream>

//using namespace std;

//class BD
//{
	//public:
		//void f()
		//{
			//cout << "BD::f(int)" << endl;
		//}

		//virtual void g()
		//{
			//cout << "BD::g()"<<endl;	
		//}

//};

//class CD : public BD
//{
	//public:
		//void f()
		//{
			//cout << "CD::f(int)" << endl;	
		//}

		//virtual void g()
		//{
			//cout << "CD::g()" << endl;	
		//}
//};

//int main()
//{
	//BD* a = dynamic_cast<BD*>(new CD());
	//CD* b = static_cast<CD*>(new BD());

	//a->f(); //BD::f(int)
	//a->g(); //CD::g()
	//b->f(); //CD::f(int)
	//b->g(); //BD::g()
	
	//return 0;
//}

//LocCase 14: break for for double for loop
//#include <iostream>
//int main()
//{
	//for(int i = 0; i < 10; ++i)
	//{
		//for(int j = 0; j < 10; ++j)
		//{
			//if(j == 5)
				//break;
		//}

		//std::cout << i << std::endl;
	//}

	//return 0;
//}

//LocCase 15: dynamic cast empty class
//fail to compile
//class A
//{
//};

//class B : public A
//{};

//int main()
//{
	//A * aa = new B;
	//B * bb = dynamic_cast<B*>(aa);
	//return 0;
//}

//LocCase 16: sizeof nullptr
#include <iostream>
int main()
{
   std::cout << "sizeof void*: " << sizeof(void*) << " sizeof nullptr: " << sizeof(nullptr) << std::endl;
   return 0;
}
