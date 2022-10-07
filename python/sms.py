#import tkinter
import csv
import datetime
import mysql.connector as msc
co=msc.connect(host="localhost",user="root",password="Debug@12",database="supermarket")
if co.is_connected():
    #print("Connected")
    print("\n")
else:
    print("Not connected")
    
c=co.cursor()

# SQL table creation - important
"""
c.execute("create table emp(id int, ename varchar(30), address varchar(60));")
print("Employee table created.")

c.execute("create table customer(cid int,cname varchar(30), cphone int);")
print("Customer table created.")

c.execute("create table prd(pid int, pname varchar(20), qty int, price int);")
print("Product table created.")
"""

print("\t\t\tWelcome to the Supermarket management system!")
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
print("\nSo, lets get started by getting you Logged-In\n")


#GUI    #can be deleted
'''heading = tkinter.Label(window,text = "Welcome to the Supermarket!",font = ("RockWell",20))
window.geometry('350x500')
heading.grid(column=0,row=0)

username = tkinter.Label(window,text = "Enter username")
username.grid(column=0,row=1)
txtusername = tkinter.Entry(window, width = 10)
txtusername.grid(column=0,row = 2)

pswd = tkinter.Label(window,text = "Enter Password")
pswd.grid(column=0,row=3)
txtpswd = tkinter.Entry(window, width = 10)
txtpswd.grid(column=0,row=4)'''

login_id=input("Enter username:  ")
psswd=input("Enter password:  ")

def sp():
    print("---------------------------------------------------------------------------------------------------------------")


    loginlist=["Employee", "Manager", "Tech Support", "Customer"]
    pswdlist=["working", "Scott", "tech guy","123"]
   
                                                                                                                                    #logging in
while True:
    if (login_id=="Employee" and psswd=="working"):
        print("\nWelcome",login_id,"!")
        break
    
    elif (login_id=="Manager" and psswd=="Scott"):
        print("\nWelcome",login_id,"!")
        break
    
    elif (login_id=="Tech Support" and psswd=="tech guy"):
        print("\nWelcome",login_id,"!")
        break
    
    elif(login_id=="Customer" and psswd=="123"):
        print("\nWelcome",login_id,"!")
        break
    
    else:
        print("Wrong ID or password")
        exit()

#function for employee
def customerdata():
    print("\n\t\tMenu of functions")
    sp()
    print("[1] Add customer ")
    print("[2] Remove customer")
    print("[3] View customer database")
    print("[4] Update customer details")
    print("[5] Exit")

    ec=int(input("Enter option choice:"))

    if (ec==1):                                                                                     #Add
        custid=int(input("Enter Customer ID:"))
        custnm=input("Enter Customer name:")
        custph=int(input("Enter 8 digit mobile number:")) 
        c.execute("insert into customer (cid,cname,cphone) values ({},' {}',{})".format(custid,custnm,custph))
        co.commit()
        print("Customer data inserted")

    elif (ec==2):                                                                               #Remove
        dnm=int(input("Enter customer id of customer whose details are to be deleted:"))
        c.execute("delete from customer where cid="+str(dnm)+";")
        co.commit()
        print("Customer record deleted")

    elif(ec == 3):                                                                          #View All
        c.execute("select * from customer")
        rs = c.fetchall()
        norec = c.rowcount
        sp()
        print("\nTotal records found are ",norec,"\n")
        for row in rs:
            print(row)
            co.commit()

    elif (ec==4):                                                                               #Update
        eid = int(input("Enter customer ID:"))
        name = input("Enter the name:")
        phno = input("Enter new phone no.:")
        c.execute("delete from customer where cid="+str(eid)+";")
        c.execute("insert into customer (cid,cname,cphone) values ({},' {}','{}')".format(eid,name,phno))

    elif(ec == 5):
        exit()
    else:
        print("Select valid option")


#function for manager
def productdata():
    print("\t\tMenu of functions")
    sp()
    print("[1] Add product")
    print("[2] Remove product")
    print("[3] View product database")
    print("[4] Update product")
    print("[5] Exit")

    ec=int(input("Enter option choice:"))

    if (ec==1):                                                                                 #Add
        pid=int(input("Enter product ID:"))
        pname=input("Enter product name:")
        qty=int(input("Enter Quantity:"))
        price = int(input("Enter Price:"))
        c.execute("insert into prd(pid,pname,qty,price) values ({},' {}',{},{})".format(pid,pname,qty,price))
        co.commit()
        print("Product added!")

    elif (ec==2):                                                                               #Remove
        dnm=int(input("Enter product id of the product to be deleted:"))
        c.execute("delete from prd where pid="+str(dnm)+";")
        co.commit()
        print("Product deleted!")

    elif(ec == 3):                                                                              #View All
        c.execute("select * from prd")
        rs = c.fetchall()
        norec = c.rowcount
        sp()
        print("\nTotal records found are ",norec,"\n")
        for row in rs:
            print(row)
            co.commit()

    elif (ec==4):                                                                                   #Update
        eid = int(input("Enter product id:"))
        name = input("Enter product name:")
        qty = int(input("Enter new qty:"))
        price = input("Enter new price:")
        c.execute("delete from prd where pid="+str(eid)+";")
        c.execute("insert into prd (pid,pname,qty,price) values ({},' {}','{}','{}')".format(eid,name,qty,price))

    elif(ec == 5):
        exit()

    else:
        print("Select valid option")


#function for tech support
def employeedata():
    print("\t\tMenu of functions")
    sp()
    print("[1] Add employee ")
    print("[2] Remove employee")
    print("[3] View employee database")
    print("[4] Update employee record")
    print("[5] Exit")

    ec=int(input("Enter option choice:"))

    if (ec==1):                                                                                 #Add
        eid=int(input("Enter employee ID:"))
        name=input("Enter name:")
        add=input("Enter address:") 
        c.execute("insert into emp (id,ename,address) values ({},' {}','{}')".format(eid,name,add))
        co.commit()
        print("Employee data inserted")

    elif (ec==2):                                                                       #Remove
        dnm=int(input("Enter employee id of customer whose details are to be deleted:"))
        c.execute("delete from emp where id="+str(dnm)+";")
        co.commit()
        print("Employee record deleted")

    elif(ec == 3):                                                                       #View All
        c.execute("select * from emp")
        rs = c.fetchall()
        norec = c.rowcount
        print("Total records found are ",norec,"\n")
        for row in rs:
            print(row)
        co.commit()

    elif (ec==4):                                                                        #update
        eid = int(input("Enter id of the employee: "))
        name = input("Enter the name: ")
        addr = input("Enter new address: ")
        c.execute("delete from emp where id="+str(eid)+";")
        c.execute("insert into emp (id,ename,address) values ({},' {}','{}')".format(eid,name,addr))
        print("Data Updated")
        co.commit()

    elif (ec==5):
        exit()

    else:
        print("Select valid option")


def neworder():
    print("\t\t\tMenu of functions")
    sp()
    print("[1] Add items")
    print("[2] View cart")
    print("[3] Checkout")
    print("[4] Exit")

    def reader():
        gtp=0
        f1=open("cart1.csv","r")
        print("\n\t\t\t\tCART\n")
        cr = csv.reader(f1)
        #rec=[]
        for i in cr:
            if(i[0] !='P_ID'):
                print(i[0],"\t\t",i[1],"\t\t",i[2],"\t\t",i[3],"\t\t",i[4],"\n")
                z=(int)(i[4])
                gtp = gtp + z
                continue

        print("\n\t\t\t\t\t\t\tGrand Total:",gtp)                          #Grand total
            
            
        f1.close()

                                                                                                                    #choice of function
    ec=int(input("\nEnter option choice:"))
    
    if(ec == 1):
        f=open("cart1.csv","w",newline="")
        cw = csv.writer(f)
        
        cw.writerow(["P_ID","P_Name","Qty","Price","Total Price"])

        #creating cart
        cart = []
        while True:
            pid = int(input("\nEnter product ID:"))
            np = input("Enter product name:")
            qty = int(input("Enter product quantity:"))
            pp = int(input("Enter product price:"))
            l = [pid,np,qty,pp,(pp*qty)]
            cart.append(l)
            ch = input("Do you want to input more records? [Y/N]")
            if(ch == 'N' or ch == 'n'):
                break

        cw.writerows(cart)
        f.close()

    elif(ec == 2):
        reader()

    elif (ec==3):
        cnm = input("\nEnter customer name:")
        paymth=input("Enter payment method[Cash / Debit Card / Credit Card / Digital Payment (UPI)]:  ")
        print("\n\t\t\tSUPERMARKET\n")
        sp()
        print("Customer Name:\t"+cnm)
        print("Payment Method:\t"+paymth)        
        td=datetime.date.today()                                        # Date, Day, Time
        z=td.strftime("%A")
        print("\nDate:\t",td)
        print("Day:\t",z)
        tmn=datetime.datetime.now()
        tm=tmn.strftime("%H:%M:%S")
        print("Time:\t",tm)
        print("")
        
        reader()
        
    elif(ec == 4):
            exit()

    else:
        print("Enter a valid option")


#MAIN

while True:
                                                                                            #function call      
    if(login_id == "Employee"):
        print("\nManage customer data - Add, Delete, View")
        customerdata()
           
    elif (login_id == "Manager"):
        print("\nManage product data - Add, Delete, View")
        productdata()
    
    elif (login_id=="Tech Support"):
        print("\nAdd, Delete, View, Update employee details")
        employeedata()

    elif (login_id=="Customer"):
        print("\n\tHappy Shopping!\n")
        neworder()
