#include <iostream>
using namespace std;

class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
        
    public:
        Fueltank(int m_FueltankCapacity=3000, int gas = 98){
            m_FueltankCapacity = m_FueltankCapacity;
            m_Gas_grade = gas;
        }
        
        void fuel_up(int v, int gas){
            set_Gas_grade(gas);
            cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas<<endl;
        }
        
        void set_Gas_grade(int Gas_grade){
            m_Gas_grade = Gas_grade;
            cout<<"Set Gas_grade = "<<Gas_grade<<endl;
        }
        int get_Gas_grade(){
            return m_Gas_grade;
        }
};

class Car{
    private:
        Fueltank m_Fueltank;
        int m_MaxSeating;
        int m_price;
        int m_base;
        string m__brand;
        string m_model;
        int m_year;
        void m_UpdatePrice(int base = 500000){}
    
    public:
        Car(string x, string y, int z, int s){
            m__brand = x;
            m_model = y;
            m_year = z;
            m_MaxSeating = s;
            Fueltank m_Fueltank;
        }
        
        int get_price(){
            return m_price;
        }
        
        void set_base(int n){
            m_base = n;
        }
        
        string get_brand(){
            return m__brand;
        }
        
    
        int get_Gas_grade(){
            return m_Fueltank.get_Gas_grade();
        }
        
        void set_gas_grade(int gas = 98){
            m_Fueltank.set_Gas_grade(gas);
        }
        
        void fuel_up(int v, int gas = 98){
            m_Fueltank.fuel_up(v, gas);
        }   

};

class BMW_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s){
        cout<< "Constructing BMW_car\n";
        m_DriveMode = "Rear-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class AUDI_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s){
        cout<< "Constructing AUDI_car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class BENZ_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s){
        cout<< "Constructing BENZ_car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){
   AUDI_Car car2("A1", 2021, 2);
   cout << car2.get_brand() << " Gas grade = "<< car2.get_Gas_grade()<<endl;
   car2.set_gas_grade(95);
   cout<<car2.get_brand()<<" Gas_grade = "<<car2.get_Gas_grade()<<endl;
   
   car2.fuel_up(300, 95);
   
   return 0;
}
