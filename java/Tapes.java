import java.util.Scanner;
import java.util.Arrays;

class Tapes
{
	static void decline(float[] r, int n)                             // arrange the tapes in descending order
	{
		for(int i=0;i<n;i++)
		{	
			for(int j=i+1;j<n;j++)
			{	float t;
				if(r[j]<r[i])
				{
					t=r[j];
					r[j]=r[i];
					r[i]=t;
				}
			}
		}
	}

	static float[] storing(float[] r, int l, int n)                        
	{
		decline(r,n);
		if(l==n)
		{
			return r;
		}
		
		else
		{
			float[] tape=new float[l];
			for(int i=0;i<n;i++)
			{
				tape[i]=r[i];
			}
			
			return tape;
		}
	}

	static float mrt(float[] tape, int l)                         //calculate the mean retrieval time
	{	
		float rt=0;

		for(int i=0;i<l;i++)
		{	rt+=tape[i]*(l-i);
		}
		
		rt=rt/l;
		return rt;
	}
		
		
			

	public static void main(String[] args)
	{
		Scanner x=new Scanner(System.in);
		System.out.println("enter the number of programs");
		int n=x.nextInt();
		float[] jobs=new float[n];
		System.out.println("enter the lengths of programs");
		for(int i=0;i<n;i++)
		{
			jobs[i]=x.nextFloat();
		}
		System.out.println("enter the length of tape");
		int l=x.nextInt();
		
		float[] tape=storing(jobs,l,n);
		System.out.println(" the optimal storage on tape is ");
		System.out.println(Arrays.toString(tape));
		float mrt= mrt(tape,l);
		System.out.println("the mean retrival time is ");	
		System.out.println(mrt);
		
	}
}
		
			
			
				
		
					
