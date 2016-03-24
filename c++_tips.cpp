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


//// Section 3: Namespace ////

Purpose: avoid naming conflicts. We can create our own namespace. 

e.g namespace LI{
  ...
}

If we have "using namespace std" in the begining, no need to use std::func() in the body.

We can also declair class in the namespace.

//// Section 4: Memory Allocation ////

In C, use malloc to allocate memory.

In C++, use new() to allocate and delete() to freee memory.

eg. int *p = new int;   //alloc one int memory
    delete p;

    int *p = new int[10] // alloc 10 int memory, p pointing to the head of array.
    delete[] p;

//// Section five: basic concepts ////

Overloading: functions can have the same name but diffrent parameter sets. You can't have two functions only differ in return types. 

Difference between struct and class in C++: They are basically the same in C++, but the default access right of variables is public in struct, while it's private in class.

Constructer in class: we can use variable initalize table to initialize variable values. eg. Book::Book(int i, int j): page(i), index(j) {}. The main function of this is to initilize a const variable. If we define a const variable in class, then we can only initialize in this way. 

Static variable and function: If the variable or function is static, then it belongs to the class and is shared with all instances. The initalization of static variable must be outside the declaration of class. But we can still define static function name in the class body. 

Friend class: we can define friend class in another class. We can then access to any variables and functions in the friend class. But friend class violates the encapsulation rule, therefore try not to use it. 

//// Section six: pointer ////

Pointer stores the address of a variable with a specific type.

Pinter array: int *ptr[num]; This statement declairs an array which has "num" number of pointers. Each element in the array is an integer pointer. Therefore, when initate the value of the array, we have to do this:

for (int i = 0; i  < num; i++)
  ptr[i] = &var[i];

where var is another integer array. 

Or normally, we use a char pointer array to initate a string list: 
char *names[max] = {"1", "2", "3"};

In this case, each element in the array is pointing to a string and there is no need to use * to access the value of the string. 

Pointer of pointer: The basic logic is the same. We can easily use this technique to create a two dimensional array. 

eg. 
int **ptr;
ptr = new int*[5]   //this will create an array with 5 int pointers to ptr. Then ptr is pointing to the first pointer in the array.
for (int i = 0; i < 5; i++)
  ptr[i] = new int[5];    //this actually creates an int array in for each pointer in the pointer array. Therefore, by now, ptr is pointing to 5 sub-pointers, each sub-pointer points to an array with 5 elements. 





