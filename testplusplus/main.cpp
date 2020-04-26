#include <iostream>
#include "wheel.h"
using namespace std;


int main(int argc, char *argv[]){

    double press;
    string model;
    pump p;
    Wheel w;
    Wheel w2;
    Car *car1=new Car;
    Car *car2=new Car(blue,"v70", 1500, 10, 15);
    
    car2->setSpeed(20);
    car2->setTurningAngle(30);
//    model=car2->get_model();
//    cout << "Car mode2: " << model<<::endl;
//    cout << "Car model: " << car1->color<<::endl;
//    cout << "Car mode2: " << car2->color<<::endl;
//    car2->get_speedinfo();
//    w.wheel_radius(1);
//    w.set_rpm(2);

//    w2.wheel_radius(1);
//    w2.set_rpm(3);
    Car *car3= new Car;
    *car3=(*car2);
    
//    press=p.setPressure(w, 2);
//    cout << "pressure: " << press<<::endl;
//    cout << "rpm: " << w.get_rpm()<<::endl;

    
    cout << "\nCar 2 info"<<::endl;
    car2->get_speedinfo();
    cout << "\nCar 3 info\n"<<::endl;
    car3->get_speedinfo();
    delete car2;
    cout<<"deleted car2"<<endl;
    cout << "\nCar 3 info"<<::endl;
    car3->get_speedinfo();
    cout << "\nCar 2 info"<<::endl;
    car2->get_speedinfo();

//     cout << "\nCar 2 model: "<<car2->get_model()<<::endl;
//     cout << "\nCar 3 model: "<<car3->get_model()<<::endl;
//     delete car2;
//    cout<<"deleted car2"<<endl;
//     cout << "\nCar 2 model: "<<car2->get_model()<<::endl;
//     cout << "\nCar 3 model: "<<car3->get_model()<<::endl;

    
    /*
    if(w==w2){
     cout << "They are the same - True"<<::endl;
    }
    else{
         cout << "They are the same - False"<<::endl;
    }

    if(w!=w2){
     cout << "They are not the same - True"<<::endl;
    }
    else{
      cout << "They are not the same - False"<<::endl;
    }

    if(w<w2){
         cout << "W is slower than w2 - True"<<::endl;
    }
    else{
          cout << "W is slower than w2 - False"<<::endl;

    }

    if(w>w2){
         cout << "W is faster than w2 - True"<<::endl;
    }
    else{
          cout << "W is faster than w2 - False"<<::endl;
    }
    if(w<=w2){
         cout << "W is slower or equal to w2 - True"<<::endl;
    }
    else{
          cout << "W is slower or equal to w2 - False"<<::endl;
    }

    if(w>=w2){
         cout << "W is faster or equal to - True"<<::endl;
    }
    else{
          cout << "W is faster or equal to w2 - False"<<::endl;
    }*/

    return 0;
}
