/* package codechef; // don't place package name! */



import java.util.*;

import java.lang.*;

import java.io.*;



/* Name of the class has to be "Main" only if the class is public. */

class Codechef

{

	public static void main (String[] args) throws java.lang.Exception
	{

		// your code goes here

		

		Scanner sc=new Scanner(System.in);

		int n=sc.nextInt();

		int a[]=new int[n];

		

		for(int i=0;i<n;i++)

		a[i]=sc.nextInt();

		

		int k=sc.nextInt();

		

		int max=-1;

		for(int i=0;i<k;i++)

		{

		    if(a[i]>max)

		    max=a[i];

		}

		System.out.print(max+" ");

		for(int i=k;i<n;i++)

		{

		    if(a[i]>max)

		    max=a[i];

		    

		    System.out.print(max+" ");

		    

		    

		}

		

	}

}
