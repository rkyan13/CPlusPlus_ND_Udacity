What graphics.cpp does
1)demonstrates how to use initalizer lists properly for classes

2) the correct order of initializer lists+ calling  constructors in the initializer list for inherited classes
i) it is poor practise for the initializer list to call the constructor of the grandparent class.
ii) But it is good practise for the initializer list to call the constructor of the parent class, rather than initialise it without the constructor

3) if you create an object of a class that has a parent and grandparent (example SmileyFace face1).
face1 constructor
i) first calls the grandparent constructor i.e Shape constructor
ii) next calls parent constructor i.e Circle constructor
iii) next calls SmileyFace constructor

4) If you create an object of a class that inherits from 2 classes
class Class C: public B, public A{
  ...blah blah
}
First constructor of B is called
Then constructor of A is called
See class Girl and class Boy

5) DIAMOND problem:
notice that you can never print Shape::<attribute name>
within Girl and Boy as it is defined now.
The following cannot be printed. Hence it is commented
//cout<<"Shape::protectVar1="<<this->Triangle.Shape::protectVar1<<endl;

The following though is an attribute of Shape, can be printed since it can be accesses via Triangle
cout<<"Shape::circum_radius="<<Triangle::circum_radius<<endl;


6) DIAMOND problem does not always error out.
as evidenced by above. Diamond problem causes some issues. But if you choose not to do sth like Shape::<attribute>. Then it wont error out. But it might not be best practise though to write a code with an unresolved diamond problem. perhaps better to use Virtual. do more research









TODO:
1) In graphics.cpp : add a debug parameter to print details inside the constructor

2) make the code leaner: reduce the # of constructors and see if you can use some constructors with default parameters

3) DIAMOND PROBLEM: try using virtual classes to be able to use Shape::<attribute>

4) make use of the friend class and actually print things and see between Girl and Boy class

5) when I wrote this code I meant for the Girl object to have a SmileyFace head and triangle body. So i wanted two instances of the shape object anyway. but for this girl cannot inherit from both SmileyFace and Triangle. When it inherits from both, it means the Girl has only one entity: one overall body that is a combination of both circle and triangle lol !
  For what I needed it should be like this
  Class Girl{
    SmileyFace face;
    Triangle   body;
  }

  So that way there will be 2 individual pieces of graphics/geometric-shape to make a complete Girl-cartoon.

  So implement sth like this and see if it works.

  The same applies to Boy,SmileyFace and Square as well
