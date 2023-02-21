interface CheckStringAlphabet
{
	public boolean IsAlphabet(String str);
}

class CheckAlphabetOnly {

	public static boolean IsStringAlphabet(String str, CheckStringAlphabet alpha)
	{
		return alpha.IsAlphabet(str);
	}

	public static void main(String args[])
	{
		String str = args[0];

		boolean res = IsStringAlphabet(str, (st)->
									{
										boolean LettersOnly = false;
										for(int i=0;i<st.length();i++)
										{	
											if(Character.isLetter(st.charAt(i)))
											{
												LettersOnly = true;
											}
											else
											{
												return false;
											}
										}
										return LettersOnly;
									});
		
		if(res)
		{
			System.out.println("String contains only alphapits");
		}
		else
		{
			System.out.println("String is not only alphapits");
		}
	}
}