import mysql.connector 
import sys

def adm_mgnt():

    print("==========================================================")
    print("==================ADMISSION MANAGEMENT====================")
    print("==========================================================")
    def insert():
        print("="*50)
        print("YOU ARE READY TO INSERT DATA!")
        try:
            b=int(input("ENTER ADMISSION NO : "))
        except ValueError:
            print("you have entered a wrong choice")
            insert()
        
        c=input("ENTER YOUR NAME : ")
        try :
            if c.isdigit():
                print("invalid")
                insert()
        except:
            print()
        d=input("ENTER YOUR CLASSNAME : ")
        try:
            if d.isdigit():
                print("invalid input")
                insert()
        except:
            print()
        e=input("ENTER YOUR CITY : ")
        try:
            if e.isdigit():
                print("invalid input please reenter data")
                insert()
        except:
            print()
        f=input("ENTER DATE OF BIRTH(yyyy-mm-dd): ")
        try:
            if f.isdigit():
                print()
        except:
            print("invalid input please reenter data")
        
        ins= (b, c, d, e, f)
        
        mydb=mysql.connector.connect(host="localhost",user="root",password="root")
        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        sql="CREATE TABLE if not exists STUDENT(admno INT(5) PRIMARY KEY,NAME VARCHAR(20),CLASS CHAR(5),CITY CHAR(10),DOI DATE)"
        mycur.execute(sql)
        query1="INSERT INTO STUDENT (admno,NAME,CLASS,CITY,DOI)values(%s,%s,%s,%s,%s)"
        mycur.execute(query1,ins)        # the query will insert the data in STUDENT table
        mydb.commit()
        print()
        print("you have successfully inserted all value")
        print("="*65)
    #----------------------------------------------------------------------------------------------------
        
    def delete():
        ans=input("Do you really want to delete data?? \nAnswer y/n : ")
        an=ans.upper()
        if an=="Y":
            mydb = mysql.connector.connect(host="localhost", user="root", password="root")
            mycur=mydb.cursor()
            mycur.execute("CREATE DATABASE if not exists PROJECT")
            mycur.execute("USE PROJECT")
            code = int(input("Enter the Admission no :"))

            sql = "DELETE FROM STUDENT WHERE admno = %s;"

            val = (code,)

            mycur.execute(sql, val)            # deletion of data is taking place

            mydb.commit()

            print(mycur.rowcount,"record(s) deleted")
            print("===========================================")
        elif ans!="y":
            sys.exit()
  #----------------------------------------------------------------------------------------------------          

    def display():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)
        try: #Using Exceptions For Validation
            dis= int(input("Please enter your admission no to be displayed : ")) #Will Take Input From User
        except ValueError:
            exit("\nHy! That's Not A Number")
        else:
            print("\n") #Print New Line
        query2="SELECT * FROM STUDENT where admno=%s"
        disc=(dis,)
        mycur.execute(query2,disc)
        for (admno,NAME,CLASS,CITY,DOI) in mycur:   # will print the details line by line
            print("===============================")
            print("ADMISSION NO IS : ",admno)
            print("your registered name is : ",NAME)
            print("your class is : ",CLASS)
            print("city is : ",CITY)
            print("DATE OF BIRTH IS : ",DOI)
            print("===============================")
    #----------------------------------------------------------------------------------------------------
    def display_all():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)
        mycur.execute("SELECT * FROM STUDENT")
        for (admno,NAME,CLASS,CITY,DOI) in mycur:          # Will print the details line by line
            print("===============================")
            print("ADMISSION NO IS : ",admno)
            print("your registered name is : ",NAME)
            print("your class is : ",CLASS)
            print("city is : ",CITY)
            print("DATE OF BIRTH IS : ",DOI)
            print("===============================")
        
  #----------------------------------------------------------------------------------------------------      
            
    def update():
        #============NOW YOU ARE GOING TO UPDATE DATA==============
        #==========================================================
        #==========================================================
        
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur = mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")

        AD = int(input("Enter his/her admission no : "))

        qty = str(input("Enter name :"))
        mycur.execute("select admno from STUDENT ")
        data2=mycur.fetchall()
        l=len(data2)
        b=(AD,)
        for i in range(l):
            if data2[i]==b:   # checking whether the data exists within table or not
                   
                sql = "UPDATE STUDENT SET NAME='{}' WHERE admno={};".format(qty,AD)

                mycur.execute(sql)

                mydb.commit()
                print()
                print("STUDENT DETAILS UPDATED")
                break
        
        else:
            print("NOT IN TABLE")

       
        print("="*40)
        
  #---------------------------------------------------------------------------------------------------- 
    def Exit():
        return
#----------------------------------------------------------------------------------------------------
    #main
    while True:
        
        print("1.ADD NEW STUDENT")
        print("2.DELETE RECORD OF STUDENT")
        print("3.DISPLAY RECORDS OF SPECIFIC STUDENT")
        print("4.DISPLAY RECORDS OF ALL STUDENT")
        print("5.UPDATE RECORD")
        print("6.ANY OTHER NO TO EXIT")
        print()
        try: #Using Exceptions For Validation
            ch= int(input("Please Select An Above Option: ")) #Will Take Input From User
        except ValueError:
            exit("\nHy! That's Not A Number")
        else:
            print() #Print New Line
        if ch==1:
            insert()   
        elif ch==2:
            delete()
        elif ch==3:
            display()
        elif ch==4:
            display_all()
        elif ch==5:
            update()
        else:
            break
    #----------------------------------------------------------------------------------------------------
def lib_mgnt():
    print("===========================================================")
    print("===================LIBRARY MANAGEMENT======================")
    print("===========================================================")
    def B_insert():
        print("="*50)
        print("U ARE READY TO INSERT DATA!")
        a=str(input("ENTER BOOK ID : "))
        try:
            if a.isdigit():
                print("invalid input")
                B_insert()
        except:
            print()
        
        b=input("ENTER BOOK NAME : ")
        try :
            if b.isdigit():
                print("invalid")
                B_insert()
        except:
            print()
        c=input("ENTER AUTHOR NAME : ")
        try:
            if c.isdigit():
                print("invalid input")
                B_insert()
        except:
            print()
        try:
            d=int(input("ENTER PRICE OF BOOK : "))
        except ValueError:
            print("invalid input please reenter data")
            B_insert()
        except:
            print()
        e=str(input("ENTER TYPE OF BOOK: "))
        try:
            if e.isdigit():
                print("WRONG ENTRY!!")
                B_insert()
        except:
            print()

        f=int(input("ENTER QUANTITY : "))
        try:
            if f.isalpha():
                print("INVALID ENTRY!!")
                B_insert()
        except:
            print()
        mydb=mysql.connector.connect(host="localhost",user="root",password="root")
        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        sql="CREATE TABLE if not exists BOOK(BOOK_ID VARCHAR(15)PRIMARY KEY ,BOOK_NAME VARCHAR(50),AUTHOR_NAME VARCHAR(30),PRICE INT(4),TYPE CHAR(15),QTY INT(2))"
        mycur.execute(sql)
        query1="INSERT INTO BOOK (BOOK_ID,BOOK_NAME,AUTHOR_NAME,PRICE,TYPE,QTY) VALUES ('{}','{}','{}',{},'{}',{})".format(a,b,c,d,e,f)
        mycur.execute(query1) # query will insert data into BOOK table
        mydb.commit()
        print("you have successfully inserted all value")
        print("="*60)

#----------------------------------------------------------------------------------------------------     
    def B_delete():
        ans=input("Do you really want to delete data?? \nAnswer y/n : ")
        an=ans.upper()
        if an=="Y":
            mydb = mysql.connector.connect(host="localhost", user="root", password="root")

            mycur=mydb.cursor()
            mycur.execute("CREATE DATABASE if not exists PROJECT")
            mycur.execute("USE PROJECT")

            code = str(input("ENTER BOOK ID: "))

            sql = "DELETE FROM BOOK WHERE BOOK_ID = %s;"  # deletion of data

            val = (code,)

            mycur.execute(sql, val)

            mydb.commit()

            print(mycur.rowcount,"record(s) deleted")
            print("===========================================")
        elif ans!="y":
            sys.exit()        
#----------------------------------------------------------------------------------------------------

    def B_details():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)
        try: #Using Exceptions For Validation
            dis= str(input("ENTER BOOK ID: ")) #Will Take Input From User
        except ValueError:
            exit("\n invalid entry ")
       
        print("="*65)#Print New Line
        query2="SELECT * FROM BOOK where BOOK_ID=%s"
        disc=(dis,)
        mycur.execute(query2,disc)
        for (BOOK_ID,BOOK_NAME,AUTHOR_NAME,PRICE,TYPE,QTY) in mycur: # Print the data of a specific book
            print("===============================")
            print("BOOK ID IS: ",BOOK_ID)
            print("BOOK NAME IS : ",BOOK_NAME)
            print("AUTHOR's NAME: ",AUTHOR_NAME)
            print("PRICE IS: ",PRICE)
            print("TYPE IS: ",TYPE)
            print("QUANTITY IS: ",QTY)
            print("===============================")

#----------------------------------------------------------------------------------------------------

    def display_all():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)
        mycur.execute("SELECT * FROM BOOK")
        for (BOOK_ID,BOOK_NAME,AUTHOR_NAME,PRICE,TYPE,QTY) in mycur: #Print the data of all books
            print("===============================")
            print("BOOK ID IS: ",BOOK_ID)
            print("BOOK NAME IS : ",BOOK_NAME)
            print("AUTHOR's NAME: ",AUTHOR_NAME)
            print("PRICE IS: ",PRICE)
            print("TYPE IS: ",TYPE)
            print("QUANTITY IS: ",QTY)
            print("===============================")

#----------------------------------------------------------------------------------------------------
        
#table book
    def B_update():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur= mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)

        AD = str(input("ENTER BOOK ID: "))

        qty = str(input("ENTER BOOK NAME: "))
        authn=str(input("ENTER NAME OF AUTHOR: "))
        ty=str(input("ENTER TYPE OF BOOK: "))
                  
        mycur.execute("select BOOK_ID from BOOK ")
                  
        data2=mycur.fetchall()
        l=len(data2)
        b=(AD,)
        for i in range(l):
            if data2[i]==b: # checking whether the entered book id belongs to table or not
                   
                sql1 = "UPDATE BOOK SET BOOK_NAME='{}' WHERE BOOK_ID='{}';".format(qty,AD)
                sql="UPDATE BOOK SET AUTHOR_NAME='{}' WHERE BOOK_ID='{}';".format(authn,AD)
                sql2="UPDATE BOOK SET TYPE='{}' WHERE BOOK_ID='{}';".format(ty,AD)

                mycur.execute(sql1)
                mycur.execute(sql)
                mycur.execute(sql2)

                mydb.commit()
                print("\n")
                print("BOOK DETAILS UPDATED")
                break
        
        else:
            print("NOT IN TABLE")
        print("="*40)
#table book
        
#----------------------------------------------------------------------------------------------------

    def B_issue():
        print("="*65)
        print("NOW YOU ARE READY TO ISSUE A BOOK!!!!")
        a=input("ENTER BOOK ID : ")
        try:
            if a.isdigit():
                print("INVALID INPUT")
                B_issue()
        except:
            print()
        try:
            b=int(input("ENTER ISSUE NUMBER: "))
        except ValueError:
            print("INVALID INPUT REENTER DATA!")
            B_issue()
        except:
            print()
        c=str(input("ENTER YOUR NAME: "))
        try:
            if c.isdigit():
                print("INVALID INPUT")
                B_issue()
        except:
            print()
        d=input("ENTER DATE OF ISSUE(yyyy-mm-dd): ")
        try:
            if d.isalpha():
                print("INVALID INPUT REENTER DATA!")
                B_issue()
                
        except:
            print("INVALID")
            B_issue()
            
        e=input("ENTER DATE OF RETURN(yyyy-mm-dd): ")
        try:
            if e.isalpha():
                print("INVALID INPUT REENTER DATA!")
                B_issue()
                
        except:
            print("INVALID")
            B_issue()
            
        det=(a,b,c,d,e)
        H=(a,)
        
        mydb=mysql.connector.connect(host="localhost",user="root",password="root")
        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        sql="CREATE TABLE if not exists ISSUE(BOOK_ID VARCHAR(15) ,ISSUE_NO INT(11) PRIMARY KEY, NAME_ISSUER VARCHAR(25),ISSUE_DATE DATE,RETURN_DATE DATE)"
        mycur.execute(sql)

        #--------------------------------------------------------------------------------
        try:
            q=("SELECT QTY FROM BOOK WHERE BOOK_ID=%s")
            
            mycur.execute(q,H)
            Z=mycur.fetchall()
            l=len(Z)
            x=Z[0][0]          # checking the quantity of book
            if x==0:
                print()
                print("BOOK IS NOT AVAILABLE ")
                print()
               
            else:
                query1="INSERT INTO ISSUE(BOOK_ID,ISSUE_NO,NAME_ISSUER,ISSUE_DATE,RETURN_DATE) VALUES('{}',{},'{}','{}','{}')".format(a,b,c,d,e)
                mycur.execute(query1)
                mycur.execute("SELECT BOOK_ID FROM BOOK")
                data2=mycur.fetchall()
                l=len(data2)
                
                for i in range(l):
                    if data2[i]==H:
                         
                        sql =mycur.execute("UPDATE BOOK SET QTY=QTY-1")

                        mycur.execute(sql)

                        mydb.commit()
                        print()
                        print("YOU HAVE ISSUED A BOOK")
                    

        except:
            print()
            print("THIS BOOK IS NOT AVAILABLE")
        print("="*60)
    #----------------------------------------------------------------------------------------------------
    def BIssued_det():
        mydb = mysql.connector.connect(host="localhost", user="root", password="root")

        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        print("="*65)
        mycur.execute("SELECT * FROM ISSUE")
        print("===============================")
        for (BOOK_ID,ISSUE_NO,NAME_ISSUER,ISSUE_DATE,RETURN_DATE) in mycur: # print the details of issued book
            print("===============================")
            print("BOOK ID IS: ",BOOK_ID)
            print("ISSUE NO IS: ",ISSUE_NO)
            print("NAME OF ISSUER: ",NAME_ISSUER)
            print("DATE OF ISSUE: ",ISSUE_DATE)
            print("DATE OF RETURN: ",RETURN_DATE)
        print("===============================")
   #----------------------------------------------------------------------------------------------------     
    def B_return():
        mydb=mysql.connector.connect(host="localhost",user="root",password="root")
        mycur=mydb.cursor()
        mycur.execute("CREATE DATABASE if not exists PROJECT")
        mycur.execute("USE PROJECT")
        mycur.execute("SELECT BOOK_ID FROM ISSUE")
        data2=mycur.fetchall()
        a=str(input("ENTER BOOK ID WHICH YOU WANT TO RETURN: "))
        c=int(input("ENTER ISSUE NUMBER OF BOOK: "))
        l=len(data2)
        b=(c,)
        mycur.execute("SELECT ISSUE_NO FROM ISSUE where book_id='{}' and ISSUE_NO={}; ".format(a,c)) # checking if entered book id and issue no matches with the issued book or not
        z=mycur.fetchall()
        le=len(z)
        try:
            for i in range(le):
                if z[i][0]==c:
                  
                    query1="delete from issue where ISSUE_NO=%s" # deleting data from issue table
                    mycur.execute(query1,b)
                    sql =mycur.execute("UPDATE BOOK SET QTY=QTY+1") # updating quantity by 1
                    print("BOOK RETURNED")
                    print("="*65)
                    mydb.commit()
        except:
            print("THIS BOOK HAS NOT BEEN ISSUED YET!!")
            print("====================================================")
            pass
        else:
            print("="*60)
            pass
        
    #----------------------------------------------------------------------------------------------------
#table breturn
    while True:
        
        print("1.ADD NEW BOOK")
        print("2.DELETE RECORDS OF BOOK")
        print("3.DISPLAY RECORDS")
        print("4.DETAILS OF ALL BOOKS")
        print("5.UPDATE RECORDS")
        print("6.BOOK ISSUE")
        print("7.DETAILS OF ISSUED BOOK")
        print("8.BOOK RETURN")
        print("9.ANY OTHER NO TO EXIT")
        print()
        try: #Using Exceptions For Validation
            ch= int(input("Please Select An Above Option: ")) #Will Take Input From User
        except ValueError:
            exit("\nHy! That's Not A Number")
        else:
            print() #Print New Line
        if ch==1:
            B_insert()   
        elif ch==2:
            B_delete()
        elif ch==3:
            B_details()
        elif ch==4:
            display_all()
        elif ch==5:
            B_update()
        elif ch==6:
            B_issue()
        elif ch==7:
            BIssued_det()
        elif ch==8:
            B_return()
        else:
            break
    #----------------------------------------------------------------------------------------------------
while True:
    print("1.ADMISSION MANAGEMENT")
    print("2.LIBRARY MANAGEMENT")
    print("3.ANY OTHER NO TO EXIT")
    print()
    try: #Using Exceptions For Validation
        mgnt_ch= int(input("Please Select An Above Option: ")) #Will Take Input From User
    except ValueError:
        exit("\n Hy! That's Not A Number")
    else:
        print() #Print New Line
    if mgnt_ch==1:
        adm_mgnt()   
    elif mgnt_ch==2:
        lib_mgnt()
    else:
        sys.exit()
