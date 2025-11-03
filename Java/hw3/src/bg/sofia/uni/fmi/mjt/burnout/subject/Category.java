package bg.sofia.uni.fmi.mjt.burnout.subject;

public enum Category {

    MATH(0.2),
    PROGRAMMING (0.1),
    THEORY(0.15),
    PRACTICAL(0.05);

    private final double restCoefficient;

    Category(double restCoefficient) {
        this.restCoefficient = restCoefficient;
    }

    public double getRestCoefficient() {
        return restCoefficient;
    }
}