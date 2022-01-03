#include <string>
#include <iostream>
#include "graphics.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;


//----------------------------- Class Shape --------------------------------------------------
//Constructors
Shape::Shape():
privateVar1_shape(-1), protectVar1(-10),circum_radius(1.1), color("shape-color-unknown"){
 cout<<"Shape NO-parameter constructor invoked"<<endl;
 //print_details();
}

Shape::Shape(string col):
privateVar1_shape(-1), protectVar1(-10),circum_radius(1.1), color(col){
 cout<<"Shape PART-parameter constructor invoked"<<endl;
 //print_details();
}

Shape::Shape(int priV1, int protV1,float cr, string col):
privateVar1_shape(priV1), protectVar1(protV1), circum_radius(cr), color(col) {
  cout<<"Shape parameter constructor invoked"<<endl;
  //print_details();
}

//Getters
int    Shape::PrivVar1Shape() const {return privateVar1_shape;}
int    Shape::ProtVar1() const {return protectVar1;}
float  Shape::CircumRadius() const {return circum_radius;}
string Shape::Color() const {return color;}

//Setters

void Shape::PrivVar1Shape(int x){  privateVar1_shape = x;}
void Shape::ProtVar1(int x){ protectVar1 = x;}
void Shape::CircumRadius(float r){ circum_radius = r;}
void Shape::Color(string s){color = s;}

//Printers
void Shape::print_privVar1_shape() const{ cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;}
void Shape::print_protVar1() const{ cout<<"Shape::protectVar1="<<protectVar1<<endl;}
void Shape::print_circum_radius() const{ cout<<"Shape::circum_radius="<<circum_radius<<endl;}
void Shape::print_color() const{ cout<<"Shape::color="<<color<<endl;}
void Shape::print_details() const{
  cout<<"------Shape details(self):-----"<<endl;
  cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
  cout<<"Shape::protectVar1="<<protectVar1<<endl;
  cout<<"Shape::circum_radius="<<circum_radius<<endl;
  cout<<"Shape::color="<<color<<endl;
  return;
}


//----------------------------- Class Circle --------------------------------------------------
//Constructors
Circle::Circle():
  Shape("circle-color-unknown"),
  privateVar1_circle(2.1), protectVar1(2.2), radius(2.3){
    cout<<"Circle NO-parameter constructor invoked"<<endl;
    //print_details();
  }

Circle::Circle(string col,float r):
  Shape(col),
  privateVar1_circle(2.1), protectVar1(2.2), radius(r){
    cout<<"Circle PART-parameter constructor invoked"<<endl;
    //print_details();
  }

Circle::Circle(string col,int priV1, int protV1,float r):
  Shape(col),
  privateVar1_circle(priV1), protectVar1(protV1), radius(r){
    cout<<"Circle parameter constructor invoked"<<endl;
    //print_details();
  }

//Getters
int    Circle::PrivVar1Circle() const {return privateVar1_circle;}
int    Circle::ProtVar1() const       {return protectVar1;}
float  Circle::Radius() const         {return radius;}

//Setters
void Circle::PrivVar1Circle(int x) {privateVar1_circle=x;}
void Circle::ProtVar1(int x)       {protectVar1=x;}
void Circle::Radius(float r)       {radius = r;}

//Printers

void Circle::print_privVar1_circle() const{cout<<"privateVar1_circle="<<privateVar1_circle<<endl;}
void Circle::print_protVar1() const       {cout<<"protectVar1="<<protectVar1<<endl;}
void Circle::print_radius() const         {cout<<"radius ="<<radius<<endl;}

void Circle::print_details() const {
  cout<<"------Circle details(self):-----"<<endl;
  cout<<"Circle::privateVar1_circle="<<privateVar1_circle<<endl;
  cout<<"Circle::protectVar1="<<protectVar1<<endl;
  cout<<"Circle::radius ="<<radius<<endl;

  cout<<"------Inherited from Shape:-----"<<endl;
  //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
  cout<<"Shape::protectVar1="<<Shape::protectVar1<<endl;
  cout<<"Shape::circum_radius="<<circum_radius<<endl;
  cout<<"Shape::color="<<color<<endl;

  return;
}


//----------------------------- Class SmileyFace --------------------------------------------------
//Constructors
SmileyFace::SmileyFace():
Circle("smiley-color-unknown",3.1),
emotion("smiley-emotion-unknown"){
  cout<<"SmileyFace NO-parameter constructor invoked"<<endl;
  //print_details();
}

SmileyFace::SmileyFace(string col, float r, string emot):
Circle(col,r),
emotion(emot){
  cout<<"SmileyFace parameter constructor invoked"<<endl;
  //print_details();
}

//Getters
string  SmileyFace::Emotion() const{return emotion;}

//Setters
void SmileyFace::Emotion(string str){emotion = str;}

//Printers
void SmileyFace::print_emotion() const{cout<<"emotion="<<emotion<<endl;}

void SmileyFace::print_details() const{
  cout<<"------SmileyFace details(self):-----"<<endl;
  cout<<"SmileyFace::emotion ="<<emotion<<endl;
  cout<<"------Inherited from Circle--------"<<endl;
  //cout<<"Circle::privateVar1_circle="<<privateVar1_circle<<endl;
  cout<<"Circle::protectVar1="<<Circle::protectVar1<<endl;
  cout<<"Circle::radius ="<<radius<<endl;
  cout<<"------Inherited from Shape--------"<<endl;
  //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
  cout<<"Shape::protectVar1="<<Shape::protectVar1<<endl;
  cout<<"Shape::circum_radius="<<circum_radius<<endl;
  cout<<"Shape::color="<<color<<endl;

  return;
}

//----------------------------- Class Triangle --------------------------------------------------
//Constructors
Triangle::Triangle():
  Shape("triangle-color-unknown"),
  base_a(4.1),side_bc(4.2){
  cout<<"Triangle NO-parameter constructor invoked"<<endl;
  //print_details();
}


Triangle::Triangle(string col, float a, float bc):
  Shape(col),
  base_a(a),side_bc(bc){
  cout<<"Triangle parameter constructor invoked"<<endl;
  //print_details();
}
//Getters
float  Triangle::BaseA() const{return base_a;}
float  Triangle::SideBC() const{return side_bc;}

//Setters
void Triangle::BaseA(float a)  {base_a  = a;}
void Triangle::SideBC(float bc){side_bc = bc;}

//Printers
void Triangle::print_base_a() const  {cout<<"base_a ="<<base_a<<endl;}
void Triangle::print_side_bc() const {cout<<"side_bc ="<<side_bc<<endl;}
void Triangle::print_details() const {
   cout<<"------Triangle details(self):-----"<<endl;
   cout<<"Triangle::base_a  ="<<base_a<<endl;
   cout<<"Triangle::side_bc ="<<side_bc<<endl;
   cout<<"------Inherited from Shape:-----"<<endl;
   //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
   cout<<"Shape::protectVar1   ="<<Shape::protectVar1<<endl;
   cout<<"Shape::circum_radius ="<<circum_radius<<endl;
   cout<<"Shape::color ="<<color<<endl;
   return;
}


//----------------------------- Class Square --------------------------------------------------
//Constructors
Square::Square(): Shape("square-color-unknown"),side(5.1){
  cout<<"Square NO-parameter constructor invoked"<<endl;
  //print_details();
}

Square::Square(string col, float side): Shape(col), side(side){
  cout<<"Square parameter constructor invoked"<<endl;
  //print_details();
}
//Getters
float Square::Side() const{return side;}

//Setters
void Square::Side(float x){side = x;}

//Printers
void Square::print_side() const {cout<<"side ="<<side<<endl;}
void Square::print_details() const {
  cout<<"------Square details(self):-----"<<endl;
  cout<<"Square::side ="<<side<<endl;
  cout<<"------Inherited from Shape:-----"<<endl;
  //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
  cout<<"Shape::protectVar1="<<Shape::protectVar1<<endl;
  cout<<"Shape::circum_radius="<<circum_radius<<endl;
  cout<<"Shape::color="<<color<<endl;
  return;
}


//----------------------------- Class Girl --------------------------------------------------
//Constructors
Girl::Girl():girl_age(6.1), neck_coord(6.2), body_angle(6.3){
       cout<<"Girl NO-parameter constructor invoked"<<endl;
       //print_details();
      }

Girl::Girl(string smiley_color,  float smiley_radius,  string emotion,
           string triangle_color,float triangle_base_a,float triangle_side_bc,
           float girl_age, float neck_coord, float body_angle):
      SmileyFace(smiley_color, smiley_radius,emotion),
      Triangle(triangle_color,triangle_base_a, triangle_side_bc),
      girl_age(girl_age), neck_coord(neck_coord), body_angle(body_angle) {
       cout<<"Girl parameter constructor invoked"<<endl;
       //print_details();
      }

//Getters
float Girl::GirlAge() const  {return girl_age;}
float Girl::NeckCoord() const{return neck_coord;}
float Girl::BodyAngle() const{return body_angle;}

//Setters
void Girl::GirlAge(float a)  {girl_age = a;}
void Girl::NeckCoord(float n){neck_coord = n;}
void Girl::BodyAngle(float b){body_angle = b;}

//Printers
void Girl::print_girl_age()   const {cout<<"girl_age   ="<<girl_age<<endl;}
void Girl::print_neck_coord() const {cout<<"neck_coord ="<<neck_coord<<endl;}
void Girl::print_body_angle() const {cout<<"body_angle ="<<body_angle<<endl;}
void Girl::print_details() const{
 cout<<"------Girl details(self):-----"<<endl;
 cout<<"girl_age   ="<<girl_age<<endl;
 cout<<"neck_coord ="<<neck_coord<<endl;
 cout<<"body_angle ="<<body_angle<<endl;

 cout<<"\n------Inherited from SmileyFace(Chain Girl-SmileyFace-Circle-Shape)-----"<<endl;
 cout<<"SmileyFace::emotion ="<<emotion<<endl;
 cout<<"------Inherited from Circle(Chain Girl-SmileyFace-Circle-Shape)--------"<<endl;
 //cout<<"Circle::privateVar1_circle="<<privateVar1_circle<<endl;
 cout<<"Circle::protectVar1="<<Circle::protectVar1<<endl;
 cout<<"Circle::radius ="<<radius<<endl;
 cout<<"------Inherited from Shape(Chain Girl-SmileyFace-Circle-Shape)--------"<<endl;
 //cout<<"Shape::protectVar1="<<this->SmileyFace.Circle.Shape::protectVar1<<endl;
 cout<<"Shape::circum_radius="<<Circle::circum_radius<<endl;
 cout<<"Shape::color="<<Circle::color<<endl;

 cout<<"\n------Inherited from Triangle(Chain Girl-Triangle-Shape):-----"<<endl;
 cout<<"Triangle::base_a ="<<base_a<<endl;
 cout<<"Triangle::side_bc ="<<side_bc<<endl;
 cout<<"------Inherited from Shape(Chain Girl-Triangle-Shape):-----"<<endl;
 //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;
 //cout<<"Shape::protectVar1="<<this->Triangle.Shape::protectVar1<<endl;
 cout<<"Shape::circum_radius="<<Triangle::circum_radius<<endl;
 cout<<"Shape::color="<<Triangle::color<<endl;

}



//----------------------------- Class Boy --------------------------------------------------
//Constructors
Boy::Boy():boy_age(7.1), neck_coord(7.2), body_angle(7.3){
     cout<<"Boy NO-parameter constructor invoked"<<endl;
     //print_details();
    }

Boy::Boy(string smiley_color,  float smiley_radius,  string emotion,
         string square_color,float square_side,
         float boy_age, float neck_coord, float body_angle):
      SmileyFace(smiley_color,smiley_radius,emotion),
      Square(square_color, square_side),
      boy_age(boy_age), neck_coord(neck_coord), body_angle(body_angle) {
      cout<<"Boy parameter constructor invoked"<<endl;
      //print_details();
    }


//Getters
float Boy::BoyAge() const   {return boy_age;}
float Boy::NeckCoord() const{return neck_coord;}
float Boy::BodyAngle() const{return body_angle;}

//Setters
void Boy::BoyAge(float a)   {boy_age = a;}
void Boy::NeckCoord(float n){neck_coord = n;}
void Boy::BodyAngle(float b){body_angle = b;}

//Printers
void Boy::print_boy_age()    const {cout<<"boy_age   ="<<boy_age<<endl;}
void Boy::print_neck_coord() const {cout<<"neck_coord ="<<neck_coord<<endl;}
void Boy::print_body_angle() const {cout<<"body_angle ="<<body_angle<<endl;}

void Boy::print_details() const{
 cout<<"------Boy details(self):-----"<<endl;
 cout<<"boy_age    ="<<boy_age<<endl;
 cout<<"neck_coord ="<<neck_coord<<endl;
 cout<<"body_angle ="<<body_angle<<endl;

 cout<<"\n------Inherited from SmileyFace(Chain Boy-SmileyFace-Circle-Shape)-----"<<endl;
 cout<<"SmileyFace::emotion ="<<emotion<<endl;
 cout<<"------Inherited from Circle(Chain Boy-SmileyFace-Circle-Shape)--------"<<endl;
 cout<<"Circle::radius ="<<radius<<endl;
 cout<<"Circle::protectVar1="<<Circle::protectVar1<<endl;
 //cout<<"Circle::privateVar1_circle="<<privateVar1_circle<<endl;
 cout<<"------Inherited from Shape(Chain Boy-SmileyFace-Circle-Shape)--------"<<endl;
 cout<<"Shape::circum_radius="<<Circle::circum_radius<<endl;
 cout<<"Shape::color="<<Circle::color<<endl;
 //cout<<"Shape::protectVar1="<<this->SmileyFace::Circle.Shape::protectVar1<<endl;

 cout<<"\n------Inherited from Square(Chain Boy-Square-Shape):-----"<<endl;
 cout<<"Square::side ="<<side<<endl;
 cout<<"------Inherited from Shape(Chain Boy-Square-Shape):-----"<<endl;
 cout<<"Shape::circum_radius="<<Square::circum_radius<<endl;
 cout<<"Shape::color="<<Square::color<<endl;
 cout<<"Shape::protectVar1="<<this->Square::protectVar1<<endl;
 //cout<<"Shape::privateVar1_shape="<<privateVar1_shape<<endl;

}
