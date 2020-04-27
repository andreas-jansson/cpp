#ifndef wheel_h
#define wheel_h
#include <iostream>
using namespace std;

class Wheel {
    double radius;
    double rpm;
    double angle;
    double pressure;
    friend class pump;
    friend class Car;
    
    public:
    
    Wheel(){
//        cout<<"c-tor wheel:"<<this<<endl;
        this->radius=10;
        this->rpm=0;
        this->angle=0;
        this->pressure=0;
    }
    
    Wheel(double rad, double newRpm, double newAngle){
        this->radius=rad;
        this->rpm=newRpm;
        this->angle=newAngle;

    }
    
    void wheel_radius(double rad){
        this->radius=rad;
    }

    bool set_rpm(double newRpm){
//        cout<<"this(set_rpm): "<<this<<endl;
        this->rpm=newRpm;
        return true;
    }
    
    double get_rpm(){
        cout<<"rpm: "<<rpm<<" this: "<<this<<endl;
        return this->rpm;
    }

    bool set_angle(double newAngle){
        this->angle=newAngle;
        return true;
    }
    
    double get_angle(){
        return this->angle;

    }

    double get_radius(){
        return this->radius;
    }

    ~Wheel(){
        radius=0;
        rpm=0;
        angle=0;
    }
    
    friend bool operator==(const Wheel &w1, const Wheel &w2);
    friend bool operator!=(const Wheel &w1, const Wheel &w2);
    friend bool operator<(const Wheel &w1, const Wheel &w2);
    friend bool operator>(const Wheel &w1, const Wheel &w2);
    friend bool operator<=(const Wheel &w1, const Wheel &w2);
    friend bool operator>=(const Wheel &w1, const Wheel &w2);

};

enum Color{
    red,green,blue
};

class Car{
    
  friend class Wheel;
  int weight;
  string model;
  double linearVelocity;
  double angularVelocity;


  
    public:
    Wheel *flWheel;
    Wheel *frWheel;
    Wheel *rlWheel;
    Wheel *rrWheel;

    Color color;
    
    Car(){
        color=red;
        model="base";
        weight= 1500;
        linearVelocity=0;
        angularVelocity=0;
        
        flWheel=new Wheel();
        frWheel=new Wheel();
        rlWheel=new Wheel();
        rrWheel=new Wheel();
//        unique_ptr<Wheel> flWheel, frWheel, rlWheel, rrWheel;

    }
    
    Car(Color ncolor, string nmodel, int nweight, double nlinearVelocity, double nangularVelocity):Car(){
          color=ncolor;
          model=nmodel;
          weight= nweight;
          linearVelocity=nlinearVelocity;
          angularVelocity=nangularVelocity;
      }
    
    string get_model(){
        return this->model;
    }
    
    double get_speedinfo(){
        return linearVelocity;
    }
    
    bool setSpeed(double speed){
        linearVelocity=speed;
        
        return true;
    }
    
    bool setTurningAngle(double anglespeed){
        angularVelocity=anglespeed;
        return true;
    }
    
    Car(const Car &old_car){
        weight=old_car.weight;
        model=old_car.weight;
        linearVelocity=old_car.weight;
        angularVelocity=old_car.weight;
        
        flWheel = new Wheel((old_car.flWheel->get_radius()), (old_car.flWheel->get_rpm()), (old_car.flWheel->get_angle()));
        frWheel = new Wheel((old_car.flWheel->get_radius()), (old_car.flWheel->get_rpm()), (old_car.flWheel->get_angle()));
        rlWheel = new Wheel((old_car.flWheel->get_radius()), (old_car.flWheel->get_rpm()), (old_car.flWheel->get_angle()));
        rrWheel = new Wheel((old_car.flWheel->get_radius()), (old_car.flWheel->get_rpm()), (old_car.flWheel->get_angle()));
    }
    
    ~Car(){
        cout<<"d-structor"<<endl;

        delete flWheel;
        delete frWheel;
        delete rlWheel;
        delete rrWheel;
        
        this->weight=0;
        this->model="";
        this->linearVelocity=0;
        this->angularVelocity=0;
        

    };
    
};


bool operator==(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1==speed2);
}

bool operator!=(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1!=speed2);
}

bool operator<(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1<speed2);
}

bool operator>(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1>speed2);
}

bool operator<=(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1<=speed2);
}

bool operator>=(const Wheel &w1, const Wheel &w2){
    double rad1=w1.radius;
    double rpm1=w1.rpm;
    double speed1=rad1*rpm1;

    double rad2=w2.radius;
    double rpm2=w2.rpm;
    double speed2=rad2*rpm2;

    return(speed1>=speed2);
}

class pump{
    double pressure;
    friend class Wheel;

    public:
    double setPressure(Wheel wheel, double newPressure){
        wheel.pressure=newPressure;
        cout << "P: " << wheel.pressure;
        return wheel.pressure;
    }
};

void hello();

#endif /* wheel_h */
