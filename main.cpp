#include <iostream>
#include <fstream>
#include <iomanip>
#include <strings.h>
#include <windows.h>

using namespace std;

void menu();

class manageMenu{
  protected:
        string userName; // hide admin name;

  public:

        manageMenu(){
        system("color 0A"); // change terminal color
        cout <<"\n\n\n\n\n\n\n\t Enter your Name to continue as an Admin:";
        cin  >>userName;
        system("CLS");
        menu();
        }
        ~manageMenu(){};

};

class Customers{

  public:
  string name, gender,address;
  int age, mobileNo;
  static int cusId;
  char all[999];

  void getDetails(){

    ofstream out("old-customers.txt", ios::app);
    {
    cout<<"Enter your Name : "<<endl;
    cin>>name;
    cout<<"Enter your gender : "<<endl;
    cin>>gender;
    cout<<"Enter your address : "<<endl;
    cin>>address;
    cout<<"Enter your age : "<<endl;
    cin>>age;
    cout<<"Enter your mobileNo : "<<endl;
    cin>>mobileNo;
    cout<<"Enter your cusId : "<<endl;
    cin>>cusId;

      out<<"\nCustomerId : "<<cusId<< "\nName : "<<name<<"\nAge : "<<age<<"\nGender : "<<gender<<"\nAddress : "<<address<<"\nMobileNo : "<<mobileNo<<endl;
      out.close();
      cout<<"\nSAVED \nNOTE : We save your details for future references";
    }
  }

  void showDetails(){

    ifstream in("old-customers.txt");
    {
      if(!in){
      cout<<"File Error!"<<endl;
    }
    while(!(in.eof())){
      in.getline(all, 999);
      cout<<all<<endl;
    }
    in.close();
    }
  }
};

int Customers::cusId;

class Cabs{
public:
  int cabChoice;
  int kilometers;
  float cabCost;
  static float lastcabCost;

  void cabDetails(){
    cout << "You have collaborated with the fastest, safest and smartest cab service in the country"<<endl;
    cout<<"------------------------Dunzo Cabs-------------------------"<<endl;
    cout<<"1.Rent a Standerd Cab : 5$ per km" << endl;
    cout<<"2.Rent a Luxury Cab : 10$ per km" << endl;

    cout<<"\nTo calculate the total cost of your journey"<<endl;
    cout<<"Enter the cab by which you want to travel : "<<endl;
    cin >> cabChoice;
    cout<<"Enter the kilometers you want to travel : "<<endl;
    cin >> kilometers;

    int hireCab;

    if(cabChoice==1){
      cabCost = 5 *  kilometers;
      cout<<"\nYour tour cost is "<<cabCost<<"$ for a Standerd cab"<<endl;
      cout<<"Press 1 to hire this cab or"<<endl;
      cout<<"Press 2 to hire another cab"<<endl;
      cin>>hireCab;

      system("CLS");
      if(hireCab==1)
      {
        lastcabCost=cabCost;
        cout<<"\nYou have successfully hired the Standerd Cab"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else if(hireCab==2)
      {
        cabDetails();
      }

      else
      {
       cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
        Sleep(999);
        system("CLS");
        cabDetails();
      }
    }

    else if(cabChoice==2){
      cabCost = 10 *  kilometers;
      cout<<"\nYour tour cost is "<<cabCost<<"$ for a luxury cab"<<endl;
      cout<<"Press 1 to hire this cab or"<<endl;
      cout<<"Press 2 to hire another cab"<<endl;
      cin>>hireCab;

      system("CLS");
      if(hireCab==1)
      {
        lastcabCost=cabCost;
        cout<<"\nYou have successfully hired the Luxury Cab"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else if(hireCab==2)
      {
        cabDetails();
      }

      else
      {
       cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
        Sleep(1100);
        system("CLS");
        cabDetails();
      }
    }

    else{
      cout<<"Invalid Input! Redirecting to Main Menu  \nPlease Wait!!"<<endl;
      Sleep(1100);
      system("CLS");
      cabDetails();
      menu();
    }

    cout<<"\nPress 1 to Redirect to Main Menu"<<endl;
    cin>>hireCab;
    system("CLS");
    if(hireCab==1){
     menu();
    }
    else{
     menu();
    }
  }
};

float Cabs::lastcabCost;

class Booking{
public:
  int choiceHotel;
  int packChoice;
  static int hotelCost;

  void hotels(){
    string hotelNo[]= {"Palmyra", "Taj", "Alessandro"};
    for(int a=0; a<3; a++){
      cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl;
    }
    cout<<"\nCurrently we are collaborated with these hotels"<<endl;
    cout<<"Please press any key to go back or\nEnter the number of Hotel you want to book"<<endl;
    cin>>choiceHotel;

    system("CLS");

    if(choiceHotel==1){

      cout<<"-------------------WELCOME TO HOTEL PALMYRA-------------------\n"<<endl;
      cout<<"The Garden, Food and Beverage. Enjoy all you can drink, Stay Cool and get chilled in the summer sun."<<endl;
      cout<<"Packages offered by Palmyra are :\n"<<endl;

      cout<<"1.Standerd Pack"<<endl;
      cout<<"\tAll basic Facilities you need for just 100 $"<<endl;
      cout<<"2.Premium Pack"<<endl;
      cout<<"\tEnjoy Premium Stay at 140 $"<<endl;
      cout<<"3.Luxury Pack"<<endl;
      cout<<"\tLive a Luxury in Palmyra at 200 $"<<endl;

      cout<<"Press another key to go back or\nSelect from the above Package : "<<endl;
      cin>>packChoice;

      if(packChoice==1){
        hotelCost=100;
        cout<<"\nYou have successfully booked the Standerd Package at Palmyra"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

       else if(packChoice==2){
        hotelCost=140;
        cout<<"\nYou have successfully booked the Premium Package at Palmyra"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else if(packChoice==3){
        hotelCost=200;
        cout<<"\nYou have successfully booked the Luxury Package at Palmyra"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else{
        cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
        Sleep(1100);
        system("CLS");
        hotels();
      }

      int gotoMenu;
      cout<<"Press 1 to redirect to Main Menu"<<endl;
      cin>>gotoMenu;
      if(gotoMenu==1){
        menu();
      }
      else{
        menu();
      }
    }

    else if(choiceHotel==2){

      cout<<"-------------------WELCOME TO HOTEL TAJ-------------------\n"<<endl;
      cout<<"The Garden, Food and Beverage. Enjoy all you can drink, Stay Cool and get chilled in the summer sun."<<endl;
      cout<<"Packages offered by Taj are :\n"<<endl;

      cout<<"1.Standerd Pack"<<endl;
      cout<<"\tAll basic Facilities you need for just 100 $"<<endl;
      cout<<"2.Premium Pack"<<endl;
      cout<<"\tEnjoy Premium Stay at 140 $"<<endl;
      cout<<"3.Luxury Pack"<<endl;
      cout<<"\tLive a Luxury in Taj at 200 $"<<endl;

      cout<<"Press another key to go back or\nSelect from the above Package : "<<endl;
      cin>>packChoice;

      if(packChoice==1){
        hotelCost=100;
        cout<<"\nYou have successfully booked the Standerd Package at Taj"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

       else if(packChoice==2){
        hotelCost=140;
        cout<<"\nYou have successfully booked the Premium Package at Taj"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else if(packChoice==3){
        hotelCost=200;
        cout<<"\nYou have successfully booked the Luxury Package at Taj"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else{
        cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
        Sleep(1100);
        system("CLS");
        hotels();
      }

      int gotoMenu;
      cout<<"Press 1 to redirect to Main Menu"<<endl;
      cin>>gotoMenu;
      if(gotoMenu==1){
        menu();
      }
      else{
        menu();
      }
    }

    else if(choiceHotel==3){

      cout<<"-------------------WELCOME TO HOTEL ALESSANDRO-------------------\n"<<endl;
      cout<<"The Garden, Food and Beverage. Enjoy all you can drink, Stay Cool and get chilled in the summer sun."<<endl;
      cout<<"Packages offered by Alessandro are :\n"<<endl;

      cout<<"1.Standerd Pack"<<endl;
      cout<<"\tAll basic Facilities you need for just 100 $"<<endl;
      cout<<"2.Premium Pack"<<endl;
      cout<<"\tEnjoy Premium Stay at 140 $"<<endl;
      cout<<"3.Luxury Pack"<<endl;
      cout<<"\tLive a Luxury in Alessandro at 200 $"<<endl;

      cout<<"Press another key to go back or\nSelect from the above Package : "<<endl;
      cin>>packChoice;

      if(packChoice==1){
        hotelCost=100;
        cout<<"\nYou have successfully booked the Standerd Package at Alessandro"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

       else if(packChoice==2){
        hotelCost=140;
        cout<<"\nYou have successfully booked the Premium Package at Alessandro"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else if(packChoice==3){
        hotelCost=200;
        cout<<"\nYou have successfully booked the Luxury Package at Alessandro"<<endl;
        cout<<"\nGoto Menu and take the receipt"<<endl;
      }

      else{
        cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
        Sleep(1100);
        system("CLS");
        hotels();
      }

      int gotoMenu;
      cout<<"Press 1 to redirect to Main Menu"<<endl;
      cin>>gotoMenu;
      if(gotoMenu==1){
        menu();
      }
      else{
        menu();
      }
    }

    else{
      cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!!"<<endl;
      Sleep(1100);
      system("CLS");
      menu();
    }
  }

};

int Booking ::hotelCost;

class Charges : public Booking, Cabs, Customers{
  public:
  void printBill()
  {
    ofstream outf("receipt.txt");
    {
    outf<<"-----------------ABC travel Agency----------------"<<endl;
    outf<<"---------------------Receipt----------------------"<<endl;
    outf<<"__________________________________________________"<<endl;

    outf<<"Customer ID : "<<Customers::cusId<<endl<<endl;
    outf<<"Description\t\t Total"<<endl;
    outf<<"Hotel Cost\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
    outf<<"Travel Cab Cost\t\t"<<fixed<<setprecision(2)<<Cabs::lastcabCost<<endl;

    outf<<"__________________________________________________"<<endl;
    outf<<"Total Charge\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost<<endl;
    outf<<"__________________________________________________"<<endl;
    outf<<"----------------------THANK YOU-------------------"<<endl;
    }
    outf.close();
  }

  void showBill()
  {
    ifstream inf("receipt.txt");
    {
      if(!inf){
        cout<<"File Opening Error!"<<endl;
      }
      while(!(inf.eof())){
        inf.getline(all, 999);
        cout<<all<<endl;
      }
    }
    inf.close();
  }
};

void menu(){
  int mainChoice, inChoice, gotoMenu;


  cout << "\t\t      * ABC Travels *\n" << endl;
  cout << "-------------------------Main Menu--------------------------" << endl;

  cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
  cout << "\t|\t\t\t\t\t|" << endl;
    //cout << "\t|\tAgency System Management -> 0" << endl;
  cout << "\t|\tCustomer Management -> 1\t|" << endl;
  cout << "\t|\tCabs Management     -> 2\t|" << endl;
  cout << "\t|\tBookings Management -> 3\t|" << endl;
  cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
  cout << "\t|\tExit                -> 5\t|" << endl;
  cout << "\t|\t\t\t\t\t|" << endl;
  cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

  cout<<"\nEnter your choice: ";
  cin>>mainChoice;

  system("CLS");

  Customers a2;
  Cabs a3;
  Booking a4;
  Charges a5;

  if(mainChoice==1){
    cout<<"\n------------------------Customers------------------------"<<endl;
    cout<<"1.Enter New Customer"<<endl;
    cout<<"2.Show Old Customer"<<endl;
    cout<<"\nEnter Choice: "<<endl;
    cin>>inChoice;

    if(inChoice==1){
      a2.getDetails();
    }

    else if(inChoice==2){
      a2.showDetails();
    }

    else{
      cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
      Sleep(1100);
      system("CLS");
      menu();
    }

    cout<<"\nPress 1 to redirect to  Main Menu"<<endl;
    cin>>gotoMenu;
    system("CLS");

    if(gotoMenu==1){
      menu();
    }
    else{
      menu();
    }
  }

  else if(mainChoice==2){
    a3.cabDetails();
  }

  else if(mainChoice==3){
    cout<<"---->Book a Luxury Hotel using this system<----"<<endl;
    a4.hotels();
  }

  else if(mainChoice==4){
    cout<<"---->Get your receipt<----"<<endl;
    a5.printBill();

    cout<<"Your receipt is already printed you can get it from file menu"<<endl;
    cout<<"To display your receipt on the screen Enter 1 or Press another key to go back to menu"<<endl;
    cin>>gotoMenu;

    if(gotoMenu==1){
      system("CLS");
      a5.showBill();
      cout<<"\nPress 1 to redirect to main menu:"<<endl;
      cin>>gotoMenu;
      system("CLS");

      if(gotoMenu==1){
        menu();
      }
      else{
        menu();
      }
    }
    else{
      system("CLS");
      menu();
    }

  }

  else if(mainChoice==5){
    cout<<"--->GOOD BYE<---"<<endl;
    Sleep(999);
    system("CLS");
    menu();
  }

  else{
    cout<<"Invalid Input! Redirecting to previous Menu  \nPlease Wait!!"<<endl;
    Sleep(1100);
    system("CLS");
    menu();
  }

}

int main() {
  manageMenu startObj;
}
