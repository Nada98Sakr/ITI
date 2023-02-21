import java.util.*;

interface CompareToGetBetterString {
	public boolean checkContains(String st1 , String st2);
}

class BetterString{
	static String CompareStr(String s1, String s2, CompareToGetBetterString cmpStr)
	{
		if( cmpStr.checkContains(s1, s2)) return s1;
		else return s2;
	}
	
	public static void main(String arg[]){
		
		String s1 = arg[0];
		String s2 = arg[1];
		
		
		String res;
		
		res = CompareStr(s1, s2, (st1, st2)-> st1.contains(st2));
		
		System.out.println(res);
		
	}	
}

