package bg.sofia.uni.fmi.mjt.show.ergenka;

public class GenericErgenka {
    protected final String name;
    protected final short age;
    protected final int romanceLevel;
    protected final int humorLevel;
    protected int rating;

    public GenericErgenka(String name, short age, int romanceLevel, int humorLevel, int rating) {
        this.name = name;
        this.age = age;
        this.romanceLevel = romanceLevel;
        this.humorLevel = humorLevel;
        this.rating = rating;
    }
}
