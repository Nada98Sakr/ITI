
class SearchString
{	
	public static int CountUsingStringSplit(String Statement, String word)
	{
		int count = 0;
		String[] words = Statement.split(" ");
		for(int i=0; i<words.length; i++)
		{
			if(words[i].matches(word))
			{
				count++;	
			}
		}	

		return count;
	}

	public static int CountUsingStringIndex(String Statement, String word)
	{
		int count = 0;
		int z = 0;
		while(Statement.indexOf(word,z) != -1)
		{
			z = Statement.indexOf(word,z)+1;
			count++;
		}

		return count;
	}	

	public static void main(String arg[])
	{	
		String str = "ITI developes people and ITI house of developers and ITI for people";
		System.out.println("The Word ITI repeated " + CountUsingStringSplit(str, "ITI"));
		System.out.println("The Word ITI repeated " + CountUsingStringIndex(str, "ITI"));
		
	}
}