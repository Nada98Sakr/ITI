import java.util.Random;

class MinMaxOfArray
{	
	public static int[] GenerateRandomArray(int size)
	{
		int intArr[] = new int[size];
		Random r = new Random();
		for (int i=0; i< intArr.length; i++)
		{
			intArr[i] = r.nextInt();
		}
		return intArr;
	}

	public static int GetMax(int [] arrayOfInt)
	{
		int Max = arrayOfInt[0];
		for(int i = 1; i<arrayOfInt.length; i++)
		{
			if (Max < arrayOfInt[i])
			{
				Max = arrayOfInt[i];
			}
		}
		return Max;
	}
	
	public static int GetMin(int [] arrayOfInt)
	{
		int Min = arrayOfInt[0];
		for(int i = 1; i<arrayOfInt.length; i++)
		{
			if (Min > arrayOfInt[i])
			{
				Min = arrayOfInt[i];
			}
		}
		return Min;
	}

	public static void main(String arg[])
	{	
		int Arr[] = GenerateRandomArray(1000);

		long time1  = System.nanoTime();
		System.out.println("Max = " + GetMax(Arr));
		long time2  = System.nanoTime();
		System.out.println("time of Max search = " + (time2-time1));

		time1  = System.nanoTime();
		System.out.println("Min = " + GetMin(Arr));
		time2  = System.nanoTime();
		System.out.println("time of Min search = " + (time2-time1));
		
	}
}