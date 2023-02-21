import java.util.function.Function;
import java.lang.Math;

class Coefficients
{
	double a, b, c;
}

class QuadraticEquationSol implements Function<Coefficients, Roots>
{
	public Roots apply(Coefficients coeff)
	{
		Roots root = new Roots();
		
		double determinant = coeff.b * coeff.b - 4 * coeff.a * coeff.c;
		double squRes = Math.sqrt(determinant);
		
		if(Double.isNaN(squRes))
		{
			return null;
		}
		
		else
		{
			if (determinant > 0 ) 
			{
				root.root1 = (-coeff.b + Math.sqrt(determinant)) / (2 * coeff.a);
				root.root2 = (-coeff.b - Math.sqrt(determinant)) / (2 * coeff.a);
			}
			else 
			{
			  root.root1 = root.root2 = -coeff.b / (2 * coeff.a);
			}
		}
		return root;
	}
}

class Roots
{
	double root1, root2;
}

class QuadraticEquationFunction
{
	public static void main(String arg[])
	{
		Coefficients coeff = new Coefficients();
		

		coeff.a = Double.parseDouble(arg[0]);
		coeff.b = Double.parseDouble(arg[1]);
		coeff.c = Double.parseDouble(arg[2]);

		Function<Coefficients, Roots> obj = new QuadraticEquationSol();
		Roots r = new Roots();
		r = obj.apply(coeff);
		
		if(r == null)
		{
			System.out.println("Complex Number");
		}
		else
		{
			System.out.println("Root1 = " + r.root1);
			System.out.println("Root2 = " + r.root2);
		}
	}
}
