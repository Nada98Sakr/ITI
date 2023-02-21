import java.math.BigDecimal;

class GenericComplex <T extends BigDecimal, R extends BigDecimal>{
	T Real; 
	R Imag;
	
	GenericComplex()
	{}

	GenericComplex(T Real , R Imag){
		this.Real = Real ; 
		this.Imag = Imag ; 
	}

	GenericComplex <T,R> add( GenericComplex <T,R> c2 ){
		return new GenericComplex<T,R> ((T)(Real.add(c2.Real)), (R)(Imag.add(c2.Imag))); 
	}
	GenericComplex<T,R> subtract( GenericComplex<T,R> c2 ){
		return new GenericComplex<T,R> ((T)(Real.subtract(c2.Real)), (R)(Imag.subtract(c2.Imag))); 
		 
	}
	GenericComplex<T,R> multiply( GenericComplex<T,R> c2 ){
		return new GenericComplex<T,R> ((T)(Real.multiply(c2.Real)), (R)(Imag.multiply(c2.Imag))); 
	}
	public static void print(GenericComplex c){
		System.out.println(c.Real + "+" + c.Imag +"i" ); 
	}
}

class TestComplex
{
	public static void main(String args[]){
		BigDecimal RealNo1 = new BigDecimal(1); 
		BigDecimal ImagNo1 = new BigDecimal(5); 
		BigDecimal RealNo2 = new BigDecimal(2); 
		BigDecimal ImagNo2 = new BigDecimal(3); 

		GenericComplex <BigDecimal, BigDecimal> comp1 = new GenericComplex<BigDecimal, BigDecimal>(RealNo1,ImagNo1);
		GenericComplex <BigDecimal, BigDecimal> comp2 = new GenericComplex<BigDecimal, BigDecimal>(RealNo2,ImagNo2);
		GenericComplex <BigDecimal, BigDecimal> result = new GenericComplex<BigDecimal, BigDecimal>();
		
		result = comp1.add(comp2); 
		GenericComplex.print(result);
		result = comp1.subtract(comp2); 
		GenericComplex.print(result);
		
		result = comp1 .multiply(comp2); 
		GenericComplex.print(result);
	}
}