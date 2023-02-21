import java.util.StringTokenizer;

class SearchStringTokenizer
{	
	public static void main(String arg[])
	{	
		String str = "ITI developes people and ITI house of developers and ITI for people";
		String Word= "ITI";
		StringTokenizer tokens = new StringTokenizer(str, Word);
		System.out.println(tokens.countTokens());
		
	}
}