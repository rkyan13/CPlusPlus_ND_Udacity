#ifndef SPHERE_H
#define SPHERE_H

class Sphere{
  public:
    Sphere();
    Sphere(float radius);

    //getter for Radius
    float Radius() const ;
    //Getter for volume
    float Volume() const ;

    //Setter for Radius, volume
    void Radius(float radius);

    void print_details();

  private:
    /*
    NOTE: Very Big Learning:
    when you are using initializer lists for the Sphere(float radius)
    It is very important that all the constants be declared first. otherwise it gets messed up. The volume will be wrong
    The order is important
    */
    float const PI_= 3.14159;
    int radius_;
    float volume_;

};

#endif
