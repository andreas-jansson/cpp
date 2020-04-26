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
        this->radius=0;
        this->rpm=0;
        this->angle=0;
        this->pressure=0;
    }
    
    Wheel(double rad){
        this->radius=rad;
    }
    
    
    
    void wheel_radius(double rad){
        this->radius=rad;
    }

    bool set_rpm(double newRpm){
        cout<<"yo"<<this<<endl;
        this->rpm=newRpm;
        return true;
    }
    
    double get_rpm(){
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

  Wheel *flWheel;
  Wheel *frWheel;
  Wheel *rlWheel;
  Wheel *rrWheel;
  
    public:
    Color color;
    Car(){
        color=red;
        model="base";
        weight= 1500;
        linearVelocity=0;
        angularVelocity=0;
        
        this->flWheel = new Wheel();
        this->frWheel = new Wheel();
        this->rlWheel = new Wheel();
        this->rrWheel = new Wheel();
        cout<<"flWheel: "<<flWheel<<endl;
        
    }
    
    Car(Color ncolor, string nmodel, int nweight, double nlinearVelocity, double nangularVelocity){
          color=ncolor;
          model=nmodel;
          weight= nweight;
          linearVelocity=nlinearVelocity;
          angularVelocity=nangularVelocity;
      }
    
    string get_model(){
        return this->model;
    }
    
    void get_speedinfo(){
        double rpm=flWheel->get_rpm();
        cout<<"flWheel rpm: "<<rpm<<::endl;
        cout<<"flWheel angle: "<<flWheel->get_angle()<<::endl;
        
        cout<<"frWheel rpm: "<<frWheel->get_rpm()<<::endl;
        cout<<"frWheel angle: "<<frWheel->get_angle()<<::endl;
        
        cout<<"rlWheel rpm: "<<rlWheel->get_rpm()<<::endl;
        cout<<"rlWheel angle: "<<rlWheel->get_angle()<<::endl;
        
        cout<<"rrWheel rpm: "<<rrWheel->get_rpm()<<::endl;
        cout<<"rrWheel angle: "<<rrWheel->get_angle()<<::endl;

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
        
        flWheel = new Wheel(old_car.flWheel->get_radius());
        flWheel->set_rpm(old_car.flWheel->get_rpm());
        
        frWheel = new Wheel(old_car.flWheel->get_radius());
        frWheel->set_rpm(old_car.frWheel->get_rpm());

        rlWheel = new Wheel(old_car.flWheel->get_radius());
        rlWheel->set_rpm(old_car.rlWheel->get_rpm());

        rrWheel = new Wheel(old_car.flWheel->get_radius());
        rrWheel->set_rpm(old_car.rrWheel->get_rpm());
        
    }
    
    ~Car(){
        cout<<"d-structor"<<::endl;

        delete flWheel;
        delete frWheel;
        delete rlWheel;
        delete rrWheel;
        
        weight=0;
        model="";
        linearVelocity=0;
        angularVelocity=0;
        

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
