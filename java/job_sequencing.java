import java.util.Scanner;
import java.util.Arrays;

class Job_sequencing{

	static int[] sequencing(int[] p, int[] d,int n)                                                        // give values of profits vector(p) in descending order
	{	
		int[] temp=new int[n];
		int profit=0;
		for(int i=0;i<n;i++){
			int k=d[i];
			while(k>0)
			{                                                                 
				if(temp[k]==0)
				{                                                                      // check if slot k is availible
					temp[k]=p[i];                                                                 // assing slot k with job i
					profit=profit+p[i];
					break;
				}
				else
				{
					k-=1;
				}
			}
	}
		return temp;
	}

	public static void main(String[] args){
		Scanner x=new Scanner(System.in);
		System.out.println();
		System.out.println("P. Sriram Bhardwaj");
		System.out.println("Regd.no - 122010308005");
		System.out.println(" ");
		System.out.println("Job Sequencing");
		System.out.println(" ");
		System.out.println("enter the number of elements");
		System.out.println("Enter the number of jobs");
		int n=x.nextInt();
		int[] arr=new int[n];

		for (int i=0;i<n;i++){                                                                //profits list
			arr[i]=x.nextInt();}

		System.out.println(" the profits are "+Arrays.toString(arr));
		int[] d=new int[n];

		for(int i=0;i<n;i++){                                                           //deadlines list
			d[i]=x.nextInt();}

		System.out.println(" the deadlines are "+Arrays.toString(d));			//selection sort based sorting of jobs and deadlines based on profits
		int j;
		int t;
		int u;
		for(int i=0;i<n;i++)
		{
			j=i;
			for (int k=i+1;k<n;k++)
			{
				if(arr[k]>arr[j])
				{
					j=k;
					t=arr[i];
					arr[i]=arr[j];
					arr[j]=t;

					u=d[i];
					d[i]=d[j];
					d[j]=u;
				}
			}


		}
		System.out.println(Arrays.toString(sequencing(arr,d,n)));
}
}





		