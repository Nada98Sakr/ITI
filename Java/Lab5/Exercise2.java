
import java.util.*;
import java.util.function.BiConsumer;
import java.util.stream.*;
import java.util.Map.Entry;


public class Exercise2 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
		
		Map <String, Optional<City>> highestPopulationInContenent = new HashMap<String,Optional<City>>();
			
		highestPopulationInContenent = countryDao.findAllCountries()
									    .stream()
										.flatMap(country -> country.getCities()
										.stream())
										.collect(Collectors.groupingBy(
													   city -> countryDao
													   .findCountryByCode(city.getCountryCode()).getContinent(),
																		Collectors.maxBy(Comparator.comparing(City::getPopulation))));
									   
	
								
								
		highestPopulationInContenent.forEach((cont, v) -> System.out.println(cont + ": City [ name= " + v.get().getName() + ", population= " + v.get().getPopulation() + " ]"));

    }

}
