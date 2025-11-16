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
        if (dateEvent == null)
            return;
        int result = (romanceLevel * 7) / dateEvent.getTensionLevel() + humorLevel / 3;
        int bonus = 0;
        if (dateEvent.getLocation().equals(this.favoriteDateLocation))
            bonus += 5;
        if (dateEvent.getDuration() < 30)
            bonus -= 3;
        if (dateEvent.getDuration() > 120)
            bonus -= 2;
        rating += result + bonus;
    }
}
