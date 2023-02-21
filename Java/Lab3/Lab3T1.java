import java.util.function.Function;

class ConvertCtoF implements Function<Integer, Float>
{
	public Float apply(Integer degInCel)
	{
		float degInF = degInCel*1.8f + 32;
		return degInF;
	}
}

class CelToFehr
{

	public static void main(String arg[])
	{
		Function<Integer, Float> obj = new ConvertCtoF();
		System.out.println(obj.apply(Integer.parseInt(arg[0])));
	}
}
