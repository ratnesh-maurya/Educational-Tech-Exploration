def convert(num):
    leng=len(num)
    if leng==0:
        print("empty string")
        return
    if leng>4:
        print("lenght is greater")
        return
    single=['zero','one','two','three','four','five','six','seven','eight','nine',]
    double=['','ten','eleven','twele','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','ninteen']
    ten_multiple=['','','twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninty']
    ten_power=['hundred','thousand']
    if leng==1:
        print(single[ord(num[0])-48])
        return
    x=0
    while(x<len(num)):
        # for first two digit
        if (leng>=3):
            if(ord(num[x])-48!=0):
             print(single[ord(num[x])-48],end=" ")
             print(ten_power[(leng-3)],end=" ")
            leng-=1
          # for last two digit
        else:
        # for 11-19
            if(ord(num[x])-48==1):
             print(double[ord(num[x])-47])
             return
        #for 20
            elif(ord(num[x])-48==2 and ord(num[x+1])-48==0):
             print("twenty")
             return
            #  for 20-99
            else:
              i=ord(num[x])-48
              if i>0:
               print(ten_multiple[i],end=" ")
              else:
                  print("",end=" ")
              x+=1
              if(ord(num[x])-48!=0):
               print(single[ord(num[x])-48])

        x+=1
num=input("enter number: ")
convert(num)
            

