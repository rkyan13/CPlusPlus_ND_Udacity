#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
using std::string;

class Shape{
   private:
     //arbitrary variable just to check private/protected/public inheritance properties
     int privateVar1_shape;
   protected:
     //arbitrary variable just to check private/protected/public inheritance properties
     int protectVar1;
     //Actual variables needed for graphics
     float  circum_radius;
     string color;

   public:
      //Constructors
      Shape();
      Shape(string col);
      Shape(int priV1, int protV1, float cr, string col);


      //Getters
      int    PrivVar1Shape() const;
      int    ProtVar1() const;
      float  CircumRadius() const;
      string Color() const;

      //Setters
      void PrivVar1Shape(int x);
      void ProtVar1(int x);
      void CircumRadius(float r);
      void Color(string s);

      //Printers
      void print_privVar1_shape() const;
      void print_protVar1() const;
      void print_circum_radius() const;
      void print_color() const;
      void print_details() const;
};



class Circle: public Shape{
  private:
    //arbitrary variable just to check private/protected/public inheritance properties
    int privateVar1_circle;
  protected:
    //arbitrary variable just to check private/protected/public inheritance properties
    int protectVar1;
    //Actual variables needed for graphics
    float  radius;

  public:
     //Constructors
     Circle();
     Circle(string col,float r);
     Circle(string col,int priV1, int protV1,float r);

     //Getters
     int    PrivVar1Circle() const;
     int    ProtVar1() const;
     float  Radius() const;

     //Setters
     void PrivVar1Circle(int x);
     void ProtVar1(int x);
     void Radius(float r);

     //Printers
     void print_privVar1_circle() const;
     void print_protVar1() const;
     void print_radius() const;
     void print_details() const;
};


class SmileyFace: public Circle{
  protected:
     string emotion;
  public:
     //Constructors
     SmileyFace();
     SmileyFace(string col, float r, string emot);

     //Getters
     string  Emotion() const;

     //Setters
     void Emotion(string str);

     //Printers
     void print_emotion() const;
     void print_details() const;
};



class Triangle: public Shape{
  protected:
     //This will be an isosceles triangle
     float  base_a;
     float  side_bc;

  public:
     //Constructors
     Triangle();
     Triangle(string col,float a, float bc);

     //Getters
     float  BaseA() const;
     float  SideBC() const;

     //Setters
     void BaseA(float a) ;
     void SideBC(float bc) ;

     //Printers
     void print_base_a() const;
     void print_side_bc() const;
     void print_details() const;

};


class Square: public Shape{
  protected:
     //This will be an isosceles triangle
     float  side;

  public:
     //Constructors
     Square();
     Square(string col,float side);

     //Getters
     float  Side() const;

     //Setters
     void Side(float x) ;

     //Printers
     void print_side() const;
     void print_details() const;
};


//Girl : Face is SmileyFace, Body is Triangle
class Girl: public SmileyFace, public Triangle{
  private:
     //arbitrary variable just to check private/protected/public inheritance properties
     float girl_age;
  protected:
     //co-ordinate where the triangle-body attaches to the face
     float neck_coord;
     float body_angle;

  public:
     //Constructors
     Girl();
     Girl(string smiley_color,  float smiley_radius,  string emotion,
          string triangle_color,float triangle_base_a,float triangle_side_bc,
          float girl_age, float neck_coord, float body_angle);
     //Getters
     float GirlAge() const;
     float NeckCoord() const;
     float BodyAngle() const;

     //Setters
     void GirlAge(float a);
     void NeckCoord(float n);
     void BodyAngle(float b);

     //Printers
     void print_girl_age() const;
     void print_neck_coord() const;
     void print_body_angle() const;
     void print_details() const;

  //Friend Class can be declared in privte, protected or public section. Makes no difference
  //Also friendship is no mututal
  friend class Boy;
};

//Boy : Face is SmileyFace, Body is Square
class Boy: public SmileyFace, public Square{
private:
   //arbitrary variable just to check private/protected/public inheritance properties
   float boy_age;
protected:
   //co-ordinate where the triangle-body attaches to the face
   float neck_coord;
   float body_angle;

public:
   //Constructors
   Boy();
   Boy(string smiley_color,  float smiley_radius,  string emotion,
       string square_color,float square_side,
       float boy_age, float neck_coord, float body_angle);


   //Getters
   float BoyAge() const;
   float NeckCoord() const;
   float BodyAngle() const;

   //Setters
   void BoyAge(float a);
   void NeckCoord(float n);
   void BodyAngle(float b);

   //Printers
   void print_boy_age() const;
   void print_neck_coord() const;
   void print_body_angle() const;
   void print_details() const;

//Friend Class can be declared in privte, protected or public section. Makes no difference
//Also friendship is no mututal
friend class Girl;

};


#endif
