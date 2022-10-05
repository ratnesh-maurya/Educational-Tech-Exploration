#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>

using namespace std;

class Shopping
{
	private:
		  int prod_code;
		  float price;
		  float discount;
		  string prod_name;
		  
		  public:
		  	 void Menu();
		  	 void Admin();
		  	 void Customer();
		  	 void Add();
		  	 void Edit();
		  	 void Rem();
		  	 void List();
		  	 void Receipt();
		  	 void Admin_List();
};

void Shopping:: Menu(){
	menu:
	int choice;
	string email;
	string passward;
	
	cout<<"\t\t\t=====================================================================\n";
	cout<<"\t\t\t                                                                     \n";
	cout<<"\t\t\t                  Supermarket Main Menu                              \n";
	cout<<"\t\t\t                                                                     \n";
   	cout<<"\t\t\t=====================================================================\n";
	cout<<"\t\t\t                                                                     \n";
	cout<<"\t\t\t\t|         1.)  Admistrator      |\n";
	cout<<"\t\t\t\t|                               |\n";
	cout<<"\t\t\t\t|         2.)  Customer         |\n";
	cout<<"\t\t\t\t|                               |\n";
	cout<<"\t\t\t\t|         3.)  Exit             |\n";
	cout<<"\t\t\t\t|                               |\n";
	cout<<"\n\t\t\t  Please enter your choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
			cout<<endl<<"\t\t\t=====================================================================\n";
			cout<<"\t\t\t                                                                     \n";
			cout<<"\t\t\t                       -----|  Please Login  |-----                       \n";
			cout<<"\t\t\t                                                                     \n";
         	cout<<"\t\t\t=====================================================================\n";
        	cout<<"\t\t\t                                                                     \n";

			cout<<"\t\t\t    Enter Email      : ";
			cin>>email;
			passward ="";
            char ch;
			cout<<"\t\t\t    Password         : ";
		    ch = getch();
            while(ch != 13){// Character 13 is Enter key
            passward.push_back(ch);
            cout << '*';
            ch = getch();
   }
			
			if(email=="abdul.armdb@gmail.com" && passward=="letscrack")
			{
				system("cls");
				Admin();
			}
			else{
				cout<<"\n\t\t\t\t***| Invalid email or password  |***\n\n";
				getch();
				system("cls");
			}
			break;
		    }
		case 2:
			{
				Customer();
				break;
			}
		case 3:
			{
				exit(0);
				break;
			}
		default:
		   {
		   	 cout<<"Please select from the given options";
		   	 break;
			}	
	}
goto menu;
}

void Shopping:: Admin(){
	
	menu:	
	//system("cls");
	int choice;
	cout<<endl<<"\t\t\t=====================================================================\n";
	cout<<"\t\t\t                                                                     \n";
	cout<<"\t\t\t                   -----|  Admin Menu  |-----                       \n";
    cout<<"\t\t\t                                                                     \n";
   	cout<<"\t\t\t=====================================================================\n";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\t\t\t\t|_______1) Add the product___________|";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\t\t\t\t|_______2) Modify the product________|";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\t\t\t\t|_______3) Delete the product________|";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\t\t\t\t|_______4) List of the product_______|";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\t\t\t\t|_______5) Back to the main Menu_____|";
	cout<<"\n\t\t\t\t|                                    |";
	cout<<"\n\n\t Please enter your choice : ";
	cin>>choice;
	
	switch(choice){
		case 1:
			Add();
			break;
		case 2:
			 Edit();
			 break;
		case 3:
			Rem();
			break;
			
		case 4:
			Admin_List();
			break;
		case 5:
			system("cls");
			Menu();
			break;
		default:
			cout<<"\t\tInvalid choice!"<<endl;
			cout<<"\n\n Press any key to go back to Admin Main Menu....";
	        getch();
	        system("cls");
	}
	
	goto menu;
}

void Shopping:: Customer()
{
	menu:
	int choice;
	cout<<endl<<"\t\t\t=====================================================================\n";
	cout<<"\t\t\t                                                                     \n";
	cout<<"\t\t\t                   -----|  Customer  |-----                       \n";
    cout<<"\t\t\t                                                                     \n";
   	cout<<"\t\t\t=====================================================================\n\n";
	cout<<"\t\t\t                 1) Buy product      \n";
	cout<<"                                           \n";
	cout<<"\t\t\t                 2) Go back         \n\n";
	cout<<"\t\t\t Enter your choice :  ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			Receipt();
			break;
		case 2:
			system("cls");
			 Menu();
			 break;
		default:
			cout<<"\n\t\t\t\t***| Invalid choice  |***\n\n";
			getch();
			system("cls");
   }

goto menu;
}

void Shopping:: Add(){
	
	menu:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t----------| Add new product |-------------";
	cout<<"\n\n\t Product code of the product : ";
	cin>>prod_code;
	cout<<"\n\n\t Name of the product         : ";
	cin>>prod_name;
	cout<<"\n\n\t Price of the product        : ";
	cin>>price;
	cout<<"\n\n\t Discount on product         : ";
	cin>>discount;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<prod_code<<" "<<prod_name<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof()){
			if(c==prod_code)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	if(token==1)
	{
		cout<<"\n\n\t\t --***| Please enter valid product code..this product code already exist. |***---\n";
		goto menu;
	}
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<prod_code<<" "<<prod_name<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
}
	cout<<"\n\n\t\t ----*| record inserted |*-----\n";
	cout<<"\n\n Press any key to go back to Admin Main Menu....";
	getch();
	system("cls");
}

void Shopping::Edit(){
	
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t----------| modify the record |-------------";
	cout<<"\n\n\t\t\t product code : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\n file doesn't exist! ";
	}
	else{
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>prod_code>>prod_name>>price>>discount;
		while(!data.eof()){
			if(pkey==prod_code)
			{
				cout<<"\n\t\t Product new code    : ";
				cin>>c;
				cout<<"\n\t\t Name of the product : ";
				cin>>n;
				cout<<"\n\t\t Price    : ";
				cin>>p;
				cout<<"\n\t\t Discount : ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
	            cout<<"\n\n\t\t ----*| record edited |*-----\n";
				token++;
				cout<<"\n\n Press any key to go back to Admin Main Menu....";
	            getch();
	            system("cls");
			}
			else
			{
				data1<<" "<<prod_code<<" "<<prod_name<<" "<<price<<" "<<discount<<"\n";
			}
			data>>prod_code>>prod_name>>price>>discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Sorry! record not found ";
			cout<<"\n\n Press any key to go back to Admin Main Menu....";
	        getch();
	        system("cls");
		}
	}
	
}

void Shopping:: Rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t\t\t----------| Delete product |-------------";
	cout<<"\n\n\t    Product code : ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"file doesn't exist ";
	}
	else{
		data1.open("database1.txt", ios::app| ios::out);
		data>>prod_code>>prod_name>>price>>discount;
		while(!data.eof())
		{
			if(prod_code==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully! ";
				token++;
				cout<<"\n\n Press any key to go back to Admin Main Menu....";
	            getch();
	            system("cls");
			}
			else
			{
				data1<<" "<<prod_code<<" "<<prod_name<<" "<<price<<" "<<discount<<"\n";
			}
		data>>prod_code>>prod_name>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Sorry! record not found";
			cout<<"\n\n Press any key to go back to Admin Main Menu....";
	        getch();
	        system("cls");
		}
	}
}

void Shopping:: List()
{
	system("cls");
	fstream data;
	data.open("database.txt", ios::in);
		cout<<"\n\n\t\t\t----------| Product List|-------------";

	cout<<"\n\n=======================================================================================\n";
	cout<<"proNo\t\tName\t\tPrice\n";
	cout<<"\n=======================================================================================\n";
	data>>prod_code>>prod_name>>price>>discount;
    while(!data.eof()){
    	cout<<prod_code<<"\t\t"<<prod_name<<"\t\t\t"<<price<<"\n";
		data>>prod_code>>prod_name>>price>>discount;
	}
	data.close();
}

void Shopping::Admin_List()
{
	system("cls");
	fstream data;
	data.open("database.txt", ios::in);
		cout<<"\n\n\t\t\t----------| Product List|-------------";

	cout<<"\n\n=======================================================================================\n";
	cout<<"proNo\t\tName\t\tPrice\n";
	cout<<"\n=======================================================================================\n";
	data>>prod_code>>prod_name>>price>>discount;
    while(!data.eof()){
    	cout<<prod_code<<"\t\t"<<prod_name<<"\t\t"<<price<<"\n";
		data>>prod_code>>prod_name>>price>>discount;
	}
	data.close();
	cout<<"\n\n Press any key to go back to Admin Main Menu...."; 
    getch();
    system("cls");
	
	
}

void Shopping:: Receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float discount=0;
	float total=0;
	
	data.open("database.txt", ios::in);
	if(!data){
		cout<<"\n\nEmpty database";
	}
	else{
		data.close();
		
		List();
		cout<<"\n\n\n\t\t===========================================\n";
		cout<<"                                          \n";
		cout<<"\t\t        Please place the order             \n";
		cout<<"                                           \n";
		cout<<"\t\t===========================================\n";
		do{
			m:
		  cout<<"\n\nEnter product code : ";
		  cin>>arrc[c];
		  cout<<"\n\nEnter the quantity : ";
		  cin>>arrq[c];
		  for(int i=0; i<c;i++)
		  {  if(arrc[c]==arrc[i])
		    {
		  	cout<<"\n\n Duplicate product code. Please try again!";
		  	goto m;
		    }
		  }
		  c++;
		  cout<<"\n\n Do you want to buy another product? if yes then press y or else n  :";
		  cin>>choice;
		}while(choice == 'y');
		system("cls");
		cout<<"\n\n\t\t\t==============================| Receipt |==============================\n";
		cout<<"\nProduct no\tProduct Name\tProductQuantity\tPrice \tAmount\tAmount with discount\n ";
        
        for(int i=0; i<c; i++)
        {
        	data.open("database.txt", ios::in);
        	data>>prod_code>>prod_name>>price>>discount;
        	while(!data.eof()){
        		if(prod_code==arrc[i])
        		{
        			amount=price*arrq[i];
        			discount=amount-(amount*discount/100);
        			total=total+discount;
        			cout<<endl<<prod_code<<"\t\t"<<prod_name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
        		}
   				data>>prod_code>>prod_name>>price>>discount;
			}
		}
         data.close();
	}
	
cout<<"\n\n==============================================";
cout<<"\n Total Amount : "<<total;
cout<<"\n-------------------------------";
cout<<"\n\n Press any key to go back to Customer Main Menu....";
getch();
system("cls");

}

int main()
{  
  Shopping s;
  s.Menu();
  return 0;
}