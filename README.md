# Treasure-hunt
This is a basic game that can be played on terminal/ command prompt including various fun challenges.  The game is completely developed in the C++ programming language and utilizes object-oriented programming for the implementation of various features. The game is an aggregation of 3 small games plotted along a path of a treasure hunt. It will test players' wit and reaction through various tasks.
 <br><br><b>Libraries Used</b>:
 <ul>
 <li>iostream</li>
 <li>conio.h</li>
 <li>stdlib.h</li>
 <li>time.h</li>
 <li>windows.h</li>
 </ul>
 <br>List of Features, Concepts, Topics used in OOP:
 <br>1.	Class <br>
Classes are a collection of objects. Here, classes are used to contain various directions(paths) and their distinguished member functions and data members. The classes are implemented for following purposes in the game: <br>
•	To contain different codes of different mini-games<br>
•	To contain the distinguished set of actions that can be taken by the players<br>
•	To implement static data, in order to maintain only 1 copy of a data regardless of the object.
 <br> 2.	Member functions<br>
Member functions are the functions that are declared inside the class. Member functions used for the creation of game are declared inside the class, for maintaining simplicity of the code. Various member functions are also accessible to other classes due to presence of inheritance. Member functions are only accessed by creating objects of the respective classes, however member functions can be called directly if the inheritance is public.
  <br>3.	Objects<br>
Objects are the instance of a class. Here we are using objects to access member functions of a class. These member functions are accessible to the classes, other than their own class because of the presence of inheritance.
  <br>4.	Inheritance<br>
Inheritance is the mechanism for constructing new class types from existing class types. The game uses inheritance to enable the code reusability again and again without writing the whole code every time for various functions. The type of inheritance used here is ‘Multiple Inheritance’, where one base class inherits multiple parent classes.
  <br><img src="https://github.com/Hrithik-Nigam/Treasure-hunt/blob/main/Paths.png"><img src="https://github.com/Hrithik-Nigam/Treasure-hunt/blob/main/path2.png">
  <br>5.	Access Specifiers<br>
Access specifiers are used to limit or grant access of attributes of a class to another class, other functions and main function. Access specifiers are also used to specify the type of inheritance between various classes. To enable easy access of members of a parent class to the base class, all the access specifiers are set to ‘public’.
 <br> 6.	Attributes <br>
Attributes are the properties of a class, which are owned by the class itself. The attributes are shared between a class and its objects. Attributes can be anything that is initiated within a class, example- int, string, functions etc. 
  <br>7.	Static Variable<br>
The static variable is a special type of variable declared within a class that maintains only one copy through out the whole program. The attributes are specific to objects so for different objects of different class, attributes may vary. But static variables maintain only one copy, regardless of the object. The static variable used in the above program is of string type, which is declared as ‘Name’.
  <br>8.	Scope Resolution operator<br>
Scope-resolution operator has various uses. In the game, it is used to access static data members. Static data members can’t be accessed directly since they are independent of the objects. Hence, can only be accessed through the scope-resolution (::) operator.
  <br>9.	Function definition and calling<br>
C++ allows us to declare, define and call any functions in the program. The declaration of these functions must be outside the main() function, which is an inbuilt function with it’s own pre-defined definition. When any function is declared inside a class, it is called its member function and is accessed through its objects.
  <br>10.	Random number generation<br>
C++ allows us to generate random numbers. This task is achieved through functions rand() and srand() in the game, whose definition are present in <stdlib.h> header file.
  <br>11.	Global and local variables<br>
Global variables are those which are declared outside any function. These variables are accessible to all the functions present in the scope of the program. 
Local variables are those which are contained within a specific function. Local variables are not accessible to other functions, without special techniques. One of these techniques is inheritance, which enables various functions in the game to access other local variables, besides their own.
  <br>12.	2D- arrays<br>
These are the arrays which have two parameters rather than one (in case of 1D arrays). These are special kind of arrays which contain elements in the form of a matrix and hence, contain more than one array in just one declaration.
