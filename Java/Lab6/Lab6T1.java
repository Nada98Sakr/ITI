import java.util.Map;
import java.util.TreeMap;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Map.Entry;

class Dictionary
{
	Map<Character, SortedSet<String> > dictionary;
	
	Dictionary()
	{
		dictionary = new TreeMap<Character, SortedSet<String>>();
	}
	
	/*public void FillDictionary()
	{
		
	}*/
	
	void AddNewWord(char key, String word)
	{
		if(dictionary.get(key) == null)
		{
			dictionary.put(key, new TreeSet<String>());
			dictionary.get(key).add(word);
		}
		
		else{
			dictionary.get(key).add(word);
		}
	}
	
	boolean SearchForWord(String word)
	{
		String NewWord = word.toLowerCase();
		char c = NewWord.charAt(0);
		
		if(dictionary.get(c) != null)
		{
			SortedSet <String> s = dictionary.get(c);
			
			if(s.contains(NewWord))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	SortedSet<String> getAllWords(char key)
	{
		return dictionary.get(key);
	}
	
	Map <Character, SortedSet<String>> getDictionary()
	{
		return dictionary;
	}
}

class TestDictionary
{
	public static void main(String args[])
	{
		
		Dictionary d = new Dictionary();
		d.AddNewWord('c', "class");
		d.AddNewWord('c', "cut");
		d.AddNewWord('c', "cup");
		d.AddNewWord('c', "cable");
		d.AddNewWord('c', "cell");
		
		d.AddNewWord('a', "anchor");
		d.AddNewWord('a', "apple");
		d.AddNewWord('a', "add");
		
		
		d.AddNewWord('b', "ball");
		d.AddNewWord('b', "bus");
		d.AddNewWord('b', "base");
		
		d.AddNewWord('a', "actor");
		d.AddNewWord('a', "ask");
		
		d.AddNewWord('b', "belt");
		d.AddNewWord('b', "bed");
		
		
		
		d.AddNewWord('d', "desk");
		d.AddNewWord('d', "door");
		d.AddNewWord('d', "design");
		d.AddNewWord('d', "direct");
		d.AddNewWord('d', "dish");
		
		System.out.println("\n---------------------------------------------------------------------------------\n");
		
		boolean IfContains = d.SearchForWord(args[0]);
		if(IfContains)
		{
			System.out.println("Word found in the dictionary");
		}
		else
		{
			System.out.println("Word Not fount in the dictionary");
		}
		
		System.out.println("\n---------------------------------------------------------------------------------\n");
		char ch = 'a';
		if(d.getAllWords(ch) == null)
		{
			System.out.println("No words Start with " + ch);
		}
		else{
			System.out.println("The words that start with the character " + ch + " are: ");
			System.out.println("	" + d.getAllWords(ch));
		}
		System.out.println("\n---------------------------------------------------------------------------------\n");
		
		System.out.println("The Dictionary:    ");
		for( Entry<Character, SortedSet<String>> dict: d.getDictionary().entrySet() )
		{
			System.out.println("\n	" + dict.getKey() +" : " + dict.getValue());
		}
		System.out.println("\n---------------------------------------------------------------------------------\n");
	
	}
}