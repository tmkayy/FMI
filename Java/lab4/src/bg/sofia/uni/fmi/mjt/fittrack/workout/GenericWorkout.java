package bg.sofia.uni.fmi.mjt.fittrack.workout;

import bg.sofia.uni.fmi.mjt.fittrack.exception.InvalidWorkoutException;

public abstract class GenericWorkout {
    protected String name;
    protected int duration;
    protected int caloriesBurned;
    protected int difficulty;
    protected WorkoutType type;

    static final int MIN_DIFFICULTY = 1;
    static final int MAX_DIFFICULTY = 5;

    protected GenericWorkout(String name, int duration, int caloriesBurned, int difficulty) {
        setName(name);
        setDuration(duration);
        setCaloriesBurned(caloriesBurned);
        setDifficulty(difficulty);
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new InvalidWorkoutException("Workout name is null or empty");
        }
        this.name = name;
    }

    public void setDuration(int duration) {
        if(duration <= 0) {
            throw new InvalidWorkoutException("Workout duration is negative");
        }
        this.duration = duration;
    }

    public void setCaloriesBurned(int caloriesBurned) {
        if(caloriesBurned <= 0) {
            throw new InvalidWorkoutException("Workout calories burned is negative");
        }
        this.caloriesBurned = caloriesBurned;
    }

    public void setDifficulty(int difficulty) {
        if(difficulty < MIN_DIFFICULTY || difficulty > MAX_DIFFICULTY) {
            throw new InvalidWorkoutException("Workout difficulty is out of range");
        }
        this.difficulty = difficulty;
    }
}
