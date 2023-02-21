class InputManyStrings
{
	public static void main(String arg[])
	{
		int stringSize = arg.length;
		if(stringSize>0)
		{
			for(int i=0; i<stringSize ;i++)
			{
				System.out.println(arg[i]);
			}
		}
		else
		{
			System.out.println("No string to print");
		}
	}
}