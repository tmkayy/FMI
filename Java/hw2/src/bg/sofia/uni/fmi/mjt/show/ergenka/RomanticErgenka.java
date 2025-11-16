package bg.sofia.uni.fmi.mjt.show.ergenka;

import bg.sofia.uni.fmi.mjt.show.date.DateEvent;

public class RomanticErgenka extends GenericErgenka implements Ergenka {

    private final String favoriteDateLocation;

    public RomanticErgenka(String name, short age, int romanceLevel, int humorLevel, int rating, String favoriteDateLocation) {
        super(name, age, romanceLevel, humorLevel, rating);
        this.favoriteDateLocation = favoriteDateLocation;
    }


    @Override
    public String getName() {
        return this.name;
    }

    public String getfavoriteDateLocation() {
        return this.favoriteDateLocation;
    }

    @Override
    public short getAge() {
        return this.age;
    }

    @Override
    public int getRomanceLevel() {
        return this.romanceLevel;
    }

    @Override
    public int getHumorLevel() {
        return this.humorLevel;
    }

    @Override
    public int getRating() {
        return this.rating;
    }

    @Override
    public void reactToDate(DateEvent dateEvent) {
        if (dateEvent == null) {
            return;
        }

        int tension = dateEvent.getTensionLevel();

        int result = (romanceLevel * 7) / tension + Math.floorDiv(humorLevel, 3);

        int bonus = 0;

        if (favoriteDateLocation != null && dateEvent.getLocation() != null &&
                favoriteDateLocation.equalsIgnoreCase(dateEvent.getLocation())) {
            bonus += 5;
        }

        int duration = dateEvent.getDuration();
        if (duration < 30) {
            bonus -= 3;
        } else if (duration > 120) {
            bonus -= 2;
        }

        rating += result + bonus;
    }
}
