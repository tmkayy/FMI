package bg.sofia.uni.fmi.mjt.fittrack.workout;

public final class CardioWorkout extends GenericWorkout implements Workout {
    public CardioWorkout(String name, int duration, int caloriesBurned, int difficulty) {
        super(name, duration, caloriesBurned, difficulty);
        type = WorkoutType.CARDIO;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getDuration() {
        return duration;
    }

    @Override
    public int getCaloriesBurned() {
        return caloriesBurned;
    }

    @Override
    public int getDifficulty() {
        return difficulty;
    }

    @Override
    public WorkoutType getType() {
        return type;
    }
}
