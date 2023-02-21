class InputString
{
	public static void main(String arg[])
	{
		int len = Integer.parseInt(arg[0]);
		if(len>0 && (arg.length == 2))
		{
			for(int i=0; i<len ;i++)
			{
				System.out.println(arg[1]);
			}
		}
		else
		{
			System.out.println("Please enter only two arguments!!! as 'java InputString 2 test' ");
		}
	}
}