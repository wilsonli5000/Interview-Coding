///// First section: virtual function and pure virtual function and abstarct class ////

virtual function:

Override: two functions with the same name and same params, subclass overrides the parent class.
Overload: two functions with the same name but either different param attribute or param numbers.

What if we want to call the override function both in base class and subclass?
We do this by delaring virtual class as the base class. 

Virtual function allows subclass to redeclaire the same name functions in the parent class, and use base class pointers to call subclass function. Without virtual, we cant call subclass override function through base class pointers, even we repoint the pointer to a subclass instance.

eg. Student is the base class. Graduate is the subclass. They have display().

class Student {
public: 
	virtual void display();
};

class Graduate: public Student{
public: 
	void display();
};

int main(){
	Student stud1;
	Graudate grad1;
	Student * pt = &stud1;
	pt->display();	//this will call the display() in Student class.

	pt = &grad1;	//change the pointer type.
	pt->display();	
	/*
	with out virtual:
	this will call the display() in Student class but with the graudate instance info.

	this is because pt is a pointer for base class, although we repoint it to a subclass instance, it still can only refer to the fucntion of this cubclass's bass class. 
	
	with virtual:
	this will call the display() both in Student class and the Graduate class. 

	this is because virtual makes the subclass override function to replace the base class override function. so we can call the subclass function even through a base class instance pointer. 
	*/
}

So how to use virtual function:
1. declair virtual in base class.
2. override virtual function in subclasses with the same declaration but different implementation.
3. declair a base class instance pointer and a subclass instance pointer. point the pointer to the subclas instance. 
4. call the virtual function, it will invode the subclass function instead.

Pure virtual function: eg. virtual void func()=o{};

Pure virtual function dont have an implementation in base class.
A base class with pure virtual functions cant be instantiated. And the base class is called abstarct class.
The implementation of pure virtual function must be in subclasses.

eg. class A 
{
    public:
    A();
   void f1();
   virtual void f2();
   virtual void f3()=0;
   virtual ~A();

};

class B : public A 
{
   public:
   B();
   void f1();
   void f2();
   void f3();
   virtual ~B();

};

int main(int argc, char* argv[])
{
   A *m_j=new B();
   m_j->f1();
   m_j->f2();
   m_j->f3();
   delete m_j;
   return 0;
}

Why we need virtual, why not just declare another pointer for subclass instance? For coding efficiency.



//// Section 2: OOP Basic Concepts ////

OOP concepts:

1. Abstraction: provide a root for inheritence and defines the type of many subclasses. object class is the root of all classes in JAVA.

2. Encapsulation: provide different authority of access data. protect the data and function.

3. Inheritence: save the code and provide a relationship between parent class and child class. 

4. Polynophism: C++ supports two kinds of Polynophism: override function and virtual function. Allows subclasses to have the same behavior in a different way.

