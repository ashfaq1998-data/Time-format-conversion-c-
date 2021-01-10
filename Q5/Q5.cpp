//19000081//
#include<iostream>
#include<cstring>

using namespace std;


class time24
{
   private:
      int hours, minutes;
   public:
      time24()
      {
         hours = 0;
         minutes = 0;
         
      }

      time24(int h, int m)
      {
         hours = h;
         minutes = m;
         
      }

      int Hours(){
	  	return hours;
	  }
      int Minutes(){
	  	return minutes;
	  }
      
      void display()
      {
         cout << hours << ":" << minutes << endl;
      }
};


class time12
{
   private:
      int hours, minutes;
      bool pm;
   public:
      time12()
      {
         hours = 0;
         minutes = 0;
         
      }

      time12(int h, int m, char *t)
      {
         hours = h;
         minutes = m;
        
         if(strcmp(strupr(t),"PM")==0)
            pm = 1;
         else
            pm = 0;
      }
   
   
   time12(time24 time)
   {
      hours = time.Hours()%12;
      minutes = time.Minutes();
      
      pm = static_cast<bool>(time.Hours()/12);
   }
   
   
   operator time24()
   {
      int h = pm ? hours + 12 : hours;
      int m = minutes;
      
      return time24(h, m);
   }

   void display()
   {
      cout << hours << ":" << minutes << " " << (pm?"PM":"AM") << endl;
   }
};

int main()
{
		int x;
   		cout << "Please enter the choices according to following" << endl;
  		cout << "1. 24 hours time format into 12 hours format" << endl;
  		cout << "2. 12 hours time format into 24 hours format" << endl;
  		cin >> x;
  		
  		if(x==1){
  				int a;
  				int b;
  				cout << "Please enter the hours :" << endl;
  				cin >> a;
  				cout << "Please enter the minutes :" << endl;
  				cin >> b;
  				time24 T(a,b);
  				time12 T1;
  				T1=T;
  				cout << "24 hour time format: ";
   				T.display();
   				cout << "\nEquivalent 12 hour time: ";
   				T1.display();
		  }else{
		  		int x;
  				int y;
  				cout << "Please enter the hours :" << endl;
  				cin >> x;
  				cout << "Please enter the minutes :" << endl;
  				cin >> y;
   				time12 T2(x,y,"PM");
  				time24 T3;
  				T3=T2;
  				cout << "\n12 hour time format: ";
  				T2.display();
  				cout << "Equivalent 24 hour time: ";
  				T3.display();
  				cout << "\n";
   			
		  }
  		
  		
return 0;

}
