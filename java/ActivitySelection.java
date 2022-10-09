package com.programs;

import java.util.ArrayList;

public class ActivitySelection {

	public static void main(String[] args) {
		int start[]= {1,3,0,5,8,5};
		int end[]= {2,4,6,7,9,9};
		
		int maxAct=0;
		ArrayList<Integer> ans=new ArrayList<>();
		
		//list activity
		
		ans.add(0);
		int lastEnd=end[0];
		for(int i=1;i<end.length;i++) {
			if(start[i]>=end[0]) {
				maxAct++;
				ans.add(i);
				lastEnd=end[i];
			}
		}
		System.out.println("max activities="+maxAct);

	}

}
