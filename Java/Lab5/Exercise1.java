import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;


public class Exercise1 {

   public static void main(String[] args){
      CountryDao countryDao= InMemoryWorldDao.getInstance();
	  
		List<City> highestPopulation = countryDao.findAllCountries()
            .stream()
            .map(country -> country.getCities()
			.stream()
			.max(Comparator.comparing(City::getPopulation)))
            .filter(Optional::isPresent)
            .map(Optional::get)
            .collect(Collectors.toList());
	  
		for(City c:highestPopulation) {
			System.out.println(c.getId()+" "+c.getName()+" "+c.getPopulation());
		}
   }

}