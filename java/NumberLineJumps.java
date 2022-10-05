public class NumberLineJumps {
    public static String kangaroo(int x1, int v1, int x2, int v2) {
        String str = null;
if (x1<x2){
    if (v1<v2){
        str="NO";
        return str;
    }
    else{
        int a = x1+v1;
        int b =x2+v2;
        while (a<b){
            a=a+v1;
            b=b+v2;
        }
        if (a==b){ 
     str="YES";
     return str;
    }
    else{
        str="NO";
        return str;
    }
}
}
else{
    if (v1<v2){
        int a = x1+v1;
        int b =x2+v2;
        while (b<a){
            a=a+v1;
            b=b+v2;
        }
        if (a==b){ 
     str="YES";
     return str;
    }
    else{
        str="NO";
        return str;
    }

    }
    else{
        str="NO";
        return str;
    }
}
}
}