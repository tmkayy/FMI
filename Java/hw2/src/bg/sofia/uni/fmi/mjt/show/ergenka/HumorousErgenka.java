package bg.sofia.uni.fmi.mjt.show.ergenka;

import bg.sofia.uni.fmi.mjt.show.date.DateEvent;

public class HumorousErgenka extends GenericErgenka implements Ergenka {

    public HumorousErgenka(String name, short age, int romanceLevel, int humorLevel, int rating) {
        super(name, age, romanceLevel, humorLevel, rating);
    }

    @Override
    public String getName() {
        return this.name;
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
        int result = (humorLevel * 5) / dateEvent.getTensionLevel() + romanceLevel / 3;
        int bonus = 0;
        if (dateEvent.getDuration() >= 30 && dateEvent.getDuration() <= 90)
            bonus += 4;
        else if (dateEvent.getDuration() < 30)
            bonus -= 2;
        else
            bonus -= 3;
        rating += result + bonus;
    }
}
