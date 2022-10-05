print("Welcome! This a food ordering prototpye website .\n\n")
#this program lets you login, sign up, store your info, edit the info, show your info, see available item, checkout
# see cart items, edit cart items, search for items and etc
print("This program lets you experience the actual foood ordering websites with basic GUI.\n")
print("To enter the site you'll first have to craete an account or login.\n")

d={"name1":"Gaurang", "pswd1":"Password","phone1":9758756452, "email1":"gaurang.s@gmail.com"}
chnse=["Noodle","Manchurian","Dimsums"]
ftfd=["Samosa","Honey Chilli Potato","Pav Bhaji"]
amrcn=["Veg Burger","Non Veg Burger","Fries","Shakes"]
mnc=["Thali","Chaap","Paneer Sabzi","Roti","Naan"]
swts=["Pastries","Tarts","Cakes","Gulab Jamun","Jalebi"]
ct=()
cart=()


food=chnse+ftfd+amrcn+mnc+swts

dp={"Noodle":80,"Manchurian":100,"Dimsums":50,"Samosa":10,"Honey Chilli Potato":70,"Pav Bhaji":60,"Veg Burger":50,"Non Veg Burger":60,"Fries":40,
        "Shakes":70,"Thali":180,"Chaap":130,"Paneer Sabzi":140,"Roti":15,"Naan":20,"Pastries":50,"Tarts":60,"Cakes":200,"Gulab Jamun":20,"Jalebi":100}


ID=input("Sign Up[1] or Sign In[2]?")
if (ID=="Sign Up" or ID=="1" or ID=="sign up"):
    print("Greetings!! Create your account here and start shopping!")
    nm=input("Enter your name:")                                                                    #create your account
    ps=input("Enter password for your account:")
    ph=int(input("Enter your phone number:  +91 "))
    em=input("Enter your E-mail Id:")
    d["name"]=nm
    d["pswd"]=ps
    d["phone"]=ph
    d["email"]=em
    print("Your data has been saved.\n\n")

elif (ID=="Sign In" or ID=="2" or ID=="sign in"):
    print("Welcome back!! Enter Id and password to continue shopping!")
    nm=input("Enter your name:")                                                                    #login to your account
    ps=input("Enter password for your account:")
    if (ps==d["name1"]):
        print("Hi,", d[0], "continue shopping.\n\n")

else:
    print("Please enter valid input.")                                                                 


print("-------------------------------------------------------------------------------------------** MAIN TASKS **---------------------------------------------------------------------------------\n")
print("(1) View Account Details. ")                                                                  #print-1
print("(2) Edit Account Information.")                                                             #d[x]=y
print("(3) View Available Food Items ")                                                         #print - list
print("(4) Search for a particular food item. ")                                               # in
print("(5) Add more Food to cart. ")                                                               #append or extend
print("(6) Delete Food item from cart. ")                                                    # by position in cart or by value - remove or pop 
print("(7) Count the total quatntity of any Food item. ")                                 #count()
print("(8) Empty cart. ")                                                                                  #clear()    
print("(9) Checkout cart items. ")                                                                   #math module or sum()


while True:
    tsk=int(input("Enter choice for main task:"))
    print("\n")

    if (tsk==1):
        if (ID=="Sign Up" or ID=="1" or ID=="sign up"):
            print("\n ------------------------------------------------------ Account Details  ------------------------------------------------------\n")                             #dictionary traversal
            print("NAME\t\t\t",d["name"])
            print("PASSWORD\t\t",d["pswd"])
            print("PHONE\t\t\t",d["phone"])
            print("EMAIL ID\t\t\t",d["email"])
        else:
            print("\n ------------------------------------------------------ Account Details  ------------------------------------------------------\n")
            print("NAME\t\t\t",d["name1"])
            print("PASSWORD\t\t",d["pswd1"])
            print("PHONE\t\t\t",d["phone1"])
            print("EMAIL ID\t\t",d["email1"])


    if (tsk==2):
        ed=input("What do you want to edit?\t")
        if(ed=="name" or ed=="Name" or ed=="NAME"):
            nme=input("Enter updated name:")
            d["name"]=nme
        if (ed=="password" or ed=="Password" or ed=="PASSWORD"):                                                                                        #dict updation
            cp=input("Please enter your old password:")
            if (cp==ps):
                psu=input("Enter your updated password:")
                d["pwsd"]=psu
                print("Your password has been updated.")
            else:
                print("Wrong Password! Please enter correct password.")
        if(ed=="phone" or ed=="Phone" or ed=="PHONE"):
            phn=int(input("Enter updated phone number:"))
            d["phone"]=phn
        if(ed=="email id" or ed=="Email Id" or ed=="EMAIL ID"):
            emid=input("Enter updated email id:")
            d["email"]=emid    

    if (tsk==3):
        print("------------------------------------------------------------- $$  MENU  $$ -------------------------------------------------------------\n")
        print("\tCHINESE","\t\t\t\t",chnse)
        print("\tFAST FOOD","\t\t\t\t",ftfd)
        print("\tAMERICAN","\t\t\t\t",amrcn)                                                                                                                                     #List printing
        print("\tMAIN COURSE","\t\t\t\t",mnc)
        print("\tSWEETS","\t\t\t\t\t",swts)

    if(tsk==4):
        sch=input("Enter food item to be searched?")
        if (sch in food):
            print(sch,"is available in our Menu!")                                                                                                                          #membership operator
        else:
            print("Sorry...",sch,"is not available.")

    if (tsk==5):
        fd=eval(input("Enter name of food item(s) to be added to the cart:"))                                                                           #tuple addition
        print("\n")
        cart=ct+fd
        print("Food Added!!","\nYour updated cart is --->\t",cart)

    if (tsk==6):
        rm=input("Enter item to be removed:")                                                                                               #upnaking tuple and remove from list
        crt=list(cart)
        crt.remove(rm)
        print("Food Removed :(","\nYour updated cart is--->\t",crt)

    if (tsk==7):
        cnt=input("Enter Food item whose quantity is to be checked:")                                                                   #count function
        crt=list(cart)
        print(cnt,"is present ",crt.count(cnt),"in quantity.")

    if (tsk==8):
        crt=list(cart)                                                                                                              #clear
        crt.clear()
        print("Cart is emptied... Keep shopping :)", crt)

    if (tsk==9):
        crt=list(cart)                                                                                                              #calculation of bill including taxes
        s=0
        for i in crt:
            s+=dp.get(i)
        k=s*0.08
        z=s+k
        print("The totalk price after taxes on the cart items is=",z)


    CH=input("Do you want to perform more Tasks?")    
    if(CH=="NO" or CH=="No" or CH=="no"):
        print("Hope you had a nice time buying!!  :)")
        break
