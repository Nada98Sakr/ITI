import java.util.Objects;
import java.util.Optional;
import java.util.Comparator;

import static java.lang.System.out;
import static java.util.stream.Collectors.maxBy;

public class Exercise5 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();
		
		Optional<City> highestPopulationCapital = countryDao.findAllCountries()
            .stream()
            .map(Country::getCapital)
			.map(cityDao::findCityById)
			.filter(Objects::nonNull)
			.max(Comparator.comparingInt(City::getPopulation));
        highestPopulationCapital.ifPresent(out::println);
    }
}