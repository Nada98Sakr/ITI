import java.util.Arrays;

class SplitIpAddress
{
	public static void SplitIp(String IP)
	{	
		String spiltedIP[] = IP.split("\\.");
		for(int i=0; i<4 ; i++)
		{	
			System.out.println(spiltedIP[i]);
		}
	}

	public static void main(String arg[])
	{
		SplitIp(arg[0]);
	}
}