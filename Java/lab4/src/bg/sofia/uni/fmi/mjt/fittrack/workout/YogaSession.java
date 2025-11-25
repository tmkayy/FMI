package bg.sofia.uni.fmi.mjt.fittrack.workout;

public final class YogaSession extends GenericWorkout implements Workout {
    public YogaSession(String name, int duration, int caloriesBurned, int difficulty) {
        super(name, duration, caloriesBurned, difficulty);
        type = WorkoutType.YOGA;
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
