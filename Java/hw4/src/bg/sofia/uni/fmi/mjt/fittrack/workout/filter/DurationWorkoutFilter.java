package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;

public class DurationWorkoutFilter implements WorkoutFilter {
    private int min;
    private int max;

    public DurationWorkoutFilter(int min, int max){
        if(min > max){
            throw new IllegalArgumentException("min > max");
        }
        setMin(min);
        setMax(max);
    }

    public int getMin() {
        if(min<0){
            throw new IllegalArgumentException("min must be greater than 0");
        }
        return min;
    }

    public void setMin(int min) {
        this.min = min;
    }

    public int getMax() {
        return max;
    }

    public void setMax(int max) {
        if(max<0){
            throw new IllegalArgumentException("min must be greater than 0");
        }
        this.max = max;
    }

    @Override
    public boolean matches(Workout workout) {
        if (workout == null) {
            return false;
        }
        return workout.getDuration()>=min && workout.getDuration()<=max;
    }
}
